#include <iostream>
using namespace std;

int main() {
    int OST = 3; // простое число определяющее остаток.
    int size;
    cin >> size;
    int* arr = new int[size];
    int n = 0; // Кратно OST
    int m = 0; // Не кратно OST
    for (int i=0; i<size; i++) {
        int d;
        cin >> d;
        if (d % OST) arr[m++] = d % OST;
        else n++;
    }
    long N = 1 << n; // Кол-во вариантов получения %OST=0 только из %OST множества (включая пустое)
    long* cnt = new long[size];
    for (int i=0; i<size; i++) cnt[i] = 0;
    cnt[0] = 1;
    for (int i=0; i<m; i++) {
        long* nw = new long[size];
        int a = arr[i];
        for (int j=0; j<OST; j++) {
            nw[j] = cnt[(OST+j-a)%OST];
        }
        for (int j=0; j<OST; j++) cnt[j] += nw[j];
    }
    cout << cnt[0] - 1 << '\n';
}
