#pragma once

#include <vector>
#include <iostream>
#include <iomanip>

using namespace std;

#define Matrix vector<vector<double>>

const double PI = 3.14159265358979323846;

void vector_transform(const Matrix& matrix, vector<double>& r);																		//������������ ������� 3x3 �� 3-� ������ ������
vector<double> vector_product(const vector<double>& lhs, const vector<double>& rhs);							//��������� ������������ 3-� ������ ��������
double length(const vector<double>& r);																														//����� 3-������� �������
vector<double> operator*(const vector<double>& lhs, double rhs);																	//������������ ������� �� �����
vector<double> operator+(const vector<double>& lhs, const vector<double>& rhs);									  //�������� ��������

//������� ��� ������������ ������ ������ ���������

void TestEulerToMistake();																																				//���� ������ EulerToMistake
void TestMistakeToOffset();																																				//���� ������ MistakeToOffset
void TestComputeMatrix();																																					//���� ������ ComputeMatrix ������ MistakeToOffset
void TestVectorTransform();																																				//���� ������� VectorTransform
void TestVectorProduct();																																					//���� ������� VectorProduct
