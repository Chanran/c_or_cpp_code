/*
 * 01背包贪心法
 */
#include <iostream>
#include <fstream>
using namespace std;
void Traceback(long* index,long ww[],long vv[],long n,long C){
    long cw = 0; //当前重量
    long cv = 0; //当前价值
    long maxv = 0; //最大价值
    long i = 0;
    long* indexindex = new long[n]; //物品是否放入背包
    while(i >= 0){
        indexindex[i] = 0;
        if(cw + ww[i] < C){
            cw += ww[i];
            cv += vv[i];
            indexindex[index[i]] = 1;
            i++;
        }else{
            break;
        }
    }
    cout << "========= 01背包贪心法 ==========" << endl;
    if(i < n){
        maxv = cv;
        cout << "最优值：" << maxv << endl;
    }
    cout << "最优解："<< endl;
    for(i = 0; i < n; i++){
        cout << i+1 << " " << indexindex[i] << endl;
    }
    cout << "======== END =============" << endl;
    delete[] indexindex;
}
void Knapsack(long n,long C,long v[],long w[]){
    double* r = new double[n];
    long* index = new long[n];
    for(int i = 0; i < n; i++){
        r[i] = (double)v[i]/(double)w[i];
        index[i] = i;
    }
    //单位重量价值r[i] = v[i]/w[i]降序排序
    for(long i = 0; i <= n; i++){
        for(long j = i
                     + 1; j < n; j++){
            if(r[i] < r[j]){
                swap(r[i],r[j]);
                swap(index[i],index[j]);
            }
        }
    }
    long* ww = new long[n];
    long* vv = new long[n];
    for (long i = 0; i < n; i++){
        ww[i] = w[index[i]];
        vv[i] = v[index[i]];
    }
    Traceback(index,ww,vv,n,C);
    delete[] r;
    delete[] index;
}
int main(int argc, char *argv[]) {
    clock_t start, finish; /* 精确到 ms(毫秒)级的时间*/
    double duration; /*测量一个事件持续的时间*/
    start = clock();
    long i,n,C,count;
    ifstream in;
    long *w,*v; //物品重量和价值数组
    long wIndex,vIndex; //物品重量和价值数组的下标
    long tmp; //读取用的暂存变量
    in.open("test.txt",ios::in|ios::binary);
    if (!in.is_open()){
        cout << "open file error" << endl;
        exit(1);
    }
    in >> tmp;  //每次读入一个long型数据
    C = tmp;    //背包容量
    in >> tmp;  //每次读入一个long型数据
    n = tmp;    //物品个数
    w = new long[n+1]; //物品重量数组
    v = new long[n+1]; //物品价值数组
    wIndex = 1;
    vIndex = 1;
    count =  1;
    in >> tmp;
    while(!in.eof()){
        if(count % 2 != 0){
            w[wIndex] = tmp;
            wIndex++;
        }else{
            v[vIndex] = tmp;
            vIndex++;
        }
        count++;
        in >> tmp;
    }
    v[vIndex] = tmp;
    long** m  = new long*[n+1];
    for (i = 0; i <= n; i++){
        m[i] = new long[C+1];
    }
    Knapsack(n,C,v,w);
    in.close(); //关闭文件
    delete []w; //释放w
    delete []v; //释放v
    /*程序运行时间*/
    finish = clock();
    duration = (double)(finish - start) / CLOCKS_PER_SEC;
    printf( "%f seconds\n", duration ); /*此 duration 单位为秒*/
    return 0;
}