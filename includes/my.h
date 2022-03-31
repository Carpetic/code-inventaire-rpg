/*
** EPITECH PROJECT, 2022
** code_inventory
** File description:
** my
*/

#ifndef MY_H_
    #define MY_H_

    #define HEIGHT 1080
    #define WIDTH 1920

#include <SFML/Graphics.h>
#include <stdbool.h>

typedef struct inventory_s inventory_t;
typedef struct sprite_s sprite_t;

struct sprite_s {
    sfIntRect rect;
    sfVector2f scale;
    sfSprite *sprite;
    sfTexture* texture;
    sfVector2f position;
    sfVector2u size;
};

struct inventory_s {
    bool(*isClick)(inventory_t, sfRenderWindow *, sfEvent);
    bool(*isOver)(sprite_t, sfRenderWindow *);
    sprite_t item;
    sprite_t back;
    bool asItem;
};


#endif /* !MY_H_ */
