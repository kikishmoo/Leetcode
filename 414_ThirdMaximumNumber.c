// 414. Third Maximum Number

int thirdMax(int* nums, int numsSize) {
    int max1, max2, max3, temp;
    max1 = max2 = max3 = *nums;
    nums++;
    for(int i = 1;  i < numsSize; i++){
        // check max1
        if (*nums > max1){
            temp = max1;
            max1 = *nums;
            // check max2
            if (temp > max2){
                if (max2 > max3){
                    max3 = max2;
                } 
                max2 = temp;
            } else if (temp > max3 && temp != max2){
                max3 = temp;
            }
        // check max1
        } else if (*nums < max1) {
            if (max2 == max1){
                max2 = *nums;
            }
            // check max2
            if (*nums > max2){
                if (max2 > max3){
                    max3 = max2;
                } 
                max2 = *nums;
            } else if ((*nums > max3 && *nums != max2) || max3 == max2) {
                max3 = *nums;
            }   
        }
        // check max3 vs max2
        if (max3 > max2){
            temp = max3;
            max3 = max2;
            max2 = temp;
        } 
        nums++;
    }
    // return maximum if there is no third max
    if (max2 == max3 || max1 == max2){
        return max1;
    }
    // return third max
    return max3;
}
