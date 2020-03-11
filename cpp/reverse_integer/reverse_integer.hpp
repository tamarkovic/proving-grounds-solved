#include <iostream>
#include <cmath>
#include <climits>

int32_t reverse(int32_t number)
{
    int64_t reverse_number = 0;

    while (number != 0)
    {
        reverse_number = number % 10 + reverse_number * 10;
        number /= 10;
    }

    if (reverse_number >= pow(-2, 31) && reverse_number <= pow(2, 31-1))
    {
        return static_cast<int32_t>(reverse_number);
    }
    else
    {
        return 0;
    }    
}