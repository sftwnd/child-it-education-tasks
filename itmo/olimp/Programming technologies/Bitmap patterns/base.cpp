#include <iostream>
using namespace std;

// 10 минут

const char HIT = '1';
const char ASK = '?';
const char LOOSE = '0'; 

char read_char() {
    char ch;
    cin >> ch;
    while(ch != HIT && ch != ASK && ch != LOOSE) cin >> ch;
    return ch;
}

int read_bit() {
    return read_char() == HIT ? 1 : 0;
}

int read_mask(int size) {
    int result = 0;
    for (int i=0; i<size; i++) {
        result = (result << 1) + read_bit();
    }
    return result;
}

int main() {
    int a, b, n, m;
    cin >> a >> b >> n >> m;
    int size = a*b; 
    for (int i=0; i<n; i++) {
        int mask = read_mask(size);
    }
    for (int i=0; i<m; i++) {
        int mask = read_mask(size);
    }
    int* counts = new int[m];
    for (int i=0; i<n; i++) {
        counts[i] = 0;
    }

    for (int i=0; i<n; i++) {
        if (i>0) cout << ' ';
        cout << counts[i];
    }
    cout << '\n';

}
