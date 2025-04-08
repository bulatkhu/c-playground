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

void node_pointer() {
    typedef struct ListNode {
        int data;
        struct ListNode *next;
    } node_t;

    struct ListNode *list_head;

    node_t node0 = { .data = 42, .next = NULL };
    node_t node1 = { .data = 1337, .next = &node0 };
    node_t node2 = { .data = -23, .next = &node1 };

    list_head = &node2;

    printf("head: %d\n", list_head->data);
    // printf("head: %d\n", (*list_head).data);



    printf("head->next: %d\n", list_head->next->data);

    const struct ListNode pointerToNode2 = *list_head->next->next;
    printf("head->next->next: %d\n", pointerToNode2.data); // 42

    printf("short form head->next->next: %d\n", (*(*(*list_head).next).next).data); // 42
    // -> ist die lesbarere Form von (*var).
    printf("long form  head->next->next: %d\n", list_head->next->next->data); // 42



    node_t *currentNode = list_head;
    int nodeCounter = 0;

    while (currentNode != NULL) {
        printf("Node: %d | Value: %d\n", nodeCounter, currentNode->data);
        nodeCounter++;
        currentNode = currentNode->next;
    }
    printf("End\n");
}

void swapByValue(int x, int y) {
    int tmp = y;
    y = x;
    x = tmp;
}

void swapByRef(int* x, int* y) {
    int tmp = *y;
    *y = *x;
    *x = tmp;
}

void calls_by_value_vs_by_reference() {
    int a = 42;
    int b = 1337;

    printf("swap by value before: a: %d, b: %d\n", a, b); // 42, 1337
    swapByValue(a, b);
    printf("swap by value  after: a: %d, b: %d\n", a, b); // 42, 1337
    printf("------------------------------------\n");



    printf("swap by reference before: a: %d, b: %d\n", a, b); // 42, 1337
    swapByRef(&a, &b);
    printf("swap by reference  after: a: %d, b: %d\n", a, b); // 1337, 42

}

int main(void) {
    // greet_user();
    // basic_syntax();
    // struct_syntax();
    // pointer_syntax();
    // node_pointer();

    calls_by_value_vs_by_reference();

    return 0;
}
