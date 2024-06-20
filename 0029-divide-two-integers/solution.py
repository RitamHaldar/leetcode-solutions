class Solution(object):
    def divide(self, dividend, divisor):
        """
        :type dividend: int
        :type divisor: int
        :rtype: int
        """
        # Constants to handle 32-bit integer limits
        MAX_INT = 2**31 - 1
        MIN_INT = -2**31

        # Special case for overflow
        if dividend == MIN_INT and divisor == -1:
            return MAX_INT
        
        # Determine the sign of the result
        sign = -1 if (dividend < 0) ^ (divisor < 0) else 1
        
        # Work with absolute values to make calculation easier
        dividend, divisor = abs(dividend), abs(divisor)
        
        quotient = 0
        # Perform the division using bit manipulation
        while dividend >= divisor:
            temp, multiple = divisor, 1
            while dividend >= (temp << 1):
                temp <<= 1
                multiple <<= 1
            dividend -= temp
            quotient += multiple
        
        # Apply the sign to the quotient
        quotient *= sign
        
        # Ensure the result is within the 32-bit signed integer range
        return min(max(MIN_INT, quotient), MAX_INT)
