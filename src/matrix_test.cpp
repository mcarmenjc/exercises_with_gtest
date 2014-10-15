#include "../include/matrix.h"
#include "gtest/gtest.h"
#include <iostream>

TEST(MatrixTest, TwoMatrixAreCorrectlySummed)
{
	Matrix first_matrix(5, 5);
	Matrix second_matrix(5, 5);
	for (int i = 0; i < 5; i++){
		for (int j = 0; j < 5; j++){
			first_matrix.set_at(i, j, 1);
			second_matrix.set_at(i, j, 1);
		}
	}
	Matrix sum_result = first_matrix.sum(second_matrix);
	for (int i = 0; i < 5; i++){
		for (int j = 0; j < 5; j++){
			ASSERT_EQ(2, sum_result.get_at(i, j));
		}
	}
}

TEST(MatrixTest, TwoMatrixAreCorrectlySubstracted)
{
	Matrix first_matrix(5, 5);
	Matrix second_matrix(5, 5);
	for (int i = 0; i < 5; i++){
		for (int j = 0; j < 5; j++){
			first_matrix.set_at(i, j, 1);
			second_matrix.set_at(i, j, 1);
		}
	}
	Matrix sum_result = first_matrix.substract(second_matrix);
	for (int i = 0; i < 5; i++){
		for (int j = 0; j < 5; j++){
			ASSERT_EQ(0, sum_result.get_at(i, j));
		}
	}
}

/*TEST(MatrixTest, TwoMatrixAreCorrectlyMultiplied)
{
	Matrix first_matrix(5, 5);
	Matrix second_matrix(5, 5);
	for (int i = 0; i < 5; i++){
		for (int j = 0; j < 5; j++){
			first_matrix.set_at(i, j, 1);
			second_matrix.set_at(i, j, 1);
		}
	}
	Matrix sum_result = first_matrix.substract(second_matrix);
	for (int i = 0; i < 5; i++){
		for (int j = 0; j < 5; j++){
			ASSERT_EQ(0, sum_result.get_at(i, j));
		}
	}
}*/

TEST(MatrixTest, MongeMatrixIsCorrectlyDetected)
{
	Matrix monge_matrix(7, 5);
	monge_matrix.set_at(0, 0, 10);
	monge_matrix.set_at(0, 1, 17);
	monge_matrix.set_at(0, 2, 13);
	monge_matrix.set_at(0, 3, 28);
	monge_matrix.set_at(0, 4, 23);

	monge_matrix.set_at(1, 0, 17);
	monge_matrix.set_at(1, 1, 22);
	monge_matrix.set_at(1, 2, 16);
	monge_matrix.set_at(1, 3, 29);
	monge_matrix.set_at(1, 4, 23);

	monge_matrix.set_at(2, 0, 24);
	monge_matrix.set_at(2, 1, 28);
	monge_matrix.set_at(2, 2, 22);
	monge_matrix.set_at(2, 3, 34);
	monge_matrix.set_at(2, 4, 24);

	monge_matrix.set_at(3, 0, 11);
	monge_matrix.set_at(3, 1, 13);
	monge_matrix.set_at(3, 2, 6);
	monge_matrix.set_at(3, 3, 17);
	monge_matrix.set_at(3, 4, 7);

	monge_matrix.set_at(4, 0, 45);
	monge_matrix.set_at(4, 1, 44);
	monge_matrix.set_at(4, 2, 32);
	monge_matrix.set_at(4, 3, 37);
	monge_matrix.set_at(4, 4, 23);

	monge_matrix.set_at(5, 0, 36);
	monge_matrix.set_at(5, 1, 33);
	monge_matrix.set_at(5, 2, 19);
	monge_matrix.set_at(5, 3, 21);
	monge_matrix.set_at(5, 4, 6);

	monge_matrix.set_at(6, 0, 75);
	monge_matrix.set_at(6, 1, 66);
	monge_matrix.set_at(6, 2, 51);
	monge_matrix.set_at(6, 3, 53);
	monge_matrix.set_at(6, 4, 34);

	ASSERT_TRUE(monge_matrix.is_monge_array());
}

TEST(MatrixTest, NormalMatrixShouldNotBeDetectedAsMongeMatrix)
{
	Matrix monge_matrix(5, 4);
	monge_matrix.set_at(0, 0, 37);
	monge_matrix.set_at(0, 1, 23);
	monge_matrix.set_at(0, 2, 22);
	monge_matrix.set_at(0, 3, 32);

	monge_matrix.set_at(1, 0, 21);
	monge_matrix.set_at(1, 1, 6);
	monge_matrix.set_at(1, 2, 7);
	monge_matrix.set_at(1, 3, 10);

	monge_matrix.set_at(2, 0, 53);
	monge_matrix.set_at(2, 1, 34);
	monge_matrix.set_at(2, 2, 30);
	monge_matrix.set_at(2, 3, 31);

	monge_matrix.set_at(3, 0, 32);
	monge_matrix.set_at(3, 1, 13);
	monge_matrix.set_at(3, 2, 9);
	monge_matrix.set_at(3, 3, 6);

	monge_matrix.set_at(4, 0, 43);
	monge_matrix.set_at(4, 1, 21);
	monge_matrix.set_at(4, 2, 15);
	monge_matrix.set_at(4, 3, 8);

	ASSERT_FALSE(monge_matrix.is_monge_array());
}