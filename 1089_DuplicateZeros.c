// 1089. Duplicate Zeros
// 17 December 2023

void duplicateZeros(int* arr, int arrSize) {
    int* end = arr + arrSize -1;
    int* next = arr + 1;
    int temp_a = -1;
    int temp_n = -1;
    while (arr < end){
        if (*arr == 0){
            temp_n = *next;
            *next = 0;
            if (temp_a != -1){
                *arr = temp_a;
                temp_a = *next;
                
                
            }
            arr ++;
            if (arr == end){
                *arr = temp_n;
                break;
            }
            next ++;
            temp_a = *next;
            *next = temp_n;
            arr++;
            next++;
        } else if (*next == 0){
            arr++;
            next++;
        } else {
            arr++;
            if (arr == end){
                *arr = temp_a;
                break;
            }
            next++;
            if (temp_n != -1){
                temp_n = *arr;
                *arr = temp_a;
                temp_a = *next;
                *next = temp_n;
            }
            
        }
        
    }
}
