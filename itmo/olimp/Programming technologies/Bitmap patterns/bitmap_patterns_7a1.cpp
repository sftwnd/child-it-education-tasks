#include <iostream>
using namespace std;

const char HIT='1';
const char ASK='?';
const char LOOSE='0';

char get_char() {
    char ch;
    cin >> ch;
    while(ch != HIT && ch != ASK && ch != LOOSE) cin >> ch;
    return ch;
}

int get_bit() {
    return get_char() == HIT ? 1 : 0;
}

int get_mask(int size) {
    int mask = 0;
    for (int i=0; i<size; i++) {
        mask = (mask << 1) + get_bit();
    }
    return mask;
}

struct List {
    List (int num, List* next) : num(num), next(next) {};
    int num;
    List *next;
};

struct Mask {
    Mask(int mask, Mask *next) : mask(mask), cnt(0), next(next), nums(nullptr) {};
    int mask;
    int cnt;
    Mask *next;
    List *nums;
};


int main() {
    int a, b, n, m;
    cin >> a >> b >> n >> m;
    int size = a*b;
    
    Mask* root = nullptr;

    {
        const int MASKS = 1<<size;
        Mask* *masks = new Mask* [MASKS];
        for(int i=0; i<MASKS; i++) masks[i] = nullptr;

        for(int i=0; i<n; i++) {
            int mask = get_mask(size);
            if (!masks[mask]) {
                root = new Mask(mask, root);
                masks[mask] = root;
            }
            masks[mask]->nums = new List(i, masks[mask]->nums);
        }
    }

    for(int i=0; i<m; i++) {
        int value = get_mask(size);
        for (Mask* mask = root; mask; mask = mask->next) {
            if ( (mask->mask & value) == mask->mask ) {
                mask->cnt++;
            }
        }
    }
    
    int* counts = new int[n];
    for(int i=0; i<n; i++) counts[i] = 0;
    
    for (Mask* mask = root; mask != nullptr;  mask = mask->next) {
        for(List* nums = mask->nums; nums; nums = nums -> next) {
            counts[nums->num] = mask->cnt;
        }
    }

    for(int i=0; i<n; i++) {
        if(i>0) cout << ' ';
        cout << counts[i];
    }
    cout << '\n';
    return 0;
}