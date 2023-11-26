#include <iostream>
#include <vector>
#include <string>
#include <functional>
std::vector<std::string> letterCombinations(const std::string &digits)
{
    std::vector<std::string> result;
    if (digits.empty())
    {
        return result;
    }
    const std::vector<std::string> digitMap = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    std::function<void(int, std::string)> generateCombinations = [&](int index, std::string current)
    {
        if (index == digits.length())
        {
            result.push_back(current);
            return;
        }

        int digit = digits[index] - '2'; // Convert char to integer and adjust index
        for (char letter : digitMap[digit])
        {
            generateCombinations(index + 1, current + letter);
        }
    };
    generateCombinations(0, "");
    return result;
}
int main()
{
    std::string input;
    std::cin >> input;
    std::vector<std::string> output = letterCombinations(input);
    if (!output.empty())
    {
        std::cout << "Letter Combinations:";
        for (const std::string &combination : output)
        {
            std::cout << " " << combination;
        }
        std::cout << std::endl;
    }
    else
    {
        std::cout << "No letter combinations for the given input." << std::endl;
    }
    return 0;
}