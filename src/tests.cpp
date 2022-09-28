/*
 * Здесь находятся реализации всех тестов функций и классов
 *
 */

#include "main.h"
#include "profiler.h"
#include "EulerToMistake.h"
#include "OffsetToEngine.h"

#include <cmath>

using namespace std;

#define Matrix vector<vector<double>>

void TestEulerToMistake() {

	EulerToMistake etm({PI / 4, PI});

	AssertEqual(etm.getMistake(), vector<double>{-PI / 4, -PI}, "EulerToMistake_1");

}

//void TestMistakeToOffset() {
//	//Реализация для набора коэффициентов P
//	for (double P : {0.1, 0.25, 0.5, 0.75, 1., 2.}) {
//		MistakeToOffset mto({PI / 4, PI / 4}, P, 0.1, 0.1);
//	}
//}

void TestComputeMatrix() {
	Matrix matrix = OffsetToEngine({0, 0}, {0, -PI / 2}).getMatrix();
	for (auto& string : matrix) {
		for (auto& item : string) {
			item = int(item * 1000) / 1000.;
		}
	}
	AssertEqual(matrix, Matrix{{0, 0, 1}, {0, 1, 0}, {-1, 0, 0}}, "Matrix_1");

	matrix = OffsetToEngine({0, 0}, {-PI / 2, 0}).getMatrix();
	for (auto& string : matrix) {
		for (auto& item : string) {
			item = int(item * 1000) / 1000.;
		}
	}

	AssertEqual(matrix, Matrix{{1, 0, 0}, {0, 0, -1}, {0, 1, 0}}, "Matrix_2");

	matrix = OffsetToEngine({0, 0}, {-PI / 2, -PI}).getMatrix();
	for (auto& string : matrix) {
		for (auto& item : string) {
			item = int(item * 1000) / 1000.;
		}
	}

	AssertEqual(matrix, Matrix{{-1, 0, 0}, {0, 0, 1}, {0, 1, 0}}, "Matrix_3");

	matrix = OffsetToEngine({0, 0}, {-PI / 2, -PI / 2}).getMatrix();
	for (auto& string : matrix) {
		for (auto& item : string) {
			item = int(item * 1000) / 1000.;
		}
	}

	AssertEqual(matrix, Matrix{{0, 0, 1}, {1, 0, 0}, {0, 1, 0}}, "Matrix_4");

	matrix = OffsetToEngine({0, 0}, {PI / 2, -PI / 2}).getMatrix();
	for (auto& string : matrix) {
		for (auto& item : string) {
			item = int(item * 1000) / 1000.;
		}
	}

	AssertEqual(matrix, Matrix{{0, 0, 1}, {-1, 0, 0}, {0, -1, 0}}, "Matrix_5");

	matrix = OffsetToEngine({0, 0}, {0, -PI / 4}).getMatrix();
	for (auto& string : matrix) {
		for (auto& item : string) {
			item = int(item * 1000) / 1000.;
		}
	}

	AssertEqual(matrix, Matrix{{0.707, 0, 0.707}, {0, 1, 0}, {-0.707, 0, 0.707}}, "Matrix_6");


}

void TestVectorTransform() {
	Matrix matrix = OffsetToEngine({0,0}, {0, -PI / 2}).getMatrix();
	for (auto& string : matrix) {
			for (auto& item : string) {
				item = int(item * 1000) / 1000.;
			}
		}

	vector<double> v = {1, 1, 1};

	vector_transform(matrix, v);
	AssertEqual(v, vector<double>{1, 1, -1}, "VectorTransform_1");

	matrix = OffsetToEngine({0, 0}, {-PI / 2, PI / 2}).getMatrix();
	for (auto& string : matrix) {
			for (auto& item : string) {
				item = int(item * 1000) / 1000.;
			}
		}

	v = {1, 1, 1};

	vector_transform(matrix, v);
	AssertEqual(v, vector<double>{-1, -1, 1}, "VectorTransform_2");

}

void TestVectorProduct() {
	vector<double> v_1 = {1, 0, 0};
	vector<double> v_2 = {0, 1, 0};

	AssertEqual(vector_product(v_1, v_2), vector<double>{0, 0, 1}, "VectorProduct_1");

	v_1 = {2, 0, 0};
	v_2 = {0, 1, 0};

	AssertEqual(vector_product(v_1, v_2), vector<double>{0, 0, 2}, "VectorProduct_2");

	v_1 = {0, 1, 1};
	v_2 = {0, 1, -1};

	AssertEqual(vector_product(v_1, v_2), vector<double>{-2, 0, 0}, "VectorProduct_2");

}
