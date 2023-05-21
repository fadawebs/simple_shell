#ifndef TBSHELL_H
#define TBSHELL_H

#include <stdio.h>
#include <assert.h>
/**
 * contents of TBshell.h go here
 */

/**
 *  TBshell.h
 */
/**
 * This function adds two integers together and returns the result
 */

int add(int x, int y);

/**
 * This function multiplies two floats together and returns the result
float multiply(float a, float b);
 */

float multiply(float a, float b);

/**
 * Here is some sample code that demonstrates
 * how to use the functions declared above:
 */

void demo(void)
{
    float product;
    /**
     * Add two integers together
     */
    int sum = add(2, 3);

    printf("2 + 3 = %d\n", sum);
    product = 0.0;
    /**
     * Multiply two floats together
     */
    product = multiply(4.5, 6.7);
    printf("4.5 * 6.7 = %.2f\n", product);
}

/**
 * And here is some testing code that
 * ensures the functions are working as intended:
 */

void test_add(void)
{
    assert(add(2, 3) == 5);
    assert(add(-2, 3) == 1);
    assert(add(0, 0) == 0);
}

void test_multiply(void)
{
    assert(multiply(2.5, 3) == 7.5);
    assert(multiply(0, 5.5) == 0);
    assert(multiply(-2.5, -2.5) == 6.25);
}

#endif /** TBSHELL_H */
