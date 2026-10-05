#include <iostream>

int func(x){
  return -18*x + 34;
}

int main(){
  int x;
  x >> std::cin;
  std::cout << func(x);
  return 0;
}
