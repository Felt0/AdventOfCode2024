#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <chrono>
#include <string>

bool is_safe(std::vector<int> nums, bool remove)
{
    bool can_remove = remove;
    int temp = 0;

    for (int i = 1; i < nums.size(); i++)
    {
        int diff = nums[i - 1] - nums[i];

        if ((abs(diff) > 3 || diff == 0) || ((temp > 0 && diff < 0) || (temp < 0 && diff > 0)))
        {
            if (!can_remove) return false;
            
            can_remove = false;

            for (int o = 0; o < nums.size(); o++)
            {
                std::vector<int> vec_copy = nums;

                vec_copy.erase(vec_copy.begin() + o);
                
                if (is_safe(vec_copy, false)) return true;
            }

            return false;
        }

        temp = diff;
    }

    return true;
}

int main()
{
    auto start = std::chrono::high_resolution_clock::now();

    std::ifstream i_file;
    std::string line;
    
    int answer = 0;

    i_file.open("input.txt");

    while (std::getline(i_file, line))
    {
        std::vector<int> nums;
        std::stringstream ss(line);
        int num = 0;

        while (ss >> num) nums.push_back(num);

        if (is_safe(nums, true))
        {
            answer += 1;
        }
    }

    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);

    std::cout << "Answer: " << answer << std::endl;
    std::cout << "Time: " << duration.count() << " microseconds" << std::endl;
}
