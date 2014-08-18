#ifndef MATRIX2BY2
#define MATRIX2BY2

class Matrix2By2 {
public:
	Matrix2By2();
	Matrix2By2(long pos00, long pos01, long pos10, long pos11);
	Matrix2By2(const Matrix2By2 &matrix);
	long get_m00();
	long get_m01();
	long get_m10();
	long get_m11();
	void set_m00(long value);
	void set_m01(long value);
	void set_m10(long value);
	void set_m11(long value);
	
	Matrix2By2 multiplication(const Matrix2By2 & matrix);
	Matrix2By2 pow(int n);
private:
	long m00;
	long m01;
	long m10;
	long m11;
};

#endif
