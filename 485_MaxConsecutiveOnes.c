// 485. Max Consecutive Ones

int findMaxConsecutiveOnes(int* nums, int numsSize) {
    int* start = nums;
    int count = 0;
    int max_count = 0;
    for (int i = 0; i < numsSize; i++){
        if(*nums == 1){
            count++;
        }
        if(*nums == 0){
            if (count > max_count){
                max_count = count;
            }
            count = 0;
        }
        nums++;
    }
    if (count > max_count){
        max_count = count;
    }
    return max_count;
}
