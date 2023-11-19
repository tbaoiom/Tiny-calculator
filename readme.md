*******************************************************


                 Read Me


*******************************************************
*  Description of the program
*******************************************************
1. Uses a calculator class to create 2 calculators and alternates them.
2. Displays a option menu for the user to choose operations.
3. Requests for 2 numbers separately from the user to compute a result. The result is stored
   and can be used by inputting an 'M'.
5. Asks the user if they want to keep using the calculator, displays the results
   if user inputs 'N'.
7. Supports addition, subtraction, multiplication, division, and modulo.


*******************************************************
*  Written Algorithm
*******************************************************
1. Create 2 calculator objects for odd and even, alternating between each for operations.
2. Keeps looping in main until user decides to stop, it will then display the results.
3. Class has static variables for operation counts and each operation has its own function.
4. Use enum type for operation type.
5. Have a function to check whether use wants to continue, this returns a bool value.
6. Save previous results in a static variable and when the user types in 'M' to use
   previous result as an operand, use that saved static variable.
7. Have a function to compute by taking operation, and 2 operands.
8. Keep a running count of the total between the two calculator objects.

*******************************************************
*  Source files
*******************************************************

Name:  main.cpp
   Main program.  This is the driver program that creates the odd and even calculator
   objects and alternates their use in a do while loop. It calls class member functions
   to take inputs and display menus for the user. This loop ends when the user is
   done using the calculator and will display the results.

Name:  tinyCalc.hpp (if you have one)
   Class interface. Contains the definitions for the class member functions and variables,
   as well as the constructor.

Name: tinyCalc.cpp
   Defines and implements the tinyCalculator class member functions.
   
*******************************************************
*  Circumstances of programs
*******************************************************

   The program runs successfully.  
   
   The program was developed and tested on gnu g++ 6.1.x  It was 
   compiled, run, and tested on gcc csegrid server.
