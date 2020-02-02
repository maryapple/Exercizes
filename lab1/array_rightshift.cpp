#include <iostream>

using namespace std;

int main()
{
    int size = 5;
    int array[size] = {1, 2, 3, 4, 5};
    // посл элемент массива
    int temp = array[size - 1];
    cout << "temp: " << temp << endl;
    
    while ( size > 0 ) {
        array[--size] = array[size-1];
    }
    array[0] = temp;
    return 0;
}