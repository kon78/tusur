#ifndef TASK9_H
#define TASK9_H
#include<iostream>
#include<functional>
enum class EnumFuncLog {fAnd=0,fOr,fXor,fEnd=9};//fAnd-1 fOr-2 fXor-3 fEnd-9
bool LogAND(bool& op1, bool& op2);
bool LogOR(bool& op1, bool& op2);
bool LogXOR(bool& op1, bool& op2);
bool BaseFunction(bool& op1, bool& op2, bool(*func_ptr)(bool&,bool&));//вызов функции с аргументами
bool BaseFunction(bool& op1, bool& op2, std::function<bool(bool&,bool&)> operation, bool(*func_ptr)(bool&,bool&));
#endif // TASK9_H
