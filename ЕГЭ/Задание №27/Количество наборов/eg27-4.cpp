#include <iostream>
using namespace std;

const int OST = 3; // простое число определяющее остаток.
int main() {
    int size;
    cin >> size;
    int* arr = new int[size];
    for (int i=0; i<size; i++) {
        int d;
        cin >> d;
        arr[i] = d % OST;
    }
    long cnt[] = {1, 0, 0};
    for (int i=0; i<size; i++) {
        long nw[] = {0, 0, 0};
        int a = arr[i];
        for (int j=0; j<OST; j++) {
            nw[j] = cnt[(OST+j-a)%OST];
        }
        for (int j=0; j<OST; j++) cnt[j] += nw[j];
    }
    cout << cnt[0] - 1 << '\n';
}