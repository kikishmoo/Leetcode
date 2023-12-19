// 1089. Duplicate Zeros
// 18 December 2023

// v1
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

// v2
void duplicateZeros(int* arr, int arrSize) {
    int* end = arr + arrSize -1;
    int* next = arr + 1;
    int temp_a = -1;
    int temp_n = -1;
    while (arr < end){
        if (*arr == 0){
            if (temp_n != -1){
                *arr = temp_n;
            }
            temp_n = *next;
            *next = 0;
            arr++;
            if (arr == end && temp_a != -1){
                *arr = temp_a;
                break;
            }
            next++;
            
            temp_a =temp_n;
            temp_n = *next;
            if  (*arr == 0 && *(arr-1) != 0){
                *next = 0;
                arr++;
                if (arr == end && temp_a != -1){
                    *arr = temp_a;
                    break;
                }
                next++;
            }
            *next = temp_a;
            arr++;
            if (arr == end && temp_a != -1){
                *arr = temp_a;
                break;
            }
            next++;
            
            
            
            
        } else {
            if (temp_n != -1){
                temp_a = temp_n;
                temp_n = *next;
                if  (*arr == 0 && *(arr-1) != 0){
                    *next = 0;
                    arr++;
                    if (arr == end && temp_a != -1){
                        *arr = temp_a;
                        break;
                    }
                    next++;
                }
                *next = temp_a;
                arr++;
                if (arr == end && temp_a != -1){
                    *arr = temp_a;
                    break;
                }
                next++;
            } else {
                arr++;
                if (arr == end && temp_a != -1){
                    *arr = temp_a;
                    break;
                }
                next++;
            }
            
        }
        
    }
}
