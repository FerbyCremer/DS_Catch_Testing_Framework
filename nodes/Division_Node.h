#ifndef H_DIVISION_NODE
#define H_DIVISION_NODE

#include "Node.h"
#include <stdexcept>

class Division_Node : public Node {
public:
    Division_Node(Node *left, Node *right);
    ~Division_Node();
    double evaluate();

private:
    bool has_two_children();
    Node *left;
    Node *right;
};
#endif