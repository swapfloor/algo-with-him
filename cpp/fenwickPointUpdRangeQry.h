namespace treetree{
template<class T>
struct Fenwick {
    int n;
    std::vector<int> a;
    Fenwick(int n) : n(n), a(n + 1) {}
    void add(int p, T v) { // add(pos, val)
        assert(1 <= p && p <= n);
        while (p <= n) {
            a[p] += v;
            p += p & -p;
        }
    }
    T query(int p) { // sum[1,...,p]
        assert(0 <= p && p <= n);
        T ans = 0;
        while (p > 0) {
            ans += a[p];
            p -= p & -p;
        }
        return ans;
    }
    T rangeQuery(int l, int r) {
        return query(r) - query(l - 1);
    }
};
}
