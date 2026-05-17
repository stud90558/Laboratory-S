#include "Summator.h"

// по умолчанию — тождественное преобразование
long long Summator::transform(long long i) const {
    return i;
}

// суммирование значений transform для 1..N
long long Summator::sum(long long N) const {
    if (N <= 0) return 0;
    long long total = 0;
    for (long long i = 1; i <= N; ++i) {
        total += transform(i);
    }
    return total;
}
