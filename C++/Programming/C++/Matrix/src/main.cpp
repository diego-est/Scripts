/* ========================================================================
 *
 *     Filename:  main.cpp
 *  Description:  matrix algorithms
 *       Author:  Diego A. Estrada Rivera
 *      Version:  0.0.1
 *
 * ======================================================================== */

#include <iostream>
auto println(auto x)
{
	std::cout << x << std::endl;
}
auto print(auto x)
{
	std::cout << x;
}

#include <bits/stdc++.h>
#define int uint64_t
using namespace std;
typedef size_t sz;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<pair<int, int>> vii;
typedef vector<vector<int>> vvi;

struct Matrix {
	Matrix(sz r, sz c) : data(vi(r * c, 0)), cols(c), rows(r)
	{
	}

	int& operator[](sz i)
	{
		return data[i];
	}

	int& operator()(sz r, sz c)
	{
		return data[r * cols + c];
	}

	int operator()(sz r, sz c) const
	{
		return data[r * cols + c];
	}

	vi get_row(sz r) const
	{
		auto ret = vi(cols, 0);
		sz i = 0;
		for (auto& e : ret) {
			e = data[rows * r + i];
			i++;
		}
		return ret;
	}

	vi get_col(sz c) const
	{
		auto ret = vi(rows, 0);
		sz i = 0;
		for (auto& e : ret) {
			e = data[cols * i + c];
			i++;
		}
		return ret;
	}

	void print() const
	{
		for (sz i = 0; i < rows; i++) {
			for (sz j = 0; j < cols; j++)
				cout << (*this)(i, j) << " ";
			cout << endl;
		}
	}

	Matrix operator*(const Matrix& rhs) const
	{
		auto out = Matrix(rhs.rows, cols);
		for (sz i = 0; i < cols; i++) {
			auto sel_row = get_row(i);
			for (sz j = 0; j < rhs.rows; j++) {
				auto sel_col = rhs.get_col(j);
				int sum = inner_product(sel_row.begin(),
							sel_row.end(),
							sel_col.begin(), 0);
				out(i, j) = sum;
			}
		}
		return out;
	}

	void operator*=(const Matrix& rhs)
	{
		for (sz i = 0; i < cols; i++) {
			auto sel_row = get_row(i);
			for (sz j = 0; j < rhs.rows; j++) {
				auto sel_col = rhs.get_col(j);
				int sum = inner_product(sel_row.begin(),
							sel_row.end(),
							sel_col.begin(), 0);
				(*this)(i, j) = sum;
			}
		}
	}

	vi data;
	sz cols;
	sz rows;
};

auto main() -> int32_t
{
	auto m = Matrix(2, 2);
	m(0, 0) = 1;
	m(0, 1) = 1;
	m(1, 0) = 1;
	auto l = Matrix(2, 1);
	l(0, 0) = 0;
	l(1, 0) = 1;
	m.print();
	cout << endl;
	auto n = 10;
	while (n--) {
		m = m * m;
		m.print();
	}

	m.print();

	return 0;
}
