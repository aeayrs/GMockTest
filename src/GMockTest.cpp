//============================================================================
// Name        : GMockTest.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <gtest/gtest.h>
#include <gmock/gmock.h>
using namespace std;

TEST(GMockTests, CanAssertTest) {
	ASSERT_TRUE(true);
	ASSERT_FALSE(false);
}
