#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

int main() {
  std::vector<int> a, b;

  do {
    a.push_back(0);
    b.push_back(0);
    std::cin >> a[a.size() - 1] >> b[b.size() - 1];
  } while (a.back() != -1 && b.back() != -1);

  std::sort(a.begin(), a.end());
  std::sort(b.begin(), b.end());

  unsigned long long int total = 0;
  for (int i = 0; i < a.size(); i++) {
    total += std::abs(a[i] - b[i]);
  }
  std::cout << total;

  return 0;
}
