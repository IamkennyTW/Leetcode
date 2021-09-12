#include <iostream>
#include <vector>



class Solution 
{
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) 
    {
        std::vector<int> result {};
        for (size_t i{0}; i < nums.size(); i++)
        {
            for(size_t j{i+1}; j < nums.size(); j++)
            {
                std::cout << "Run once" << std::endl;
                if (nums[i]+nums[j] == target)
                {
                    result.push_back(nums[i]);
                    result.push_back(nums[j]);
                    return result;
                }
            }
        }
        return result;    
    }
};



int main ()
{
    Solution myresult;

    std::vector<int> vec {0,7,3,2,2,7,11,15};
    int target {9};
    std::vector<int> result;

    result = myresult.twoSum(vec,target);
    std::cout << result[0] << result[1] << std::endl;

    return 0;
}