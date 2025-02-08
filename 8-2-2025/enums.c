#include <stdio.h>

enum Color {
    RED,   
    GREEN,  
    BLUE    
};

int main() {
    enum Color favoriteColor = GREEN;
    printf("Favorite Color: %d\n", favoriteColor);
    return 0;
}
enum Day { MON, TUE, WED, THU, FRI, SAT, SUN };

int main() {
    enum Day today = FRI;

    switch (today) {
        case MON: printf("Monday\n"); break;
        case FRI: printf("Friday\n"); break;
        default: printf("Another day\n");
    }

    return 0;
}
