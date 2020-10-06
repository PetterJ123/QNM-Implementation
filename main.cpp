#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
	if((std::string)argv[1] == "--help")
	{
		std::cout << "<service demand> <think time> <customers>\n";
		exit(0);
	}
	double Qi[100];
	double Rprime[100];
	double X[100];

	int n = 50;     // # of customers

	double Di = 0.25;   // service demand
	double Z = 3.0;     // think time

	if (argc > 1)
	{
		Di = strtod(argv[1], &argv[1]);
		Z = strtod(argv[2], &argv[2]);
		n = strtod(argv[3], &argv[3]);
		std::cout << "Using following values: " << "\nthink time (Z): " << Z << "\nService demand(D): " << Di << "\nCustomers/Requests (n): " << n << "\n\n";
	}

	Qi[0] = 0.0;

	for (int i=1; i<n; i++){
		Rprime[i] = Di*(1.0 + Qi[i - 1]);
		X[i] = i/(Z + Rprime[i]);
		Qi[i] = X[i]*Rprime[i];

		double Ui = X[i] * Di * 100;
		double Ri = Di/(1.0 - Ui * 0.01);

		std::cout << "Customer=" << i << "\tUtilization=" << Ui << "%\tResidence time=" << Rprime[i] << "\tResponse time= " << Ri << "\tThroughput=" << X[i] << "\tQueue=" << Qi[i] << "\n\n";
	}

	return 0;
}
