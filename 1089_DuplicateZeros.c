// 1089. Duplicate Zeros
// 17 December 2023

void duplicateZeros(int* arr, int arrSize) {
    int* end = arr + arrSize -1;
    int* next = arr + 1;
    int temp_a = -1;
    int temp_n = -1;
    while (arr < end-1){
        if (*arr == 0){
            temp_n = *next;
            *next = 0;
            arr += 2;
            if (arr == end){
                *arr = temp_a;
                break;
            }
            next += 2;
            if (temp_n != -1){
                temp_a = *arr;
                *arr = temp_n;
                temp_n = *next;
            }
        } else {
            arr++;
            next++;
            if (temp_n != -1){
                *arr = temp_a;
                temp_a = *next;
                *next = temp_n;
                // arr++;
                // next++;
            }
            
        }
        
    }
}
