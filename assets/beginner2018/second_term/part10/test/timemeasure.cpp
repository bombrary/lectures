#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

int fib(int n)
{
  if (n == 0) return 0;
  if (n == 1) return 1;
  else return fib(n - 1) + fib(n - 2);
}

int main()
{
  for (int i = 30; i <= 48; i++) {
    auto start =  system_clock::now();
    cout << i << ",";
    fib(i);
    auto end =  system_clock::now();
    auto dur = end - start;
    auto sec = duration_cast<milliseconds>(dur).count();
    cout << sec << endl;
  }

  return 0;
}
