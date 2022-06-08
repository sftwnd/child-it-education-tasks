#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int* arr = new int[n];
    for (int i=0; i<n; i++) {
        cin >> arr[i];
        arr[i] = arr[i]%3;
    }
    int val[] = {0, 1, 2, 0, 1};
    int cnt = 0;
    unsigned LIMIT = 1 << n;
    for (unsigned i=1; i< LIMIT; i++) {
        int x = 0;
        for(unsigned j=0, n=1; j<n; j++, n <<= 1) {
            if (n & i) x = val[arr[j]+x];
        }
        if (x == 0) cnt++;
    }
    cout << cnt << '\n';
}