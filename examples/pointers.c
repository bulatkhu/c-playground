//
// Created by Bulat on 8/3/2024.
//
#include <stdio.h>
#include <stdlib.h>

struct Person {
    char name[64];
    int age;
};

void updateStruct(struct Person *p, int age) {
    p->age = age;
}

int main(void) {
    int x = 4;
    printf("integer named x is set to 4: %p \n", x);
    // integer named x is set to 4;

    int *pointerX = &x;
    // integer named pointerX is set to address of x
    printf("integer named pointerX is set to address in memory of x: %p \n", pointerX);

    int y = *pointerX;
    // integer named y is set to the thing pointed to by pointerX
    printf("integer named y is set to x via pointerX's address: %p \n", y);


    struct Person lowlewellearning;
    updateStruct(&lowlewellearning, 20);

    struct Person *pPerson = &lowlewellearning;
    struct Person person = *pPerson;

    return 0;
}
