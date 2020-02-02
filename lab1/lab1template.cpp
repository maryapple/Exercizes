#include <iostream>
#include <vector>
#include <cstdlib>
#include <math.h>
#include <algorithm>
#include <time.h>

using namespace std;

int main() {

    srand(time(0));
    
    int N = 0;
    vector <int> v;
    cout << "Enter N: ";
    cin >> N;
    for (int i = 0; i < N; i++) {
        v.push_back((rand() % 201 - 100) );
    }
    cout << "\nSource array:" << endl;
    for (auto i = v.begin(); i != v.end(); i++) {
        cout << *i << " ";
    }
    cout << endl;

    int amount = count_if(v.begin(), v.end(), [](int x) { return (!(x % 2)); });
    cout << "\n" << amount;
    return 0;
}