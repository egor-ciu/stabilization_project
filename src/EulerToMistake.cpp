/*
 * Реализация класса EulerToMistake
 *
 */

#include "main.h"
#include "EulerToMistake.h"

#include <cmath>

using namespace std;


EulerToMistake::EulerToMistake(vector<double> euler_coords_t) :            														//{крен, тангаж} - такой же порядок поворотов. При изменении порядка нужно только поменять матрицу поворота.
	euler_coords(euler_coords_t)
	{

	computeMistake();

}



void EulerToMistake::computeMistake() {
	//Ошибка - углы Эйлера с обратным знаком, так как setpoint у нас 0 градусов
	mistake = {-euler_coords[0], -euler_coords[1]};
}

vector<double> EulerToMistake::getEulerCoords() const { return euler_coords;}
vector<double> EulerToMistake::getMistake() const {	return mistake;}
