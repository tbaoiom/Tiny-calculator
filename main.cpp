#include <iostream>
#include "tinyClass.hpp"
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main() {
  bool playAgain = true;
  int opTurn = 1;

  // Create odd and even calculator objects
  TinyCalculator oddCalc("Odd");
  TinyCalculator evenCalc("Even");

  // Keep looping until user wants to end
  do
  {
    cout << "\n";
    
    // Display the user menu
    OpType opType = TinyCalculator::displayUserMenu();

    // Alternating use of calculators
    if (opTurn % 2 == 1)
    {
      oddCalc.processInputType(opType);
    } 
    else {
      evenCalc.processInputType(opType);
    }
		opTurn++;

    // Prompt user if they want to go again, end loop if not
    playAgain = oddCalc.checkForPlayAgain();
  } while(playAgain);

  // Create list of calculator objects and display a final report
  TinyCalculator calculators[] = {oddCalc, evenCalc};
  TinyCalculator::displayReport(calculators, 2);

  return 0;
}