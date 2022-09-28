#pragma once

#include <vector>

using namespace std;

#define Matrix vector<vector<double>>

class OffsetToEngine {									       //класс, отвечающий за симулирование работы моторов        
public:
	OffsetToEngine(vector<double> offset_t, vector<double> old_mistake);                   //на вход подаются смещение и текущая ошибка   

	void computeMatrix(vector<double> mistake);                                            //метод, вычисляющий матрицу поворота
	void OffsetToMistakeModel(vector<double> old_mistake);				       //метод, вычисляющий ошибку после смещения моторов (модель)
	void OffsetToMistake();								       //метод, вычисляющий ошибку после смещения моторов (истинная ошибка, полученная с датчика; метод пока реализован);

	vector<double> getMistake() const;						       //метод, возвращающий ошибку
	Matrix getMatrix() const;							       //метод, возвращающий матрицу поворота

private:
	vector<double> offset;								       //смещение на двух моторах
	vector<double> new_mistake;							       //ошибка, {крен, тангаж}
	Matrix matrix;									       //матрица поворота
};
