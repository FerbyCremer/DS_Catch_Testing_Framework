#include "catch.hpp"

#include "Division_Node.h"
#include "Addition_Node.h"
#include "Numeric_Node.h"

// SCENARIO ( "" ) {
    
//     GIVEN ( "" ) {
        
//         WHEN ( "" ) {
            
//             THEN ( "" ) {

//             }
//         }
//     }
// }

SCENARIO ( "A Division Node is created without two children" ) {
    
    Numeric_Node *left;
    Numeric_Node *right;

    GIVEN ( "A nullptr left child" ) {
        right = new Numeric_Node(1);
        Division_Node div_node(nullptr, right);

        WHEN ( "Evaluate is called" ) {
            
            THEN ( "Runtime exception should be thrown" ) {
                REQUIRE_THROWS_WITH (div_node.evaluate(), "DivisionNode::evaluate(): lacks two children");        
            }
        }
    }

    GIVEN ( "A nullptr right child" ) {
        left = new Numeric_Node(1);
        Division_Node div_node(left, nullptr);

        WHEN ( "Evaluate is called" ) {
            
            THEN ( "Runtime exception should be thrown" ) {
                REQUIRE_THROWS_WITH (div_node.evaluate(), "DivisionNode::evaluate(): lacks two children");        
            }
        }
    }

    GIVEN ( "Both children are nullptr's") {
        Division_Node div_node(nullptr, nullptr);

        WHEN ( "Evaluate is called" ) {

            THEN ( "Runtime exception should be thrown" ) {
                REQUIRE_THROWS_WITH(div_node.evaluate(), "DivisionNode::evaluate(): lacks two children");
            }
        }
    }
}

SCENARIO ( "A division node is created with two children" ) {
    
    Numeric_Node *left;
    Numeric_Node *right;

    GIVEN ( "Two numeric nodes" ) {
        
        WHEN ( "Both children are positive" ) {
            left = new Numeric_Node(6);
            right = new Numeric_Node(2);
            Division_Node div_node(left, right);

            THEN ( "The result is the correct positive value" ) {
                double result = div_node.evaluate();
                REQUIRE (result == 3);    
            }
        }

        WHEN ( "The both children are positive and not evenly divided" ) {
            left = new Numeric_Node(5);
            right = new Numeric_Node(2);
            Division_Node div_node(left, right);

            THEN ( "The result is the correct double value") {
                double result = div_node.evaluate();
                REQUIRE (result == 5.0/2.0);
            }
        }

        WHEN ( "Left child is zero and right child is positive" ) {
            left = new Numeric_Node(0);
            right = new Numeric_Node(7);
            Division_Node div_node(left, right);
            
            THEN ( "The result is zero" ) {
                double result = div_node.evaluate();
                REQUIRE (result == 0);
            }
        }

        WHEN ( "Left child is zero and right child is negative" ) {
            left = new Numeric_Node(0);
            right = new Numeric_Node(-7);
            Division_Node div_node(left, right);
            
            THEN ( "The result is zero" ) {
                double result = div_node.evaluate();
                REQUIRE (result == 0);
            }
        }

        // if (right_value == 0) {
        //     throw std::runtime_error("DivisionNode::evaluate(): cannot divide by zero");
        // }
        WHEN ( "Right child is zero" ) {
            left = new Numeric_Node(10);
            right = new Numeric_Node(0);
            Division_Node div_node(left, right);
            
            THEN ( "The result is zero" ) {
                REQUIRE_THROWS_WITH (div_node.evaluate(), "DivisionNode::evaluate(): cannot divide by zero"); 
            }
        }
    }

    GIVEN ( "Non-numeric node children" ) {

        Node *left;
        Node *right;

        WHEN ("Left and right children are addition nodes") {
            Numeric_Node *one = new Numeric_Node(1);
            Numeric_Node *two = new Numeric_Node(2);
            Addition_Node *add_node_one = new Addition_Node(one, two);

            Numeric_Node *three = new Numeric_Node(3);
            Numeric_Node *four = new Numeric_Node(4);
            Addition_Node *add_node_two = new Addition_Node(three, four);

            Division_Node div_node(add_node_one, add_node_two);

            THEN ( "The result is the result of left divided by right" ) {
                double result = div_node.evaluate();
                REQUIRE(result == Approx(3.0/7.0));
            }
        }
    }
}
