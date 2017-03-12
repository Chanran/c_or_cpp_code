/*
 * 01背包动态规划
 */
#include <iostream>
#include <fstream>
using namespace std;
long max(long a,long b)  {
    if(a>b){
        return a;
    }
    return b;
}
long min(long a,long b)  {
    if(a<b){
        return a;
    }
    return b;
}
void Traceback(long w[],long n,long C,long** m){
    long* x = new long[n+1];
    for (long i = 1; i < n; i++){
        if (m[i][C] == m[i+1][C]){
            x[i] = 0;
        }else{
            x[i] = 1;
            C-= w[i];
        }
    }
    x[n] = (m[n][C])?1:0;
    cout << "最优解：" << endl;
    for (long i = 1; i <= n; i++){
        cout << i << " " << x[i] << endl;
    }
    cout << "========== 结束 ============" << endl;
}
void knapsack(long w[],long v[],long n,long C,long** m){  //01背包，动态规划
    cout << "========== 01背包的动态规划方法 ============" << endl;
    long jMax = min(w[n]-1,C);
    for (long j = 0;j <= jMax; j++){
        m[n][j] = 0;
    }
    for (long j = w[n];j <= C; j++){
        m[n][j] = v[n];
    }
    for (long i = n - 1; i > 1; i--){
        jMax = min(w[i]-1,C);
        for (long j = 0; j <= jMax; j++){
            m[i][j] = m[i+1][j];
        }
        for (long j = w[i]; j <= C; j++){
            m[i][j] = max(m[i+1][j],m[i+1][j-w[i]]+v[i]);
        }
    }
    m[1][C] = m[2][C];
    if (C >= w[1]){
        m[1][C] = max(m[1][C],m[2][C-w[1]]+v[1]);
    }
    cout << "背包可以装的最大价值为：" << m[1][C] << endl;
    Traceback(w,n,C,m); //打印最优解
    delete[] m;
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
    knapsack(w,v,n,C,m); //调用动态规划法求最优值和最优解
    in.close();
    delete []w;
    delete []v;
    /*程序运行时间*/
    finish = clock();
    duration = (double)(finish - start) / CLOCKS_PER_SEC;
    printf( "%f seconds\n", duration ); /*此 duration 单位为秒*/
    return 0;
}