namespace treetree{
template<class T>
struct Discretization {
    int n;
    std::vector<int> a;
    Discretization(const std::vector<T>& b) {
        a = b;
        sort(a.begin(), a.end());
        a.erase(unique(a.begin(), a.end()), a.end());
        n = a.size();
    }
    int operator[](T v) {
        auto it = std::lower_bound(a.begin(), a.end(), v);
        assert(it != a.end() && *it == v);
        return it - a.begin(); // return pos [0, n)
    }
    int size() const { return n; }
};
}
