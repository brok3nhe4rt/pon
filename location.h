#ifndef LOCATION_H_INCLUDED
#define LOCATION_H_INCLUDED

#define MAX_LOCATION_TYPE_LENGTH 50
#define MAX_LOCATION_NAME_LENGTH 50
#define MAX_RAZMER_LENGTH 500

typedef struct {
    char type[MAX_LOCATION_TYPE_LENGTH];        // Тип локации (например, "площадь", "пещера")
    char name_loc[MAX_LOCATION_NAME_LENGTH];    // Название локации (например, "Площадь Грибного Королевства")
    float razmer;                                  // Размер локации (например, площадь в квадратных метрах)
} Location;


#endif // LOCATION_H_INCLUDED