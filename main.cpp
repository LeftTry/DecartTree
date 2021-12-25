#include <iostream>
#include "random"
#include "vector"

using namespace std;

class node{
public:
    int key = 0;
    int p = 0;
    node* l = nullptr;
    node* r = nullptr;
    node();
    node(int key);
    node(int key, int p);
    node(int key, int p, node* l, node* r);
    void split(int x, node* l, node* r);
    node* add(int x);
    node* build(vector<int>& v, vector<int>& y);
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

void node::split(int x, node* l, node* r){
    node* tree = nullptr;
    if(this->key <= x){
        if(this->r == nullptr) r = nullptr;
        else this->r->split(x,tree, r);
        l = new node(this->key, p, this->l, tree);
    }
    else{
        if(this->l == nullptr) l = nullptr;
        else this->l->split(x, l, tree);
        r = new node(this->key, p, tree, this->r);
    }
}

node* node::add(int x){
    node* l;
    node* r;
    this->split(x, l, r);
    srand(time(0));
    node* m = new node(x, rand() % 10);
    return merge(merge(l, m), r);
}

node::node(int key_, int p_) {
    key = key_;
    p = p_;
    l = nullptr;
    r = nullptr;
}

node *node::build(vector<int> &v, vector<int> &y) {
    node* tree = new node(v[0], y[0]);
    auto last = tree;
    for(int i = 1;i < v.size();i++)
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
