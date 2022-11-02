#include "pch.h"

#include<iostream>
#include<array>

using namespace std;
constexpr size_t groesse = 3;

void fill_array_with_user_input(array<int, groesse>& zubefuellen) {
	for (int i = 0; i < zubefuellen.size(); ++i)
	{
		cout << "Nummer " << i << ": ";
		cin >> zubefuellen[i];
	}
}

void print_even_elements(array<int, groesse>& auszugeben) {
	for (auto element : auszugeben) {
		if (element % 2 == 0) cout << element << "\n";
	}
}

int sum_of_absolute_from_to(int from, int to) {
	if (to < from) {
		throw std::invalid_argument("to is smaller then from");
	}
	int sum = 0;
	for (int i = 0; (from + i) <= to; i++) {
		sum += abs(from + i);
	}
	return sum;
}


TEST(TestCaseName, TestNegatives) {
	EXPECT_EQ(sum_of_absolute_from_to(-2, -1), 3);
	EXPECT_EQ(sum_of_absolute_from_to(-4, -2), 9);
	EXPECT_EQ(sum_of_absolute_from_to(-4, -4), 4);
	EXPECT_THROW(sum_of_absolute_from_to(-2, -4), std::invalid_argument);
}

TEST(TestCaseName, Testgemischtes) {
	EXPECT_EQ(sum_of_absolute_from_to(-2, 2), 6);
	EXPECT_THROW(sum_of_absolute_from_to(2, -2), std::invalid_argument);
	EXPECT_EQ(sum_of_absolute_from_to(-100, 100), 10100);
}

TEST(TestCaseName, TestPositives) {
	EXPECT_EQ(sum_of_absolute_from_to(1, 2), 3);
	EXPECT_EQ(sum_of_absolute_from_to(1, 3), 6);
	EXPECT_EQ(sum_of_absolute_from_to(1, 4), 10);

	EXPECT_EQ(sum_of_absolute_from_to(5, 7), 18);
	EXPECT_EQ(sum_of_absolute_from_to(2, 3), 5);
	EXPECT_EQ(sum_of_absolute_from_to(2, 4), 9);

	EXPECT_EQ(sum_of_absolute_from_to(0, 3), 6);

	EXPECT_EQ(sum_of_absolute_from_to(4, 4), 4);

	EXPECT_ANY_THROW(sum_of_absolute_from_to(4, 2));
	EXPECT_THROW(sum_of_absolute_from_to(4, 2), std::invalid_argument);

	EXPECT_EQ(sum_of_absolute_from_to(2, 8), (sum_of_absolute_from_to(2, 5) + sum_of_absolute_from_to(6,8)));
}