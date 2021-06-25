/*
Approach as per GFG

As every number can be represented in base 2(0 or 1), 
represent the quotient in binary form by using shift operator as given below : 

>> Determine the most significant bit in the quotient. 
   This can easily be calculated by iterating on the bit position i from 31 to 1.
   
>> Find the first bit for which divisor << i 
   is less than dividend and keep updating the ith bit position for which it is true.
   
>> Add the result in temp variable for checking the next position such that (temp + (divisor << i) ) is less than dividend.

>> Return the final answer of quotient after updating with corresponding sign.

Time complexity : O(log(a)) 
Auxiliary space : O(1)

*/

//I am not writing main() 
#include <bits/stdc++.h>
using namespace std;
 
// Function to divide a by b and
// return floor value it
int divide(long long dividend, long long divisor) {
 
  // Calculate sign of divisor i.e.,
  // sign will be negative only iff
  // either one of them is negative
  // otherwise it will be positive
  int sign = ((dividend < 0) ^
              (divisor < 0)) ? -1 : 1;
 
  // remove sign of operands
  dividend = abs(dividend);
  divisor = abs(divisor);
 
  // Initialize the quotient
  long long quotient = 0, temp = 0;
 
  // test down from the highest bit and
  // accumulate the tentative value for
  // valid bit
  for (int i = 31; i >= 0; --i) {
 
    if (temp + (divisor << i) <= dividend) {
      temp += divisor << i;
      quotient |= 1LL << i; //1LL is long long integer (64 bit) to prevent overflow while shifting leftwards
    }
  }
 
  return sign * quotient;
}


