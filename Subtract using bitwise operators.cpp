//use subtractor logic

#include<stdio.h>
 
int subtract(int x, int y)
{
    // Iterate till there
    // is no carry
    while (y != 0)
    {
        // borrow contains common
        // set bits of y and unset
        // bits of x
        int borrow = (~x) & y;
 
        // Subtraction of bits of x
        // and y where at least one
        // of the bits is not set
        x = x ^ y;
 
        // Borrow is shifted by one
        // so that subtracting it from
        // x gives the required sum
        y = borrow << 1;
    }
    return x;
}
 
// Driver Code
int main()
{
    int x = 29, y = 13;
    printf("x - y is %d", subtract(x, y));
    return 0;
}
