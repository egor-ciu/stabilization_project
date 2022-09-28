/*
 * ���������� ������ OffsetToEngine
 *
 */

#include "main.h"
#include "profiler.h"
#include "OffsetToEngine.h"

#include <cmath>

using namespace std;

#define Matrix vector<vector<double>>

OffsetToEngine::OffsetToEngine(vector<double> offset_t, vector<double> old_mistake) :            					//{����, ������} - ����� �� ������� ���������. ��� ��������� ������� ����� ������ �������� ������� ��������.
	offset(offset_t)
	{

	computeMatrix(old_mistake);
	OffsetToMistakeModel(old_mistake);

}

void OffsetToEngine::computeMatrix(vector<double> mistake) {
	/*
	 * ������� ������������ �� ������������ ��� X (����), ����� ������������ �� ������������ ����� ��� Y' (������).
	 * ����������� ��� ������� �������� � �������� ������� � �������� ����������� �������.
	 * ������� �������� ������������ ������� � ������������ ���� ����� ����� �� ���������.
	 *
	 */

  double alpha = -mistake[0];																																					//����
  double beta = -mistake[1];																																					//������
	matrix = {{cos(beta), 											0, 									sin(beta)},
				   {sin(beta) * sin(alpha), 					cos(alpha), 				-sin(alpha) * cos(beta)},
					 {-sin(beta) * cos(alpha), 	 		  sin(alpha),  				cos(alpha) * cos(beta)}};
}

void OffsetToEngine::OffsetToMistakeModel(vector<double> old_mistake) {
	/*
		 * ������� ��������� ����� ���� ������ (������), ���� ���������� ������ � ��������, ������� ����� ������ �������.
		 * �������� ������:
		 * 		1. ��������� ������� ��������, ������� ������������ ��������� ���, ��� ������ ���� ������.
		 * 		��� ���������� ��� ����, ����� ��������� ������-������� ���� �����, � ������� ����������� ������.
		 *
		 * 		2. ������ ����������� ��������� ���� ����� ���, ����� ��� � ������� ��������� ���������� �������������� �����������. ����� ������ �������� ���������.
		 * 		������ ������� � ��������� z = 0.
		 *
		 * 		3. ����������� ������-������� ���� ����� � ������������ � ��������� ���������.
		 * 		������ ����� � ��� ��������� ���, ��� � ������ ����, ���� ��������� ����������� �� ��������� ����������.
		 *
		 * 		4. ������ �������� ���� ����� �� ��� Z, ��� ��� ������ ����� ��������� ������ � ���� �����������.
		 * 		����� ����� ��������� ������-������� ���� �����, ��� ��� �� ����� ���������� ���������.
		 * 		��-�� ����������, �������� �������� ������, ��� ��, ��� �� ���������� ������, �� ������ �������� ��� �� ������.
		 * 		��� ����� ����� ����� ���� ����������, ��� ������� ����� �� 90 �������� �������� �������� ����� ������ ����������������.
		 * 		���� ������� ����� ���������, ����� ����������, �� ������� �������� ����� � �������.
		 *
		 * 		5. ��������� ������� ����� ���������, ����������� ��� �� ���� ��������� ������-��������.
		 *
		 * 		6. ���� �������, ����� ����� ����� ���� ������. ����� �������� ���� �������� ������ ��� ����� �� -90 �� 90 ��������.
		 *
		 */

		vector<double> point_1 = {sqrt(3) * 0.5, 0.5, 0};
		vector<double> point_2 = {sqrt(3) * 0.5, -0.5, 0};
		vector<double> n = {0, 0, 1};
		vector_transform(matrix, point_1);
		vector_transform(matrix, point_2);

		point_1 = point_1 + vector<double>{0, 0, offset[0]};
		point_2 = point_2 + vector<double>{0, 0, offset[1]};
		point_1 = point_1 * (1 / length(point_1));
		point_2 = point_2 * (1 / length(point_2));
//		cout << "length: " << length({point_1[0] - point_2[0], point_1[1] - point_2[1], point_1[2] - point_2[2]}) << endl;


		n = vector_product(point_2, point_1);
		n = n * (1 / length(n));
		new_mistake = {atan(n[1] / n[2]), -asin(n[0])};

}

vector<double> OffsetToEngine::getMistake() const {	return new_mistake;}
Matrix OffsetToEngine::getMatrix() const {	return matrix;}
