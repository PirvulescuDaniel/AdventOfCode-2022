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

void solve(const std::string& aString ,const int & offset)
{
  unsigned int head = 0;
  unsigned int tail = head + offset;

  while (tail < aString.size())
  {
    bool check = true;
    for (int i = head; i <= tail - 1; i++) {
      for (int j = i + 1; j <= tail; j++)
      {
        if (aString[i] == aString[j])
          check = false;
      }
    }

    if (check)
    {
      std::cout << tail + 1;
      return;
    }

    head++;
    tail++;
  }
}

int main()
{
  std::string input;
  std::getline(f, input);

  std::cout << "Part 1 : ";
  solve(input, 3);
  std::cout << std::endl;
  std::cout << "Part 2 : ";
  solve(input, 13);

  return 0;
}
