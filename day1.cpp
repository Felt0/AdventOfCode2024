#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

int main()
{
    std::vector<int> l_list, r_list;
    std::ifstream i_file;
    std::string line;

    int answer = 0;

    i_file.open("input.txt");

    while(std::getline(i_file, line))
    {
        int num1, num2;

        std::stringstream ss(line);

        while (ss >> num1 >> num2)
        {
            l_list.push_back(num1);
            r_list.push_back(num2);
        }
    }
    
    std::sort(l_list.begin(), l_list.end());
    std::sort(r_list.begin(), r_list.end());

    for (int i = 0; i < l_list.size(); i++)
    {
        answer += abs(l_list[i] - r_list[i]);
    }

    std::cout << answer << std::endl;
}
