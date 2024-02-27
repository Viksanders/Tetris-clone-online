#include <stdlib.h>
#include <time.h>

#ifdef _WIN32
#include "include/curses.h"
#else
#include <ncurses.h>
#endif // _WIN32

#include "best_results.h"
const char* results_filename = "results_tetris.dat";

int add_best_result(Note_t** note, Note_t** all_notes)
{
    int is_added = 0;
    if (*all_notes == NULL)
    {
        *all_notes = *note;
        is_added = 1;
        return is_added;
    }

    Note_t* loop_ptr = *all_notes;
    Note_t* loop_ptr_prev = NULL;
    int ctr = 0;
    while (loop_ptr != NULL)
    {
        if ((*note)->score > loop_ptr->score)
        {
            Note_t* temp = loop_ptr;
            if (loop_ptr != *all_notes)
            {
                loop_ptr = *note;
                loop_ptr_prev->next = loop_ptr;
                loop_ptr->next = temp;
                ctr++;
                is_added = 1;
                break;
            }
            else
            {
                *all_notes = *note;
                (*all_notes)->next = temp;
                ctr++;
                is_added = 1;
                break;
            }
        }
        else if (loop_ptr->next == NULL)
        {
            loop_ptr->next = *note;
            is_added = 1;
            ctr++;
            break;
        }

        loop_ptr_prev = loop_ptr;
        loop_ptr = loop_ptr->next;
    }
    //*
    loop_ptr = *all_notes;
    while (loop_ptr != NULL)
    {
        if (ctr <= 10)
        {
            loop_ptr_prev = loop_ptr;
            loop_ptr = loop_ptr->next;
            ctr++;
        }
        else
        {
            Note_t* temp = loop_ptr;
            if (loop_ptr_prev->next) loop_ptr_prev->next = NULL;
            loop_ptr = loop_ptr->next;
            ctr++;
            free(temp);
        }
    }

    return is_added;
    //*/
}

void print_notes(Note_t** all_notes)
{
    clear();
    int ctr = 0;
    int x_menu_offset = 20;
    int y_menu_offset = 4;
    mvprintw(y_menu_offset - 3, x_menu_offset + 5, "BEST RESULTS");
    mvprintw(y_menu_offset - 2, x_menu_offset - 5, "(Press any arrow key to exit)");
    int key = 0;

    Note_t* loop_ptr = *all_notes;
    while (loop_ptr != NULL)     //while((loop_ptr != NULL) && (ctr < 10))
    {
        mvprintw(y_menu_offset + ctr * 2, x_menu_offset, "%s : %d", loop_ptr->name, loop_ptr->score);
        ctr++;
        loop_ptr = loop_ptr->next;
    }

    //*
    while (ctr < 10)
    {
        mvprintw(y_menu_offset + ctr * 2, x_menu_offset, "------- : -------");
        ctr++;
    }
    //*/

    while (1)
    {
        key = getch();
        if ((key == KEY_LEFT) || (key == KEY_RIGHT) || (key == KEY_UP) || (key == KEY_DOWN)) break;
    }
}


void add_new_note(Note_t** note, Note_t** all_notes)
{
    if (*all_notes == NULL)
    {
        *all_notes = *note;
        return;
    }

    Note_t* loop_ptr = *all_notes;
    while (loop_ptr->next != NULL)
    {
        loop_ptr = loop_ptr->next;
    }

    loop_ptr->next = *note;
}

int is_addable_note(int score, Note_t** all_notes)
{
    Note_t* loop_ptr = *all_notes;
    int ctr = 0;

    if (*all_notes == NULL) return 1;

    while ((loop_ptr != NULL) && (ctr < 10))
    {
        if (score > loop_ptr->score) return 1;
        loop_ptr = loop_ptr->next;
        ctr++;
    }

    if (ctr < 10) return 1;

    return 0;
}


void delete_all_notes(Note_t** all_notes)
{
    Note_t* loop_ptr = *all_notes;

    while (loop_ptr != NULL)
    {
        Note_t* temp = loop_ptr;
        loop_ptr = loop_ptr->next;
        free(temp);
    }
}


void get_name_from_user_input(Note_t** note)
{
#ifdef WIN32
    fflush(stdin);
#endif // WIN32

    int ctr = 0;
    char c;

    while (((c = (char)getch()) != '\n') && (ctr <= 20))
    {
        (*note)->name[ctr] = c;
        ctr++;
        if (ctr > 20) break;
    }

    (*note)->name[ctr] = '\0';

#ifdef WIN32
    fflush(stdin);
#endif // WIN32
}

void write_results_to_file(Note_t** all_notes)
{
    if (*all_notes == NULL) return;

    FILE* results_file = fopen(results_filename, "wb");

    Note_t* loop_ptr = *all_notes;

    while (loop_ptr != NULL)
    {
        fwrite(loop_ptr, sizeof(Note_t), 1, results_file);
        loop_ptr = loop_ptr->next;
    }

    fclose(results_file);
}


int load_results_form_file(Note_t** all_notes)
{
    FILE* results_file = fopen(results_filename, "rb");
    if (results_file == NULL) return 0;  //cannot load from file
    Note_t loaded;

    while (fread(&loaded, sizeof(Note_t), 1, results_file))
    {
        Note_t* new_node = (Note_t*)malloc(sizeof(Note_t));
        for (int i = 0; i < NAMESIZE; ++i)
        {
            new_node->name[i] = loaded.name[i];
        }
        new_node->next = NULL;
        new_node->score = loaded.score;
        add_new_note(&new_node, all_notes);
    }
    return 1;                       //load has passed successfully
}

