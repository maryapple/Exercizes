#include <iostream>
#include <vector>
#include <cstdlib>
#include <math.h>
<<<<<<< HEAD
#include <time.h>
=======
#include <algorithm>
>>>>>>> a6bff102b78a5253594bb12dc900a7f128b3a5d7

using namespace std;

int main()
{
    srand(time(0));
    
    int N = 0, amountMult3 = 0, amountOfEven = 0;
    // auto *i1, *i2;
    int sumOfEven = 0;
    vector <int> v;
        // auto i1 = v.begin(), i2 = v.begin();
    // cout << "v.begin(): " << &i1 << endl;
    cout << "Enter N: ";
    cin >> N;
    for (int i = 0; i < N; i++) {
        v.push_back((rand() % 201 - 100) );
    }

    auto first_even = find_if(v.begin(), v.end(), [](int i){ return i % 2 == 0; });
    auto le = find_if(v.rbegin(), v.rend(), [](int i){ return i % 2 == 0; });
    vector<int>::iterator last_even = le;
    cout << "first even: " << *first_even << " last: " << *last_even << endl;
    
    for (auto i = v.begin(); i != v.end(); i++) {
        cout << *i << " ";
        //Проверка делится ли элемент массива на 3
        if (! (abs(*i) % 3)) {
            amountMult3++;
        }
        
        // Суммируем четное число
        if (!(abs(*i)% 2)) {
/*            amountOfEven ++;
            if (amountOfEven == 1) {
                cout << "\nFIRST EVEN " << &i << endl;
                i1 = i;
                cout << "i1: " << &i1 << endl;
            }
            cout << "even!" << " "; */
            sumOfEven += *i;
        }
    }
    cout << "\namountMult3: " << amountMult3 << endl;
    
    // Запоминаем последний элемент
    int temp = v.back();
    
    for (auto i = v.end() - 1; i > v.begin(); i--) {
        // cout << *(i) << " " << *(i - 1) << endl;
        *i = *(i - 1);
    }
    
    // Записываем в 0 элемент temp
    v.at(0) = temp;
    
    cout << "Right shift: " << endl;
    
    for (auto i = v.begin(); i != v.end(); i++) {
        cout << *i << " ";
    }
    
    cout << "\nAdded sumOfEven: " << endl;
    v.push_back(sumOfEven);
    
    for (auto i = v.begin(); i != v.end(); i++) {
        cout << *i << " ";
    }
    cout << endl;

    // Умножим на 2 
    for (auto i = last_even; i != v.end(); i++ )
	{ 
		*i *= 2;
		cout << *i << " " ;
	}
    
    return 0;
}
