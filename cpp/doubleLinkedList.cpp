struct Node {
    int v;
    Node *l, *r;
    Node(int v = 0) : v(v), l(nullptr), r(nullptr) {}
};
class MyLinkedList {
public:
    Node *pl, *pr;
    int sz;
    MyLinkedList() {
        sz = 0;
        pl = new Node();
        pr = new Node();
        pl->r = pr;
        pr->l = pl;
    }
    
    int get(int index) {
        if (index < 0 || index >= sz) {
            return -1;
        }
        auto cur = pl;
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
        auto cl = pl;
        for (int i = 0; i < index; i++) {
            cl = cl->r;
        }
        sz++;
        auto cr = cl->r;
        auto node = new Node(val);
        cr->l = node;
        node->r = cr;
        node->l = cl;
        cl->r = node;
    }
    
    void deleteAtIndex(int index) {
        if (index >= sz) {
            return;
        }
        auto cur = pl;
        for (int i = 0; i <= index; i++) {
            cur = cur->r;
        }
        sz--;
        cur->l->r = cur->r;
        cur->r->l = cur->l;
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
