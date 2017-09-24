#include "Addition_Node.h"

Addition_Node::Addition_Node(Node *left, Node *right) 
: left(left), right(right) {}

Addition_Node::~Addition_Node() {
    delete this->left;
    delete this->right;
}

double Addition_Node::evaluate() {
    if (!has_two_children()) {
        throw std::runtime_error("AddNode::evaluate(): lacks two children");
    }
    double left_value = this->left->evaluate();
    double right_value = this->right->evaluate();

    return left_value + right_value;
}

bool Addition_Node::has_two_children() {
    return (this->left != nullptr && this->right != nullptr);
}