#include <iostream>
#include <fstream>
#include <string>
#include <limits>
#include <vector>
#include <algorithm>

std::ifstream f("input.txt");

int main()
{
  auto maxSum = std::numeric_limits<long long>::min();
  long long actualSum = 0;
  std::vector<long long> elves;

  while (!f.eof())
  {
    std::string line;
    std::getline(f, line);

    if (line == "")
    {
      elves.push_back(actualSum);
      actualSum = 0;   
      continue;
    }

    actualSum += std::stoll(line);
  }

  std::sort(elves.begin(), elves.end(), std::greater<int>());

  std::cout << "Part 1 : " << elves[0] << std::endl;
  std::cout << "Part 2 : " << elves[0] + elves[1] + elves[2] << std::endl;

  return 0;
}
