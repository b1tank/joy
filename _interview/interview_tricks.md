# taking mod

reference: https://leetcode.com/mojojojo77/

the question asks to give the answer mod 1000000007. this is to keep it within the range of int.

1000000007 is a large prime number under the size of max value of int.

because it is prime number, you can do lot of mod operations and still keep your answer within int ranges.

a * b = answer
if a*b is larger than int you can do mod 1000000007 at each step and keep it within int ranges.

- ( a * b ) % c = ( ( a % c ) * ( b % c ) ) % c = answer % c
- ( a + b ) % c = ( ( a % c ) + ( b % c ) ) % c
- ( a * b ) % c = ( ( a % c ) * ( b % c ) ) % c
- ( a – b ) % c = ( ( a % c ) - ( b % c ) ) % c