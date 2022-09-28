#include "profiler.h"
#include "main.h"
#include "EulerToMistake.h"
#include "MistakeToOffset.h"

#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <fstream>
using namespace std;

#define Matrix vector<vector<double>>                              //������� �������� �� �������



void TestAll() {																									 //����� ������� � �������
	TestRunner tr;
	tr.RunTest(TestComputeMatrix, "TestComputeMatrix");
	tr.RunTest(TestVectorTransform, "TestVectorTransform");
	tr.RunTest(TestVectorProduct, "TestVectorProduct");
	tr.RunTest(TestEulerToMistake, "TestEulerToMistake");
}

int main() {

	TestAll();

	const double alpha = PI / 10;
	const double beta = PI / 15;

	cout << setprecision(2);
	cout << "��������� ������: ���� = " << alpha / PI * 180 << " ��������, ������ = " << beta / PI * 180 << " ��������" << endl;

	for (double P : {0.1, 0.25, 0.5, 0.75, 1., 2.}) {
		vector<double> mistake = {alpha, beta};
		string file_name = "P = " + to_string(P) +
											 ", ���� = " + to_string(alpha / PI * 180) +
											 ", ������ = " + to_string(beta / PI * 180) + ".txt";   				                //�������� �����, ���� ����� ������������ ������

		ofstream output(file_name);
		cout << "P = " << P << endl;
		MistakeToOffset mto(mistake, P, 0, 0, 0, output);
	}

	return 0;
}
