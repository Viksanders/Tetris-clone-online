#ifndef MENUS_H_INCLUDED
#define MENUS_H_INCLUDED

#include "constants.h"

void print_settings_menu(int x_menu_offset, int y_menu_offset, settings_t* sttngs);
void settings_menu(settings_t* sttngs);
void print_main_menu(int x_menu_offset, int y_menu_offset);
void main_menu();

#endif // MENUS_H_INCLUDED
