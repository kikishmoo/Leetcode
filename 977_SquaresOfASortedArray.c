// 977. Squares of a Sorted Array

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortedSquares(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;
    int* result = (int*)malloc(numsSize * sizeof(int));
    int* copyReturn = result;
    
    // square it
    for (int i = 0; i < numsSize; i++){
        *copyReturn = pow(*nums, 2);
        //printf("%d ", *nums);
        // printf("%d ", *copyReturn);
        // printf("%d ", copyReturn);
        // printf("%d ", *result);
        // printf("%d ", result);
        nums++;
        copyReturn++;
    }
    
    // sort it
    
    
    return result;
}
