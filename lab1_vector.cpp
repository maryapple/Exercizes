#include <iostream>
#include <vector>
#include <cstdlib>
#include <math.h>
#include <algorithm>
#include <time.h>

using namespace std;

int printArray (vector <int>v) 
{
    for (auto i = v.begin(); i != v.end(); i++)
        cout << *i << " ";
}

int main()
{
    int N = 0, amountMult3 = 0, amountOfEven = 0;
    int sumOfEven = 0;
    vector <int> v;
    cout << "Enter N: ";
    cin >> N;
    
    // 1. Заполнение массива случайными числами
    srand(time(0));
    for (int i = 0; i < N; i++)
        v.push_back((rand() % 201 - 100) );
    printArray(v);

    // 2. Находим, сколько элементов делится на 3 и сумму четных чисел
    for (auto i = v.begin(); i != v.end(); i++) 
    {
        if (! (abs(*i) % 3))
            amountMult3++;
        
        if (!(abs(*i)% 2))
            sumOfEven += *i;
    }
    cout << "\n2. Amount of numbers divisible by 3: " << amountMult3 << endl;
    
    // 3. Циклический сдвиг массива вправо
    // Запоминаем последний элемент
    int temp = v.back();
    for (auto i = v.end() - 1; i > v.begin(); i--)
        *i = *(i - 1);
    // Записываем в 0 элемент temp
    v.at(0) = temp;
    cout << "3. Right shift: " << endl;
    printArray(v);
    
    // 4. Добавим в конец массива элемент, равный сумме всех четных элементов массива
    cout << "\n4. Added sum of all even elements in the end: " << endl;
    v.push_back(sumOfEven);
    printArray(v);

    // 5. Поиск первого и последнего четных значений
    vector<int>::iterator first = v.begin() - 1, last = v.begin() - 2;
    for (auto i = v.begin(); i != v.end(); i++) 
        if (!(*i % 2)) 
        {
            if (first == v.begin() - 1)
                first = i;
            last = i;
        }
    cout << "\n5. First even element: " << *first << ", last even element: " << *last << endl;

    // Умножение на 2 все элементов до первого и после последнего четных элементов
    for (auto i = last; i != v.end(); i++) {
        *i *= 2;
    }

    for (auto i = first; i != v.begin() - 1; i--) {
        *i *= 2;
    }
    cout << "Array after multiplying by 2:" << endl;
    printArray(v);

    // 6. Если сумма элементов массива с индексами от i1 до i2 положительная, то удалим из массива все эти элементы
    int sumBetween = 0;
    int i1, i2;
    cout << "\n6. Enter i1 and i2:";
    cin >> i1 >> i2;
    for (auto i = v.begin() + i1; i != v.begin() + i2 + 1; i++) 
        sumBetween += *i;

    if (sumBetween > 0) 
        v.erase(v.begin() + i1, v.begin() + i2 + 1);
    cout << "Array after erasing elements between i1 and i2:" << endl;
    printArray(v);


    // 7. Отсортировать по убыванию часть массива от минимального и максимального элементов
    vector<int>::iterator minEl = v.begin(), maxEl = v.begin();

    for (auto i = v.begin(); i != v.end(); i++) 
    {
        if (*i < *minEl) 
            minEl = i;
        if (*i > *maxEl)
            maxEl = i;
    }
    cout << "\n7. Sort elements between min=" << *minEl << " and max=" << *maxEl << ": " << endl;
    auto minIndex = minEl;
    auto maxIndex = maxEl;
    if (maxEl < minEl) 
    {
        minIndex = maxEl;
        maxIndex = minEl;
    }
    bool swapp = true;
    while(swapp)
    {
        swapp = false;
        for (auto i = minIndex; i != maxIndex ; i++)
            if (*i < *(i + 1))
            {
                int tmp = *i;
                *i = *(i + 1);
                *(i + 1) = tmp;
                swapp = true;
            }
    }
    printArray(v);

    // 8. Подсчитать сумму элементов массива, кратных 3 или 4
    int sumOfDiv3_4 = 0;
    for (auto i = v.begin(); i != v.end(); i++) 
        if (!(*i % 3) || !(*i % 4)) 
            sumOfDiv3_4 += *i;
    cout << "\n8. Sum of elements divisible by 3 or 4: " << sumOfDiv3_4;
    
    return 0;
}
