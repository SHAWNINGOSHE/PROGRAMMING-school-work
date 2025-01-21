#include <stdio.h>
#include <string.h>

int main() {
    char name[50];
    int age;

    printf("Enter your name: ");
    scanf("%s", name);

    printf("Enter your age: ");
    scanf("%d", &age);

    if (age >= 18) {
        printf("%s, you can vote.\n", name);
    } else {
        printf("%s, you are not of the required age to vote.\n", name);
    }

    return 0;
}

