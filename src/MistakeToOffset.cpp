/*
 * ���������� ������ MistakeToOffset
 *
 */

#include "main.h"
#include "profiler.h"
#include "MistakeToOffset.h"
#include "OffsetToEngine.h"

#include <cmath>
#include <iostream>
#include <fstream>

using namespace std;


MistakeToOffset::MistakeToOffset(vector<double> mistake_t, double P_t, double I_t, double D_t, int step_t, ostream& output_t) :          //{����, ������} - ����� �� ������� ���������. ��� ��������� ������� ����� ������ �������� ������� ��������.
	mistake(mistake_t),
	P(P_t),
	I(I_t),
	D(D_t),
	output(output_t),
	step(step_t)
	{

	computeOffset();

}

void MistakeToOffset::computeOffset() {
	//������ ������ ���������� � �������: ���   ����   ������
	output << step << " " << mistake[0] / PI * 180 << " " << mistake[1] / PI * 180 << endl;
	/*
	 * ������ ���������� �������� ��� ���� �������:
	 * 		�1 = ���� * P - ������ * P
	 * 		M2 = - ���� * P - ������ * P
	 */
	offset = {mistake[0] * P - mistake[1] * P, - mistake[0] * P - mistake[1] * P};                        //��������, ������� ���������� ����������. ������������� ��� ���������� ������, �� ������� � ���������

	mistake = OffsetToEngine(offset, mistake).getMistake();																								//��������� ������ ��� ����� �������� �������

	if ((abs(mistake[0] / PI * 180) > 0.1 || abs(mistake[1] / PI * 180) > 0.1)) {

		if (abs(mistake[0] / PI * 180) > 89.999 || abs(mistake[1] / PI * 180) > 89.999) {
			cout << "������������ ������ ��������!" << endl;
		} else {
			MistakeToOffset m(mistake, P, I, D, ++step, output);
		}

	} else {
		output << step << " " << mistake[0] / PI * 180 << " " << mistake[1] / PI * 180 << endl;
		cout << "������������ ������ �������! ���������� �����: " << step << endl;
	}
	//� ��������, ����� ����� ������ ������ ���������� ������� �����, ������� �� ��������� ������ ������� �� ��������, � ��������� �������� ����� ����� ������ (�.�. ������)


}

vector<double> MistakeToOffset::getMistake() const { return mistake;}
vector<double> MistakeToOffset::getOffset() const {	return offset;}
