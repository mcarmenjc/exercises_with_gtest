#include "../include/matrix.h"
#include <new>
#include <iostream>

Matrix::Matrix(int num_rows, int num_cols){
	if (num_rows * num_cols > 0){
		rows = num_rows;
		columns = num_cols;
		data = new (std::nothrow) int*[rows];
		for (int i = 0; i < rows; i++){
			data[i] = new (std::nothrow) int[columns];
		}
	}
}

Matrix::Matrix(const Matrix &matrix){
	rows = matrix.rows;
	columns = matrix.columns;
	data = new (std::nothrow) int*[rows];
	for (int i = 0; i < rows; i++){
		data[i] = new (std::nothrow) int[columns];
	}
	for (int i = 0; i < rows; i++){
		for (int j = 0; j < columns; j++){
			data[i][j] = matrix.data[i][j];
		}
	}
}

Matrix::~Matrix(){
	for (int i = 0; i < rows; i++){
		delete [] data[i];
	}
	delete [] data;
}

void Matrix::set_at(int row_pos, int col_pos, int value){
	if (row_pos >= 0 && row_pos < rows && col_pos >= 0 && col_pos < columns){
		data[row_pos][col_pos] = value;
	}
}

int Matrix::get_at(int row_pos, int col_pos){
	return data[row_pos][col_pos];
}

int Matrix::get_rows(){
	return rows;
}

int Matrix::get_columns(){
	return columns;
}

Matrix Matrix::sum(const Matrix &matrix){
	Matrix sum_result(rows, columns);
	for (int i = 0; i < rows; i++){
		for (int j = 0; j < columns; j++){
			sum_result.data[i][j] = data[i][j] + matrix.data[i][j];
		}
	}

	return sum_result;
}

Matrix Matrix::substract(const Matrix &matrix){
	Matrix sum_result(rows, columns);
	for (int i = 0; i < rows; i++){
		for (int j = 0; j < columns; j++){
			sum_result.data[i][j] = data[i][j] - matrix.data[i][j];
		}
	}

	return sum_result;
}

Matrix Matrix::product(const Matrix &matrix){
	Matrix C (rows, columns);
	if (rows == 2 && columns == 2){
		C.data[0][0] = data[0][0]*matrix.data[0][0] + data[0][1]*matrix.data[1][0];
		C.data[0][1] = data[0][0]*matrix.data[0][1] + data[0][1]*matrix.data[1][1];
		C.data[1][0] = data[1][0]*matrix.data[0][0] + data[1][1]*matrix.data[1][0];
		C.data[1][1] = data[1][0]*matrix.data[0][1] + data[1][1]*matrix.data[1][1];
	}
	else{
		Matrix A11(rows/2, columns/2);
		Matrix A12(rows/2, columns/2);
		Matrix A21(rows/2, columns/2);
		Matrix A22(rows/2, columns/2);
		Matrix B11(rows/2, columns/2);
		Matrix B12(rows/2, columns/2);
		Matrix B21(rows/2, columns/2);
		Matrix B22(rows/2, columns/2);

		for (int i = 0; i < rows/2; i++){
			for (int j = 0; j < columns/2; j++){
				A11.data[i][j] = data[i][j];
				B11.data[i][j] = matrix.data[i][j];
			}
		}

		for (int i = 0; i < rows/2; i++){
			for (int j = columns/2; j < columns; j++){
				A12.data[i][j] = data[i][j];
				B12.data[i][j] = matrix.data[i][j];
			}
		}

		for (int i = rows/2; i < rows; i++){
			for (int j = 0; j < columns/2; j++){
				A21.data[i][j] = data[i][j];
				B21.data[i][j] = matrix.data[i][j];
			}
		}

		for (int i = rows/2; i < rows; i++){
			for (int j = columns/2; j < columns; j++){
				A22.data[i][j] = data[i][j];
				B22.data[i][j] = matrix.data[i][j];
			}
		}

		Matrix S1 = B12.substract(B22);
		Matrix S2 = A11.sum(A12);
		Matrix S3 = A21.sum(A22);
		Matrix S4 = B21.substract(B11);
		Matrix S5 = A11.sum(A22);
		Matrix S6 = B11.sum(B22);
		Matrix S7 = A12.substract(A22);
		Matrix S8 = B21.sum(B22);
		Matrix S9 = A11.substract(A21);
		Matrix S10 = B11.sum(B12);

		Matrix P1 = A11.product(S1);
		Matrix P2 = S2.product(B22);
		Matrix P3 = S3.product(B11);
		Matrix P4 = A22.product(S4);
		Matrix P5 = S5.product(S6);
		Matrix P6 = S7.product(S8);
		Matrix P7 = S9.product(S10);

		for (int i = 0; i < rows/2; i++){
			for (int j = 0; j < columns/2; j++){
				C.data[i][j] = P5.data[i][j] + P4.data[i][j] - P2.data[i][j] + P6.data[i][j];
			}
		}

		for (int i = 0; i < rows/2; i++){
			for (int j = columns/2, k = 0; j < columns; j++, k++){
				C.data[i][j] = P1.data[i][k] + P2.data[i][k];
			}
		}

		for (int i = rows/2, k = 0; i < rows; i++, k++){
			for (int j = 0; j < columns/2; j++){
				C.data[i][j] = P3.data[k][j] + P4.data[k][j];
			}
		}

		for (int i = rows/2, k = 0; i < rows; i++, k++){
			for (int j = columns/2, l = 0; j < columns; j++, l++){
				C.data[i][j] = P5.data[k][l] + P1.data[k][l] - P3.data[k][l] - P7.data[k][l];
			}
		}
	}

	return C;
}

