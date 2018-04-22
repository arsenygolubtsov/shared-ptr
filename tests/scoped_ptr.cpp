#include <catch.hpp>
#include <sstream>

#include "scoped_ptr.hpp"

TEST_CASE("num1"){
	scoped_ptr <int> ptr1;
	ptr1.reset(new int(3));
	int *ptr_1 = ptr1.get();
	
	scoped_ptr <int> ptr2;
	ptr1.reset(new int(6));
	int ptr_2 = *ptr2;
	
	REQUIRE(*ptr_1 == 3);
	REQUIRE(ptr_2 == 6);
}

TEST_CASE("num2"){
	scoped_ptr <int> ptr1;
	ptr1.reset(new int(3));
	
	scoped_ptr <int> ptr2;
	ptr1.reset(new int(6));
	
	ptr1.swap(ptr2);
	
	int *ptr_1 = ptr1.get();
	int ptr_2 = *ptr2;
	
	REQUIRE(*ptr_1 == 6);
	REQUIRE(ptr_2 == 3);	
}
