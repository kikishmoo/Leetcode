// 977. Squares of a Sorted Array
// 12 December 2023

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortedSquares(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;
    int* result = (int*)malloc(numsSize * sizeof(int));
    int* copyStart = result;
    
    // square it
    for (int i = 0; i < numsSize; i++){
        *copyStart = pow(*nums, 2);
        //printf("%d ", *nums);
        // printf("%d ", *copyStart);
        // printf("%d ", copyStart);
        // printf("%d ", *result);
        // printf("%d ", result);
        nums++;
        copyStart++;
    }
    
    // sort it
    copyStart = result;
    int* end = result + numsSize - 1;
    for (int i = 0; i < numsSize; i++){
        int* copyEnd = end;
        while (copyStart != copyEnd){
            if (*copyStart <= *copyEnd){
                copyEnd--;
            } else {
                int temp = *copyStart;
                *copyStart = *copyEnd;
                *copyEnd = temp;
                copyEnd--;
            }   
        }
        copyStart++;
    }

    return result;
}
