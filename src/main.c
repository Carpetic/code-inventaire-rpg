/*
** EPITECH PROJECT, 2022
** code_inventory
** File description:
** main
*/

#include "../includes/my.h"

sprite_t init_sprite(sfIntRect rect, char *path)
{
    sprite_t sprite;
    /*
        Initialiser la structure sprite à l'aide du path pour créer une texture,
        Afin de créer un sprite et d'utiliser le rect donné
        puis ce return sprite
    */
    return (sprite);
}

bool overlay_check(sprite_t sprite, sfRenderWindow *window)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(window);
    /*
        Return true si la souris se trouve au-dessus du sprite
        aussi non return false
    */
    return (false);
}

bool isClicked(inventory_t inventory, sfRenderWindow *window, sfEvent event)
{
    if (inventory.isOver(inventory.back, window) && event.mouseButton.button == sfMouseLeft && event.type == sfEvtMouseButtonPressed)
        return (true);
    return (false);
}

sfRenderWindow *create_window(char *name)
{
    sfRenderWindow *window = sfRenderWindow_create(*sfVideoMode_getFullscreenModes(0), name, sfFullscreen, NULL);
    sfRenderWindow_setFramerateLimit(window, 60);
    return (window);
}

int drop_item(inventory_t *selected, inventory_t *new_item)
{
    if (new_item->asItem == true)
        return -1;

    /*
        new_item obtient un objet et selected perd son objet
        Copier toutes les informations de l'item présent dans selected à new_item
        Détruire le sprite et la texture dans selected, et remettre la valeur asitem à false
    */
    return (0);
}

void event_handling(sfRenderWindow *window, sfEvent event, inventory_t *inventory)
{
    static int id = -1;
    static bool pressed = false;
    static sfVector2f og_pos;
    sfIntRect rect = {0, 0, 65, 65};
    sfVector2i mvector = sfMouse_getPositionRenderWindow(window);
    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtKeyPressed && sfKeyboard_isKeyPressed(sfKeyEscape) == 1)
            sfRenderWindow_close(window);

        for (int i = 0; i < 14; i++) {
            /*
                Si on clic sur une case de l'inventaire, le bord devient rouge
                Si on passe sur une case de l'inventaire, le bord devient blanc
                Si rien n'est fait alors le bord redevient noir
            */
            sfSprite_setTextureRect(inventory[i].back.sprite, rect);
            /*
                Si la case est cliquée et qu'elle a un item
                alors enregistrer les informations sur la case cliquée et modifier pressed
            */
        }

        if (id != -1 && pressed)
            sfSprite_setPosition(inventory[id].item.sprite, (sfVector2f){mvector.x - 32.5, mvector.y - 32.5});

        /*
            Si un item est sélectionné et que la personne relâche le bouton
            Alors chercher si la souris est au-dessus d'une case de l'inventaire
            SI oui alors appeler drop item et modifier la position de l'objet sur la case
            Si non remettre l'item à sa position initial
            Puis réinitialiser pressed et id
        */
    }
}

int main(int ac, char **av)
{
    (void) ac;
    (void) av;
    int i = 0;
    sfEvent event;
    inventory_t inventory[14];
    sfRenderWindow *window = create_window("#code inventaire");
    for (i = 0; i < 14; i++) {
        inventory[i].asItem = false;
        inventory[i].isClick = &isClicked;
        inventory[i].isOver = &overlay_check;
        inventory[i].back = init_sprite((sfIntRect){0, 0, 65, 65}, "./assets/inventory.png");
        inventory[i].back.position = (sfVector2f) {(WIDTH - 910) / 2 + 65 * i, HEIGHT / 2};
        inventory[i].back.size = (sfVector2u) {65, 65};
        sfSprite_setPosition(inventory[i].back.sprite, inventory[i].back.position);
    }
    inventory[0].asItem = true;
    inventory[0].item = init_sprite((sfIntRect){0, 0, 65, 65}, "./assets/sword.png");
    inventory[0].item.position = inventory[0].back.position;
    inventory[0].item.size = (sfVector2u) {65, 65};
    sfSprite_setPosition(inventory[0].item.sprite, inventory[0].item.position);

    while (sfRenderWindow_isOpen(window)) {
        sfRenderWindow_clear(window, sfBlack);
        event_handling(window, event, inventory);
        for (i = 0; i < 14; i++)
            sfRenderWindow_drawSprite(window, inventory[i].back.sprite, NULL);
        for (i = 0; i < 14; i++) {
            if (inventory[i].asItem)
                sfRenderWindow_drawSprite(window, inventory[i].item.sprite, NULL);
        }
        sfRenderWindow_display(window);
    }
    return 0;
}
