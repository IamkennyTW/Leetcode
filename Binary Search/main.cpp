#include <iostream>
#include <vector>


class Solution 
{

public:
    int search(std::vector<int>& nums, int target) 
    {
        int start {0};
        int end = nums.size()-1;

        while( start <= end )
        {
            int mid = start + (end-start)/2 ;
            if (target == nums.at(mid)){return mid;}
            else if (target < nums.at(mid))
            {
                end = mid-1;
            }
            else
            {
                start = mid+1;
            }
        }
        return -1;
    }
};


int main ()
{
    Solution myresult;

    std::vector<int> vec {-1,0,3,5,9,12};
    int target {2};
    int result;
    result = myresult.search(vec,target);
    std::cout << result << std::endl;

    return 0;
}