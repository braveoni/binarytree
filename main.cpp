#include <iostream>

using namespace std;

class Node {
public:
    Node(Node* parent, int data) {
        this->left = nullptr;
        this->right = nullptr;
        this->parent = parent;
        this->data = data;
    }

    Node* get_left() {
        return this->left;
    }

    Node* get_right() {
        return this->right;
    }

    Node* get_parent() {
        return this->parent;
    }

    int get_data() {
        return this->data;
    }

    void set_right(Node* node) {
        this->right = node;
    }

    void set_left(Node* node) {
        this->left = node;
    }

    void set_parent(Node* parent) {
        this->parent = parent;
    }

    void remove() {
        this->left->parent = this->right;
        this->right->parent = this->parent;
        delete(this);
    }

private:
    Node* parent;
    Node* left;
    Node* right;
    int data;
};

class Tree {
public:
    Tree(int data) {
        this->root = new Node(nullptr, data);
    }

    Node* find(int data) {
        Node* p = root;

        while (p->get_data() < data && p->get_right() != nullptr) {
            p = p->get_right();
        }

        while (p->get_data() > data && p->get_left() != nullptr) {
            p = p->get_left();
        }

        return p;
    }

    void insert(int data) {
        Node* p = find(data);
        Node* node = new Node(p, data);

        if (p->get_data() > data) p->set_left(node);
        else p->set_right(node);
    }

    // Swap node to remove to max node from left / min node from right
    // If left/right node doesn't exist, check opposite. If only root, then delete.

    void remove(int data) {
    }

    void print() {
        inOrder(this->root);
    }

private:
    Node* root;

    void inOrder(Node* node) {
        if (node) {
            inOrder(node->get_left());
            cout << node->get_data() << ' ';
            inOrder(node->get_right());
        }
    }

    void preOrder(Node* node) {
        if (node) {
            cout << node->get_data() << ' ';
            inOrder(node->get_left());
            inOrder(node->get_right());
        }
    }

    void postOrder(Node* node) {
        if (node) {
            inOrder(node->get_left());
            inOrder(node->get_right());
            cout << node->get_data() << ' ';
        }
    }
};

int main() {
    Tree t = *new Tree(5);
    t.insert(3);
    t.insert(8);
    t.insert(1);
    t.insert(4);
    t.insert(7);
    t.insert(9);

//    t.print();

    t.remove(5);

    t.print();

    return 0;
}
