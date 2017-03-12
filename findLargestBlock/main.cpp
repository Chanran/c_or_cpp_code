#include <iostream>
#include <vector>

using namespace std;

vector <int> findLargestBlock (const vector <vector <int> > &m,int n){
    int t = 1;
    int i = 0,j = 0,l = 0;
    int x = 0,y = 0;
    vector<int> result(3,0);

    for(l=n;l>=1;l--){ //矩阵维数，从最大开始
        for(i=0;i<=n-l;i++){
            for(j=0;j<=n-l;j++){
                t=1;
                for(x=i;x<i+l;x++){
                    for(y=j;y<j+l;y++){
                        if(m[x][y]!=1){    //不为1退出此轮循环
                            t=0;
                            break;
                        }
                    }
                    if(t==0) break;
                }
                if(t==1) break;
            }
            if(t==1) break;
        }
        if(t==1) break;
    }

    result[0] = i;
    result[1] = j;
    result[2] = l;

    return result;
}

int main() {

    int n;
    vector<vector <int> > m(100,vector<int>(100,0));
    cout << "Enter the number of rows for the matrix:";
    cin >> n;
    cout << "Enter the matrix row by row:" << endl;
    int numOfOne = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> m[i][j];
        }
    }
    vector<int> result =  findLargestBlock(m,n);

    cout << "横坐标：" << result[0] << " 纵坐标：" << result[1] << " 最大子方阵的行数：" << result[2] << endl;
    return 0;
}