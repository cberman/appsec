#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void random_number() {
    srand(time(NULL));
    printf("%d\n", rand());
}

void menu() {
    printf("pancakes\neggs\nsausages\nwater\n");
}

void fortune() {
    printf("today is your lucky day!!\n");
}


int convert(char *s) {
    int n = 0;
    while(*s) {
        n *= 10;
        n += *(s++) - '0';
    }
    printf("You chose option %d\n", n);
    return n;
}

void do_option(int choice) {
    void (*func)(void);
    switch(choice) {
        case 1:
            func = &random_number;
            break;
        case 2:
            func = &menu;
            break;
        case 3:
            func = &fortune;
            break;
        case 0:
            printf("You need to pick an option!\n");
            return;
    }
    (*func)();
}

void main(int argc, char **argv) {
    if(argc == 1) {
        printf("Usage: %s <option>\n", argv[0]);
        exit(1);
    }
    int choice = convert(argv[1]);
    do_option(choice);
}
