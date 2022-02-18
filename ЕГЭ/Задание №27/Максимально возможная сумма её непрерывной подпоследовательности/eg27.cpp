#include <iostream>
#include <algorithm>
using namespace std;

const int ELEMENTS = 30; // кратность набора
const int CHECK_FLAG = 1; // Нечётные
const int MAX_SUM = 2 * 1000000000; // Максимальная сумма
const int NO_SUM = MAX_SUM + 1; 

bool check_num(int num) {
    return (num > 0) && ((num & 1) == CHECK_FLAG); 
}

int main() {
    int len; cin >> len;
    long long sum = 0;
    int count = 0;

    long long min_sum[ELEMENTS]; for (int i=0; i<ELEMENTS; i++) min_sum[i] = NO_SUM;

    long long max_sum = 0;

    for (int i=0; i<len; i++) {
        int num; cin >> num;
        sum+=num;
        if (check_num(num)) count++;
        int ost = count % ELEMENTS;
        if (sum < min_sum[ost]) min_sum[ost] = sum;
        if (sum - min_sum[ost] > max_sum) max_sum = sum - min_sum[ost];
    }
    cout << max_sum << endl;
    return 0;
}