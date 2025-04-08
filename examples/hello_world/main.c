#include <stdio.h>

void greet_user(void) {
    printf("Hello World!\n");
}

int func(int b[], size_t len) {
    return b[len-1];
}

void basic_syntax() {
    int numbers[4] = {1,2,3,4};
    int numbers2[2]; // uninit.
    numbers2[0] = 23;
    numbers2[1] = 42;
    func(numbers, sizeof(numbers));
    func(numbers2, 2);
    char string[] = "Hallo Welt";
    printf("%c\n", string[6]); // ’W’
    string[6] = 'B';
    printf("%c\n", string[6]); // ’B’
    printf("%s\n", string); // ’B’
}

struct date {
    int year;
    int month;
    int day;
};

typedef struct date date_t;

void struct_syntax() {
    struct date today = { 2022, 2, 2 };

    date_t tomorrow = { 2022, 2 };
    date_t yesterday = {
        .year = 2022,
        .month = 2,
    };

    tomorrow.day = today.day + 1;
    yesterday.day = today.day - 1;

    printf("tomorrow day: %d\nyesterday day: %d\n", tomorrow.day, yesterday.day);
}

void pointer_syntax() {
    int a = 42;
    // b zeigt auf a
    int *b = &a;
    // lese a (über b)
    printf("%d\n", *b); // 42
    // lese a direkt
    printf("%d\n", a);  // 42
    // schreibe a (über b)
    *b = 23;
    printf("%d\n", *b); // 23
    printf("%d\n", a);  // 23
    // schreibe a (direkt)
    a = 42;
    printf("%d\n", *b); // 42
    printf("%d\n", a);  // 42
}

int main(void) {
    // greet_user();
    // basic_syntax();
    // struct_syntax();
    pointer_syntax();

    return 0;
}
