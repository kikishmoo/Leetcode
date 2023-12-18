// 628. Maximum Product of Three Numbers

int maximumProduct(int* nums, int numsSize) {
    if (numsSize == 3){
        int product = 1;
        for(int i = 0;  i < 3; i++){
            product *= *nums;
            nums++;
        }
        return product;
    }

    int max1, max2, max3, temp;
    int min1, min2, min3;
    max1 = max2 = max3 = *nums;
    min1 = min2 = min3 = *nums;
    nums++;
    for(int i = 1;  i < numsSize; i++){
        // min
        if (*nums <= min1){
            temp = min1;
            min1 = *nums;
            if (temp <= min2){
                min3 = min2;
                min2 = temp;
            } else if (temp <= min3) {
                min3 = temp;
            }
        } else if (*nums <= min2){
            min3 = min2;
            min2 = *nums;
        } else if (*nums <= min3) {
            min3 = *nums;
        } else if (min2 == min1 && i <2){
            min3 = *nums;
            min2 = *nums;
        } else if (min2 == min3 && i <3) {
            min3 = *nums;
        }
        // max
        if (*nums >= max1){
            temp = max1;
            max1 = *nums;
            if (temp >= max2) {
                max3 = max2;
                max2 = temp;
            } else if (temp >= max3) {
                max3 = temp;
            }
        } else if (*nums >= max2) {
            max3 = max2;
            max2 = *nums;
        } else if (*nums >= max3) {
            max3 = *nums;
        } else if (max2 == max1 && i <2){
            max3 = *nums;
            max2 = *nums;
        } else if (max2 == max3 && i <3){
            max3 = *nums;
        }
        nums++;
    }

    int product1, product2, product3;

    product1 = max1 * max2 * max3;
    product2 = max1 * min1 * min2;
    product3 = min1 * min2 * min3;

    
    // printf("%d %d %d %d %d %d\n", max1, max2, max3, min1, min2, min3);
    // printf("%d %d %d", product1, product2, product3);
    if (product1 >= product2 && product1 >= product3){
        return product1;
    } else if (product2 >= product1 && product2 >= product3){
        return product2;
    } else {
        return product3;
    }
}
