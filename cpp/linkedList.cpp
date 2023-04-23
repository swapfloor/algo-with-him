struct Node {
    int v;
    Node *r;
    Node(int v = 0) : v(v), r(nullptr) {}
};
class MyLinkedList {
public:
    Node *root;
    int sz;
    MyLinkedList() {
        sz = 0;
        root = new Node();
    }
    
    int get(int index) {
        if (index >= sz) {
            return -1;
        }
        auto cur = root;
        for (int i = 0; i <= index; i++) {
            cur = cur->r;
        }
        return cur->v;
    }
    
    void addAtHead(int val) {
        addAtIndex(0, val);
    }
    
    void addAtTail(int val) {
        addAtIndex(sz, val);
    }
    
    void addAtIndex(int index, int val) {
        if (index > sz) {
            return;
        }
        auto cl = root;
        for (int i = 0; i < index; i++) {
            cl = cl->r;
        }
        sz++;
        auto node = new Node(val);
        node->r = cl->r;
        cl->r = node;
    }
    
    void deleteAtIndex(int index) {
        if (index >= sz) {
            return;
        }
        auto cur = root;
        for (int i = 0; i < index; i++) {
            cur = cur->r;
        }
        sz--;
        cur->r = cur->r->r;
    }

    void tour() {
        auto cur = root;
        for (int i = 0; i < sz; i++) {
            cur = cur->r;
            cout << cur->v << " ";
        }
        cout << "\n";
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
