/*
 * Реализация класса MistakeToOffset
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


MistakeToOffset::MistakeToOffset(vector<double> mistake_t, double P_t, double I_t, double D_t, int step_t, ostream& output_t) :          //{крен, тангаж} - такой же порядок поворотов. При изменении порядка нужно только поменять матрицу поворота.
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
	//Запись данных происходит в формате: шаг   крен   тангаж
	output << step << " " << mistake[0] / PI * 180 << " " << mistake[1] / PI * 180 << endl;
	/*
	 * Логика вычисления смещения для двух моторов:
	 * 		М1 = крен * P - тангаж * P
	 * 		M2 = - крен * P - тангаж * P
	 */
	offset = {mistake[0] * P - mistake[1] * P, - mistake[0] * P - mistake[1] * P};                        //смещение, которое передается двигателям. Положительная ось направлена наверх, по нормали к плоскости

	mistake = OffsetToEngine(offset, mistake).getMistake();																								//вычисляем ошибку уже после смещения моторов

	if ((abs(mistake[0] / PI * 180) > 0.1 || abs(mistake[1] / PI * 180) > 0.1)) {

		if (abs(mistake[0] / PI * 180) > 89.999 || abs(mistake[1] / PI * 180) > 89.999) {
			cout << "Стабилизация прошла неудачно!" << endl;
		} else {
			MistakeToOffset m(mistake, P, I, D, ++step, output);
		}

	} else {
		output << step << " " << mistake[0] / PI * 180 << " " << mistake[1] / PI * 180 << endl;
		cout << "Стабилизация прошла успешно! Количество шагов: " << step << endl;
	}
	//В принципе, здесь можно вместо модели двигателей вызвать класс, который бы отправлял запрос моторам на смещение, и возвращал значение новых углов Эйлера (т.е. ошибку)


}

vector<double> MistakeToOffset::getMistake() const { return mistake;}
vector<double> MistakeToOffset::getOffset() const {	return offset;}
