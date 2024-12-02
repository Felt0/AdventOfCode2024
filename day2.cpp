#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <chrono>
#include <string>

int main()
{
    auto start = std::chrono::high_resolution_clock::now();

    std::ifstream i_file;
    std::string line;
    std::string safeness = "";

    int answer = 0;

    i_file.open("input.txt");

    while (std::getline(i_file, line))
    {
        std::vector<int> nums;
        std::stringstream ss(line);
        int num = 0;
        int temp = 0;
        safeness = "safe";

        while (ss >> num)
        {
            nums.push_back(num);
            int i = nums.size();

            if (i == 1) continue;

            int diff = nums[i - 2] - nums[i - 1];

            if ((abs(diff) > 3 || diff == 0) || ((temp > 0 && diff < 0) || (temp < 0 && diff > 0)))
            {
                safeness = "unsafe";
                break;
            }

            temp = diff;
        }

        if (safeness == "safe")
        {
            answer += 1;
        }
    }

    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);

    std::cout << "Answer: " << answer << std::endl;
    std::cout << "Time: " << duration.count() << " microseconds" << std::endl;
}
