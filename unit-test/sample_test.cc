#include <doctest/doctest.h>

int fact(int n){
	if (n == 0)return 1;
	else return n*fact(n-1);
}

TEST_CASE("SampleTest")
{
	SUBCASE("FactorialTest"){
		REQUIRE(fact(5)==120);
	}
	SUBCASE("Subtraction"){
		CHECK(3-3==0);
	}
}