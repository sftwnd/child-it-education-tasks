#include <iostream>
using namespace std;

const int DEVIDER = 43;

int main() {
    int len; cin >> len;
    int NOIDX = len+1;
    
    long long summ = 0;
    long long max_summ = 0;
    int min_len = 0;
    
    int ost_idx[DEVIDER]; for (int i=0; i<DEVIDER; i++) { ost_idx[i] = NOIDX; }
    long long ost_summ[DEVIDER]; for(int i=0; i<DEVIDER; i++) { ost_summ[i] = 0; }
    
    ost_idx[0] = -1;
    ost_summ[0] = 0;
    
    for (int i=0; i<len; i++) {
        int num; cin >> num; // Зачитываем номер
        summ += num; // Вычисляем сумму
        int ost = summ % DEVIDER; // Берём остаток
        if (ost_idx[ost] == NOIDX) {
            ost_idx[ost] = i;
            ost_summ[ost] = summ;
        } else if ( // Если вес цепочки равен маскимальному
             summ - ost_summ[ost] == max_summ &&
             // И её для меньше найденой
             min_len > i - ost_idx[ost]
        ) {
            min_len = i - ost_idx[ost]; // Определяем минимальную длину цепочки
        }
        // Если вес цепочки больше маскимального
        else if (summ - ost_summ[ost] > max_summ) {
            max_summ = summ - ost_summ[ost]; // Запоминаем цепочку
            min_len = i - ost_idx[ost]; // Определяем минимальную длину цепочки
        } else {
        }
        
    }
    cout << min_len << '\n';
    return 0;
} 