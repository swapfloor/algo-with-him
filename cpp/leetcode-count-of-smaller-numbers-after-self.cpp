/*-----------逆序对求答案模板---------*/
// https://leetcode.cn/problems/count-of-smaller-numbers-after-self
using i64 = long long;
namespace treetree{
    /*
 * 统计右侧小于当前元素的个数，
 * 统计逆序对，
 * 或者统计满足区间个数，
 * T 元素类型，
 * f(T a, T al) a 指左半区间元素，设满足条件为 l，则 al = a[l - 1]
 * g(T a, T ar) a 指左半区间元素，设满足条件为 r，则 ar = a[r]
 * 如果是求逆序对，
 * 则令 f(T a, T al) { return a <= al; }
 * g(T a, T ar) { return a > ar; }
 * 如果是统计元素差在一定范围内 [lower, upper]，
 * 则令 f(T a, T al) { return (al - a) < lower; }
 * g(T a, T ar) { return (ar - a) <= upper; }
 * R 统计类型，一般是 long long
 * rev 从大到小 if rev=true, 从小到大 else
 * rev 默认从小到大
 * */
    template<class T, bool (*g)(T, T), class R = long long, bool rev = false>
    void mergeSort(vector<T>& a, vector<int>& idx, vector<R>& cnt,
                  int left, int right){
        if (left + 1 >= right) {
            return;
        }
        int mid = left + (right - left) / 2;
        mergeSort<T,g,R,rev>(a, idx, cnt, left, mid);
        mergeSort<T,g,R,rev>(a, idx, cnt, mid, right);
        int i = left, l = mid, r = mid;
        // 求逆序对啊，什么的，
        // 假设我们已经分别求出了左右两侧的 pair(i, j)，
        // 这是 i in [left, mid) j in [mid, right),
        // l r 指右侧的合法指针，将 [l, r) 累计到答案中。
        while (i < mid) {
            if (l == right) break;
            if (!g(a[i], a[l])) {
                i++;
                continue;
            }
            while (r < right && g(a[i], a[r])) r++;
            cnt[idx[i]] += r - l;
            i++;
        }
        // 合并
        vector<T> tmp(right - left);
        vector<int> tmpIdx(right - left);
        int j = left, k = mid, p = 0;
        while (j < mid || k < right) {
            if (j == mid) tmpIdx[p] = idx[k], tmp[p++] = a[k++];
            else if (k == right) tmpIdx[p] = idx[j], tmp[p++] = a[j++];
            else if ((a[j] < a[k]) ^ int(rev)) tmpIdx[p] = idx[j], tmp[p++] = a[j++];
            else tmpIdx[p] = idx[k], tmp[p++] = a[k++];
        }
        for (int u = left, v = 0; u < right; u++, v++) {
            a[u] = tmp[v];
            idx[u] = tmpIdx[v];
        }
    }
};
bool g(int l,int r) { return i64(l) > i64(r); }
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int>idx(nums.size());
        iota(idx.begin(),idx.end(),0);
        vector<int>cnt(nums.size());
        treetree::mergeSort<
            int,
            g,
            int
            >(nums,idx,cnt,0,int(nums.size()));
        return cnt;
    }
};


/*----------离散化树状数组模板-----------*/
using i64 = long long;
namespace treetree{
template<class T>
struct Discretization {
    int n;
    std::vector<int> a;
    Discretization(std::vector<T>& b) {
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
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        treetree::Discretization idx(nums);
        treetree::Fenwick<int> tr(idx.size());
        int n = nums.size();
        vector<int> ans(n);
        for (int i = n - 1; i >= 0; i--) {
            int p = idx[nums[i]] + 1;
            ans[i] = tr.query(p - 1);
            tr.add(p, 1);
        }
        return ans;
    }
};
