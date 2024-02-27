#include "best_results.h"
#include "core_fucntions.h"
#include "menus.h"

const char* settings_filename = "settings_tetris.dat";

void print_settings_menu(int x_menu_offset, int y_menu_offset, settings_t* sttngs)
{
    clear();
    mvprintw(y_menu_offset - 3, x_menu_offset + 5, "SETTINGS");
    mvprintw(y_menu_offset - 2, x_menu_offset - 10, "(UP and DOWN keys for navigation, RIGHT/LEFT keys for change value)");
    mvprintw(y_menu_offset, x_menu_offset, "FAST FALL ON DOWN ARROW = %d", sttngs->fast_placedown);
    mvprintw(y_menu_offset + 2, x_menu_offset, "SHOW PROJECTION = %d", sttngs->show_projection);
    mvprintw(y_menu_offset + 4, x_menu_offset, "HEIGTH = %d", sttngs->heigth);
    mvprintw(y_menu_offset + 6, x_menu_offset, "WIDTH = %d", sttngs->width);
    mvprintw(y_menu_offset + 8, x_menu_offset, "START LEVEL = %d", sttngs->start_level);
    mvprintw(y_menu_offset + 10, x_menu_offset, "SKIP TO DEFAULT");
    mvprintw(y_menu_offset + 12, x_menu_offset, "BACK");
}

void settings_menu(settings_t* sttngs)
{
    int x_menu_offset = 20;
    int y_menu_offset = 4;
    int key = 0;
    char choice = '>';
    int x_choice = x_menu_offset - 2;
    int y_choice = y_menu_offset;
    int y_choice_pre = y_choice;

    FILE* sttngs_file;

    print_settings_menu(x_menu_offset, y_menu_offset, sttngs);
    mvprintw(y_choice, x_choice, "%c", choice);

    while (1)
    {
        mvprintw(y_choice_pre, x_choice, "%c", SPCE_CHR);
        mvprintw(y_choice, x_choice, "%c", choice);
        key = getch();
        y_choice_pre = y_choice;
        if (key == KEY_UP) y_choice = y_choice - 2;
        if (key == KEY_DOWN) y_choice = y_choice + 2;

        if (y_choice < y_menu_offset) y_choice = y_menu_offset + 12;
        if (y_choice > y_menu_offset + 12) y_choice = y_menu_offset;

        if (key == KEY_RIGHT)
        {
            if (y_choice == y_menu_offset)          //FAST FALL
            {
                sttngs->fast_placedown = (sttngs->fast_placedown == 0) ? 1 : 0;
                print_settings_menu(x_menu_offset, y_menu_offset, sttngs);
            }
            if (y_choice == y_menu_offset + 2)      //SHOW PROJECTION
            {
                sttngs->show_projection = (sttngs->show_projection == 0) ? 1 : 0;
                print_settings_menu(x_menu_offset, y_menu_offset, sttngs);
            }
            if (y_choice == y_menu_offset + 4)      //HEIGTH = 20 default
            {
                sttngs->heigth++;
                if (sttngs->heigth > HEIGTH_MAX) sttngs->heigth = HEIGTH_MIN;
                print_settings_menu(x_menu_offset, y_menu_offset, sttngs);
            }
            if (y_choice == y_menu_offset + 6)      //WIDTH  = 10 default
            {
                sttngs->width++;
                if (sttngs->width > WIDTH_MAX) sttngs->width = WIDTH_MIN;
                print_settings_menu(x_menu_offset, y_menu_offset, sttngs);
            }
            if (y_choice == y_menu_offset + 8)      //START LEVEL
            {
                sttngs->start_level++;
                if (sttngs->start_level > 49) sttngs->start_level = 1;      //take care of leveling, tbd
                print_settings_menu(x_menu_offset, y_menu_offset, sttngs);
            }
            if (y_choice == y_menu_offset + 10)      //DEFAULT SETTINGS
            {
                set_default_settings(sttngs);
                print_settings_menu(x_menu_offset, y_menu_offset, sttngs);
            }
            if (y_choice == y_menu_offset + 12)      //BACK
            {
                sttngs_file = fopen(settings_filename, "wb");
                fwrite(sttngs, sizeof(settings_t), 1, sttngs_file);
                fclose(sttngs_file);
                return;
            }
        }

        if (key == KEY_LEFT)
        {
            if (y_choice == y_menu_offset)          //FAST FALL
            {
                sttngs->fast_placedown = (sttngs->fast_placedown == 0) ? 1 : 0;
                print_settings_menu(x_menu_offset, y_menu_offset, sttngs);
            }
            if (y_choice == y_menu_offset + 2)      //SHOW PROJECTION
            {
                sttngs->show_projection = (sttngs->show_projection == 0) ? 1 : 0;
                print_settings_menu(x_menu_offset, y_menu_offset, sttngs);
            }
            if (y_choice == y_menu_offset + 4)      //HEIGTH = 20 default
            {
                sttngs->heigth--;
                if (sttngs->heigth < HEIGTH_MIN) sttngs->heigth = HEIGTH_MAX;
                print_settings_menu(x_menu_offset, y_menu_offset, sttngs);
            }
            if (y_choice == y_menu_offset + 6)      //WIDTH  = 10 default
            {
                sttngs->width--;
                if (sttngs->width < WIDTH_MIN) sttngs->width = WIDTH_MAX;
                print_settings_menu(x_menu_offset, y_menu_offset, sttngs);
            }
            if (y_choice == y_menu_offset + 8)      //START LEVEL
            {
                sttngs->start_level--;
                if (sttngs->start_level < 1) sttngs->start_level = 49;      //take care of leveling, tbd
                print_settings_menu(x_menu_offset, y_menu_offset, sttngs);
            }
        }
    }
}


