#include"task9.h"
//bool bAnswer;//ответ для лог.функций
bool LogAND(bool& op1, bool& op2){
  return op1 & op2;

}

bool LogOR(bool& op1, bool& op2){
  return op1 | op2;
}

bool LogXOR(bool& op1, bool& op2){
  return op1 ^ op2;
}

bool BaseFunction(bool& op1, bool& op2, bool(*func_ptr)(bool&,bool&)){
  return func_ptr(op1,op2);
}

bool BaseFunction(bool& op1, bool& op2, std::function<bool(bool&,bool&)> operation, bool(*func_ptr)(bool&,bool&)){
  operation = func_ptr;
  return operation(op1,op2);
}
