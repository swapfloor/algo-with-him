// https://leetcode.cn/problems/design-front-middle-back-queue
class FrontMiddleBackQueue {
private:
    vector<int> que;
public:
    FrontMiddleBackQueue() {

    }
    
    void pushFront(int val) {
        que.insert(que.begin(), val);
    }
    
    void pushMiddle(int val) {
        que.insert(que.begin() + (que.size() / 2), val);
    }
    
    void pushBack(int val) {
        que.push_back(val);
    }
    
    int popFront() {
        if (que.empty()) return -1;
        int ans = *que.begin();
        que.erase(que.begin());
        return ans;
    }
    
    int popMiddle() {
        if (que.empty()) return -1;
        int ans = *(que.begin() + (que.size() - 1) / 2);
        que.erase(que.begin() + (que.size() - 1) / 2);
        return ans;
    }
    
    int popBack() {
        if (que.empty()) return -1;
        int ans = que.back();
        que.pop_back();
        return ans;
    }
};

/**
 * Your FrontMiddleBackQueue object will be instantiated and called as such:
 * FrontMiddleBackQueue* obj = new FrontMiddleBackQueue();
 * obj->pushFront(val);
 * obj->pushMiddle(val);
 * obj->pushBack(val);
 * int param_4 = obj->popFront();
 * int param_5 = obj->popMiddle();
 * int param_6 = obj->popBack();
 */
