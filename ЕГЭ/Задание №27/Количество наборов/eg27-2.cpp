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
        if (d % 3 == 0) n++;
        else arr[m++] = d %3;
    }
    long N = 1 << n; // Кол-во вариантов получения %3=0 только из %3 множества (включая пустое)
    long cnt[] = { N, 0, 0 };
    for (int i=0; i<m; i++) {
        long nw[] = {0, 0, 0};
        int a = arr[i];
        if (a == 1) {
            nw[0] = cnt[2];
            nw[1] = cnt[0];
            nw[2] = cnt[1];
        } else {
            nw[0] = cnt[1];
            nw[1] = cnt[2];
            nw[2] = cnt[0];
        }
        for (int j=0; j<3; j++) cnt[j] += nw[j];
    }
    long CNT = cnt[0] - 1;
    cout << CNT << '\n';
}