#include <iostream>
using namespace std;
int *dp(int n, int *v, int *k, int m) {
    int i, j, o;
    int *result = new int[2];
    int **d = new int *[n + 1];
    for (i = 1; i <= n; i++) {
        d[i] = new int[m + 1];
        for (j = 0; j <= m; j++) {
            d[i][j] = 0;
        }
    }
    for (i = 1; i <= n; i++) {
        for (j = 0; j <= m; j++) {
            if (j == 0){
                d[i][j] = 1;
            }else if(i == 1){
                    if(j % v[i] == 0 && j / v[i] <= k[i]) {
                        d[i][j] = 1;
                    }else{
                        d[i][j] = 0;
                    }
            } else if (i > 1) {
                d[i][j] = 0;
                d[i][j] += d[i - 1][j];
                for (o = 1; o <= k[i]; o++) {
                    if (o * v[i] <= j) {
                        d[i][j] += d[i - 1][j - o * v[i]];
                    }else{
                        break;
                    }
                }
            }
        }
    }
    result[0] = d[n][m];
    int **c = new int *[n + 1];
    for (i = 1; i <= n; i++) {
        c[i] = new int[m + 1];
    }
    long long t = 1000000;
    for (i = 1; i <= n; i++){
        for (j = 0; j <= m; j++){
            if (j == 0){
                c[i][j] = 0;
            }else if(i == 1){
                if (j % v[i] == 0 && j/v[i] <= k[i]){
                    c[i][j] = (int)j/v[i];
                }
                if(j % v[i] != 0 || j/v[i] > k[i]){
                    c[i][j] = 1000000;
                }
            }else if(i > 1){
                t = (int)(j/v[i])> k[i]?k[i]:(int)(j/v[i]);
                for (o = 0; o <= t; o++){
                    if (o == 0){
                        c[i][j] = o+c[i-1][j-o*v[i]];
                    }
                    if (j-o*v[i]>=0) {
                        c[i][j] = (o + c[i - 1][j - o * v[i]]) > c[i][j] ? c[i][j] : (o + c[i - 1][j - o * v[i]]);
                    }
                }
            }
        }
    }
    result[1] = c[n][m];
    return result;
}
int main() {
    int i;
    int n, m;
    int *result;
    cin >> n;
    int *v = new int[n + 1];
    int *k = new int[n + 1];
    for (i = 1; i <= n; i++) {
        cin >> v[i];
    }
    for (i = 1; i <= n; i++) {
        cin >> k[i];
    }
    cin >> m;
    result = dp(n, v, k, m);
    if (result[1] == 1000000){
        cout << result[0] << endl << "no possible" << endl;
    }else{
        cout << result[0] << endl << result[1] << endl;
    }
    return 0;
}