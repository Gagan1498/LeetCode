/************************************************************************************************************************************************************************************************************************************************************
The idea is to swap val with numbers that are not equal to val. You loop through the nums array and check each element. 
Keep a pointer k to track the index where the last val was found. If the current element is equal to val, you simply leave it and move to the next element. However, if you find a number that is not equal to val, you swap it with the element at index k.
This way, the non-val elements are moved to the front of the array, and the rest of the array can be ignored. 
*************************************************************************************************************************************************************************************************************************************************************/

int removeElement(int* nums, int numsSize, int val) {
    int k = 0; // Pointer for the position of elements not equal to val
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] != val) {  // If the current element is NOT val
            nums[k] = nums[i]; // Move it to the position tracked by k
            k++;               // Increment k to track the next position
        }
    }
    return k; // Return the count of elements not equal to val
}