void print_main_menu(int x_menu_offset, int y_menu_offset)
{
    clear();
    mvprintw(y_menu_offset - 3, x_menu_offset + 5, "TETRIS CLONE BETA");
    mvprintw(y_menu_offset - 2, x_menu_offset - 10, "(UP and DOWN keys for navigation, RIGHT key for select)");
    mvprintw(y_menu_offset, x_menu_offset, "START SINGLE GAME");
    mvprintw(y_menu_offset + 2, x_menu_offset, "MULTIPLAYER: SERVER");
    mvprintw(y_menu_offset + 4, x_menu_offset, "MULTIPLAYER: CLIENT");
    mvprintw(y_menu_offset + 6, x_menu_offset, "BEST RESULTS");
    mvprintw(y_menu_offset + 8, x_menu_offset, "SETTINGS");
    mvprintw(y_menu_offset + 10, x_menu_offset, "EXIT");
}

void main_menu()
{
    int x_menu_offset = 20;
    int y_menu_offset = 4;
    int key = 0;
    int score = 0;
    char choice = '>';
    int x_choice = x_menu_offset - 2;
    int y_choice = y_menu_offset;
    int y_choice_pre = y_choice;

    settings_t sttngs;
    settings_t sttngs_network;  //settings for spectator watcher mode / multiplayer
    FILE* sttngs_file = fopen(settings_filename, "rb");
    if (sttngs_file)
    {
        //load settings from file
        if (fread(&sttngs, sizeof(settings_t), 1, sttngs_file) > 0) fclose(sttngs_file);
        else set_default_settings(&sttngs);
    }
    else
    {
        set_default_settings(&sttngs);
    }

    set_default_settings(&sttngs_network);      //for network game settings are always default

    Note_t* result_list = NULL;
    FILE* result_file = fopen(results_filename, "rb");
    if (result_file)
    {
        //load results from file
        load_results_form_file(&result_list);
        fclose(result_file);
    }


    print_main_menu(x_menu_offset, y_menu_offset);
    mvprintw(y_choice, x_choice, "%c", choice);

    while (1)
    {
        mvprintw(y_choice_pre, x_choice, "%c", SPCE_CHR);
        mvprintw(y_choice, x_choice, "%c", choice);
        key = getch();
        y_choice_pre = y_choice;
        if (key == KEY_UP) y_choice = y_choice - 2;
        if (key == KEY_DOWN) y_choice = y_choice + 2;

        if (y_choice < y_menu_offset) y_choice = y_menu_offset + 10;
        if (y_choice > y_menu_offset + 10) y_choice = y_menu_offset;

        if (key == KEY_RIGHT)
        {
            if (y_choice == y_menu_offset)          //SINGLE
            {
                score = single_game(&sttngs);
                //best result check
                if (is_addable_note(score, &result_list))
                {
                    Note_t* new_note = (Note_t*)malloc(sizeof(Note_t) * 1);
                    new_note->score = score;
                    new_note->next = NULL;
                    clear();
                    deinit_curses();
                    printw("Enter name: ");
                    get_name_from_user_input(&new_note);
                    if (add_best_result(&new_note, &result_list) == 0) free(new_note);
                    init_curses();
                    write_results_to_file(&result_list);
                }
                print_main_menu(x_menu_offset, y_menu_offset);
            }
            if (y_choice == y_menu_offset + 2)      //MULTIPLAYER: SERVER
            {
                score = multiplayer_game(&sttngs_network, 1);
                print_main_menu(x_menu_offset, y_menu_offset);
            }
            if (y_choice == y_menu_offset + 4)      //MULTIPLAYER: CLIENT
            {
                score = multiplayer_game(&sttngs_network, 0);
                print_main_menu(x_menu_offset, y_menu_offset);
            }
            if (y_choice == y_menu_offset + 6)      //RECORDS
            {
                print_notes(&result_list);
                print_main_menu(x_menu_offset, y_menu_offset);
            }
            if (y_choice == y_menu_offset + 8)      //SETTINGS
            {
                settings_menu(&sttngs);
                print_main_menu(x_menu_offset, y_menu_offset);
            }
            if (y_choice == y_menu_offset + 10)      //EXIT
            {
                delete_all_notes(&result_list);
                clear();
                endwin();
                exit(0);
            }
        }
    }
}

//
