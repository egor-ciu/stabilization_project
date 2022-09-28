/*
 * ���������� ������ EulerToMistake
 *
 */

#include "main.h"
#include "EulerToMistake.h"

#include <cmath>

using namespace std;


EulerToMistake::EulerToMistake(vector<double> euler_coords_t) :            														//{����, ������} - ����� �� ������� ���������. ��� ��������� ������� ����� ������ �������� ������� ��������.
	euler_coords(euler_coords_t)
	{

	computeMistake();

}



void EulerToMistake::computeMistake() {
	//������ - ���� ������ � �������� ������, ��� ��� setpoint � ��� 0 ��������
	mistake = {-euler_coords[0], -euler_coords[1]};
}

vector<double> EulerToMistake::getEulerCoords() const { return euler_coords;}
vector<double> EulerToMistake::getMistake() const {	return mistake;}
