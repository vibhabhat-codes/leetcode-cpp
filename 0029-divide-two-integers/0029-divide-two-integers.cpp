class Solution {
public:
    int divide(int dividend, int divisor) {
        long long INT_MAX_LL = pow(2, 31) - 1;
        long long INT_MIN_LL = -pow(2, 31);

        if (dividend == INT_MIN_LL && divisor == -1) return INT_MAX_LL;

        long long a = llabs(dividend);
        long long b = llabs(divisor);
        long long result = 0;

        // Bitwise division
        while (a >= b) {
            long long temp = b, multiple = 1;
            while (a >= (temp << 1)) {
                temp <<= 1;
                multiple <<= 1;
            }

            a -= temp;
            result += multiple;
        }

        // Adjust sign
        if ((dividend < 0) ^ (divisor < 0)) result = -result;

        // Clamp result in 32-bit range
        if (result > INT_MAX_LL) return INT_MAX_LL;
        if (result < INT_MIN_LL) return INT_MIN_LL;

        return result;
     
    }
};