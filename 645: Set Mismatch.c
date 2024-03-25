/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findErrorNums(int* nums, int numsSize, int* returnSize) {
    int* ptr = (int*)malloc(2 * sizeof(int));

    for (int i = 0; i < numsSize; i++) {
        if (nums[abs(nums[i]) - 1] < 0) {
            *ptr = abs(nums[i]);
        } else {
            nums[abs(nums[i]) - 1] = nums[abs(nums[i]) - 1] * (-1);
        }
    }

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] > 0) {
            *(ptr + 1) = i + 1;
        }
    }

    *returnSize = 2;
    return ptr;
}
