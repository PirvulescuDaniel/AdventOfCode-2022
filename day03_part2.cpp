#include <iostream>
#include <fstream>
#include <string>
#include <limits>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

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
    std::string input1;
    std::string input2;
    std::string input3;

    std::getline(f, input1);
    std::getline(f, input2);
    std::getline(f, input3);

    std::set<int> letters;

    for (const auto& let : input1)
    {
      if (input2.find(let) != std::string::npos)
      {
        letters.insert(let);
      }
    }

    for (const auto& let : letters)
    {
      if (input3.find(let) != std::string::npos)
      {
        sum += alphabet[let];
        break;
      }
    }
  }

  std::cout << "Part 2 : " << sum << std::endl;

  return 0;
}
