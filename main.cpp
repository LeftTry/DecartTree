#include <iostream>

class node{
public:
    int key = 0;
    int p = 0;
    node* l = nullptr;
    node* r = nullptr;
    node();
    node(int key);
    node(int key, int p, node* l, node* r);
};

node::node() {
    key = 0;
    p = 0;
    l = nullptr;
    r = nullptr;
}

node::node(int key_) {
    key = key_;
    p = 0;
    l = nullptr;
    r = nullptr;
}

node::node(int key_, int p_, node *l_, node *r_) {
    key = key_;
    p = p_;
    l = l_;
    r = r_;
}

node* merge(node* l, node* r){
    if(l == nullptr) return r;
    if(r == nullptr) return l;
    node* ans;
    if(l->p > r->p){
        node* Node = merge(l->r, r);
        ans = new node(l->key, l->p, l->l, Node);
    }
    else{
        node* Node = merge(l, r->l);
        ans = new node(r->key, r->p, Node, r->r);
    }
    return ans;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
