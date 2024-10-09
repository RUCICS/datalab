/* WARNING: Do not include any other libraries here,
 * otherwise you will get an error while running test.py
 * You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.
 *
 * Using printf will interfere with our script capturing the execution results.
 * At this point, you can only test correctness with ./btest.
 * After confirming everything is correct in ./btest, remove the printf
 * and run the complete tests with test.py.
 */

/*
 * bitXor - x ^ y using only ~ and &
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 7
 *   Difficulty: 1
 */
int bitXor(int x, int y) {
    return (~(~x & ~y) & ~(x & y));
}

/*
 * samesign - Determines if two integers have the same sign.
 *   0 is not positive, nor negative
 *   Example: samesign(0, 1) = 0, samesign(0, 0) = 1
 *            samesign(-4, -5) = 1, samesign(-4, 5) = 0
 *   Legal ops: >> << ! ^ && if else &
 *   Max ops: 12
 *   Difficulty: 2
 *
 * Parameters:
 *   x - The first integer.
 *   y - The second integer.
 *
 * Returns:
 *   1 if x and y have the same sign , 0 otherwise.
 */
int samesign(int x, int y) {
   
    if (!x & !y) // 均为0
        return 1;
    if ((x ^ 0) && (y ^ 0))
        return !((x >> 31) ^ (y >> 31)); // 同符号返回1，不同返回0,(0,1)=0,(0,0)=1
    return 0;
}

/*
 * logtwo - Calculate the base-2 logarithm of a positive integer using bit
 *   shifting. (Think about bitCount)
 *   Note: You may assume that v > 0
 *   Example: logtwo(32) = 5
 *   Legal ops: > < >> << |
 *   Max ops: 25
 *   Difficulty: 4
 */
int logtwo(int v) {
        int count = 0;
    return count;
}

/*
 *  byteSwap - swaps the nth byte and the mth byte
 *    Examples: byteSwap(0x12345678, 1, 3) = 0x56341278
 *              byteSwap(0xDEADBEEF, 0, 2) = 0xDEEFBEAD
 *    Note: You may assume that 0 <= n <= 3, 0 <= m <= 3
 *    Legal ops: ! ~ & ^ | + << >>
 *    Max ops: 17
 *    Difficulty: 2
 */
int byteSwap(int x, int n, int m) {
 
   int origin_x = x;
    n <<= 3; // 将m,n乘8，方便与掩码&
    m <<= 3;
    int mask1 = 0xff;
    int temp = (((mask1 & (origin_x >> m)) << n) | ((mask1 & (origin_x >> n)) << m)); // 用mask来实现，n，m交换,注意先将origin_x的m号字节移到0号上，再与0xff按位与
    int mask2 = ~((0xff << n) | (0xff << m));
    x &= mask2; // 用mask2把x中n,m的字节清为0
    x |= temp;
    return x;
}

/*
 * reverse - Reverse the bit order of a 32-bit unsigned integer.
 *   Example: reverse(0xFFFF0000) = 0x0000FFFF reverse(0x80000000)=0x1 reverse(0xA0000000)=0x5
 *   Note: You may assume that an unsigned integer is 32 bits long.
 *   Legal ops: << | & - + >> for while ! ~ (You can define unsigned in this function)
 *   Max ops: 30
 *   Difficulty: 3
 */
unsigned reverse(unsigned x)
{
    x = (x & 0x55555555) << 1 | (x & 0xAAAAAAAA) >> 1;   // 交换相邻的1位
    x = (x & 0x33333333) << 2 | (x & 0xCCCCCCCC) >> 2;   // 交换相邻的2位
    x = (x & 0x0F0F0F0F) << 4 | (x & 0xF0F0F0F0) >> 4;   // 交换相邻的4位
    x = (x & 0x00FF00FF) << 8 | (x & 0xFF00FF00) >> 8;   // 交换相邻的8位
    x = (x & 0x0000FFFF) << 16 | (x & 0xFFFF0000) >> 16; // 交换相邻的16位
    return x;
}
//基本思路是：初始化一个变量 result 为0，用于存储反转后的结果。
//通过循环32次，逐位x 的每一位移动到 result 的相应位置。
//每次循环中，将 x 右移一位，将 result 左移一位，并将 x 的最低位添加到 result 的最低位。
//当 x 变为0时，循环结束，result 即为反转后的结果。
//为了减少操作数，使用分治法，逐步将32位分成更小的部分，然后逐级反转。

