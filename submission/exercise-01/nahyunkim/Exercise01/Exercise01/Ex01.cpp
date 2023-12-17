#include <iostream>
#include <list>
#include <exception>
#include <algorithm>

using namespace std;

typedef int _int;

template <typename T>
void def(_int num);

template <typename T>
void confirmList();

template <typename T>
void solution();

int main() {
    solution<_int>();
}

list<_int> mylist;


template <typename T>
void def(_int num) {
    for (size_t i = 0; i < num; ++i) {
        _int temp;

        try {
            cin >> temp;

            if (cin.fail()) {
                cerr << "Error from Insert Number to List" << endl;
                throw exception();  
            }
            else {
                mylist.push_back(temp);   
            }
        }
        catch (exception& e) {
            exit(0);
        }

    }
   confirmList<_int>();
   
}

template <typename T>
void confirmList() {
    //Confirm List
    typename list<T>::iterator it = mylist.begin();
    size_t i = 0;
    for (it = mylist.begin(); it != mylist.end(); it++, i++) {
        cout << i << "¹øÂ° : " << *it << endl;
    }
}

template <typename T>
void solution() {
    _int num;
    _int in01, in02;
    _int min_num, max_num;

    try {
        cin >> num;
        if ((num < 0) || (num > 10)) {
            cerr << "Insert Number is big" << endl;
            throw exception();  
        }
        else if (cin.fail()) {
            cerr << "cin error" << endl;
            throw exception(); 
        }
        else {
            def<_int>(num);  
        }
    }
    catch (exception& e) {
        exit(0);
    }

    
    try {
        cin >> in01;
        if (cin.fail()) { throw exception(); }
        else if(in01 > mylist.size()) { 
            std::cerr << "Number is bigger then list size"<<endl;
            throw exception(); }
       
        cin >> in02;
        if (cin.fail()) { throw exception(); }
        else if (in01 > mylist.size()) {
            std::cerr << "Number is bigger then list size" << endl;
            throw exception(); }
               
    }
    catch (exception& e) {
        std::cerr << "Error from Insert Min, Max num";
    }

    min_num = min(in01, in02);
    max_num = max(in01, in02);

    cout << "Min number: " << min_num << endl;
    cout << "Max number: " << max_num << endl;

    try {
        typename list<T>::iterator start = std::next(mylist.begin(), min_num);
        typename list<T>::iterator end = std::next(mylist.begin(), max_num + 1);
        mylist.erase(start, end);
    }
    catch (exception& e) {
        std::cerr << "Error to erase list" << endl;
    }
  
    confirmList<_int>();




}
