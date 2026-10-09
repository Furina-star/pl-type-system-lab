/* Demonstrate different runtime type behaviors in C. (Static, Weak) */

#include <stdio.h>

int add_one(int n) {
    return n + 1;
}

int main(void) {

    // Demonstrate type coercion 
    printf("1. int + char\n");
    int x = 5;
    char y = '3';
    printf("   %d\n", x + y);

    // Demonstrate reassigning to a different type 
    printf("2. reassign to a different type\n");
    int v = 10;
    printf("   %d\n", v);
    v = 'A';
    printf("   %d\n", v);

    // Demonstrate function with wrong type 
    printf("3. function with wrong type\n");
    printf("   %d\n", add_one(4));
    printf("   %d\n", add_one(3.9));

    // Demonstrate int + float
    printf("4. int + float\n");
    int r = 5 + 2.5;
    printf("   %d\n", r);

    return 0;
}