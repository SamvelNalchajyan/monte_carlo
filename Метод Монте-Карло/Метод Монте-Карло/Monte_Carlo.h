#pragma once
#define _USE_MATH_DEFINES
#include <math.h>
#include <vector>

std::vector<std::vector<double>> A_matrix = { {-0.940, -0.536, -0.743}, {-0.502,  0.804,  0.769}, {-0.428, -0.789,  0.204} };
std::vector<std::vector<double>> B_matrix = { { 0.590,  0.160, -0.681}, { 0.387,  0.945, -0.195}, {-0.231,  0.152,  0.295} };
std::vector<std::vector<double>> C_matrix = { {-0.896, -0.613, -0.463}, { 0.038, -0.428, -0.714}, { 0.103,  0.741, -0.317} };
std::vector<std::vector<double>> D_matrix = { {-0.754, -0.558, -0.989}, {-0.702,  0.881,  0.397}, {-0.056,  0.085, -0.616} };

double horrific_function(std::vector<double> argument)
{
	if (argument.size() == 2)
	{
		double x = argument[0];
		double y = argument[1];
		double result = 0;
		double sum1 = 0, sum2 = 0;
		double A, B, C, D;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				A = A_matrix[i][j];
				B = B_matrix[i][j];
				C = C_matrix[i][j];
				D = D_matrix[i][j];
				sum1 += A * sin(i * M_PI * (x - 1 / 2)) * sin(j * M_PI * (y - 1 / 2)) + B * cos(i * M_PI * (x - 1 / 2)) * cos(j * M_PI * (y - 1 / 2));
				sum2 += C * sin(i * M_PI * (x - 1 / 2)) * sin(j * M_PI * (y - 1 / 2)) + D * cos(i * M_PI * (x - 1 / 2)) * cos(j * M_PI * (y - 1 / 2));
			}
		}
		return sqrt(sum1 * sum1 + sum2 * sum2);
	}
	else
	{
		throw - 1;
	}
}

double TestFunction(std::vector<double> argument)
{
	if (argument.size() == 2)
	{
		double x = argument[0];
		double y = argument[1];
		//return (1 + sin(10 * x) + cos(2 * x) + cos(2 * x + 2 * y) + cos(2 * y) + sin(20 * y) + y * y);
		return ((1 - x) * (1 - x) + 100 * (y - x * x) * (y - x * x));
	}
	else
	{
		throw - 1;
	}
}

double FRand(double min, double max)
{
	double tmp = static_cast<double>(rand()) / RAND_MAX;
	return min + tmp * (max - min);
}

std::vector<double> GenerateCandidate(double x_min, double x_max, double y_min, double y_max)
{
	std::vector<double> res;
	double x, y;
	x = FRand(x_min, x_max);
	y = FRand(y_min, y_max);
	res.push_back(x);
	res.push_back(y);
	return res;
}

std::vector<double> MonteCarlo(int n, double x_min, double x_max, double y_min, double y_max)
{
	std::vector<double> current = GenerateCandidate(x_min, x_max, y_min, y_max);
	std::vector<double> candidate;
	for (int i = 0; i < n; i++)
	{
		candidate = GenerateCandidate(x_min, x_max, y_min, y_max);
		if (TestFunction(candidate) < TestFunction(current))
		{
			current = candidate;
		}
	}
	return current;
}