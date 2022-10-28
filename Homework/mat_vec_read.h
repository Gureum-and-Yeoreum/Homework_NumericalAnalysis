#ifndef MAT_VEC_READ
#define MAT_VEC_READ

#include <vector>
#include <tuple>
#include <string>

using std::vector;
using std::string;
using std::tuple;

tuple<vector<double>, vector<int>, int, int, int> genSparse(const string& file_mat);
vector<double> genVector(const string& file_vec, const int& row);

#endif // !MAT_VEC_READ