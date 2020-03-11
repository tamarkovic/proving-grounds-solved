#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

bool isValidRowAndCol(const std::vector<std::vector<char>>& sudoku)
{
    std::vector<std::vector<char>> sudoku_numbers;

    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            if(sudoku[i][j] != '.')
            {
                sudoku_numbers.push_back({sudoku[i][j], static_cast<char>(i), static_cast<char>(j)});
            }
        }
    }

    std::sort(sudoku_numbers.begin(), sudoku_numbers.end());

    for(size_t i = 0; i < sudoku_numbers.size() - 1; i++)
    {
        size_t j = i + 1;

        while(j < sudoku_numbers.size() && sudoku_numbers[i][0] == sudoku_numbers[j][0])
        {
            if(sudoku_numbers[i][1] == sudoku_numbers[j][1] || sudoku_numbers[i][2] == sudoku_numbers[j][2])
            {
                // std::cout << sudoku_numbers[i][0] << ' '<< sudoku_numbers[j][0];
                return false;
            }
            ++j;
        }
    }
    return true;
}

bool isValidBox(const std::vector<std::vector<char>>& sudoku)
{
    for(int i = 1; i <= 7; i += 3)
    {
        for(int j = 1; j <= 7; j += 3)
        {
            std::unordered_set<char> number_container;

            for(int m = i - 1; m <= i + 1; m++)
            {
                for(int n = j - 1; n <= j + 1; n++)
                {
                    char number = sudoku[m][n];

                    if(number_container.find(number) != number_container.end())
                    {
                        return false;
                    }
                    if(number != '.')
                    {
                        number_container.insert(number);
                    }
                }
            }
        }
    }
    return true;
}

bool isValidSudoku(const std::vector<std::vector<char>>& sudoku)
{
    if(!isValidRowAndCol(sudoku))
    {
        return false;
    }
    
    return isValidBox(sudoku);
}