/*
  Last digit of fibonacci sum repeats after 60 elements.
  Here the period is 60; [0-59]
  So to get the last digit of n'th number is the last digit of n%60'th number

*/
#include <iostream>
#include <vector>
#include <algorithm>
int get_last_digit(int n){
  std::vector<int> last_digits(60);
  long long a = 0, b = 1;
  last_digits[0] = 0;
  last_digits[1] = 1;
  long long temp, sum = 1;
  // Fill last_digits vector with the first 60 sums last digits
  for (int i = 2; i < 60; i++) {
    temp = a+b;
    a = b;
    b = temp;
    sum += temp;
    last_digits[i] = sum%10;
  }
  // Now return n%60'th element
  return last_digits[n%60];
}
int main(int argc, char const *argv[]) {
  int n;
  std::cin>>n;
  std::cout << get_last_digit(n);
  return 0;
}
