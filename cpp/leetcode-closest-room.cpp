// https://leetcode.cn/problems/closest-room
// 离线算法
// 排序+二分
struct Event {
    int type;
    int size;
    int id;
    int origin;
    Event(
        int type,
        int size,
        int id,
        int origin)
            : type(type),
              size(size),
              id(id),
              origin(origin) {}
    bool operator < (const Event& o) const {
        return size != o.size ? size > o.size : type < o.type;
    }
};
class Solution {
public:
    vector<int> closestRoom(vector<vector<int>>& rooms, vector<vector<int>>& queries) {
        int m = rooms.size();
        int n = queries.size();
        vector<Event> events;
        for (int i = 0; i < m; i++) {
            events.emplace_back(0, rooms[i][1], rooms[i][0], i);
        }
        for (int i = 0; i < n; i++) {
            events.emplace_back(1, queries[i][1], queries[i][0], i);
        }
        sort(events.begin(), events.end());
        vector<int> ans(n, -1);
        set<int> valid;
        for (const auto& event : events) {
            if (event.type == 0) {
                valid.insert(event.id);
            } else {
                int dist = INT_MAX;
                auto it = valid.lower_bound(event.id);
                if (it != valid.end() && *it - event.id < dist) {
                    dist = *it - event.id;
                    ans[event.origin] = *it;
                }
                if (it != valid.begin()) {
                    it = prev(it);
                    if (event.id - *it <= dist) {
                        ans[event.origin] = *it;
                    }
                }
            }
        }
        return ans;
    }
};
