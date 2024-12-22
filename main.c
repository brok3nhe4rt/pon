#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "character.h"
#include "location.h"
#include "item.h"
#include "funcii.c"
#include "locale.h"
#define MAX_NAME_LENGTH 100
#define MAX_CHARACTERS 5
#define MAX_ITEMS 2
#define MAX_ENEMYS 100
#define MAX_LOCATIONS 100

int main() {
    setlocale(LC_ALL,"Russian");
    Character characters[MAX_CHARACTERS];
    Location locations[MAX_CHARACTERS];
    Item items[MAX_ITEMS];
    Enemy enemys[MAX_ENEMYS];
    int characterCount = 0, locationCount = 0, itemCount = 0;
    char filename[MAX_NAME_LENGTH];

    // Запрос имени файла для сохранения
    printf("Введите имя файла для сохранения: ");
    fgets(filename, MAX_NAME_LENGTH, stdin);
    filename[strcspn(filename, "\n")] = 0; // Удаление символа новой строки

    char choice;

    // Ввод персонажей
    do {
        if (characterCount < MAX_CHARACTERS) {
            inputCharacter(&characters[characterCount]);
            characterCount++;
        } else {
            printf("Достигнуто максимальное количество персонажей.\n");
            break;
        }
        printf("Хотите ввести еще одного персонажа? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y');

    // Ввод локаций
    do {
        if (locationCount < MAX_CHARACTERS) {
            inputLocation(&locations[locationCount]);
            locationCount++;
        } else {
            printf("Достигнуто максимальное количество локаций.\n");
            break;
        }
        printf("Хотите ввести еще одну локацию? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y');

    // Ввод предметов
    do {
        if (itemCount < MAX_ITEMS) {
            inputItem(&items[itemCount]);
            itemCount++;
        } else {
            printf("Достигнуто максимальное количество предметов.\n");
            break;
        }
        printf("Хотите ввести еще один предмет? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y');
     
    do {
        if (enemyCount < MAX_ENEMYS) {
            inputEnemy(&enemys[enemyCount]);
            enemyCount++;
        } else {
            printf("Достигнуто максимальное количество врагов.\n");
            break;
        }
         printf("Хотите ввести еще одного врага? (y/n): ");
         scanf(" %c", &choice);
    } while (choice == 'y');

    // Сохранение данных в файл
    saveToFile(filename, characters, characterCount, locations, locationCount, items, itemCount, enemys, enemyCount);


    return 0;
}