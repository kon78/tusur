#ifndef MYCALC_H
#define MYCALC_H
#include <string>
class myCalc
{
public:
    myCalc();
    double result();
    void run(char op);
    void moveOpA(std::string s);
    void moveOpB(std::string s);
    bool getStat();
    void Reset();
private:
    double operandA;
    double operandB;
    double equal;
    bool error;
};

#endif // MYCALC_H
