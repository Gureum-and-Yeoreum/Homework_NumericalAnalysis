#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include "mat_vec_read.h"
#include "matrix_oper.h"

using namespace std;

int main()	{
	string file_mat, file_vec;
	cout << "Enter the txt file containing matrix data: ";
	cin >> file_mat;

	cout << "Enter the txt file containing vector data: ";
	cin >> file_vec;

	tuple<vector<double>, vector<int>, int, int, int> mat;
	mat = genSparse(file_mat);

	vector<double> AA = get<0>(mat);
	vector<int> JA = get<1>(mat);
	int row = get<2>(mat);
	int col = get<3>(mat);
	int n_nze = get<4>(mat);

	vector<double> vec = genVector(file_vec, row);
	
	vector<double> prod_res(row);
	vector<double> product(vector<double> result, vector<double> AA, vector<int> JA, vector<double> vec, int row, int col);


}