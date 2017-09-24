#ifndef H_ADDITION_NODE
#define H_ADDITION_NODE

#include "Node.h"
#include <stdexcept>

class Addition_Node : public Node {
public:
    Addition_Node(Node *left, Node *right);
    ~Addition_Node();
    double evaluate();

private:
    bool has_two_children();
    Node *left;
    Node *right;
};
#endif