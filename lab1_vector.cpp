#include <iostream>
#include <vector>
#include <cstdlib>
#include <math.h>

using namespace std;

int main()
{
    srand(time(0));
    
    int N = 0, amountMult3 = 0;
    vector <float> v;
    
    cin >> N;
    
    for (int i = 0; i < N; i++) {
        v.push_back((rand() % 201 - 100) / 10.0);
    }
    
    for (auto i = v.begin(); i != v.end(); i++) {
        cout << *i << " ";
        //Проверка делится ли элемент массива на 3
        if (!fmod(abs(*i), 3)) {
            amountMult3++;
        }
    }
    cout << "\namountMult3: " << amountMult3 << endl;
    
    // Запоминаем последний элемент. 
    // Почему-то берется только целая часть
    int temp = v.back();  
    // cout << temp;
    
    for (auto i = v.end() - 1; i > v.begin(); i--) {
        // cout << *(i) << " " << *(i - 1) << endl;
        *i = *(i - 1);
    }
    
    // Записываем в 0 элемент temp
    v.at(0) = temp;
    
    for (auto i = v.begin(); i != v.end(); i++) {
        cout << *i << " ";
    }
    
    return 0;
}
