// 切比雪夫定理：n < p < 2n, p is prime
// 如果k+1为prime，且没有k+1的倍数（大于或者等于2倍），需要一天，有倍数需要两天，如果不为prime需要两天。
#include<iostream>
using namespace std;
typedef long long LL;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    LL n, k;
    cin >> n >> k;
    k++;
    bool prime = true;
    for (LL i = 2; i * i <= k; i++) {
        if (k % i == 0) {
            prime = false;
            break;
        }
    }
    if (prime) {
        if ((n + 1) / k >= 2) {
            cout << 2 << "\n";
        } else {
            cout << 1 << "\n";
        }
    } else {
        cout << 2 << "\n";
    }
    return 0;
}
