#include <iostream>

typedef const int _int;

template<typename T>
constexpr T GCD(T in1, T in2);

template<typename T>
constexpr T GCD(T in1, T in2) {
    if (in2 == 0) {
        return in1;
    }
    else {
        T r = in1 % in2;
        return GCD(in2, r);
    }
}

void solution();

int main() {
    solution();
}

void solution() {
    constexpr _int result = GCD<_int>(100, 150);

    static_assert(result == 50, "Error: GCD is not 50");
}


