#include <iostream>
using namespace std;

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

struct Num {
    Num(int num, Num* next) : num(num), next(next) {};
    int num;
    Num* next;
};

struct Bit {
    Bit* bits[2];
    int cnt;
    Num* nums;
};

Bit* create_bit(int size) {
    if (size >=0) {
        Bit* bit = new Bit();
        bit->nums = nullptr;
        bit->cnt = 0;
        bit->bits[0] = create_bit(size-1);
        bit->bits[1] = create_bit(size-1);
        return bit;
    }
    return nullptr;
}

void apply_mask(Bit *bit, int mask, int num) {
    if (bit) {
        if (mask == 0) {
            bit->nums = new Num(num, bit->nums);
        } else {
            apply_mask(bit->bits[mask&1], mask >> 1, num);   
        }
    }
}

void check_masks(Bit* bit, int value) {
    if (bit) {
        bit->cnt++;
        if (value > 0) {
            if (value & 1) check_masks(bit->bits[1], value >> 1);
            check_masks(bit->bits[0], value >> 1);
        }
    }
}

void save_count(Num* num, int cnt, int* counts) {
    if (num) {
        counts[num->num] = cnt;
        save_count(num->next, cnt, counts);
    }
}

void save_counts(Bit* bit, int* counts) {
    if (bit) {
        save_count(bit->nums, bit->cnt, counts);
        for(int i=0; i<2; i++) {
            save_counts(bit->bits[i], counts);
        }
    }
}

void print_bits(Bit* bit);

int main() {
    int a, b, n, m;
    cin >> a >> b >> n >> m;
    int size = a*b; 
    Bit* root = create_bit(size);
    for (int i=0; i<n; i++) {
        int mask = read_mask(size);
        apply_mask(root, mask, i);
    }
    // print_bits(root);
    for (int i=0; i<m; i++) {
        int mask = read_mask(size);
        check_masks(root, mask);
    }
    // print_bits(root);
    int* counts = new int[m];
    for (int i=0; i<n; i++) counts[i] = 0;
    //print_bits(root);
    save_counts(root, counts);
    for (int i=0; i<n; i++) {
        if (i>0) cout << ' ';
        cout << counts[i];
    }
    cout << '\n';
}

void print_nums(Num* nums) {
    if (nums) {
        cerr << " #" << nums->num;
        print_nums(nums->next); 
    }
}

const string OFFSET = "    ";

void print_bit(Bit* bit, string offset) {
    cerr << " cnt: " << bit->cnt;
    cerr << " NUMS: {";
    print_nums(bit->nums);
    cerr << "}";
    cerr << '\n';
    for (int i=0; i<2; i++) {
        if (bit->bits[i]) {
            cerr << offset << i;
            print_bit(bit->bits[i], offset+OFFSET);
        }
    }
}

void print_bits(Bit* bit) {
    if (bit) {
        cerr << '.';
        print_bit(bit, OFFSET);
    }
}

