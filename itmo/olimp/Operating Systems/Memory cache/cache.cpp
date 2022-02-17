#include <iostream>
#include <string>

using namespace std;

const int CNT = 4;
const string EMPTY = "";
string addresses[CNT] = {EMPTY, EMPTY, EMPTY, EMPTY};
int counters[CNT] = {0, 0, 0, 0};

bool hit(string addr) {
    for (int i=0; i<CNT; i++) {
        if (addresses[i] == addr) {
            counters[i] = 0;
            return true;
        }
    }
    return false;
}

void inc() {
    for (int i=0; i<CNT; i++) {
        counters[i]++;
    }
}

int min_clean() {
    for (int i=0; i<CNT; i++) {
        if (addresses[i] == EMPTY) {
            return i;
        }
    }
    return -1;
}

int max_cnt() {
    int cnt = 0;
    for (int i=0; i<CNT; i++) {
        if (cnt < counters[i]) cnt = counters[i];
    }
    return cnt;
}

int to_change() {
    int cnt = max_cnt();
    for (int i=0; i<CNT; i++) {
        if (cnt == counters[i]) {
            return i;
        }
    }
    cerr << "OOPS!!!\n";
    return -1;
}

int main() {
    int counter = 0;
    // int lines = 0;

    string str;
    getline(cin, str);
    while(!str.empty()) {
        if (str[0] == '1') {
            // lines++;
            string addr = str.substr(1,3);
            if (hit(addr)) {
                counter++;
            } else {
                int id = min_clean();
                if (id == -1) id = to_change();
                addresses[id] = addr;
                counters[id] = 0;
            }
            inc();
        }
        getline(cin, str);
    }
    // cerr << lines << '\n';
    cout << "Hit to cache: " << counter << '\n';
    return 0;
}