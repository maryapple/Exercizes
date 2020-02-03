#include <iostream>
#include <vector>
#include <cstdlib>
#include <math.h>
#include <algorithm>
#include <time.h>
#include <numeric>

using namespace std;

int printArray (vector <int>v) 
{
    for (auto i = v.begin(); i != v.end(); i++)
        cout << *i << " ";
}

int main() {
    int N = 0, amountMult3 = 0, amountOfEven = 0;
    int sumOfEven = 0;
    vector <int> v;
    cout << "Enter N: ";
    cin >> N;
    
    // 1. Заполнение массива случайными числами
    srand(time(0));
    for (int i = 0; i < N; i++)
        v.push_back((rand() % 201 - 100) );
    cout << "\nSource array:" << endl;
    printArray(v);

    // 2. Находим, сколько элементов делится на 3
    amountMult3 = count_if(v.begin(), v.end(), [](int x) { return (!(x % 3)); });
    cout << "\n2. Amount of numbers divisible by 3: " << amountMult3 << endl;

    // 3. Циклический сдвиг массива вправо
    rotate(v.begin(), v.end() - 1, v.end());
    printArray(v);

    // 4. Добавить в конец массива элемент, равный сумме всех четных элементов массива
    // Это не работает
    // sumOfEven = accumulate(v.begin(), v.end(), find_if(v.begin(), v.end(), [](int x) { return (!(x % 2)); }););
    // for_each(v.begin(), v.end(), [](int &n){ n++; }) {
    //     if (!(n % 2))
    //         sumOfEven += n;
    // });
    // тут нет шаблонной функции
    for (auto i = v.begin(); i != v.end(); i++) 
    {
        if (!(abs(*i)% 2))
            sumOfEven += *i;
    }
    cout << "\n4. Added sum of all even elements in the end: " << endl;
    v.push_back(sumOfEven);
    printArray(v);

    // 5. Умножить на 2 все элементы до первого четного и после последнего четного элементов

    return 0;
}