/*
 * logicalShift - shift x to the right by n, using a logical shift
 *   Examples: logicalShift(0x87654321,4) = 0x08765432
 *   Note: You can assume that 0 <= n <= 31
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Difficulty: 3
 */

   int logicalShift(int x, int n)
{
    int result=0;
    int mask=0xffffffff>>n;//得到一个掩码，前n位是0，后32-n位是1
    result=(x>>n)&mask;
    result=(x>>n)&mask;
    return result;
}


/*
 * leftBitCount - returns count of number of consective 1's in left-hand (most) end of word.
 *   Examples: leftBitCount(-1) = 32, leftBitCount(0xFFF0F0F0) = 12,
 *             leftBitCount(0xFE00FF0F) = 7
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 50
 *   Difficulty: 4
 */
int leftBitCount(int x) {


    int count = 0;
    int mask = 1 << 31;
    int count16, count8, count4, count2, count1;
    count16 = (!(~(x & (mask >> 15)) >> 16)) << 4;
    count += count16;
    x <<= count16;
    count8 = (!(~(x & (mask >> 7)) >> 24)) << 3;
    count += count8;
    x <<= count8;
    count4 = (!(~(x & (mask >> 3)) >> 28)) << 2;
    count += count4;
    x <<= count4;
    count2 = (!(~(x & (mask >> 1)) >> 30)) << 1;
    count += count2;
    x <<= count2;
    count1 = (!(~(x & mask) >> 31));
    count += count1;
    x <<= count1;

   int  single_1 = x >> 31 & 1;
    count+=single_1;
    return count;

}
// 思路：运用并行的思想，先判断前16位是否全为1，若是，count+=16,然后x<<16;若否，则进入下一个判断，x<<count16
//                     再判断前8位是否全为1，若是，count+=8,然后x<<8;
//                     再判断前4位是否全为1，若是，count+=4,然后x<<4;
// 以此类推一直到判断前一位是否为1

/*
 * float_i2f - Return bit-level equivalent of expression (float) x
 *   Result is returned as unsigned int, but it is to be interpreted as
 *   the bit-level representation of a single-precision floating point values.
 *   Legal ops: if else while for & | ~ + - >> << < > ! ==
 *   Max ops: 30
 *   Difficulty: 4
 */
unsigned float_i2f(int x) {
    return 2;
}

/*
 * floatScale2 - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: & >> << | if > < >= <= ! ~ else + ==
 *   Max ops: 30
 *   Difficulty: 4
 */
unsigned floatScale2(unsigned uf) {
    return 2;
}

/*
 * float64_f2i - Convert a 64-bit IEEE 754 floating-point number to a 32-bit signed integer.
 *   The conversion rounds towards zero.
 *   Note: Assumes IEEE 754 representation and standard two's complement integer format.
 *   Parameters:
 *     uf1 - The lower 32 bits of the 64-bit floating-point number.
 *     uf2 - The higher 32 bits of the 64-bit floating-point number.
 *   Returns:
 *     The converted integer value, or 0x80000000 on overflow, or 0 on underflow.
 *   Legal ops: >> << | & ~ ! + - > < >= <= if else
 *   Max ops: 60
 *   Difficulty: 3
 */
int float64_f2i(unsigned uf1, unsigned uf2)
{

    int  E;
    unsigned S = (uf2 >> 31);
    unsigned M,value;
    int mask1 = 0x000007ff; // 用于得到E
    int mask2 = 0x000fffff; 
    E = ((uf2 >> 20) & mask1);
    int actual_E = E - 1023;
    M = ((uf2 & mask2) << 11) | (((uf1 >> 21) & mask1)) | (0x80000000); // uf2的低20位+uf1的高11位
    // 处理指数
    if (actual_E >= 31)
    {
        // 溢出
        return  0x80000000;
    }
    else if (actual_E < 0)
    {
        // 下溢
        return 0;
    }
    value = (M >> (31 - actual_E)) & ~(0x80000000 >> (31 - actual_E) << 1);
    if (S)
    {
        value = -value;
    }
    return value;
}

/*
 * floatPower2 - Return bit-level equivalent of the expression 2.0^x
 *   (2.0 raised to the power x) for any 32-bit integer x.
 *
 *   The unsigned value that is returned should have the identical bit
 *   representation as the single-precision floating-point number 2.0^x.
 *   If the result is too small to be represented as a denorm, return
 *   0. If too large, return +INF.
 *
 *   Legal ops: < > <= >= << >> + - & | ~ ! if else &&
 *   Max ops: 30
 *   Difficulty: 4
 */
unsigned floatPower2(int x) {
    return 2;
}
