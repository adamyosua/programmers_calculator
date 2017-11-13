#include "operations.h"

/* add 2 ints */
int add(int op1, int op2)
{
    return op1 + op2;
}
/* substract 2 ints */
int subtract(int op1, int op2)
{
    return op1 - op2;
}
/* multiply 2 ints */
int multiply(int op1, int op2)
{
    return op1 * op2;
}
/* divide 2 ints and return the DIVISION_ERROR value if division by 0 occurs*/
int divide(int op1, int op2)
{
    if(op2 == 0)
        return DIVISION_ERROR;
    else
        return op1 / op2;
}
