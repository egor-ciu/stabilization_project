/*
 * Реализация класса OffsetToEngine
 *
 */

#include "main.h"
#include "profiler.h"
#include "OffsetToEngine.h"

#include <cmath>

using namespace std;

#define Matrix vector<vector<double>>

OffsetToEngine::OffsetToEngine(vector<double> offset_t, vector<double> old_mistake) :            					//{крен, тангаж} - такой же порядок поворотов. При изменении порядка нужно только поменять матрицу поворота.
	offset(offset_t)
	{

	computeMatrix(old_mistake);
	OffsetToMistakeModel(old_mistake);

}

void OffsetToEngine::computeMatrix(vector<double> mistake) {
	/*
	 * Вначале поворачиваем СК относительно оси X (крен), потом поворачиваем СК относительно новой оси Y' (тангаж).
	 * Перемножаем обе матрицы поворота в обратном порядке и получаем необходимую матрицу.
	 * Матрицы поворота относительно главной и произвольной осей можно найти на Википедии.
	 *
	 */

  double alpha = -mistake[0];																																					//крен
  double beta = -mistake[1];																																					//тангаж
	matrix = {{cos(beta), 											0, 									sin(beta)},
				   {sin(beta) * sin(alpha), 					cos(alpha), 				-sin(alpha) * cos(beta)},
					 {-sin(beta) * cos(alpha), 	 		  sin(alpha),  				cos(alpha) * cos(beta)}};
}

void OffsetToEngine::OffsetToMistakeModel(vector<double> old_mistake) {
	/*
		 * Функция вычисляет новые углы Эйлера (ошибку), зная предыдущую ошибку и смещение, которое нужно задать моторам.
		 * Алгоритм работы:
		 * 		1. Вычисляем матрицу поворота, которая поворачивает плоскость так, как заданы углы Эйлера.
		 * 		Это необходимо для того, чтобы повернуть радиус-векторы двух точек, к которым прикреплены моторы.
		 *
		 * 		2. Задаем изначальное положение двух точек так, чтобы они с началом координат образовали равносторонний треугольник. Длина радиус векторов единичная.
		 * 		Задаем нормаль к плоскости z = 0.
		 *
		 * 		3. Преобразуем радиус-векторы двух точек в соответствии с поворотом плоскости.
		 * 		Теперь точки у нас находятся там, где и должны быть, если платформа отклонилась от положения равновесия.
		 *
		 * 		4. Задаем смещение двух точек по оси Z, так как моторы могут двигаться только в этом направлении.
		 * 		После этого нормируем радиус-векторы двух точек, так как их длина изначально единичная.
		 * 		Из-за нормировки, реальное смещение меньше, чем то, что мы изначально задали, но логики процесса это не меняет.
		 * 		При малых углах можно этим пренебречь, при больших углах до 90 градусов реальное смещение будет больше смоделированного.
		 * 		Этот недочет можно исправить, задав окружность, по которой движется точка с мотором.
		 *
		 * 		5. Вычисляем нормаль новой плоскости, построенной уже по двум смещенным радиус-векторам.
		 *
		 * 		6. Зная нормаль, можно найти новые углы Эйлера. Здесь алгоритм пока работает только для углов от -90 до 90 градусов.
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
