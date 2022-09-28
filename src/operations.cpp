/*
 * Здесь находятся реализации всех необходимых математических операций:
 * 			преобразование вектора,
 * 			векторное произведение,
 * 			длина вектора,
 * 			произведение вектора на число,
 * 			сложение 2-х векторов.
 *
 */

#include <vector>
#include <cmath>

using namespace std;

#define Matrix vector<vector<double>>


void vector_transform(const Matrix& matrix, vector<double>& r) {
	if (r.size() != 3) { throw "Vector length is not 3!";}
	if (matrix.size() != 3 || matrix[0].size() != 3 || matrix[1].size() != 3 || matrix[2].size() != 3) { throw "Matrix is not 3x3!";}

	vector<double> r_t = r;
		r = {matrix[0][0] * r_t[0] + matrix[0][1] * r_t[1] + matrix[0][2] * r_t[2],
				matrix[1][0] * r_t[0] + matrix[1][1] * r_t[1] + matrix[1][2] * r_t[2],
				matrix[2][0] * r_t[0] + matrix[2][1] * r_t[1] + matrix[2][2] * r_t[2]};
}
vector<double> vector_product(const vector<double>& lhs, const vector<double>& rhs) {
	if (lhs.size() != 3 || rhs.size() != 3) {	throw "Vector lengths are not 3!";}

	return {lhs[1] * rhs[2] - lhs[2] * rhs[1], lhs[2] * rhs[0] - lhs[0] * rhs[2], lhs[0] * rhs[1] - lhs[1] * rhs[0]};
}
double length(const vector<double>& r) {
	return sqrt(r[0]*r[0] + r[1]*r[1] + r[2]*r[2]);
}

vector<double> operator*(const vector<double>& lhs, double rhs) {
	vector<double> result;
	for (size_t i = 0; i < lhs.size(); ++i) {
		result.push_back(lhs[i] * rhs);
	}
	return result;
}
vector<double> operator+(const vector<double>& lhs, const vector<double>& rhs) {
	if (lhs.size() != rhs.size()) {	throw "Vector lengths are not equal!";}
	vector<double> result;

	for (size_t i = 0; i < lhs.size(); ++i) {
		result.push_back(lhs[i] + rhs[i]);
	}
	return result;
}