bool Matrix::is_monge_array(int row_beginning, int row_end, int col_beginning, int col_end){
	if ((row_end - row_beginning + 1 == 1) || (col_end - col_beginning + 1 == 1)){
		return true;
	}

	bool is_monge = true;
	if ((row_end - row_beginning + 1 == 2) || (col_end - col_beginning + 1 == 2)){
		if (row_end - row_beginning + 1 == 2){
			for (int i = col_beginning; i < col_end; i++){
				is_monge = is_monge && (data[row_beginning][i] + data[row_end][i+1] <= data[row_beginning][i+1] + data[row_end][i]);
			}
		}
		if (col_end - col_beginning + 1 == 2){
			for (int i = row_beginning; i < row_end; i++){
				is_monge = is_monge && (data[i][col_beginning] + data[i+1][col_end] <= data[i][col_end] + data[i+1][col_beginning]);
			}
		}
	}
	else {
		int middle_row = (row_beginning + row_end)/2;
		int middle_col = (col_beginning + col_end)/2;
		is_monge = is_monge_array(row_beginning, middle_row-1, col_beginning, middle_col-1) && 
		                is_monge_array(middle_row, row_end, col_beginning, middle_col-1) &&
		                is_monge_array(row_beginning, middle_row-1, middle_col, col_end) && 
		                is_monge_array(middle_row, row_end, middle_col, col_end) &&
		                is_monge_check_edge_cases(row_beginning, row_end, col_beginning, col_end);
	}

	return is_monge;
}

bool Matrix::is_monge_check_edge_cases(int row_beginning, int row_end, int col_beginning, int col_end){
	bool is_monge_edge_cases = true;
	int middle_row = (row_beginning + row_end)/2;
	int middle_col = (col_beginning + col_end)/2;
	for (int i = row_beginning; i < row_end; i++){
		is_monge_edge_cases = is_monge_edge_cases && (data[i][middle_col-1] + data[i+1][middle_col] <= data[i][middle_col] + data[i+1][middle_col-1]);
	}

	for (int i = col_beginning; i < col_end; i++){
		is_monge_edge_cases = is_monge_edge_cases && (data[middle_row-1][i] + data[middle_row][i+1] <= data[middle_row-1][i+1] + data[middle_row][i]);
	}

	return is_monge_edge_cases;
}

bool Matrix::is_monge_array(){
	return is_monge_array(0, rows-1, 0, columns-1);
}