// 最大生成树
#include<bits/stdc++.h>
using namespace std;
struct E {
    int u, v;
    long long c;
};
struct UF {
    vector<int> ds, sz;
    UF(int n) : ds(n), sz(n) {
        iota(ds.begin(), ds.end(), 0);
    }
    int find(int x) {
        return x == ds[x] ? x : ds[x] = find(ds[x]);
    }
    void merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) return;
        sz[x] += sz[y];
        ds[y] = x;
    }
    int scale(int x) {
        return sz[find(x)];
    }
    bool same(int x, int y) {
        return find(x) == find(y);
    }
};
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    UF uf(n);
    for (int i = 0; i < k; i++) {
        int d;
        cin >> d;
        uf.sz[d] = 1;
    }
    vector<E> es(n);
    for (int i = 0; i < n - 1; i++) {
        cin >> es[i].u >> es[i].v >> es[i].c;
    }
    sort(es.begin(), es.end(), [&](const E& L, const E& R){
        return L.c > R.c; 
    });
    long long ans = 0;
    for (int i = 0; i < n - 1; i++) {
        int u = es[i].u, v = es[i].v;
        long long c = es[i].c;
        if (uf.scale(u) + uf.scale(v) < 2) {
            uf.merge(u, v);
        } else {
            ans += c;
        }
    }
    cout << ans << "\n";
    return 0;
}
