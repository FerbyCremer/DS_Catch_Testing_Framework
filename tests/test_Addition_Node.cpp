#include "catch.hpp"

#include "Addition_Node.h"
#include "Numeric_Node.h"

SCENARIO( "Addition Node is constructed without two children" ) {

    GIVEN ( "A Node with only a left child" ) {
        Numeric_Node *one = new Numeric_Node(1);
        Addition_Node addNode(one, nullptr);

        WHEN ( "Evaluate is called" ) {
            
            THEN ( "Runtime exception should be thrown" ) {
                REQUIRE_THROWS_WITH (addNode.evaluate(), "AddNode::evaluate(): lacks two children");
            }
            
        }
    }

    GIVEN ( "A Node with only a right child" ) {
        Numeric_Node *one = new Numeric_Node(1);
        Addition_Node addNode(nullptr, one);

        WHEN ( "Evaluate is called" ) {
            
            THEN ( "Runtime exception should be thrown" ) {
                REQUIRE_THROWS_WITH (addNode.evaluate(), "AddNode::evaluate(): lacks two children");
            }
            
        }
    }
}

SCENARIO ( "Addition Node is constructed with two children" ) {
    
    Numeric_Node *one;
    Numeric_Node *two;

    GIVEN ( "Two positive children" ) {
        one = new Numeric_Node(1);
        two = new Numeric_Node(2);
        Addition_Node addNode(one, two);

        WHEN ( "Evaluate is called" ) {
            double result = addNode.evaluate();

            THEN ( "It should succeed with a correct result" ) {
                REQUIRE (result == 3);
            } 
        }
    }

    GIVEN ( "Two negative children" ) {
        one = new Numeric_Node(-1);
        two = new Numeric_Node(-5);
        
        Addition_Node addNode(one, two);
        WHEN ( "Evaluate is called" ) {
            double result = addNode.evaluate();

            THEN ( "It should return the correct result" ) {
                REQUIRE (result == -6);
            }
        }
    }

    GIVEN ( "Children with a zero value" ) {
        one = new Numeric_Node(0);
        two = new Numeric_Node(0);

        Addition_Node addNode(one, two);

        WHEN ( "Evaluate is called" ) {
            double result = addNode.evaluate();

            THEN ( "It should return the correct result" ) {
                REQUIRE (result == 0);
            }
        }
    }

    GIVEN ( "A negative and positive child" ) {
        one = new Numeric_Node(-5);
        two = new Numeric_Node(5);

        Addition_Node addNode(one, two);

        WHEN ( "Evaluate is called" ) {
            double result = addNode.evaluate();

            THEN ( "It should return the correct result" ) {
                REQUIRE (result == 0);
            }
        }
    }
}