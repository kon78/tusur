#include "mycalc.h"

myCalc::myCalc():operandA(0),operandB(0),equal(0),error(false) {}

void myCalc::run(char op){
         if(op == 'p'){
        equal = operandA + operandB;
        }
    else if(op == 'm'){
        equal = operandA - operandB;
        }
    else if(op == 'd' && operandB != 0){
        equal = operandA / operandB;
        }
    else if(op == 'u'){
        equal = operandA * operandB;
        }
    else if(op == 'd' && operandB == 0){
            error = true;
        }
}

void myCalc::moveOpA(std::string s){
    operandA = std::atof(s.c_str());
}

void myCalc::moveOpB(std::string s){
    operandB = std::atof(s.c_str());
}

double myCalc::result(){
    return equal;
}

bool myCalc::getStat(){
    return error;
}

void myCalc::Reset(){
    error = false;
}
