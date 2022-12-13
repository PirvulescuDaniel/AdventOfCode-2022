#include <iostream>
#include <fstream>
#include <string>
#include <limits>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

std::ifstream f("input.txt");

std::vector< std::pair<std::pair<int, int>, std::pair<int, int>> > pairs;

std::pair<int, int> parsePair(const std::string& aString)
{
  auto separatorIndex = aString.find('-');
  auto first =  std::stoi( aString.substr(0, separatorIndex) );
  auto second = std::stoi(aString.substr(separatorIndex + 1, std::string::npos));
  return std::make_pair(first, second);
}

void parseInput(const std::string& aString)
{
  auto separatorIndex = aString.find(',');
  std::string firstPair = aString.substr(0, separatorIndex);
  std::string secondPair = aString.substr(separatorIndex + 1, std::string::npos);

  auto actualPair = std::make_pair(parsePair(firstPair), parsePair(secondPair));
  pairs.push_back(actualPair);
}

int main()
{

  while (!f.eof())
  {
    std::string input;
    std::getline(f, input);
    parseInput(input);
  }

  auto pairNo{ 0 };
  auto pairNo_part2{ 0 };

  for (const auto& _pair : pairs)
  {
    const auto& firstPair  = _pair.first;
    const auto& secondPair = _pair.second;

    if (firstPair.first <= secondPair.first && secondPair.second <= firstPair.second ||
      secondPair.first <= firstPair.first && firstPair.second <= secondPair.second)
      pairNo++;

    if (!(firstPair.second < secondPair.first || secondPair.second < firstPair.first))
      pairNo_part2++;
  }

  std::cout << "Part 1 : " << pairNo << std::endl;
  std::cout << "Part 2 : " << pairNo_part2 << std::endl;

  return 0;
}
