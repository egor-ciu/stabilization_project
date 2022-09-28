#pragma once

#include <vector>
#include <iostream>
#include <iomanip>

using namespace std;

#define Matrix vector<vector<double>>

const double PI = 3.14159265358979323846;

void vector_transform(const Matrix& matrix, vector<double>& r);																		//произведение матрицы 3x3 на 3-х мерный вектор
vector<double> vector_product(const vector<double>& lhs, const vector<double>& rhs);							//векторное произведение 3-х мерных векторов
double length(const vector<double>& r);																														//длина 3-мерного вектора
vector<double> operator*(const vector<double>& lhs, double rhs);																	//произведение вектора на число
vector<double> operator+(const vector<double>& lhs, const vector<double>& rhs);									  //сложение векторов

//Функции для тестирования разных частей программы

void TestEulerToMistake();																																				//тест класса EulerToMistake
void TestMistakeToOffset();																																				//тест класса MistakeToOffset
void TestComputeMatrix();																																					//тест метода ComputeMatrix класса MistakeToOffset
void TestVectorTransform();																																				//тест функции VectorTransform
void TestVectorProduct();																																					//тест функции VectorProduct
