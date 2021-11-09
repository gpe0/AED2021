#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "funSearchProblem.h"
#include <iostream>

using namespace std;
using testing::Eq;

TEST(test, facingsun){
    vector<int> v1 = {2, 3, 1, 2, 4, 1};
    EXPECT_EQ(3, FunSearchProblem::facingSun(v1));
    vector<int> v2 = {};
    EXPECT_EQ(0, FunSearchProblem::facingSun(v2));
    vector<int> v3 = {7};
    EXPECT_EQ(1, FunSearchProblem::facingSun(v3));

}

TEST(test, squareR){
    EXPECT_EQ(1, FunSearchProblem::squareR(2));
    EXPECT_EQ(2, FunSearchProblem::squareR(5));
    EXPECT_EQ(0, FunSearchProblem::squareR(0));
    EXPECT_EQ(1, FunSearchProblem::squareR(1));
    EXPECT_EQ(5, FunSearchProblem::squareR(25));
}

TEST(test, missingvalue){
    //EXPECT_EQ(2, FunSearchProblem::smallestMissingValue({-4, 1, 5, 3, 7, 9}));
    //EXPECT_EQ(0, FunSearchProblem::smallestMissingValue({-4, -2, 0, 0, 0, -5, -1}));
    //EXPECT_EQ(0, FunSearchProblem::smallestMissingValue({}));
    EXPECT_EQ(2, FunSearchProblem::smallestMissingValue({1}));
}

TEST(test, minPages){

}
