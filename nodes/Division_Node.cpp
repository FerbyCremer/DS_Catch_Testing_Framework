#include "Division_Node.h"

Division_Node::Division_Node(Node *left, Node *right) 
: left(left), right(right) {}

Division_Node::~Division_Node() {
    delete this->left;
    delete this->right;
}

double Division_Node::evaluate() {
    if (!has_two_children()) {
        throw std::runtime_error("DivisionNode::evaluate(): lacks two children");
    }
    double left_value = this->left->evaluate();
    double right_value = this->right->evaluate();

    return left_value / right_value;
}

bool Division_Node::has_two_children() {
    return (this->left != nullptr && this->right != nullptr);
}