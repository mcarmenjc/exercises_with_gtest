#ifndef MATRIX
#define MATRIX

class Matrix {
public:
	Matrix(int num_rows, int num_cols);
	Matrix(const Matrix &matrix);
	~Matrix();
	void set_at(int row_pos, int col_pos, int value);
	int get_at(int row_pos, int col_pos);
	int get_rows();
	int get_columns();
	Matrix sum(const Matrix &matrix);
	Matrix substract(const Matrix &matrix);
	Matrix product(const Matrix &matrix);
	bool is_monge_array();
private:
	int ** data;
	int rows;
	int columns;
	bool is_monge_array(int row_beginning, int row_end, int col_beginning, int col_end);
	bool is_monge_check_edge_cases(int row_beginning, int row_end, int col_beginning, int col_end);
};

#endif
