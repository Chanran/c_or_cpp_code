// 用分治法求众数

#include <iostream>
#include <cstdio>

using namespace std;

// 本程序的关键， 以中间的数字为界限， 确定左右起始和终止界限
void split(int s[], int n, int &l, int &r)
{
    int mid = n/2;
    for(l=0; l<n; ++l)
    {
        if (s[l] == s[mid])
            break;
    }
    for(r=l+1; r<n; ++r)
    {
        if (s[r] != s[mid])
            break;
    }

}

// num 众数， maxCnt 重数
void getMaxCnt(int &mid, int &maxCnt, int s[], int n)
{
    int l, r;
    split(s, n, l, r);  // 进行切割，这个函数是本程序的关键
    int num = n/2;
    int cnt = r-l;

    // update
    if (cnt > maxCnt)
    {
        maxCnt = cnt;
        mid = s[num];
    }

    // l 表示左边的个数，左边的个数必须大于 maxCnt 才有必要搜寻
    if (l+1 > maxCnt)
    {
        getMaxCnt(mid, maxCnt, s, l+1);
    }

    // 右边搜寻, 右边数组的起始地址要变更
    if (n-r > maxCnt)
    {
        getMaxCnt(mid, maxCnt, s+r, n-r);
    }
}

int main(void)
{
    int n;
    cin >> n;
    int a[n];
    int i;
    for (i = 0; i < n; i++){
        cin >> a[i];
    }

    int maxCnt = 0;
    int num = 0;
    getMaxCnt(num, maxCnt, a, n);
    printf("%d %d\n", num, maxCnt);

    return 0;
}