#include <iostream>
#include <math.h>
#include <limits>

class Solution {
public:
    int reverse(int x) 
    {
        int result {0};
        int largest_digits {0};
        int x_copy {0};
        if (x <  std::numeric_limits<int>::max() && x > std::numeric_limits<int>::lowest() && x != 0)
        {
            x_copy = abs(x);

            do
            {
                largest_digits++;
            } while(pow(10,largest_digits) < std::numeric_limits<int>::max() && x_copy/static_cast<int>(pow(10,largest_digits)) != 0);

            int counter {0};
            for (int i {largest_digits-1}; i > -1; i--)
            {
                int buffer {0};
                buffer = x_copy/static_cast<int>(pow(10,i));
                if ( result > INT_MAX - buffer * pow(10,counter))
                {
                    return 0;
                }
                result += (buffer * pow(10,counter));
                x_copy -= (buffer * pow(10,i));
                counter++;
            }
            return (x > 0) ?
                        result:-result;
        }
        return 0;
    }



    // other people solution
    int reversDigits(int num)
    {
        // Handling negative numbers
        bool negativeFlag = false;
        if (num < 0)
        {
            negativeFlag = true;
            num = -num ;
        }
    
        int prev_rev_num = 0, rev_num = 0;
        while (num != 0)
        {
            int curr_digit = num % 10;
    
            rev_num = (rev_num * 10) + curr_digit;
    
            // checking if the reverse overflowed or not.
            // The values of (rev_num - curr_digit)/10 and
            // prev_rev_num must be same if there was no
            // problem.
            if ((rev_num - curr_digit) / 10 != prev_rev_num)
            {
                std::cout << "WARNING OVERFLOWED!!!" << std::endl;
                return 0;
            }
    
            prev_rev_num = rev_num;
            num = num / 10;
        }
    
        return (negativeFlag == true) ?
                            -rev_num : rev_num;
    }
 
};



int main ()
{
    Solution myresult;

    int result {0};
    result = myresult.reverse(1000000045);

    std::cout << result << std::endl;

    result = myresult.reversDigits(1000000045);

    std::cout << result << std::endl;

    return 0;
}