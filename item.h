#ifndef ITEM_H_INCLUDED
#define ITEM_H_INCLUDED

#define MAX_ITEM_TYPE_LENGTH 50
#define MAX_ITEM_NAME_LENGTH 100

typedef struct {
    char type[MAX_ITEM_TYPE_LENGTH];        // Тип предмета (например, "монета", "мощность")
    char name_item[MAX_ITEM_NAME_LENGTH];   // Название предмета (например, "Золотая монета")
    int kolichestvo;                           // Количество предметов
} Item;


#endif // ITEM_H_INCLUDED