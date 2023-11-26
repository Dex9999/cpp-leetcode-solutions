class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int length = 0;
        //(nums1.size() > nums2.size()) ? length = nums1.size() : length = nums2.size();
        length = nums1.size() + nums2.size();
        int index1 = 0;
        int index2 = 0;
        int test = 0;
        std::vector<int> merge;

        for(int i = 0; i < length; ++i){
            if(index1 < nums1.size() && (index2 >= nums2.size() || nums1[index1] <= nums2[index2])){
                merge.push_back(nums1[index1]);
                index1++;
            } else {
                merge.push_back(nums2[index2]);
                index2++;
            }
        }

        //return length;
        // if even (two middles)
        if(merge.size()%2 == 0){
            return (merge[((merge.size())/2) - 1] + merge[merge.size()/2]) / 2.0;
        } else {
            return (merge[merge.size()/2]);
        }
    }
};

/*
Stats

Runtime: 20ms
Beats 83.04% of users with C++
Memory: 90.46 MB
Beats 24.93% of users with C++
*/
