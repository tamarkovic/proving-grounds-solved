#include <iostream>
#include <vector>

std::vector<unsigned int> twoSum(std::vector<int> int_array, int sum)
{
    std::vector<unsigned int> indices;

    for(unsigned int i = 0; i < int_array.size(); i++)
    {
        for(unsigned int j = i + 1; j < int_array.size() - 1; j++)
        {
            if(int_array[i] + int_array[j] == sum)
            {
                indices.push_back(i);
                indices.push_back(j);
                break;
            }
        }
    }
    return indices;
}