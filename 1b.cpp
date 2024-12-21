#include <cstdlib>
#include <iostream>
#include <ostream>
#include <unordered_map>
#include <vector>

int main() {
  std::vector<int> a;
  std::unordered_map<int, int> b;

  int x = 0, y = 0;
  for (;;) {
    std::cin >> x >> y;
    if (x == -1 && y == -1) {
      break;
    }
    a.push_back(x);
    b[y] += 1;
  };

  unsigned long long int total = 0;
  for (auto &x : a) {
    total += x * b[x];
  }
  std::cout << total << std::endl;

  return 0;
}
