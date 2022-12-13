#include <iostream>
#include <fstream>
#include <string>
#include <limits>
#include <vector>
#include <algorithm>
#include <map>

std::ifstream f("input.txt");

std::map<char, char> loose; // if pair {a,b} exists, I LOOSE
std::map<char, char> draw; // if pair {a,b} exists, DRAW
std::map<char, char> win; // if pair {a,b} exists, I WIN

std::map<char,int> score;

static const int & pointsLose = 0;
static const int & pointsDraw = 3;
static const int & pointsWin  = 6;

int main()
{
  loose['A'] = 'Z'; loose['B'] = 'X'; loose['C'] = 'Y';
  draw['A'] = 'X'; draw['B'] = 'Y'; draw['C'] = 'Z';
  win['A'] = 'Y'; win['B'] = 'Z'; win['C'] = 'X';

  score['X'] = 1; score['Y'] = 2; score['Z'] = 3;

  auto points{ 0 };

  while (!f.eof())
  {
    char opponent{};
    char mine{};

    f >> opponent >> mine;
    if (opponent == '\0' || mine == '\0')
      break;

    //if need to loose
    if (mine == 'X')
    {
      mine = loose[opponent];
    }
    //if need to draw
    else if (mine == 'Y')
    {
      mine = draw[opponent];
    }
    //if need to win
    else if (mine == 'Z')
    {
      mine = win[opponent];
    }
    
    //draw
    {
      auto find = loose.find(opponent);
      if (find->second == mine)
        points += pointsLose + score[mine];
    }

    //if opponent win
    {
      auto find = draw.find(opponent);
      if (find->second == mine)
        points += pointsDraw + score[mine];
    }
    
    //if I win
    {
      auto find = win.find(opponent);
      if (find->second == mine)
        points += pointsWin + score[mine];
    }
  }

  std::cout << "Part 2 : " << points;

  return 0;
}
