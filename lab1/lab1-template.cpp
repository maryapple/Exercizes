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

bool isEven(int i)
{
    if (i % 2 == 0)
        return true;
    else
        return false;
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
    cout << "3. Right shift:" << endl;
    printArray(v);

    // 4. Добавить в конец массива элемент, равный сумме всех четных элементов массива
    for_each(v.begin(), v.end(), [&](int n) {
        if (isEven(n))
            sumOfEven += n;
    });
    cout << "\n4. Added sum=" << sumOfEven << " of all even elements in the end: " << endl;
    v.push_back(sumOfEven);
    printArray(v);

    // 5. Умножить на 2 все элементы до первого четного и после последнего четного элементов
    vector<int>::iterator first = find_if(v.begin(), v.end(), isEven);
    vector<int>::iterator last = v.begin() - 2;
    for (auto i = v.begin(); i != v.end(); i++)
        if (!(*i % 2))
            last = i;
    cout << "\nLast even=" << *last << " first even=" << *first << endl;
    for_each(last, v.end(), [](int &n) { n *= 2; } );
    for_each(v.begin(), first, [](int &n) { n *= 2; });

    cout << "\nArray after multiplying by 2:" << endl;
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
    sort(minIndex, maxIndex + 1, greater<int>());
    printArray(v);

    // 8. Подсчитать сумму элементов массива, кратных 3 или 4
    int sumOfDiv3_4 = 0;
    for_each(v.begin(), v.end(), [&](int i) { if (!(i % 3) || !(i % 4)) sumOfDiv3_4 += i;});
    cout << "\n8. Sum of elements divisible by 3 or 4: " << sumOfDiv3_4;

    return 0;
}