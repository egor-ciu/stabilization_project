#pragma once

#include <vector>

using namespace std;

class EulerToMistake {                            		         																		//�����, ���������� �� ���������� ������ �� ����� ������
public:
	EulerToMistake(vector<double> euler_coords_t);

	void computeMistake();                                   																				//�����, ����������� ������
	vector<double> getEulerCoords() const;									 																				//�����, ������������ ���� ������
	vector<double> getMistake() const;											 																				//�����, ������������ ������

private:
	vector<double> euler_coords;                                																	  //���� ������, {����, ������}, ������������� ����������� ����� ���������� �� ������� ������ ����
	vector<double> mistake;																																					//������, {����, ������}
};
