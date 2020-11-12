#include <iostream>
#include <cstdlib>
#include <clocale>
#include "Monte_Carlo.h"

int main()
{
	setlocale(LC_CTYPE, "Russian");

	double x_min, x_max, y_min, y_max;
	std::cout << "¬ведите границы области" << std::endl;
	std::cin >> x_min >> x_max >> y_min >> y_max;
	int n;
	std::cout << std::endl << "¬ведите число точек" << std::endl;
	std::cin >> n;
	std::vector<double> res;
	for (int i = 0; i < 5; i++)
	{
		res = MonteCarlo(n, x_min, x_max, y_min, y_max);
		std::cout << std::endl << "ќтвет - (" << res[0] << ", " << res[1] << ")" << std::endl;
	}

	system("pause");
	return 0;
}