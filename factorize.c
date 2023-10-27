#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

/**
 * factorizeNumber - Factors a positive integer and prints its factors.
 * @number: The number to factorize.
 *
 * This function factors a positive integer and prints its factors.
 *
 * Author: [Your Name]
 * Return: 0 on success.
 */
int factorizeNumber(uint32_t number)
{
    if (number <= 1) {
        printf("Invalid input. Please provide a positive integer greater than 1.\n");
        return 1;
    }

    printf("Factors of %u: ", number);

    for (uint32_t i = 2; i <= number; i++) {
        while (number % i == 0) {
            printf("%u", i);
            number /= i;
            if (number > 1) {
                printf("*");
            }
        }
    }

    printf("\n");
    return 0;
}

int main(int argc, char *argv[])
{
    if (argc != 2) {
        printf("Usage: %s <number>\n", argv[0]);
        return 1;
    }

    char *input = argv[1];
    uint32_t num = atoi(input);

    return factorizeNumber(num);
}

