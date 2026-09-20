# INET_Assignment_2
Auditing and correcting recursive base conversion in C.

**Problem_&_Audit_Summary**

The goal of this program is to convert a number into a base between 2 and 16. The starter code used recursion, but it was missing some checks and didn't format all the answers correctly.
First the code didn't check whether the base was valid. Using base 0 would cause an invalid remainder, and base 1 could keep the function calling over and over without stopping. The corrected code checks the base first, prints an error if it's outside 2-16 and returns.
Another problem was how it printed digits above 9. For example, it printed 10 instead of a. The corrected code uses "0123456789abcdef" to select the right character for each of the remainders.
The starter also left out the prefix 0 and hex prefix 0x. The corrected version prints the prefix once in to_base_n(), then uses print_digits() to recursively print the digits.
Lastly the corrected code also handles zero and prints an error for negative numbers.
After having ChatGPT make the changes and print the code, I compiled and ran the program. All eight tests that it put in main produced the expected output. The valid inputs showed the converted numbers, and invalid bases or negative numbers showed error messages.

**Call-Stack_Tracing**

For this example I used to_base_n(129,16). First the function checks whether the base and number are valid. Since they are, it prints the prefix 0x and calls print_digits(129,16).
In this first call, num is 129 and base is 16. The remainder r is 1 because 129 % 16 equals 1. Since 129 is greater than or equal to 16, the function calls print_digits(8,16). The 8 comes from integer division, where 129 / 16 equals 8. The first call waits before printing its remainder.
In the second call, num is 8, base is 16, and r is 8. Since 8 is less than 16, there are no more recursive calls. This call prints 8 and returns to the first call.
The first call still has num 129, base as 16, and its own saved r of 1. It now prints 1 and returns. This is the unwinding part, where the calls finish and return to the functions that called them.
The output is 0x81 because the prefix prints first, then 8, then 1. Each call keeps its own remainder, and waiting until after the recursive call to print puts the digits in the right order.

**AI_Tool_Reflection**

I gave ChatGPT the starter code and the assignment requirements and asked for help fixing it. It suggested checking the base before doing any division or remainder operations. It also used "0123456789abcdef" to print the right character for each remainder and separated the prefix from the recursive function so the prefix would only print once.
One little thing too that ChatGPT pointed out what that the starter comment was wrong. The original code would print 81 for 129 in base 16, not 1281. It added a test using 171 to check whether the code correctly printed letters in hexadecimal.
After having it print out the new code with it's own comments and everything I still needed to compile and run the code to check the results. All eight tests it put produced the expected output. The code handled zero and rejected negative numbers, but the only thing the tests didn't do was cover every valid base or the largest possible integer.
I also asked whether the program should let me type in numbers in the terminal. ChatGPT explained that the fixed tests matched the examples in the assignment and offered an interactive version. The version had a limitation because it assumed the input would fit in an int. I kept the fixed test version for my submission.
ChatGPT helped me fix the code and understand how the recursive calls work, but I still had to compare its suggestions with the assignment and check what the program actually printed.
