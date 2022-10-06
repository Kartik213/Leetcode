class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int>s;
        vector<int>res;
        if(nums1.size() >= nums2.size()){
            for(int i=0;i<nums1.size();i++){
                s.insert(nums1[i]);
            }
            for(int i=0;i<nums2.size();i++){
                if(s.find(nums2[i]) != s.end()){
                    res.push_back(nums2[i]);
                    s.erase(nums2[i]);
                }
            }
        }
        else{
            for(int i=0;i<nums2.size();i++){
                s.insert(nums2[i]);
            }
            for(int i=0;i<nums1.size();i++){
                if(s.find(nums1[i]) != s.end()){
                    res.push_back(nums1[i]);
                    s.erase(nums1[i]);
                }
            }
        }
        return res;
    }
};