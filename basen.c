/*
 * INET 3101 - AI Code Audit
 *
 * Converts a nonnegative integer to a base from 2 through 16.
 * Uses lowercase letters for digits 10 through 15.
 * Adds a leading 0 for octal and 0x for hexadecimal.
 */

#include <stdio.h>

/*
 * Print the digits recursively.
 * The caller ensures num >= 0 and base is between 2 and 16.
 */
static void print_digits(int num, int base)
{
    const char digits[] = "0123456789abcdef";
    int r = num % base;

    /*
     * Print the more significant digits first.
     * Integer division removes the last digit in this base.
     */
    if (num >= base) {
        print_digits(num / base, base);
    }

    /* Map the remainder to one digit: 0-9 or a-f. */
    printf("%c", digits[r]);
}

/*
 * Validate the input, print any prefix, then print the digits.
 * Invalid input prints an error and returns without converting.
 */
void to_base_n(int num, int base)
{
    /* Validate before performing division or remainder operations. */
    if (base < 2 || base > 16) {
        printf("Error: base must be between 2 and 16.\n");
        return;
    }

    if (num < 0) {
        printf("Error: number must be nonnegative.\n");
        return;
    }

    /*
     * Prefixes belong here so recursive calls cannot repeat them.
     * Octal zero is simply "0", so it needs no extra leading zero.
     */
    if (base == 8 && num != 0) {
        printf("0");
    } else if (base == 16) {
        printf("0x");
    }

    /* This also handles zero by printing digits[0]. */
    print_digits(num, base);
}

int main(void)
{
    printf("Octal (21, base 8): ");
    to_base_n(21, 8);
    printf("\n");

    printf("Hexadecimal (129, base 16): ");
    to_base_n(129, 16);
    printf("\n");

    printf("Hexadecimal letters (171, base 16): ");
    to_base_n(171, 16);
    printf("\n");

    printf("Binary (10, base 2): ");
    to_base_n(10, 2);
    printf("\n");

    printf("Zero (0, base 8): ");
    to_base_n(0, 8);
    printf("\n");

    printf("Invalid base (129, base 20): ");
    to_base_n(129, 20);

    printf("Invalid base (129, base 0): ");
    to_base_n(129, 0);

    printf("Negative input (-5, base 10): ");
    to_base_n(-5, 10);

    return 0;
}