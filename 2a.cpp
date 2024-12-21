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

    for (int i = 0; i < numbers.size(); i++) {
      cout << numbers[i] << " ";
    }
    cout << endl;

    bool asc = numbers[0] < numbers[1];
    bool safe = true;
    for (int i = 0; i < numbers.size() - 1; i++) {
      if (numbers[i] < numbers[i + 1] != asc) {
        safe = false;
        break;
      }
      if (numbers[i] == numbers[i + 1] ||
          abs(numbers[i] - numbers[i + 1]) > 3) {
        safe = false;
        break;
      }
    }
    if (safe) {
      total++;
    }
  }

  cout << total << endl;
  return 0;
}
