/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */
class Solution {
public:
 
    int findInMountainArray(int target, MountainArray &mountainArr) {
//         int start = 0;
//         int n = mountainArr.length() ;
//         int end = n -1 ;
//         int mid ;
//         while(start < end){
//             mid = start + (end - start)/2;
//             if(mountainArr.get(mid) > mountainArr.get(mid+1)){
//                 start = mid + 1;
//             }else{
//                 end = mid;
//             }
//         }
//         int pivot = start;
//         if(target==mountainArr.get(pivot))    return pivot;
//         int a1 = binarySearch(0,pivot,mountainArr,target);
//         int a2 = binarySearch(pivot+1,n-1,mountainArr,target);
//         return max(a1,a2);
        
        
         int n = mountainArr.length();
    int low = 0;
    int high = n-1;
    
    // Finding the peak element.
    // https://leetcode.com/problems/peak-index-in-a-mountain-array/
    
    while(low<high){
        int mid = low + (high-low)/2;
        if(mountainArr.get(mid)>mountainArr.get(mid+1)){
            high = mid;
        }
        else{
            low = mid + 1;
        }
    }
    
    // Once we get the peak index apply BS on increasing part of array.
    low = 0;
    int peak = high+1;
    
    while(low<=high){
        int mid = low + (high-low)/2;
        int val = mountainArr.get(mid);
        if(val==target){
            return mid;
        }
        else if(val<target){
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }
    
    // If element is not found in first half search in second half
    low = peak;
    high = n-1;
    while(low<=high){
        int mid = low + (high-low)/2;
        int val = mountainArr.get(mid);
        if(val==target){
            return mid;
        }
        else if(val>target){
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }
    
    return -1;
        
        
    }
};