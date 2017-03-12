#include <iostream>

using namespace std;

int findKmin(int a[],int aBeg,int aEnd,int b[],int bBeg,int bEnd,int k){
    if (aBeg > aEnd){
        return b[bBeg+k-1];
    }
    if (bBeg > bEnd){
        return a[aBeg+k-1];
    }

    int aMid = aBeg + (aEnd - aBeg)/2;
    //cout << aMid << endl;
    int bMid = bBeg + (bEnd - bBeg)/2;
    //cout << bMid << endl;
    int halfLen = aMid - aBeg + bMid - bBeg + 2;
    //cout << halfLen << endl;

    if (a[aMid] < b[bMid]){
        if (k < halfLen){
            findKmin(a,aBeg,aEnd,b,bBeg,bMid-1,k);
        }else{
            findKmin(a,aMid+1,aEnd,b,bBeg,bEnd,k-(aMid-aBeg+1));
        }
    }else{
        if (k < halfLen){
            findKmin(a,aBeg,aMid-1,b,bBeg,bEnd,k);
        }else{
            findKmin(a,aBeg,aEnd,b,bMid+1,bEnd,k-(bMid-bBeg+1));
        }
    }
}

int main()
{
    int i,m,n,k;
    cin >> m >> n >> k;
    int a[m],b[n];
    for (i = 0; i < m; i++){
        cin >> a[i];
    }
    for (i = 0; i < n; i++){
        cin >> b[i];
    }
    int kMin = findKmin(a,0,m-1,b,0,n-1,k);
    cout << kMin << endl;

    return 0;
}