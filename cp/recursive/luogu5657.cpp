// 每次选l和r，然后记得翻转，去位k-(mid+1)，然后翻转mid-( k-(mid+1) )
#include<iostream>
using namespace std;
typedef long long LL;
#define ull unsigned long long
void dfs(ull l, ull r, ull k) {
    if (l == r) return;
    ull mid = (l + r) / 2;
//    cout << l << " " << mid << " " << r << "\n";
    if (k <= mid) {
        cout << "0";
        dfs(l, mid, k);
    } else {
        cout << "1";
        dfs(l, mid, mid - (k - (mid + 1))); 
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    ull k;
    cin >> n >> k;
    dfs(0, n == 64 ? -1 : (1ull << n) - 1, k);
    return 0;
}
