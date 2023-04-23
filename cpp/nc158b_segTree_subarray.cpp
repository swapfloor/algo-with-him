// https://ac.nowcoder.com/acm/contest/158/B
#include <bits/stdc++.h>

using namespace std;

int a[100000 + 12];

struct Info {
    int lans;
    int rans;
    int ans;
    int l;
    int r;
    Info() {}
    Info(int lans, int rans, int ans, int l, int r) : 
        lans(lans), rans(rans), ans(ans),
        l(l), r(r) {}
};

Info operator+(const Info& l, const Info& r) {
    int lans = l.lans;
    assert(l.r + 1 == r.l);
    if (l.r - l.l + 1 == lans && a[l.r] < a[r.l]) {
        lans = lans + r.lans;
    }
    int rans = r.rans;
    if (r.r - r.l + 1 == rans && a[l.r] < a[r.l]) {
        rans = rans + l.rans;
    }
    int ans = max(l.ans, r.ans);
    if (a[l.r] < a[r.l]) {
        ans = max(ans, l.rans + r.lans);
    }
    return Info(
        lans,
        rans,
        ans,
        l.l,
        r.r
    );
}

Info info[4 * 100000 + 12];

void build(int p, int l, int r) {
    if (l == r) {
        info[p] = Info(1, 1, 1, l, r);
        return;
    }
    int m = (l + r) / 2;
    build(2 * p, l, m);
    build(2 * p + 1, m + 1, r);
    info[p] = info[2 * p] + info[2 * p + 1];
}

void modify(int p, int l, int r, int x, int v) {
    if (l == r) {
        assert(l == x);
        a[x] = v;
        return;
    }
    int m = (l + r) / 2;
    if (x <= m) {
        modify(2 * p, l, m, x, v);
    } else {
        modify(2 * p + 1, m + 1, r, x, v);
    }
    info[p] = info[2 * p] + info[2 * p + 1];
}

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    
    build(1, 1, n);
    
    cout << info[1].ans << "\n";
    
    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        
        modify(1, 1, n, x, y);
        
        cout << info[1].ans << "\n";
    }
    
    return 0;
}
