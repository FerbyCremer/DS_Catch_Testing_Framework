#ifndef H_NUMERIC_NODE
#define H_NUMERIC_NODE

#include "Node.h"

class Numeric_Node : public Node {
public:
    Numeric_Node(double val);
    ~Numeric_Node();
    double evaluate();

private:
    double val;
};
#endif