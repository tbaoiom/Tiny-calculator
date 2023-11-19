#ifndef TINY_CLASS_HPP
#define TINY_CLASS_HPP
#include <string>

// Enum type for operations
enum OpType {
addition = 0,
subtraction,
division,
multiplication,
modulo
};

class TinyCalculator {
  public:
    TinyCalculator(std::string name);
    void processInputType(OpType operation);
    static OpType displayUserMenu();
    static void displayReport(TinyCalculator TinyCalculator[], int size);
    bool checkForPlayAgain();

    // Getters
    std::string getCalcName();
    int getRunningTotal();

  private:
    static int addCount;
    static int subCount;
    static int divCount;
    static int multCount;
    static int modCount;
    static char userInput;
    static double savedResult;

    std::string calcName;
    double runningTotal;
    double firstNum;
    double secondNum;

    double add(double left, double right);
    double subtract(double left, double right);
    double divide(double left, double right);
    double multiply(double left, double right);
    double modulo(double left, double right);
    double compute(double left, double right, OpType operation);
};

#endif