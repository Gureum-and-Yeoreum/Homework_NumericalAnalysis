#define _CRT_SECURE_NO_WARNINGS
#include <vector>
#include <tuple>
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <fstream>
#include <stdio.h>
#include "mat_vec_read.h"


using std::vector;
using std::string;
using std::ifstream;
using std::stringstream;
using std::ifstream;
using std::cout;
using std::endl;



tuple<vector<double>, vector<int>, int, int, int> genSparse(const string& file_mat) {
	int row, col, n_nze;
	string line, tmp, token;
	stringstream buffer;

	ifstream file(file_mat);
	if (!file.is_open()) {
		cout << "unable to open file";
		exit(0);
	}


	/*int asd, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10;
	ifstream t(file_mat);
	buffer << t.rdbuf();
	buffer >> row >> col >> n_nze;
	buffer >> row >> col >> n_nze >> a1 >> a2 >> a3 >> a4 >> a5 >> a6 >> a7 >> a8 >> a9 >> a10;
	cout << buffer << endl;*/

	getline(file, line);
	tmp = line;
	stringstream ss(tmp);
	ss >> row >> col >> n_nze;
	cout << "# of rows: " << row << "\t # of  cols: " << col << "\t # of non-zero elements: " << n_nze << endl;
	
	vector<double> AA(n_nze + 1); // save value of non zero elements
	vector<int> JA(n_nze + 1);
	int n_diag_nz = row;
	int row_tmp, col_tmp, n_offdiag_tmp = 0, row_tmp_prev = 0, starting_idx = 0;
	double val;

	/*char filename[12] = "MatrixA.txt";
	FILE *fp;
	fp = fopen(filename, "r");
	fseek(fp, 0, SEEK_END);
	long lSize = ftell(fp);
	fseek(fp, 0, SEEK_SET);

	char* buff = (char*)malloc(sizeof(char) * lSize);
	unsigned int totnum = 0, curnum = 0;
	while ((curnum = fread(&buff[totnum], sizeof(char), lSize - totnum, fp)) > 0) {
		totnum += curnum;
		cout << buff << endl;
	}
	
	//fclose(fp);
	
	//fread(fp, 0, SEEK_END);
	/*char ch[100];
	string asdf[100];
	strcpy_s(ch, file_mat.c_str());
	FILE* fp;
	fopen_s(&fp,ch, "r");
	fread(&asdf, 1000, 1, fp);*/


	while (getline(file, line)) {
		tmp = line;
		stringstream ss(tmp);
		ss >> row_tmp >> col_tmp >> val;
		if (row_tmp != row_tmp_prev) {
			starting_idx = 0;
		}
		//cout << '(' << row_tmp << ',' << col_tmp << ')' << '=' << val << endl;
		if (row_tmp == col_tmp) {
			AA[row_tmp-1] = val;
		}
		else if (row_tmp != col_tmp) {
			AA[n_diag_nz + 1 + n_offdiag_tmp] = val;
			JA[n_diag_nz + 1 + n_offdiag_tmp] = col_tmp;
			n_offdiag_tmp++;
			if (starting_idx == 0) {
				JA[row_tmp-1] = n_diag_nz + n_offdiag_tmp;
				starting_idx = 1;
			}
		}
	}
	cout << "done!" << endl;
	JA[n_diag_nz] = n_nze + 1;
	file.close();
	return make_tuple(AA, JA, row, col, n_nze);
}

vector<double> genVector(const string& file_vec, const int &row_of_matrix) {
	int row, row_tmp;
	double val;
	string line, tmp;

	ifstream file(file_vec);
	if (!file.is_open()) {
		cout << "unable to open file" << endl;
		exit(0);
	}

	getline(file, line);
	tmp = line;
	stringstream ss(tmp);
	ss >> row;

	if (row != row_of_matrix) {
		cout << "matrix and vector size error" << endl;
		exit(0);
	}

	vector<double> X(row); // save value of non zero elements
	while (getline(file, line)) {
		tmp = line;
		stringstream ss(tmp);
		ss >> row_tmp >> val;
		X[row_tmp - 1] = val;
	}
	
	file.close();
	return X;
}