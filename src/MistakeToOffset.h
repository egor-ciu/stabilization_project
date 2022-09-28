#pragma once

#include <vector>

using namespace std;

class MistakeToOffset {                                       																 	  //класс, отвечающий за вычисление смещени€ дл€ моторов
public:
	MistakeToOffset(vector<double> mistake_t, double P_t, double I_t, double D_t, int step, ostream& output_t);       						//на вход подаютс€ ошибка, коэффициенты P, I, D, шаг, поток вывода

	void computeOffset();																																						//метод, вычисл€ющий смещение моторов
	vector<double> getOffset() const;																																//метод, возвращающий смещение моторов
	vector<double> getMistake() const;																															//метод, возвращающий ошибку

private:
	vector<double> mistake;																																					//ошибка, {крен, тангаж}
	double P, I, D;																																									//коэффициенты PID-регул€тора
	vector<double> offset;                          																								//смещение на двух моторах
	ostream& output;																																								//поток вывода
	int step;																																												//шаг стабилизации
};
