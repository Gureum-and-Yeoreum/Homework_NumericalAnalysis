#ifndef MATRIX_OPER
#define MATRIX_OPER

#include <vector>
#include <tuple>

using std::vector;
using std::tuple;

vector<double> product(vector<double> result, const vector<double> AA, const vector<int> JA, const vector<double> vec, int row, int col);

#endif // !MATRIX_OPER