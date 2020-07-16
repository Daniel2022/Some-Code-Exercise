#include <stdlib.h>
#include <iostream>

/*******************************************************
 *       Declaration of class FibonacciGenerator       *
 *******************************************************/

class FibonacciGenerator {
private:
  int firstnum;
  int secondnum;
  int count;
  int process1, process2;
public:
  FibonacciGenerator(int number1 = 0, int number2 = 1);
  void PrintAndAdvance();
};

/*****************************************************************
 *       Definition of members of class FibonacciGenerator       *
 *****************************************************************/
void FibonacciGenerator::PrintAndAdvance()
{
  int temp;
  temp = process2;
  if(count==1){
    process2 = firstnum;
    count++;
  }
  else if(count==2){
    process2 = secondnum;
    count++;
  }
  else
    process2 += process1;
  process1 = temp;
  std::cout << "The next number is " << process2 << std::endl;
}
FibonacciGenerator::FibonacciGenerator(int number1, int number2)
{
  firstnum = number1;
  secondnum = number2;
  count =1;
  process1 = process2 = 0;
}


/********************************************************************************
 *       Main Function which is using FibonacciGenerator (do not change!)       *
 ********************************************************************************/

int main() {
  FibonacciGenerator fg1;
  for( int i = 0; i < 10; i++ )
    fg1.PrintAndAdvance();
  std::cout << "\n";
  
  int number1;
  int number2;
  std::cin >> number1 >> number2;
  FibonacciGenerator fg2(number1, number2);
  for( int i = 0; i < 10; i++ )
    fg2.PrintAndAdvance();
  std::cout << "\n";
  
  return 0;
}