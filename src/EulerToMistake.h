#pragma once

#include <vector>

using namespace std;

class EulerToMistake {                            		         																		//класс, отвечающий за вычисление ошибки из углов Ёйлера
public:
	EulerToMistake(vector<double> euler_coords_t);

	void computeMistake();                                   																				//метод, вычисл€ющий ошибку
	vector<double> getEulerCoords() const;									 																				//метод, возвращающий углы Ёйлера
	vector<double> getMistake() const;											 																				//метод, возвращающий ошибку

private:
	vector<double> euler_coords;                                																	  //углы Ёйлера, {крен, тангаж}, положительное направление углов выбираетс€ по правилу правой руки
	vector<double> mistake;																																					//ошибка, {крен, тангаж}
};
