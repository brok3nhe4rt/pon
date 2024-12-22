#ifndef CHARACTER_H_INCLUDED
#define CHARACTER_H_INCLUDED

#define MAX_NAME_LENGTH 100
#define MAX_OPISANIE_LENGTH 1000

typedef struct {
    char firstName[MAX_NAME_LENGTH];
    float sex;
    char opisanie[MAX_OPISANIE_LENGTH];
} Character;

#endif // CHARACTER_H_INCLUDED