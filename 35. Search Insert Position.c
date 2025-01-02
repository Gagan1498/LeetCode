/****************************************************************************************
This code is implemented based on the targeted time complexity of O(logn)
****************************************************************************************/

int searchInsert(int* nums, int numsSize, int target) {
    int l =0;
    int r = numsSize-1;

    while(l<=r){
        int mid = l+ (r-l)/2;
        if(nums[mid] == target) return mid;
        if(nums[mid]>target) r=mid-1;
        if(nums[mid]<target) l=mid+1;
    }
    return l;
}
