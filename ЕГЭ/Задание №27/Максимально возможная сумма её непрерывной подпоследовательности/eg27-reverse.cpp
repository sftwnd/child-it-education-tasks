#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int len; cin >> len; cout << len << endl;
    short* buff = new short[len];
    for (int i=1; i<=len; i++) {
        cin >> buff[len-i];
    }
    for (int i=0; i<len; i++) {
        cout << buff[i] << '\n';
    }
    return 0;
}