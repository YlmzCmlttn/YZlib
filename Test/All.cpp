#define TEST_ALL
#ifdef TEST_ALL
#define TEST_CORE
#define TEST_LINEAR_ALGEBRA
#endif

#ifdef TEST_CORE
#endif

#ifdef TEST_LINEAR_ALGEBRA
#define TEST_MATRIX
#endif

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "Helper.hpp"

#ifdef TEST_MATRIX
//#include "YZlib_Test/Matrix_Test.hpp"
#endif
int main(int argc, char **argv){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}