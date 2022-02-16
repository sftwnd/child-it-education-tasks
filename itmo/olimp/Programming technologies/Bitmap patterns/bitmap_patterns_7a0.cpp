#include <iostream>
using namespace std;

const char HIT='1';
const char ASK='?';
const char LOOSE='0';

int read_mask(int size) {
    int mask = 0;
    for (int i=0; i<size; i++) {
        char ch;
        cin >> ch;
        while(ch != HIT && ch != ASK && ch != LOOSE) cin >> ch;
        int bit = ch == HIT ? 1 : 0;
        mask = (mask << 1) + bit;
    }
    return mask;
}

int main() {
    int p = sizeof(int);
    int a, b, n, m;
    cin >> a >> b >> n >> m;
    const int SIZE = a*b;
    const int MASKS = 1<<SIZE;
    int* masks_pattern = new int[n]; // mask# -> mask
    int* masks_cnt= new int[MASKS]; // mask -> cnt
    int active_masks = 0;
    int* masks_active = new int[MASKS]; // mask# -> mask
    for (int i=0; i<MASKS; i++) masks_cnt[i] = -1;
    for (int i=0; i<n; i++) {
        int mask = read_mask(SIZE);
        masks_pattern[i] = mask;
        if (masks_cnt[mask]) { // Если маска ещё не встречалась
            masks_cnt[mask] = 0; // Ставим счётчик в 0
            masks_active[active_masks++] = mask; // Добавляем активную маску
        }
    }
    for (int i=0; i<m; i++) {
        int value = read_mask(SIZE);
        for(int j=0; j<active_masks; j++) {
            int mask = masks_active[j];
            if ( (mask & value) == mask) {
                masks_cnt[mask]++;
            }
        }
    }
    for(int i=0; i<n; i++) {
        if(i>0) cout << ' ';
        cout << masks_cnt[masks_pattern[i]];
    }
    cout << '\n';
    return 0;
}