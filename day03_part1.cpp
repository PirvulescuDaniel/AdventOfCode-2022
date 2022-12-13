#include <iostream>
#include <fstream>
#include <string>
#include <limits>
#include <vector>
#include <algorithm>
#include <map>

std::ifstream f("input.txt");

int main()
{
  std::map<char, int> alphabet;
  char letter = 'a';

  for (int i = 1; i <= 52; i++)
  {
    alphabet[letter] = i;
    letter++;
    
    if (i == 26)
      letter = 'A';
  }

  auto sum{ 0 };

  while (!f.eof())
  {
    std::string input;
    std::getline(f, input);

    std::string firstStr(input.substr(0, input.size()/2));
    std::string secondStr(input.substr(input.size()/2, input.size() / 2));

    for (const auto& let : firstStr)
    {
      if (secondStr.find(let) != std::string::npos)
      {
        sum += alphabet[let];
        break;
      }
    }
  }

  std::cout << "Part 1 : " << sum << std::endl;

  return 0;
}
