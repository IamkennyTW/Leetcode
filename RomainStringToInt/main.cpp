#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
// Symbol       Value
// I             1
// V             5
// X             10
// L             50
// C             100
// D             500
// M             1000


class Solution 
{
public:
    int romanToInt(std::string s) 
    {   
        int sum {0};
        char pre_last_char {};
        size_t length {0};

        std::unordered_map<char, int> romanInt =
        {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };

        length = s.size();
        for (size_t i{0}; i < length; i++)
        {
            char &last_char = s.back();
            if (romanInt[last_char] >= romanInt[pre_last_char])
            {
                sum += romanInt[last_char];
            }
            else if (romanInt[last_char] < romanInt[pre_last_char])
            {
                sum -= romanInt[last_char];
            }
            
            pre_last_char = last_char;
            s.pop_back();
        }

        return sum;
    }
};


int main ()
{
    Solution myresult;

    std::string roman_Num {"CD"};

    int result;
    result = myresult.romanToInt(roman_Num);
    std::cout << result << std::endl;


    std::unordered_map<char, int> test =
    {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}
    };
    char n {};
    std::cout << test[n] << std::endl;
    return 0;
}