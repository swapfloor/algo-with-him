// 裴蜀定理推广，求向量x 数量积另一个向量y，求最终答案ans，则ans最大值等于gcd{abs(x)}
// 根据二元方程有 gcd(x,y)|ans，则多元方程的即 gcd({x_i})|ans。
#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long LL;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int ans = 0;
    while (n--) {
        int p;
        cin >> p;
        ans = __gcd(ans, std::abs(p));
    }
    cout << ans << "\n";
    return 0;
}
