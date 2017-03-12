/*
 * 01背包回溯法
 */
#include <iostream>
#include <fstream>
using namespace std;
class Knap {
    friend long Knapsack(long v[], long w[], long c, long n);
public:
    void print() {
        long* indexindex = new long[n];
        cout <<  "最优解:" << endl;
        for (long j = 1; j <= n; j++) {
            indexindex[j-1] = 0;
            if (bestx[j] == 1){
                indexindex[index[j-1]] = 1;
            }
        }
        for (long j = 0; j < n; j++){
            cout << j+1 << " " << indexindex[j] << endl;
        }
        cout << endl;
        cout << "最优值：";
    };
private:
    long Bound(long i);
    void Backtrack(long i);
    long c;//背包容量
    long n; //物品数
    long *w;//物品重量数组
    long *v;//物品价值数组
    long cw;//当前重量
    long cv;//当前价值
    long bestv;//当前最优值
    long *bestx;//当前最优解
    long *index;//坐标变换数组
    long *x;//当前解
};
long Knap::Bound(long i) {
    //计算上界
    long cleft = c - cw;//剩余容量
    long b = cv;
    //以物品单位重量价值递减序装入物品
    while (i <= n && w[i] <= cleft) {
        cleft -= w[i];
        b += v[i];
        i++;
    }
    //装满背包
    if (i <= n)
        b += v[i] * cleft / w[i];
    return b;
}
void Knap::Backtrack(long i) {
    if (i > n) { //到达叶子节点
        if (bestv < cv) {
            for (long j = 1; j <= n; j++)
                bestx[j] = x[j];
            bestv = cv;
        }
        return;
    }
    if (cw + w[i] <= c) {   //搜索左子树
        x[i] = 1;
        cw += w[i];
        cv += v[i];
        Backtrack(i + 1);
        cw -= w[i];
        cv -= v[i];
    }
    if (Bound(i + 1) > bestv){  //搜索右子树
        x[i] = 0;
        Backtrack(i + 1);
    }
}
class Object {
    friend long Knapsack(long* v, long* w, long C, long n);
public:
    long operator<=(Object a) const {
        return (d >= a.d);
    }
private:
    long ID;
    double d;
};
void Sort(Object *Q,long len,long *index) {
    for(long i=0;i<len;i++)
        for(long j=0;j<len;j++)
            if(Q[i]<=Q[j]) {
                Object temp=Q[i];
                Q[i]=Q[j];
                Q[j]=temp;
                long tmp = index[i];
                index[i] = index[j];
                index[j] = tmp;
            }
}
long Knapsack(long* v, long* w, long C, long n) {
    //为Knap::Backtrack初始化
    long W = 0;
    long V = 0;
    long i = 1;
    Object *Q = new Object[n];
    for (i = 1; i <= n; i++) {
        Q[i - 1].ID = i;
        Q[i - 1].d = 1.0 * v[i] / w[i];
        V += v[i];
        W += w[i];
    }
    if (W <= C)
        return V;//装入所有物品
    Knap K; //实例化Knap
    //依物品单位重量排序
    K.index = new long[n];
    for(long j = 0; j < n; j++){   //初始化下标数组，交换的时候记录坐标变换
        K.index[j] = j;
    }
    Sort(Q,n,K.index);  //排序
    K.v = new long[n + 1];
    K.w = new long[n + 1];
    K.x = new long[n + 1];
    K.bestx = new long[n + 1];
    K.x[0] = 0;
    K.bestx[0] = 0;
    for (i = 1; i <= n; i++) {
        K.v[i] = v[Q[i - 1].ID];
        K.w[i] = w[Q[i - 1].ID];
    }
    K.cv = 0;
    K.cw = 0;
    K.c = C;
    K.n = n;
    K.bestv = 0;
    //回溯搜索
    K.Backtrack(1);
    K.print();
    delete[] Q;
    delete[] K.w;
    delete[] K.v;
    return K.bestv;
}
int main(int argc, char *argv[]) {
    clock_t start, finish; /* 精确到 ms(毫秒)级的时间*/
    double duration; /*测量一个事件持续的时间*/
    start = clock();
    long i, n, C, count;
    ifstream in;
    long *w, *v; //物品重量和价值数组
    long wIndex, vIndex; //物品重量和价值数组的下标
    long tmp; //读取用的暂存变量
    in.open("test.txt", ios::in | ios::binary);
    if (!in.is_open()) {
        cout << "open file error" << endl;
        exit(1);
    }
    in >> tmp;  //每次读入一个long型数据
    C = tmp;    //背包容量
    in >> tmp;  //每次读入一个long型数据
    n = tmp;    //物品个数
    w = new long[n + 1]; //物品重量数组
    v = new long[n + 1]; //物品价值数组
    wIndex = 1;
    vIndex = 1;
    count = 1;
    in >> tmp;
    while (!in.eof()) {
        if (count % 2 != 0) {
            w[wIndex] = tmp;
            wIndex++;
        } else {
            v[vIndex] = tmp;
            vIndex++;
        }
        count++;
        in >> tmp;
    }
    v[vIndex] = tmp;
    long **m = new long *[n + 1];
    for (i = 0; i <= n; i++) {
        m[i] = new long[C + 1];
    }
    cout << Knapsack(v, w, C, n) << endl;
    in.close(); //关闭文件
    delete[]w; //释放w
    delete[]v; //释放v
    /*程序运行时间*/
    finish = clock();
    duration = (double) (finish - start) / CLOCKS_PER_SEC;
    printf("%f seconds\n", duration); /*此 duration 单位为秒*/
    return 0;
}