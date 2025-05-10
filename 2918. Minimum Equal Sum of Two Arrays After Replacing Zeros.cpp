//medium


class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        int z1 = 0;
        int z2 = 0;
        long long int sum1 = 0;
        long long int sum2 = 0;
        for(int i=0;i<nums1.size();i++){
            if(nums1[i] == 0) z1++;
            sum1 += nums1[i];
        }
        for(int i=0;i<nums2.size();i++){
            if(nums2[i] == 0) z2++;
            sum2 += nums2[i];
        }
        if(z1==0 && z2==0 && sum1 != sum2) return -1;
        else if(z1==0){
            if(sum1 >= sum2+z2) return sum1;
            else return -1;
        }else if(z2 == 0){
            if(sum2 >= sum1+z1) return sum2;
            else return -1;
        }else{
            return max(sum1+z1,sum2+z2);
        }
        return -1;
    }
};