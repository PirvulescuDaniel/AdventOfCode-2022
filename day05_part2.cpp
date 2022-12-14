#include <iostream>
#include <fstream>
#include <string>
#include <limits>
#include <vector>
#include <algorithm>
#include <map>
#include <stack>
#include <tuple>

std::ifstream f("input.txt");

std::vector<std::stack<char>> stacks;

std::vector<std::string> SplitByDelimiters(const std::string& aString, std::vector<std::string> aDelimiters)
{
  std::sort(aDelimiters.begin(), aDelimiters.end(),
	[](const std::string& first, const std::string& second) {
	  return first.size() > second.size();
	}
  );

  std::vector<std::string> output;
  std::string stringCopy(aString);

  size_t index{};
  size_t delimSize{};

  while (true)
  {
	size_t indexMin = std::numeric_limits<size_t>::max();

	for (const auto& delimitator : aDelimiters)
	{
	  index = stringCopy.find(delimitator);
	  if (index != std::string::npos && index < indexMin)
	  {
		indexMin = index;
		delimSize = delimitator.size();
	  }
	}

	if (indexMin == std::numeric_limits<size_t>::max())
	{
	  output.push_back(stringCopy);
	  break;
	}

	output.push_back(stringCopy.substr(0, indexMin));
	stringCopy = stringCopy.substr(indexMin + delimSize, stringCopy.size());
  }

  auto last = std::remove_if(output.begin(), output.end(),
	[](const std::string& obj) {
	  return obj.size() == 0;
	}
  );

  output = std::vector<std::string>(output.begin(), last);
  return output;
}

std::tuple<int, int, int> parseInsttruction(const std::string& aString)
{
  std::vector<std::string> v1 = SplitByDelimiters(aString, { "move "," from "," to " });

  return std::tuple(std::stoi(v1[0]), std::stoi(v1[1]), std::stoi(v1[2]));
}

int main()
{
  std::vector<std::string> strings = {
    " ", // 0 - do not count
    "SMRNWJVT",
    "BWDJQPCV",
    "BJFHDRP",
    "FRPBMND",
    "HVRPTB",
    "CBPT",
    "BJRPL",
    "NCSLTZBW",
    "LSG"
  };

  for (auto i = 0; i <= 9; i++)
  {
    std::stack<char> stk;
    for (const auto& character : strings[i])
    {
      stk.push(character);
    }
    stacks.push_back(stk);
  }
  
  //paste in the input.txt just the instructions (move...)
  while (!f.eof())
  {
    std::string input;
    std::getline(f, input);

	const auto& [noOfCrate, whereToGet, whereToMove] = parseInsttruction(input);

	for (auto i = 0; i < noOfCrate; i++)
	{
	  const auto& crate = stacks[whereToGet].top();
	  stacks[whereToGet].pop();
	  stacks[whereToMove].push(crate);
	}

	std::string tempString{};
	for (auto i = 0; i < noOfCrate; i++)
	{
	  tempString.push_back(stacks[whereToMove].top());
	  stacks[whereToMove].pop();
	}

	for (const auto& character : tempString)
	  stacks[whereToMove].push(character);
  }

  for (const auto& stk : stacks)
  {
	if (stk == stacks[0]) continue;
	std::cout << stk.top();
  }

  return 0;
}
