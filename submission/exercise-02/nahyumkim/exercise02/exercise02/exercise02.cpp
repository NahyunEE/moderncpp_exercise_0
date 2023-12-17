#include <iostream>
#include <vector>
#include <algorithm>
#include <exception>

typedef int _int;

template<typename T>
void configVector(const std::vector<T>& vec);

template <typename T>
void makeVector(std::vector<T>& vec);

template <typename T>
void findVector(const std::vector<T>& vec, T num);

int main() {
    std::vector<_int> vecInt;
    makeVector(vecInt);

    _int num;
    std::cin >> num;

    findVector(vecInt, num);

    return 0;
}

template <typename T>
void configVector(const std::vector<T>& vec) {
    for (size_t i = 0; i < vec.size(); ++i) {
        std::cout << i << "번째: " << vec[i] << std::endl;
    }
}

template <typename T>
void makeVector(std::vector<T>& vec) {
    try {
        for (size_t i = 0; i < 10; ++i) {
            T temp;
            std::cin >> temp;
            vec.push_back(temp);
        }
        configVector(vec);
    }
    catch (std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

template <typename T>
void findVector(const std::vector<T>& vec, T num) {
    try {
        auto cnum = std::find(vec.begin(), vec.end(), num);

        if (cnum != vec.end()) {
            size_t index = std::distance(vec.begin(), cnum);
            std::cout << "Index of " << num << ": " << index << std::endl;
        }
        else {
            auto it = std::upper_bound(vec.begin(), vec.end(), num);

            if (it != vec.end()) {
                std::cout << "가장 가까운 수: " << *it << std::endl;
            }
            else {
                std::cout << "-1" << std::endl;
            }
        }
    }
    catch (std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}
