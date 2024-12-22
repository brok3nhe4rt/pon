#include <stdio.h>
#include <string.h>
#include "item.h"
#include "character.h"
#include "location.h"
#include "enemy.h"
#include "funcii.h"
#define MAX_CHARACTERS 5
#define MAX_LOCATIONS 100
#define MAX_ITEMS 2
#define MAX_ENEMYS 100

Character characters[MAX_CHARACTERS];
int characterCount = 0;

Location locations[MAX_LOCATIONS];
int locationCount = 0;

Item items[MAX_ITEMS];
int itemCount = 0;
Enemy enemys[MAX_ITEMS];
int enemyCount = 0; 
// Функция для ввода персонажа
void inputCharacter(Character *character_p) {
    printf("Введите имя персонажа: ");
    scanf("%s", character_p->firstName);
    printf("Введите пол персонажа: ");
    scanf("%s", &character_p->sex);
    printf("Введите описание персонажа: ");
    while (getchar() != '\n');
    fgets(character_p->opisanie, MAX_OPISANIE_LENGTH, stdin);
    
}

// Функция для ввода локации
void inputLocation(Location *location_p) {
    printf("Введите тип локации: ");
    scanf("%s", location_p->type);
    printf("Введите название локации: ");
    scanf("%s", location_p->name_loc);
    printf("Введите площадь локации (только цифры): ");
    scanf("%f", &location_p->razmer);
    while (getchar() != '\n');
    locations[locationCount++] = *location_p;
}

// Функция для ввода предмета
void inputItem(Item *item_p) {
    printf("Введите тип предмета: ");
    scanf("%s", item_p->type);
    printf("Введите название предмета: ");
    scanf("%s", item_p->name_item);
    printf("Введите количество предметов (только цифры): ");
    scanf("%d", &item_p->kolichestvo);
    
    items[itemCount++] = *item_p;
}

// Функция для ввода врага
void inputEnemy(Enemy *enemy_p) {
    printf("Введите название врага: ");
    scanf("%s", enemy_p->name);
    printf("Введите здоровье (только цифры): ");
    scanf("%f", &enemy_p->health);
    printf("Введите силу врага (только цирфры): ");
    scanf("%f", &enemy_p->attackPower);

    enemys[enemyCount++] = *enemy_p;
    
}
void saveToFile(const char *filename, Character *characters, int characterCount, Location *locations, int locationCount, Item *items, int itemCount, Enemy *enemys, int enemyCount) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Ошибка при открытии файла!\n");
        return;
    }

    for (int i = 0; i < characterCount; i++) {
        fprintf(file, "Character: %s %s, sex: %s, History: %s\n",
                characters[i].firstName, characters[i].sex,characters[i].opisanie);
    }

    for (int i = 0; i < locationCount; i++) {
        fprintf(file, "Location: %s, Location name: %s, Size: %.2f, Description: %s\n",
                locations[i].type, locations[i].name_loc, locations[i].razmer);
    }

    for (int i = 0; i < itemCount; i++) {
        fprintf(file, "Item: %s, Name: %s, Kolichestvo: %d\n",
                items[i].type, items[i].name_item, items[i].kolichestvo);
    }
    for (int i = 0; i < enemyCount; i++) {
        fprintf(file,"Name: %s,Health: %f, Attack Power: %f\n,",
               enemys[i].name, enemys[i].health, enemys[i].attackPower);
    }
    fclose(file);
}