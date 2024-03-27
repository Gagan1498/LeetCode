/* Brute-force solution */

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int flag=0;
    *returnSize = 2;
    int *ptr = (int *)malloc(2*sizeof(int));

    for (int i=0;i<numsSize;i++){
        for(int j=i+1;j<numsSize;j++){
            if(nums[i] + nums[j] == target){
                ptr[0] = i;
                ptr[1] = j;
                return ptr;
            }
        }
    }
return ptr;
}

/* Note: If using break; statements in nested loops, remember that break statement only breaks you out of the inner loop, not all the nested loops */
