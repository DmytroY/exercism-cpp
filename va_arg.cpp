#include <iostream>
#include <stdarg.h>

using namespace std;

void myFunc(int num, ...);

int main() {
   myFunc( 5, 32.4f, 12.3, 0.0, 4.0, 1.2e-3 );

    return 0;
}
/* first argument is number of variable arguments we will pass to function*/
void myFunc(int num, ...) {
  va_list args;
  va_start(args, num);
  for(int i = 0; i < num; i++){
    cout << va_arg(args, double) << endl;
  }
  va_end(args);
}