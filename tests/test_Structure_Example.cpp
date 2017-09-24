#include "catch.hpp"

/// scenario is executed from the start for each given/when/then
SCENARIO ( "vectors can be sized and resized" ) {
    
    GIVEN ( "A vector with some items" ) {
        std::vector<int> v(5);

        REQUIRE (v.size() == 5);
        REQUIRE (v.capacity() >= 5);

        WHEN ( "the size is increased" ) {
            v.resize(10);

            THEN ( "the size and capacity are increased" ) {
                REQUIRE (v.size() == 10);
                REQUIRE (v.capacity() >= 10);
            }
        }

        WHEN( "the size is reduced" ) {
            v.resize( 0 );
            
            THEN( "the size changes but not capacity" ) {
                REQUIRE( v.size() == 0 );
                REQUIRE( v.capacity() >= 5 );
            }
        }
    }
}
    
// test case is executed from the start for each section
TEST_CASE ( "vectors can be sized and resized" ) {
    std::vector<int> v(5);

    REQUIRE (v.size() == 5);
    REQUIRE (v.capacity() >= 5);

    SECTION ( "resizing bigger changes size and capacity" ) {
        v.resize(10);

        REQUIRE(v.size() == 10);
        REQUIRE(v.capacity() >= 10);
    }

    SECTION ( "resizing smaller changes the size but not the capacity" ) {
        v.resize(0);

        REQUIRE(v.size() == 0);
        REQUIRE(v.capacity() >= 5);
    }
}