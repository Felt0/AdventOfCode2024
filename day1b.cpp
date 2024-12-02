#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <chrono>
#include <map>

int main()
{
    auto start = std::chrono::high_resolution_clock::now();

    std::vector<int> l_list, r_list;
    std::map<int, int> similarity_map;
    std::ifstream i_file;
    std::string line;

    int answer = 0;

    i_file.open("input.txt");

    while (std::getline(i_file, line))
    {
        int num1, num2;

        std::stringstream ss(line);

        while (ss >> num1 >> num2)
        {
            l_list.push_back(num1);
            r_list.push_back(num2);
        }
    }

    for (int i = 0; i < l_list.size(); i++)
    {
        for (int o = 0; o < r_list.size(); o++)
        {
            if (l_list[i] == r_list[o])
            {
                similarity_map[l_list[i]] += 1;
            }
        }
    }

    std::map<int, int>::iterator it = similarity_map.begin();

    while (it != similarity_map.end())
    {
        answer += it->first * it->second;
        ++it;
    }

    auto stop = std::chrono::high_resolution_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);

    std::cout << "Answer: " << answer << std::endl;
    std::cout << "Time: " << duration.count() << " microseconds" << std::endl;
}