#include "constants.h"
#include "best_results.h"
#include "core_fucntions.h"
#include "menus.h"


int main()
{
    init_curses();
    main_menu();
    clear();
    endwin();
    return 0;
}

