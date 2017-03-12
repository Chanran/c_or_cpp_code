#include <iostream>

using namespace std;

void swap(int &a,int & b){
    int temp = a;
    a = b;
    b = temp;
}

int main() {
    int n;
    int i,j;
    int count = 1,base;
    cin >> n;
    int* house = new int[n];
    for (i = 0; i < n; i++){
        cin >> house[i];
    }

    for (i = 0; i < n-1; i++){
        for (j = i + 1; j < n; j++){
            if (house[i] > house[j]){
                swap(house[i],house[j]);
            }
        }
    }

    base = house[0] + 4;
    for(i = 1; i < n; i++){
        if (base < house[i] - 4){
            count++;
            base = house[i] + 4;
        }
    }

    cout << count << endl;

    return 0;
}