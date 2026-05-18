#include <iostream>
#include <string>
#include <sstream>
#include "Matrix.h"

using namespace std;

int main() {
    try {
        Matrix<int> a(2, 3);
        Matrix<int> b(2, 3);
        for (size_t i = 0; i < a.Rows(); ++i)
            for (size_t j = 0; j < a.Cols(); ++j) {
                a.Set(i, j, static_cast<int>(i * 10 + j));
                b.Set(i, j, static_cast<int>(1 + i + j));
            }

        cout << "Matrix a (int):\n" << a;
        cout << "Matrix b (int):\n" << b;

        Matrix<int> c = a + b;
        cout << "a + b:\n" << c;

        Matrix<int> m1(2, 3);
        Matrix<int> m2(3, 2);
        int val = 1;
        for (size_t i = 0; i < m1.Rows(); ++i)
            for (size_t j = 0; j < m1.Cols(); ++j)
                m1.Set(i, j, val++);

        val = 1;
        for (size_t i = 0; i < m2.Rows(); ++i)
            for (size_t j = 0; j < m2.Cols(); ++j)
                m2.Set(i, j, val++);

        cout << "m1:\n" << m1;
        cout << "m2:\n" << m2;
        cout << "m1 * m2:\n" << (m1 * m2);

        Matrix<string> sa(2, 2);
        Matrix<string> sb(2, 2);
        sa.Set(0, 0, "a"); sa.Set(0, 1, "b");
        sa.Set(1, 0, "c"); sa.Set(1, 1, "d");
        sb.Set(0, 0, "1"); sb.Set(0, 1, "2");
        sb.Set(1, 0, "3"); sb.Set(1, 1, "4");

        cout << "sa:\n" << sa;
        cout << "sb:\n" << sb;

        Matrix<string> sc = sa + sb;
        cout << "sa + sb (concatenation):\n" << sc;

        istringstream iss("2 2 x y z w");
        Matrix<string> din;
        iss >> din;
        cout << "Read matrix (from stringstream):\n" << din;

    }
    catch (const exception& ex) {
        cerr << "Exception: " << ex.what() << '\n';
        return 1;
    }
    return 0;
}
