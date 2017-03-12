#include <iostream>
using namespace std;
typedef struct section{
    int start;
    int end;
} Section;
int greedySelector(Section* sectionArr,int n){
    int i,j;
    int count = 1;
    int current = 0;
    Section tmp;
    int length = n;
    for (i = 0; i < length-1; i++){
        for(j = i+1; j < length; j++){
            if (sectionArr[i].end >  sectionArr[j].end){
                tmp = sectionArr[i];
                sectionArr[i] = sectionArr[j];
                sectionArr[j] = tmp;
            }
        }
    }
    for(i = 1; i < length; i++){
        if (sectionArr[current].end <= sectionArr[i].start){
            count++;
            current = i;
        }
    }
    return count;
}
int main() {
    int n;
    cin >> n;
    Section* sectionArr = new Section[n];
    for (int i = 0; i < n; i++){
        cin >> sectionArr[i].start;
        cin >> sectionArr[i].end;
    }
    cout << n-greedySelector(sectionArr,n) << endl;
    delete []sectionArr;
    return 0;
}