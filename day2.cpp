#include <fstream>
#include <iostream>
#include <regex>
#include <string>

int main() {
  std::fstream inp("input/day2.txt");
  std::string line;
  int total1{0};
  int total2{0};

  int max_red{12};
  int max_green{13};
  int max_blue{14};
  int min_red, min_green, min_blue;

  std::regex rex_red("(\\d+) red");
  std::regex rex_green("(\\d+) green");
  std::regex rex_blue("(\\d+) blue");
  int id{1};
  bool possible;
  while (std::getline(inp, line)) {
    possible = true;
    min_red = 0;
    min_green = 0;
    min_blue = 0;

    auto red_begin = std::sregex_iterator(line.begin(), line.end(), rex_red);
    auto red_end = std::sregex_iterator();

    auto green_begin =
        std::sregex_iterator(line.begin(), line.end(), rex_green);
    auto green_end = std::sregex_iterator();

    auto blue_begin = std::sregex_iterator(line.begin(), line.end(), rex_blue);
    auto blue_end = std::sregex_iterator();

    for (std::sregex_iterator it = red_begin; it != red_end; ++it) {
      auto match = *it;
      int tmp = std::stoi(match[1].str());
      if (tmp > max_red) {
        possible = false;
      }
      min_red = std::max(min_red, tmp);
    }
    for (std::sregex_iterator it = green_begin; it != green_end; ++it) {
      auto match = *it;
      int tmp = std::stoi(match[1].str());
      if (tmp > max_green) {
        possible = false;
      }
      min_green = std::max(min_green, tmp);
    }
    for (std::sregex_iterator it = blue_begin; it != blue_end; ++it) {
      auto match = *it;
      int tmp = std::stoi(match[1].str());
      if (tmp > max_blue) {
        possible = false;
      }
      min_blue = std::max(min_blue, tmp);
    }
    if (possible) {
      total1 += id;
    }
    total2 += min_red * min_blue * min_green;
    ++id;
  }
  std::cout << total1 << std::endl;
  std::cout << total2 << std::endl;
}