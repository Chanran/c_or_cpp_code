#include <iostream>

using namespace std;

int mergeInversion(int a[],int low,int middle,int high){
    int count = 0;
    int i,j;
    for (i = low; i <= middle; i++){
        for (j = middle+1; j <= high; j++){
            if (a[i] > a[j]){
                count++;
            }
        }
    }
    return count;
}

int countInversion(int a[],int low,int high){
    int count = 0,middle;
    if (low < high){
        middle = low + (high-low)/2;
        count += countInversion(a,low,middle);
        count += countInversion(a,middle+1,high);
        count += mergeInversion(a,low,middle,high);
    }
    return count;
}

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    int time = countInversion(a,0,n-1);

    cout << time << endl;
    return 0;
}
