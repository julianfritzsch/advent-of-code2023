#include <fstream>
#include <iostream>
#include <map>
#include <regex>
#include <string>

std::map<std::string, std::string> nums{
    {"one", "1"}, {"two", "2"},   {"three", "3"}, {"four", "4"}, {"five", "5"},
    {"six", "6"}, {"seven", "7"}, {"eight", "8"}, {"nine", "9"}};

std::string get_number(std::string);

int main() {
  std::ifstream inp("input/day1.txt");
  std::string line;

  std::regex rex1("(\\d)");
  std::regex rex2("(?=(one|two|three|four|five|six|seven|eight|nine|\\d))");

  int total1{0};
  int total2{0};

  while (std::getline(inp, line)) {
    std::string first1, last1, first2, last2;

    auto words_begin1 = std::sregex_iterator(line.begin(), line.end(), rex1);
    auto words_end1 = std::sregex_iterator();

    auto words_begin2 = std::sregex_iterator(line.begin(), line.end(), rex2);
    auto words_end2 = std::sregex_iterator();

    auto dist1 = std::distance(words_begin1, words_end1);
    auto dist2 = std::distance(words_begin2, words_end2);

    if (dist1 != 0) {
      first1 = words_begin1->str();
    }
    for (int i = 0; i < dist1 - 1; ++i) {
      ++words_begin1;
    }
    last1 = words_begin1->str();
    total1 += std::stoi(first1 + last1);
    
    if (dist2 != 0) {
      first2 = words_begin2->str();
    }
    std::smatch match1 = *words_begin2;
    for (int i = 0; i < dist2 - 1; ++i) {
      ++words_begin2;
    }
    std::smatch match2 = *words_begin2;
    total2 += std::stoi(get_number(match1[1]) + get_number(match2[1]));
  }
  std::cout << total1 << std::endl;
  std::cout << total2 << std::endl;
}

std::string get_number(std::string in) {
  if (in.size() == 1) {
    return in;
  }
  return nums[in];
}
