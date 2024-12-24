/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* nextGreaterElement(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    int *ans = (int*)malloc(sizeof(int)*nums1Size);
    *returnSize = nums1Size;
    for(int i=0; i<nums1Size; i++){
        int j = 0;
        int returnVal = -1;
        while(nums1[i]!=nums2[j]){
            j++;
        }
        while(j<nums2Size){
            if (nums2[j]>nums1[i]){
                returnVal=nums2[j];
                break;  
            }
            j++;
        }
        ans[i]=returnVal;
    }
    return ans;
}