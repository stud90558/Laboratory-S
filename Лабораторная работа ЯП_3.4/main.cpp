#include <iostream>
#include "Summator.h"
#include "SquareSummator.h"
#include "CubeSummator.h"
using namespace std;

// вспомогательные функции для проверок (формулы)
long long sum_n(long long N) {
    return N * (N + 1) / 2;
}
long long sum_sq_formula(long long N) {
    return N * (N + 1) * (2 * N + 1) / 6;
}
long long sum_cu_formula(long long N) {
    long long s = sum_n(N);
    return s * s;
}

int main() {
    long long N = 10; // пример, можно менять

    // раннее связывание (объекты конкретных типов)
    Summator base;
    SquareSummator sq;
    CubeSummator cu;

    cout << "Base sum (1..N): " << base.sum(N) << " (formula: " << sum_n(N) << ")\n";
    cout << "Squares sum (1..N): " << sq.sum(N) << " (formula: " << sum_sq_formula(N) << ")\n";
    cout << "Cubes sum (1..N): " << cu.sum(N) << " (formula: " << sum_cu_formula(N) << ")\n";

    // позднее связывание (через указатели/ссылки на базовый класс)
    const Summator* p;

    p = &sq;
    cout << "Polymorphic via pointer -> squares: " << p->sum(N) << "\n";

    p = &cu;
    cout << "Polymorphic via pointer -> cubes: " << p->sum(N) << "\n";

    return 0;
}
