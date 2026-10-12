#include <iostream>
#include <cmath>

int main(){

  /* инизиализация */
  float x;
  float y;
  
  std::cin >> x;
  std::cin >> y;

  int i = 0;
  
  /* цикл */
  while (x < y) {
  i++;
  x = x * 1.1;
  }

  std::cout << i;
}
