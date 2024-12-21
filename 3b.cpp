#include <fstream>
#include <iostream>
#include <regex>
#include <sstream>
#include <string>

using namespace std;

int main() {
  ifstream in("3.txt");
  ostringstream ssInput;
  ssInput << in.rdbuf();
  string input = ssInput.str();

  std::regex re("mul\\((\\d{1,3}),(\\d{1,3})\\)|do\\(\\)|don't\\(\\)");

  unsigned long long int total = 0;
  bool enabled = true;
  for (sregex_iterator i = sregex_iterator(input.begin(), input.end(), re);
       i != sregex_iterator(); i++) {
    smatch m = *i;

    if (m.str() == "do()") {
      enabled = true;
    } else if (m.str() == "don't()") {
      enabled = false;
    } else if (enabled) {
      int a = stoi(m[1]), b = stoi(m[2]);
      total += a * b;
    }
  }
  cout << total << endl;

  return 0;
}
