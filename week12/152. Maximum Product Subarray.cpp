//TC: O(n)
//MC: O(1)

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxProd = nums[0], tempMaxProd = nums[0], tempMinProd = nums[0];

        for(int i = 1; i < nums.size(); i++){
            if(nums[i] < 0) swap(tempMaxProd, tempMinProd);
            tempMaxProd = max(nums[i], tempMaxProd*nums[i]);
            tempMinProd = min(nums[i], tempMinProd*nums[i]);

            maxProd = max(maxProd, tempMaxProd);
        }

        return maxProd;
    }
};
