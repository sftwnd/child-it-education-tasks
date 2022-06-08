#include <iostream>
using namespace std;

const int OST = 3; // простое число определяющее остаток.
int main() {
    int size;
    cin >> size;
    unsigned long long* cnt = new unsigned long long[OST];
    for (int i=0; i<size; i++) cnt[i] = 0;
    cnt[0] = 1;
    for (int i=0; i<size; i++) {
        unsigned long long* nw = new unsigned long long[OST];
        int a; cin >> a; a = a % OST;
        for (int j=0; j<OST; j++) {
            nw[j] = cnt[(OST+j-a)%OST];
        }
        for (int j=0; j<OST; j++) cnt[j] += nw[j];
    }
    cout << cnt[0] - 1 << '\n';
}
