// 扩展欧几里得求互质逆元，mod非质数
#include<iostream>
using namespace std;
typedef long long LL;
int gcd(int a, int b, int &x, int &y) {
    if (!b) {
        x = 1;
        y = 0;
        return a;
    }
    int x0, y0;
    int d = gcd(b, a % b, x0, y0);
    x = y0;
    y = x0 - a / b * y0;
}
int inv(int a, int mod) {
    int x, y;
    gcd(a, mod, x, y); // a*x=1
    return (x % mod + mod) % mod;
}
int main(){
    int a, b;
    cin >> a >> b;
    cout << inv(a, b) << "\n";
    return 0;
}
