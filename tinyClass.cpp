#include "tinyClass.hpp"
#include <iostream>
#include <string>
#include <cctype>

using std::cin;
using std::cout;
using std::endl;
using std::string;

// Static variables
char TinyCalculator::userInput = ' ';
int TinyCalculator::addCount = 0;
int TinyCalculator::subCount = 0;
int TinyCalculator::multCount = 0;
int TinyCalculator::divCount = 0;
int TinyCalculator::modCount = 0;
double TinyCalculator::savedResult = 0;

// Object constructor takes parameter for the name
TinyCalculator::TinyCalculator(string name) {
  calcName = name;
}

// Displays a user menu for the user and takes an input
OpType TinyCalculator::displayUserMenu() {
  while (true) {
    cout << "Select one of the following operations." << endl;
    cout << "[A]ddition" << endl;
    cout << "[S]ubtraction" << endl;
    cout << "[M]ultiplication" << endl;
    cout << "[D]ivision" << endl;
    cout << "[%]Modulo" << endl;
    cin >> userInput;
    userInput = std::toupper(userInput);
    
    // Converts user input into operation enum type and returns it
    // Let the user know what operation they picked and keep a count of
    // the operation
    if (userInput == 'A') {
      addCount++;
      cout << "You have selected addition." << endl;
      return OpType::addition;
    } 
    else if (userInput == 'S') {
      subCount++;
      cout << "You have selected subtraction." << endl;
      return OpType::subtraction;
    } 
    else if (userInput == 'M') {
      multCount++;
      cout << "You have selected multiplication." << endl;
      return OpType::multiplication;
    } 
    else if (userInput == 'D') {
      divCount++;
      cout << "You have selected division." << endl;
      return OpType::division;
    } 
    else if (userInput == '%') {
      modCount++;
      cout << "You have selected modulo." << endl;
      return OpType::modulo;
    }
    else {
      cout << "Invalid input, try again." << endl;
    }
  }
}

// Processes the user's input by asking for the numbers and 
// uses an operation parameter to compute the result with a helper function
// Saves the result to a static variable
// If user enters 'M', use the previous saved result
void TinyCalculator::processInputType(OpType operation) {
  string input;
  double result;
  cout << "Enter the first number: " << endl;
  cin >> input;
  if (input == "M") {
    firstNum = savedResult;
  }
  else {
    firstNum = std::stof(input);
  }
  
  cout << "Enter the second number: " << endl;
  cin >> input;
  
  if (input == "M") {
    secondNum = savedResult;
  }
  else {
    secondNum = std::stof(input);
  }
  
  result = compute(firstNum, secondNum, operation); // Helper function
  cout << "The result is: " << result << endl;
  savedResult = result;
  runningTotal += result; // Keep track of total results
}

// Asks user if they want to use the calculator again
// Returns a bool value
bool TinyCalculator::checkForPlayAgain() {
  char response;
  cout << "Would you like to make another calculation? [Y/N]" << endl;
  cin >> response;
  response = std::toupper(response);
  return (response == 'Y');
}

// Helper function to compute the result using switch case and 
// operation member functions, returning result
double TinyCalculator::compute(double left, double right, OpType operation) {
  switch (operation) {
  case (OpType::addition):
    return add(left, right);
  case (OpType::subtraction):
    return subtract(left, right);
  case (OpType::multiplication):
    return multiply(left, right);
  case (OpType::division):
    return divide(left, right);
  case (OpType::modulo):
    return modulo(left, right);
  }
}

// Displays the final report given a list and its size
void TinyCalculator::displayReport (TinyCalculator TinyCalculator[], int size) {
  // Displays amount of each operation used
  cout << "Calculator Report" << endl;
  cout << "\t" << "Number of additions: " << addCount << endl;
  cout << "\t" << "Number of subtractions: " << subCount << endl;
  cout << "\t" << "Number of multiplications: " << multCount << endl;
  cout << "\t" << "Number of divisions: " << divCount << endl;
  cout << "\t" << "Number of modulos: " << modCount << endl;
  cout << "\t" << "Total operations: " << addCount + subCount + multCount + divCount + modCount << endl;

  // Displays name and total for each calculator object
  for (int i=0; i<size; i++) {
    cout << "\t" << "Running total for " << TinyCalculator[i].getCalcName() << " calculator: "
         << TinyCalculator[i].getRunningTotal() << endl;
  }

  // Displays total and average from both calculator objects
  cout << "\t" << "Running total for all operations: " << TinyCalculator[0].getRunningTotal() +   
  TinyCalculator[1].getRunningTotal() << endl;
  cout << "\t" << "Average total of operations: " << (TinyCalculator[0].getRunningTotal() + 
  TinyCalculator[1].getRunningTotal()) / (addCount + subCount + multCount + divCount + modCount) << endl;
}

// Addition operation function
double TinyCalculator::add(double left, double right) {
  return left + right;
  }

// Subtraction operation function
double TinyCalculator::subtract(double left, double right) {
  return add(left, -right);
}

// Multiplication operation function
double TinyCalculator::multiply(double left, double right) {
  double multTotal = 0;
  for (int i = 0; i < right; i++) {
    multTotal += left;
  }
  return multTotal;
}

// Division operation function
double TinyCalculator::divide(double left, double right) {
  double divTotal = 0;
  while (left > 0) {
    divTotal++;
    left -= right;
  }
  return divTotal-1;
}

// Modulo operation function
double TinyCalculator::modulo(double left, double right) {
  return left - (divide(left, right) * right);
}

// Getter for the object name
string TinyCalculator::getCalcName () {
  return calcName;
}

// Getter for the total results after each operation
int TinyCalculator::getRunningTotal () {
  return runningTotal;
}