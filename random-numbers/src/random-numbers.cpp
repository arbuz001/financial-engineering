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
#include <vector>
#include "SimpleRNG.h"

using namespace std;

void clean(double a[])
{
	delete [] a;
};

int main()
{
	std::vector<int> vec1(4,100); // five ints with value 100

	ifstream in_stream;
	ofstream out_stream;

	SimpleRNG qRNG;
	double rValue;

	const int nSize = 100;
	double arValues[nSize];
	// double arInValues[nSize];

	typedef double* doublePtr;
	doublePtr arInValuesDynamic;
	arInValuesDynamic = new double [nSize-3];

	in_stream.open("infile.dat");

	cout << "size of vec1 before " << vec1.size() << endl;

	vec1.push_back(5);
	vec1[5] = 45;

	cout << "vec1 capacity " << vec1.capacity() <<endl;

	cout << "all values of vec1" << endl;
	for(unsigned int i = 0; i < vec1.size(); i++)
	{
		cout << " " << vec1[i] << endl;
	}
	cout << " " << endl;

	double qIn;

	int i= 0;
	while(in_stream >> qIn)
	{
		// arInValues[i] = qIn;
		arInValuesDynamic[i] = qIn;
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
	// cout << "arInValues_3 " << arInValues[3] << endl;
	cout << "arInValuesDynamic_3 " << arInValuesDynamic[3] << endl;

	clean(arInValuesDynamic);

	cout << "!!!All calculations completed!!!" << endl;

	return 0;
}
