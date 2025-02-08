#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
#define MAX_CITIES 100000
#define MAX_LEN 101
 
typedef struct {
    char source[MAX_LEN];
    char destination[MAX_LEN];
} Ticket;
 
typedef struct {
    char key[MAX_LEN];
    char value[MAX_LEN];
} MapEntry;
 
MapEntry flight_map[MAX_CITIES];
int map_size = 0;
 
void add_to_map(const char *source, const char *destination) {
    strcpy(flight_map[map_size].key, source);
    strcpy(flight_map[map_size].value, destination);
    map_size++;
}
 
const char* find_destination(const char *source) {
    for (int i = 0; i < map_size; i++) {
        if (strcmp(flight_map[i].key, source) == 0) {
            return flight_map[i].value;
        }
    }
    return NULL;
}
 
int is_destination(const char *city) {
    for (int i = 0; i < map_size; i++) {
        if (strcmp(flight_map[i].value, city) == 0) {
            return 1;
        }
    }
    return 0;
}
 
const char* find_start_city() {
    for (int i = 0; i < map_size; i++) {
        if (!is_destination(flight_map[i].key)) {
            return flight_map[i].key;
        }
    }
    return NULL;
}
 
void find_itinerary(int n) {
    const char *start_city = find_start_city();
    if (!start_city) return;
    while (start_city) {
        const char *next_city = find_destination(start_city);
        if (next_city) {
            printf("%s->%s", start_city, next_city);
            start_city = next_city;
            if (find_destination(start_city)) {
                printf(", ");
            }
        } else {
            break;
        }
    }
    printf("\n");
}
 
void trim(char *str) {
 
    int start = 0;
 
    while (str[start] != '\0' && str[start]==' ') {
 
        start++;
 
    }
 
    int end = strlen(str) - 1;
 
    while (end >= start && str[end]==' ') {
 
        end--;
 
    }
 
    int length = end - start + 1;
 
    for (int i = 0; i <= length; i++) {
 
        str[i] = str[start + i];
 
    }
 
    str[length] = '\0';
 
}

 
int main() {
    int n;
    scanf("%d", &n);
    getchar();
    char source[MAX_LEN], destination[MAX_LEN];
    for (int i = 0; i < n; i++) {
        scanf(" %[^-]->%[^\n]", source, destination);
        trim(source);
        trim(destination);
        add_to_map(source, destination);
    }
    find_itinerary(n);
    return 0;
}