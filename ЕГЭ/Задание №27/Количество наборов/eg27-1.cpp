#include <iostream>
using namespace std;

int main() {
    int size;
    cin >> size;
    int* arr = new int[size];
    int n = 0; // Кратно 3
    int m = 0; // Не кратно 3
    for (int i=0; i<size; i++) {
        int d;
        cin >> d;
        if (d % 3) arr[m++] = d %3;
        else n++;
    }
    unsigned long cnt = 0; // Кол-во вариантов не пустых множеств без элементов, делящихся на 3
    unsigned long LIMIT = 1 << m;
    for (unsigned long i=1; i< LIMIT; i++) {
        int x = 0;
        long mask = 1;
        for(unsigned long j=0; j<m; j++, mask <<= 1) {
            if (mask & i) x += arr[j];
        }
        if (x%3 == 0) cnt++;
    }
    unsigned long  N = 1 << n; // Количество вариантов из элементов делящихся на 3, включая пустое множество
    cout << cnt * N + N - 1 << '\n'; // кол-во вариантов * кол-во N + cnt * N - пустое множество
}