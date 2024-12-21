#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  ifstream in("2.txt");

  int total{};
  while (!in.eof()) {
    string line;
    getline(in, line);

    vector<int> numbers;
    int number = 0;
    int last = 0, next;
    while ((next = line.find(' ', last)) != string::npos) {
      numbers.push_back(stoi(line.substr(last, next - last)));
      last = next + 1;
    }
    try {
      numbers.push_back(stoi(line.substr(last)));
    } catch (exception e) {
      continue;
    }

    bool anySafe = false;
    for (int i = -1; i < (int)numbers.size(); i++) {
      bool asc = false;
      bool set = false;

      bool safe = true;
      for (int j = 0; j < numbers.size() - 1; j++) {
        if (j == i) {
          continue;
        }
        int next = j + 1;
        if (next == i) {
          next++;
        }
        if (next >= numbers.size()) {
          break;
        }

        if (!set) {
          asc = numbers[j] < numbers[next];
          set = true;
        }

        if (numbers[j] < numbers[next] != asc) {
          safe = false;
          break;
        }
        if (numbers[j] == numbers[next] ||
            abs(numbers[j] - numbers[next]) > 3) {
          safe = false;
          break;
        }
      }
      if (safe) {
        anySafe = true;
        break;
      }
    }
    if (anySafe) {
      total++;
    }
  }

  cout << total << endl;
  return 0;
}
