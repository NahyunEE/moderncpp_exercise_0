#include <iostream>

typedef int _int;

template<typename T>
constexpr T GCD(T in1, T in2);

void solution();

int main() {
	solution();
}

void solution() {

	_int in01, in02;
	_int result;
	std::cin >> in01 >> in02;

	result = GCD<_int>(in01, in02);

	std::cout << "Result:" << result<<std::endl;
}

template<typename T>
constexpr T GCD(T in1, T in2) {

	T r = in1 % in2;
	if (r == 0) {
		return in2;
	}
	else {
		return GCD(in2, r);
	}


}