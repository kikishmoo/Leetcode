// 1295. Find Numbers with Even Number of Digits
// 12 December 2023

int findNumbers(int* nums, int numsSize) {
    int count = 0;
    int num;
    for (int i = 0; i < numsSize; i++){
        int digit = 1;
        num = *nums / 10;
        while (num){
            num = num / 10;
            digit++;
        }
        if (digit % 2 == 0){
            count++;
        }
        nums++;
    }
    return count;
}
