int removeDuplicates(int* nums, int numsSize) {
    if (numsSize == 0) {
        return 0; // No elements in the array
    }

    int writeIndex = 1; // Index to write the next unique element

    for (int i = 1; i < numsSize; i++) {
        if (nums[i] != nums[i - 1]) { // Found a unique element
            nums[writeIndex] = nums[i];
            writeIndex++;
        }
    }

    return writeIndex; // The number of unique elements
}
