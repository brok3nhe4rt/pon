#ifndef ENEMY_H_INCLUDED
#define ENEMY_H_INCLUDED

#include "item.h"
#include "location.h"

#define MAX_ENEMY_NAME_LENGTH 100

typedef struct {
    char name[MAX_ENEMY_NAME_LENGTH]; // Имя врага
    int health;                       // Здоровье врага
    int attackPower;                  // Сила атаки врага
    Location location;                // Локация, где находится враг
} Enemy;

#endif // ENEMY_H_INCLUDED