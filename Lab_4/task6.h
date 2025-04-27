#ifndef TASK6_H
#define TASK6_H
#define PRINT_VAL_INT(ptr) printf("%d", *ptr)
#define PRINT_VAL_DOUBLE(ptr) printf("%f", *ptr)
#define PRINT_VAL_CHAR(ptr) printf("%c", *ptr)
void PrintValAddr(void *addr, int vsize);
enum{elem_val=3};
//void PrintValueAddr(void*(&arr_val)[elem_val]);

#endif // TASK6_H
