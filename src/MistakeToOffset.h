#pragma once

#include <vector>

using namespace std;

class MistakeToOffset {                                       																 	  //�����, ���������� �� ���������� �������� ��� �������
public:
	MistakeToOffset(vector<double> mistake_t, double P_t, double I_t, double D_t, int step, ostream& output_t);       						//�� ���� �������� ������, ������������ P, I, D, ���, ����� ������

	void computeOffset();																																						//�����, ����������� �������� �������
	vector<double> getOffset() const;																																//�����, ������������ �������� �������
	vector<double> getMistake() const;																															//�����, ������������ ������

private:
	vector<double> mistake;																																					//������, {����, ������}
	double P, I, D;																																									//������������ PID-����������
	vector<double> offset;                          																								//�������� �� ���� �������
	ostream& output;																																								//����� ������
	int step;																																												//��� ������������
};
