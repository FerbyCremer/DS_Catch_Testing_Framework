#ifndef H_NODE
#define H_NODE

class Node {
public:
    virtual ~Node() = 0;
    virtual double evaluate() = 0;
};

inline Node::~Node() {};
#endif