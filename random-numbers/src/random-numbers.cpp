////============================================================================
//// Name        : random-numbers.cpp
//// Author      :
//// Version     :
//// Copyright   : Your copyright notice
//// Description : Hello World in C++, Ansi-style
////============================================================================
//

#include <iostream>
#include <fstream>
#include <string>
#include "SimpleRNG.h"

using namespace std;

int main()
{
	ifstream in_stream;
	ofstream out_stream;

	SimpleRNG qRNG;
	double rValue;

	const int nSize = 100;
	double arValues[nSize];
	double arInValues[nSize];

	in_stream.open("infile.dat");

	double qIn;

	int i= 0;
	while(in_stream >> qIn)
	{
		arInValues[i] = qIn;
		i++;
	}

	in_stream.close();

	for(int i= 0; i<nSize; i++)
	{
		rValue = qRNG.GetUniform();
		arValues[i] = rValue;
	}

	out_stream.open("outfile.dat");

	for(int i= 0; i<nSize; i++)
	{
		out_stream << arValues[i] << endl;
	}

	out_stream.close();

	cout << "rValue " << rValue << endl;
	cout << "arInValues_3 " << arInValues[3] << endl;
	cout << "!!!All calculations completed!!!" << endl;

	return 0;
}
