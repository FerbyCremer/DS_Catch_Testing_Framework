#include "Numeric_Node.h"

Numeric_Node::Numeric_Node(double val) 
: val(val) {}

Numeric_Node::~Numeric_Node() {

}

double Numeric_Node::evaluate() {
    return this->val;
}