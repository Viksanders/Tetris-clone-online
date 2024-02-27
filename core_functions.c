#include "core_fucntions.h"

const unsigned int x_offset = 4;
const unsigned int y_offset = 4;
clock_t initial_movedown_speed = 600;
const unsigned int HEIGTH_MAX = 40;
const unsigned int HEIGTH_MIN = 10;
const unsigned int WIDTH_MAX = 20;
const unsigned int WIDTH_MIN = 5;
unsigned int random_seed;

//FIGURES STORED IN MEMORY
//O
char O_any[4 * 4] = { SPCE_CHR,SPCE_CHR,SPCE_CHR,SPCE_CHR, SPCE_CHR,SPCE_CHR,SPCE_CHR,SPCE_CHR, B_CHR,B_CHR,SPCE_CHR,SPCE_CHR, B_CHR,B_CHR,SPCE_CHR,SPCE_CHR };

//I
char I_horizontal[4 * 4] = { SPCE_CHR,B_CHR,SPCE_CHR,SPCE_CHR, SPCE_CHR,B_CHR,SPCE_CHR,SPCE_CHR, SPCE_CHR,B_CHR,SPCE_CHR,SPCE_CHR, SPCE_CHR,B_CHR,SPCE_CHR,SPCE_CHR };
char I_vertical[4 * 4] = { SPCE_CHR,SPCE_CHR,SPCE_CHR,SPCE_CHR, B_CHR,B_CHR,B_CHR,B_CHR, SPCE_CHR,SPCE_CHR,SPCE_CHR,SPCE_CHR, SPCE_CHR,SPCE_CHR,SPCE_CHR,SPCE_CHR };

//T
char T_top[4 * 4] = { SPCE_CHR,SPCE_CHR,SPCE_CHR,SPCE_CHR, SPCE_CHR,SPCE_CHR,SPCE_CHR,SPCE_CHR, SPCE_CHR,B_CHR,SPCE_CHR,SPCE_CHR, B_CHR,B_CHR,B_CHR,SPCE_CHR };
char T_right[4 * 4] = { SPCE_CHR,SPCE_CHR,SPCE_CHR,SPCE_CHR, SPCE_CHR,B_CHR,SPCE_CHR,SPCE_CHR, SPCE_CHR,B_CHR,B_CHR,SPCE_CHR, SPCE_CHR,B_CHR,SPCE_CHR,SPCE_CHR };
char T_bot[4 * 4] = { SPCE_CHR,SPCE_CHR,SPCE_CHR,SPCE_CHR, SPCE_CHR,SPCE_CHR,SPCE_CHR,SPCE_CHR, B_CHR,B_CHR,B_CHR,SPCE_CHR, SPCE_CHR,B_CHR,SPCE_CHR,SPCE_CHR };
char T_left[4 * 4] = { SPCE_CHR,SPCE_CHR,SPCE_CHR,SPCE_CHR, SPCE_CHR,B_CHR,SPCE_CHR,SPCE_CHR, B_CHR,B_CHR,SPCE_CHR,SPCE_CHR, SPCE_CHR,B_CHR,SPCE_CHR,SPCE_CHR };

//L
char L_top[4 * 4] = { SPCE_CHR,SPCE_CHR,SPCE_CHR,SPCE_CHR, B_CHR,SPCE_CHR,SPCE_CHR,SPCE_CHR, B_CHR,SPCE_CHR,SPCE_CHR,SPCE_CHR, B_CHR,B_CHR,SPCE_CHR,SPCE_CHR };
char L_right[4 * 4] = { SPCE_CHR,SPCE_CHR,SPCE_CHR,SPCE_CHR, SPCE_CHR,SPCE_CHR,SPCE_CHR,SPCE_CHR, B_CHR,B_CHR,B_CHR,SPCE_CHR, B_CHR,SPCE_CHR,SPCE_CHR,SPCE_CHR };
char L_bot[4 * 4] = { SPCE_CHR,SPCE_CHR,SPCE_CHR,SPCE_CHR, B_CHR,B_CHR,SPCE_CHR,SPCE_CHR, SPCE_CHR,B_CHR,SPCE_CHR,SPCE_CHR, SPCE_CHR,B_CHR,SPCE_CHR,SPCE_CHR };
char L_left[4 * 4] = { SPCE_CHR,SPCE_CHR,SPCE_CHR,SPCE_CHR, SPCE_CHR,SPCE_CHR,SPCE_CHR,SPCE_CHR, SPCE_CHR,SPCE_CHR,B_CHR,SPCE_CHR, B_CHR,B_CHR,B_CHR,SPCE_CHR };

//J
char J_top[4 * 4] = { SPCE_CHR,SPCE_CHR,SPCE_CHR,SPCE_CHR, SPCE_CHR,B_CHR,SPCE_CHR,SPCE_CHR, SPCE_CHR,B_CHR,SPCE_CHR,SPCE_CHR, B_CHR,B_CHR,SPCE_CHR,SPCE_CHR };
char J_right[4 * 4] = { SPCE_CHR,SPCE_CHR,SPCE_CHR,SPCE_CHR, SPCE_CHR,SPCE_CHR,SPCE_CHR,SPCE_CHR, B_CHR,SPCE_CHR,SPCE_CHR,SPCE_CHR, B_CHR,B_CHR,B_CHR,SPCE_CHR };
char J_bot[4 * 4] = { SPCE_CHR,SPCE_CHR,SPCE_CHR,SPCE_CHR, B_CHR,B_CHR,SPCE_CHR,SPCE_CHR, B_CHR,SPCE_CHR,SPCE_CHR,SPCE_CHR, B_CHR,SPCE_CHR,SPCE_CHR,SPCE_CHR };
char J_left[4 * 4] = { SPCE_CHR,SPCE_CHR,SPCE_CHR,SPCE_CHR, SPCE_CHR,SPCE_CHR,SPCE_CHR,SPCE_CHR, B_CHR,B_CHR,B_CHR,SPCE_CHR, SPCE_CHR,SPCE_CHR,B_CHR,SPCE_CHR };

//S
char S_horizontal[4 * 4] = { SPCE_CHR,SPCE_CHR,SPCE_CHR,SPCE_CHR, SPCE_CHR,SPCE_CHR,SPCE_CHR,SPCE_CHR, SPCE_CHR,B_CHR,B_CHR,SPCE_CHR, B_CHR,B_CHR,SPCE_CHR,SPCE_CHR };
char S_vertical[4 * 4] = { SPCE_CHR,SPCE_CHR,SPCE_CHR,SPCE_CHR, B_CHR,SPCE_CHR,SPCE_CHR,SPCE_CHR, B_CHR,B_CHR,SPCE_CHR,SPCE_CHR, SPCE_CHR,B_CHR,SPCE_CHR,SPCE_CHR };

//Z
char Z_horizontal[4 * 4] = { SPCE_CHR,SPCE_CHR,SPCE_CHR,SPCE_CHR, SPCE_CHR,SPCE_CHR,SPCE_CHR,SPCE_CHR, B_CHR,B_CHR,SPCE_CHR,SPCE_CHR, SPCE_CHR,B_CHR,B_CHR,SPCE_CHR };
char Z_vertical[4 * 4] = { SPCE_CHR,SPCE_CHR,SPCE_CHR,SPCE_CHR, SPCE_CHR,B_CHR,SPCE_CHR,SPCE_CHR, B_CHR,B_CHR,SPCE_CHR,SPCE_CHR, B_CHR,SPCE_CHR,SPCE_CHR,SPCE_CHR };

//cross-platform clock() function
clock_t clock_wrapper()
{
#ifdef _WIN32
    return clock();
#else
    struct timespec current_time;
    if (clock_gettime(CLOCK_BOOTTIME, &current_time) != 0) return -1;
    return (current_time.tv_sec * CLOCKS_PER_SEC + current_time.tv_nsec / (1000000000 / CLOCKS_PER_SEC)) / 1000;
#endif // _WIN32
}

void srand_wrapper(unsigned int rand_seed)
{
    random_seed = rand_seed;
}

int rand_wrapper()
{
    int const a = 1103515245;       //https://en.wikipedia.org/wiki/Linear_congruential_generator
    int const c = 12345;
    random_seed = a * random_seed + c;
    return (random_seed >> 16) & 0x7FFF;
}

char sys_init_master()
{
    time_t now_seed;
    time(&now_seed);
    srand_wrapper(now_seed);
    char ch = rand_wrapper();
    srand_wrapper(ch);
    return ch;
}

void sys_init_slave(char seed)
{
    srand_wrapper((unsigned int)seed);
}

void init_curses()
{
    initscr();
    keypad(stdscr, 1);
    noecho();
    curs_set(0);
    raw();
    timeout(1);
    cbreak();
}

void deinit_curses()
{
    keypad(stdscr, 0);
    echo();
    curs_set(1);
    noraw();
    timeout(10000);
    nocbreak();
}

Field_t* init_field(unsigned int width, unsigned int height)
{
    Field_t* fld = (Field_t*)malloc(sizeof(Field_t));

    unsigned int width_l = width + x_offset * 2 + 2;
    unsigned int height_l = height + y_offset * 2 + 2;
    fld->width = width_l;
    fld->width_start = x_offset;
    fld->width_end = width_l - x_offset - 1;
    fld->height = height_l;
    fld->heigth_start = y_offset;
    fld->height_end = height_l - y_offset - 1;
    fld->field = (char**)malloc(sizeof(char*) * height_l);

    size_t i = 0;
    size_t j = 0;
    for (i = 0; i < height_l; ++i)
    {
        fld->field[i] = (char*)calloc(width_l, sizeof(char));
    }

    //draw border
    for (i = 0; i < fld->height; ++i)
    {
        for (j = 0; j < fld->width; ++j)
        {
            if ((i == fld->heigth_start) && (j >= fld->width_start) && (j <= fld->width_end)) fld->field[i][j] = BORDER_CHR_H_TOP;
            else if ((i == fld->height_end) && (j >= fld->width_start) && (j <= fld->width_end)) fld->field[i][j] = BORDER_CHR_H_BOT;
            else if (((j == fld->width_start) && (i >= fld->heigth_start - 2) && (i <= fld->height_end)) \
                || ((j == fld->width_end) && (i >= fld->heigth_start - 2) && (i <= fld->height_end))) fld->field[i][j] = BORDER_CHR_V;
            else fld->field[i][j] = SPCE_CHR;
        }
    }
    fld->field[fld->heigth_start][fld->width_start] = BORDER_CHR_V;
    fld->field[fld->heigth_start][fld->width_end] = BORDER_CHR_V;
    return fld;
}

void remove_field(Field_t* fld)
{
    size_t i = 0;
    for (i = 0; i < fld->height; ++i)
    {
        free(fld->field[i]);
    }
    free(fld->field);
    free(fld);
}

void print_field(Field_t* fld)
{
    size_t i = 0;
    size_t j = 0;
    for (i = 0; i <= fld->height_end; ++i)
    {
        for (j = 0; j <= fld->width_end; ++j)
        {
            printw("%c", fld->field[i][j]);
        }
        printw("\n");
    }
    //refresh();
}


void print_enemy_field(Field_t* fld, int y, int x)
{
    size_t i = 0;
    size_t j = 0;
    for (i = 0; i <= fld->height_end; ++i)
    {
        for (j = 0; j <= fld->width_end; ++j)
        {
            //printw("%c", fld->field[i][j]);
            mvprintw(y + i, x + j, "%c", fld->field[i][j]);
        }
    }
    //refresh();
}


void print_fig(Figure_t* fig)
{
    for(int i = 0; i < fig->heigth; i++)
    {
        for(int j = 0; j < fig->width; j++)
        {
            printw("%c", fig->field[i*fig->heigth + j]);
        }
        printw("\n");
    }
    printw("\n");
}

void cpy_projection(Figure_t* fig, Figure_t* proj)
{
    proj->heigth = fig->heigth;
    proj->width = fig->width;
    proj->x = fig->x;
    proj->y = fig->y;
    proj->x_pre = fig->x_pre;
    proj->y_pre = fig->y_pre;
    proj->type = fig->type;
    proj->state = fig->state;

    proj->field = fig->field;
}

void place_down(Figure_t* fig, Field_t* fld)
{
    size_t i, j;
    while (1)
    {
        for (i = 0; i < fig->heigth; ++i)
        {
            for (j = 0; j < fig->width; ++j)
            {
                if ((fld->field[fig->y + i][fig->x + j] != SPCE_CHR) && (fig->field[i * fig->width + j] != SPCE_CHR))
                {
                    fig->y_pre = fig->y;
                    fig->y--;
                    return;
                }
            }
        }

        fig->y_pre = fig->y;
        fig->y++;
    }
}

void draw_figure(Figure_t* fig, char type, char state)
{
    fig->type = type;
    fig->state = state;
    if (type == 'O') fig->field = O_any;
    else if (type == 'I')
    {
        if ((state == '<') || (state == '>')) fig->field = I_horizontal;
        else if ((state == 'v') || (state == '^')) fig->field = I_vertical;
    }
    else if (type == 'T')
    {
        if (state == '^') fig->field = T_top;
        else if (state == '>') fig->field = T_right;
        else if (state == 'v') fig->field = T_bot;
        else if (state == '<') fig->field = T_left;
    }
    else if (type == 'L')
    {
        if (state == '^') fig->field = L_top;
        else if (state == '>') fig->field = L_right;
        else if (state == 'v') fig->field = L_bot;
        else if (state == '<') fig->field = L_left;
    }
    else if (type == 'J')
    {
        if (state == '^') fig->field = J_top;
        else if (state == '>') fig->field = J_right;
        else if (state == 'v') fig->field = J_bot;
        else if (state == '<') fig->field = J_left;
    }
    else if (type == 'S')
    {
        if ((state == '<') || (state == '>')) fig->field = S_horizontal;
        else if ((state == 'v') || (state == '^')) fig->field = S_vertical;
    }
    else if (type == 'Z')
    {
        if ((state == '<') || (state == '>')) fig->field = Z_horizontal;
        else if ((state == 'v') || (state == '^')) fig->field = Z_vertical;
    }
}

void rotate_figure(Figure_t* fig)
{
    if (fig->type == 'O') return;
    else if (fig->type == 'I')
    {
        if ((fig->state == '^') || (fig->state == 'v'))
        {
            fig->state = '>'; //or '<' doesnt matter
            fig->field = I_horizontal;
        }
        else if ((fig->state == '>') || (fig->state == '<'))
        {
            fig->state = '^'; //or 'v' doesnt matter
            fig->field = I_vertical;
        }
    }
    else if (fig->type == 'S')
    {
        if ((fig->state == '^') || (fig->state == 'v'))
        {
            fig->state = '>'; //or '<' doesnt matter
            fig->field = S_horizontal;
        }
        else if ((fig->state == '>') || (fig->state == '<'))
        {
            fig->state = '^'; //or 'v' doesnt matter
            fig->field = S_vertical;
        }
    }
    else if (fig->type == 'Z')
    {
        if ((fig->state == '^') || (fig->state == 'v'))
        {
            fig->state = '>'; //or '<' doesnt matter
            fig->field = Z_horizontal;
        }
        else if ((fig->state == '>') || (fig->state == '<'))
        {
            fig->state = '^'; //or 'v' doesnt matter
            fig->field = Z_vertical;
        }
    }
    else if (fig->type == 'T')
    {
        if (fig->state == '^')
        {
            fig->state = '>';
            fig->field = T_right;
        }
        else if (fig->state == '>')
        {
            fig->state = 'v';
            fig->field = T_bot;
        }
        else if (fig->state == 'v')
        {
            fig->state = '<';
            fig->field = T_left;
        }
        else if (fig->state == '<')
        {
            fig->state = '^';
            fig->field = T_top;
        }
    }
    else if (fig->type == 'L')
    {
        if (fig->state == '^')
        {
            fig->state = '>';
            fig->field = L_right;
        }
        else if (fig->state == '>')
        {
            fig->state = 'v';
            fig->field = L_bot;
        }
        else if (fig->state == 'v')
        {
            fig->state = '<';
            fig->field = L_left;
        }
        else if (fig->state == '<')
        {
            fig->state = '^';
            fig->field = L_top;
        }
    }
    else if (fig->type == 'J')
    {
        if (fig->state == '^')
        {
            fig->state = '>';
            fig->field = J_right;
        }
        else if (fig->state == '>')
        {
            fig->state = 'v';
            fig->field = J_bot;
        }
        else if (fig->state == 'v')
        {
            fig->state = '<';
            fig->field = J_left;
        }
        else if (fig->state == '<')
        {
            fig->state = '^';
            fig->field = J_top;
        }
    }
}

void unrotate_figure(Figure_t* fig)
{
    if (fig->type == 'O') return;
    else if (fig->type == 'I')
    {
        if ((fig->state == '^') || (fig->state == 'v'))
        {
            fig->state = '>'; //or '<' doesnt matter
            fig->field = I_horizontal;
        }
        else if ((fig->state == '>') || (fig->state == '<'))
        {
            fig->state = '^'; //or 'v' doesnt matter
            fig->field = I_vertical;
        }
    }
    else if (fig->type == 'S')
    {
        if ((fig->state == '^') || (fig->state == 'v'))
        {
            fig->state = '>'; //or '<' doesnt matter
            fig->field = S_horizontal;
        }
        else if ((fig->state == '>') || (fig->state == '<'))
        {
            fig->state = '^'; //or 'v' doesnt matter
            fig->field = S_vertical;
        }
    }
    else if (fig->type == 'Z')
    {
        if ((fig->state == '^') || (fig->state == 'v'))
        {
            fig->state = '>'; //or '<' doesnt matter
            fig->field = Z_horizontal;
        }
        else if ((fig->state == '>') || (fig->state == '<'))
        {
            fig->state = '^'; //or 'v' doesnt matter
            fig->field = Z_vertical;
        }
    }
    else if (fig->type == 'T')
    {
        if (fig->state == '^')
        {
            fig->state = '<';
            fig->field = T_left;
        }
        else if (fig->state == '<')
        {
            fig->state = 'v';
            fig->field = T_bot;
        }
        else if (fig->state == 'v')
        {
            fig->state = '>';
            fig->field = T_right;
        }
        else if (fig->state == '>')
        {
            fig->state = '^';
            fig->field = T_top;
        }
    }
    else if (fig->type == 'L')
    {
        if (fig->state == '^')
        {
            fig->state = '<';
            fig->field = L_left;
        }
        else if (fig->state == '<')
        {
            fig->state = 'v';
            fig->field = L_bot;
        }
        else if (fig->state == 'v')
        {
            fig->state = '>';
            fig->field = L_right;
        }
        else if (fig->state == '>')
        {
            fig->state = '^';
            fig->field = L_top;
        }
    }
    else if (fig->type == 'J')
    {
        if (fig->state == '^')
        {
            fig->state = '<';
            fig->field = J_left;
        }
        else if (fig->state == '<')
        {
            fig->state = 'v';
            fig->field = J_bot;
        }
        else if (fig->state == 'v')
        {
            fig->state = '>';
            fig->field = J_right;
        }
        else if (fig->state == '>')
        {
            fig->state = '^';
            fig->field = J_top;
        }
    }
}


void remove_figure(Figure_t* fig)
{
    free(fig);
}

Figure_t* get_figure()
{
    Figure_t* fig = (Figure_t*)malloc(sizeof(Figure_t));
    fig->width = 4; //4x4 figure sprite field for better symmetric rotation
    fig->heigth = 4;
    fig->is_placed = 0;

    char type, state;
    int fig_pool = rand_wrapper() % 7;
    int rotation_pool = rand_wrapper() % 4;
    switch (fig_pool)
    {
    case 0:
        type = 'O';
        break;
    case 1:
        type = 'I';
        break;
    case 2:
        type = 'T';
        break;
    case 3:
        type = 'L';
        break;
    case 4:
        type = 'J';
        break;
    case 5:
        type = 'S';
        break;
    case 6:
        type = 'Z';
        break;
    default:
        type = 'O';
        break;
    }

    switch (rotation_pool)
    {
    case 0:
        state = '^';
        break;
    case 1:
        state = '>';
        break;
    case 2:
        state = '<';
        break;
    case 3:
        state = 'v';
        break;
    default:
        state = '^';
        break;
    }

    draw_figure(fig, type, state);

    return fig;
}

Figure_t* get_figure_norand()
{
    Figure_t* fig = (Figure_t*)malloc(sizeof(Figure_t));
    fig->width = 4; //4x4 figure sprite field for better symmetric rotation
    fig->heigth = 4;
    fig->is_placed = 0;

    char type = 'O';
    char state = '>';

    draw_figure(fig, type, state);

    return fig;
}

void set_fig_coord(Figure_t* fig, Field_t* fld)
{
    //fig->y = y_offset - 1;
    //fig->x = (fld->width / 2) + (fld->width / 4);
    fig->y = y_offset - 2;
    fig->x = (fld->width - x_offset + 2) / 2;
}

void field_cpy(Field_t* from, Field_t* to)
{
    //if ((from->width != to->width) || (from->height != to->height)) return;
    size_t i = 0;
    size_t j = 0;
    for (i = 0; i < from->height; ++i)
    {
        for (j = 0; j < from->width; ++j)
        {
            to->field[i][j] = from->field[i][j];
        }
    }
}

void place_figure_to_field(Field_t* fld, Figure_t* fig)
{
    unsigned int x;
    unsigned int y;
    for (y = fig->y; y < fig->y + fig->heigth; ++y)
    {
        for (x = fig->x; x < fig->x + fig->width; ++x)
        {
            if (fig->field[y - fig->y * (fig->x + fig->width) + x - fig->x] == B_CHR) fld->field[y][x] = PLACED_CHR;
        }
    }
}


int check_borders(Field_t* fld, Figure_t* fig)
{
    unsigned x = fig->x;
    unsigned y = fig->y;
    unsigned v = fig->heigth;
    unsigned h = fig->width;
    unsigned i, j;

    //printf("fig->heigth = %u, fig->width = %u,   ")

    for (i = 0; i < v; ++i, ++y, x = fig->x)
    {
        for (j = 0; j < h; ++j, ++x)
        {
            //printf("figure at [%u][%u] = %c, field at [%u][%u] = %c\n", i, j, fig->field[i][j], y, x, fld->field[y][x]);
            if ((fld->field[y][x] != ' ') && (fig->field[i * h + j] != ' '))
            {
                //printf("Trouble at: x = %u, y = %u\n", x, y);
                return 0;
            }
        }
    }
    return 1;
}


void update_fig_pos(Field_t* fld, Figure_t* fig, char lastmove)        //for ordinary figure
{
    int i = 0;
    int j = 0;
    /*
    //for linux this function provides no blinking figure, but in windows it's blinking
    for (i = 0; i < fig->heigth; ++i)
    {
        for (j = 0; j < fig->width; ++j)
        {
            mvaddch(fig->y_pre + i, fig->x_pre + j, fld->field[fig->y_pre + i][fig->x_pre + j]);
            if (fig->field[i * fig->width + j] == B_CHR) mvaddch(fig->y + i, fig->x + j, B_CHR);
        }
    }
    */
    if (lastmove == '0')
    {
        for (i = 0; i < fig->heigth; ++i)
        {
            for (j = 0; j < fig->width; ++j)
            {
                if (fig->field[i * fig->width + j] == B_CHR) mvaddch(fig->y + i, fig->x + j, B_CHR);
            }
        }
    }
    else if ((lastmove == '^') || (lastmove == 'x') || (lastmove == '<'))
    {
        for (i = 0; i < fig->heigth; ++i)
        {
            for (j = 0; j < fig->width; ++j)
            {
                mvaddch(fig->y_pre + i, fig->x_pre + j, fld->field[fig->y_pre + i][fig->x_pre + j]);
                if (fig->field[i * fig->width + j] == B_CHR) mvaddch(fig->y + i, fig->x + j, B_CHR);
            }
        }
    }
    else if (lastmove == '>')
    {
        for (i = 0; i < fig->heigth; ++i)
        {
            for (j = fig->width - 1; j >= 0; --j)
            {
                mvaddch(fig->y_pre + i, fig->x_pre + j, fld->field[fig->y_pre + i][fig->x_pre + j]);
                if (fig->field[i * fig->width + j] == B_CHR) mvaddch(fig->y + i, fig->x + j, B_CHR);
            }
        }
    }
    else if (lastmove == 'v')
    {
        for (i = fig->heigth - 1; i >= 0; --i)
        {
            for (j = 0; j < fig->width; ++j)
            {
                mvaddch(fig->y_pre + i, fig->x_pre + j, fld->field[fig->y_pre + i][fig->x_pre + j]);
                if (fig->field[i * fig->width + j] == B_CHR) mvaddch(fig->y + i, fig->x + j, B_CHR);
            }
        }
    }

}


void update_fig_pos_enemy(Field_t* fld, Figure_t* fig, char lastmove, int y, int x)        //for nework figure
{
    int i = 0;
    int j = 0;
    /*
    //for linux this function provides no blinking figure, but in windows it's blinking
    for (i = 0; i < fig->heigth; ++i)
    {
        for (j = 0; j < fig->width; ++j)
        {
            mvaddch(fig->y_pre + i, fig->x_pre + j, fld->field[fig->y_pre + i][fig->x_pre + j]);
            if (fig->field[i * fig->width + j] == B_CHR) mvaddch(fig->y + i, fig->x + j, B_CHR);
        }
    }
    */
    if (lastmove == '0')
    {
        for (i = 0; i < fig->heigth; ++i)
        {
            for (j = 0; j < fig->width; ++j)
            {
                if (fig->field[i * fig->width + j] == B_CHR) mvaddch(fig->y + i + y, fig->x + j + x, B_CHR);
            }
        }
    }
    else if ((lastmove == '^') || (lastmove == 'x') || (lastmove == '<'))
    {
        for (i = 0; i < fig->heigth; ++i)
        {
            for (j = 0; j < fig->width; ++j)
            {
                mvaddch(fig->y_pre + i + y, fig->x_pre + j + x, fld->field[fig->y_pre + i][fig->x_pre + j]);
                if (fig->field[i * fig->width + j] == B_CHR) mvaddch(fig->y + i + y, fig->x + j + x, B_CHR);
            }
        }
    }
    else if (lastmove == '>')
    {
        for (i = 0; i < fig->heigth; ++i)
        {
            for (j = fig->width - 1; j >= 0; --j)
            {
                mvaddch(fig->y_pre + i + y, fig->x_pre + j + x, fld->field[fig->y_pre + i][fig->x_pre + j]);
                if (fig->field[i * fig->width + j] == B_CHR) mvaddch(fig->y + i + y, fig->x + j + x, B_CHR);
            }
        }
    }
    else if (lastmove == 'v')
    {
        for (i = fig->heigth - 1; i >= 0; --i)
        {
            for (j = 0; j < fig->width; ++j)
            {
                mvaddch(fig->y_pre + i + y, fig->x_pre + j + x, fld->field[fig->y_pre + i][fig->x_pre + j]);
                if (fig->field[i * fig->width + j] == B_CHR) mvaddch(fig->y + i + y, fig->x + j + x, B_CHR);
            }
        }
    }

}


void update_fig_pos_independent_coords(Field_t* fld, Figure_t* fig, unsigned int x_pre, unsigned int y_pre, char lastmove)     //for projecticle
{
    int i = 0;
    int j = 0;
    /*
    //for linux this function provides no blinking figure, but in windows it's blinking
    for (i = 0; i < fig->heigth; ++i)
    {
        for (j = 0; j < fig->width; ++j)
        {
            mvaddch(y_pre + i, x_pre + j, fld->field[y_pre + i][x_pre + j]);
            if (fig->field[i * fig->width + j] == B_CHR) mvaddch(fig->y + i, fig->x + j, P_CHR);
        }
    }
    */
    if ((lastmove == '^') || (lastmove == 'x') || (lastmove == '<') || (lastmove == 'v') || (lastmove == '0'))
    {
        for (i = 0; i < fig->heigth; ++i)
        {
            for (j = 0; j < fig->width; ++j)
            {
                mvaddch(y_pre + i, x_pre + j, fld->field[y_pre + i][x_pre + j]);
                if (fig->field[i * fig->width + j] == B_CHR) mvaddch(fig->y + i, fig->x + j, P_CHR);
            }
        }
    }
    else if (lastmove == '>')
    {
        for (i = 0; i < fig->heigth; ++i)
        {
            for (j = fig->width - 1; j >= 0; --j)
            {
                mvaddch(y_pre + i, x_pre + j, fld->field[y_pre + i][x_pre + j]);
                if (fig->field[i * fig->width + j] == B_CHR) mvaddch(fig->y + i, fig->x + j, P_CHR);
            }
        }
    }
}


void clear_fig_pos_independent_coords(Field_t* fld, Figure_t* fig, unsigned int x_pre, unsigned int y_pre)     //for projecticle
{
    unsigned i = 0;
    unsigned j = 0;

    for (i = 0; i < fig->heigth; ++i)
    {
        for (j = 0; j < fig->width; ++j)
        {
            mvaddch(y_pre + i, x_pre + j, fld->field[y_pre + i][x_pre + j]);
        }
    }
}


void print_next_fig_score(Field_t* fld, Figure_t* fig, int score, unsigned int level)
{
    unsigned i = 0;
    unsigned j = 0;
    mvprintw(y_offset, x_offset + fld->width_end + 0, "Next:");
    for (i = 0; i < fig->heigth; ++i)
    {
        for (j = 0; j < fig->width; ++j)
        {
            mvaddch(y_offset + 1 + i, x_offset + fld->width - 2 + j, fig->field[i * fig->width + j]);
        }
    }
    mvprintw(y_offset + fig->heigth + 2, x_offset + fld->width_end + 0, "Score: %d", score);
    mvprintw(y_offset + fig->heigth + 4, x_offset + fld->width_end + 0, "Level: %u", level);
    //refresh();
}


void print_next_fig(Field_t* fld, Figure_t* fig, unsigned int level)
{
    unsigned i = 0;
    unsigned j = 0;
    mvprintw(y_offset, x_offset + fld->width_end + 0, "Next:");
    for (i = 0; i < fig->heigth; ++i)
    {
        for (j = 0; j < fig->width; ++j)
        {
            mvaddch(y_offset + 1 + i, x_offset + fld->width - 2 + j, fig->field[i * fig->width + j]);
        }
    }
    mvprintw(y_offset + fig->heigth + 4, x_offset + fld->width_end + 0, "Level: %u", level);
    //refresh();
}


void print_score(Field_t* fld, int score, int enemy_field_offset)
{
    mvprintw(fld->height_end + 2, x_offset + enemy_field_offset + 0, "Score: %d", score);
    //refresh();
}


void place_figure(Field_t* fld, Figure_t* fig)
{
    unsigned i = 0;
    unsigned j = 0;

    for (i = 0; i < fig->heigth; ++i)
    {
        for (j = 0; j < fig->width; ++j)
        {
            if (fig->field[i * fig->width + j] != SPCE_CHR) fld->field[fig->y + i][fig->x + j] = B_CHR;
        }
    }
}


int burn_count(Field_t* fld)
{
    int i = fld->heigth_start + 1;
    int j = fld->width_start + 1;
    int sum = 0;
    int ctr = 0;
    for (; i < fld->height_end; ++i, j = fld->width_start + 1)  //суммировать все непустые клетки
    {
        for (; j < fld->width_end; ++j)
        {
            if (fld->field[i][j] == B_CHR) sum += 1;
        }
        if (sum == fld->width_end - fld->width_start - 1)   //если сумма равна ширине - ряд заполнен
        {
            //сжигаем полностью заполненное
            for (int k = fld->width_start + 1; k < fld->width_end; ++k)
            {
                fld->field[i][k] = SPCE_CHR;
            }

            //двигаем всё поле, выше сожженной строки, вниз;   была сожжена i-я строка
            int i2 = i;
            for (; i2 > fld->heigth_start + 1; --i2)
            {
                for (int k = fld->width_start + 1; k < fld->width_end; ++k)
                {
                    fld->field[i2][k] = fld->field[i2 - 1][k];
                }
            }

            //увеличиваем счетчик очков
            ctr++;
        }
        sum = 0;
    }
    if (ctr == 1) return 100;
    else if (ctr == 2) return 300;
    else if (ctr == 3) return 700;
    else if (ctr == 4) return 1500;
    else return 0;
}


int is_game_over(Field_t* fld)
{
    size_t i = fld->heigth_start;
    size_t j = 0;

    for (j = fld->width_start + 1; j < fld->width_end; ++j)
    {
        if (fld->field[i][j] != BORDER_CHR_H_TOP) return 1;
    }
    return 0;
}

void set_default_settings(settings_t* sttngs)
{
    sttngs->fast_placedown = 1;
    sttngs->show_projection = 1;
    sttngs->heigth = 20;
    sttngs->width = 10;
    sttngs->start_level = 1;
    sttngs->cheat = 0;      //not represented in settings menu
}


void init_game_state(gamestate_t* state, settings_t* sttngs)
{
    state->level = sttngs->start_level;
    state->movedown_speed = initial_movedown_speed - (clock_t)(50 * state->level);
    state->score = 0;
}

void update_level(gamestate_t* state, settings_t* sttngs, int score_prev)
{
    if ((score_prev == 0) && (state->score == 0)) state->level = sttngs->start_level;
    if ((score_prev / 1000) != (state->score / 1000)) state->level = (state->score / 1000) + sttngs->start_level;
    else return;
    if (state->level >= 49) state->level = 49;
}

void update_speed(gamestate_t* state)
{
    if (state->level <= 10)
    {
        state->movedown_speed = initial_movedown_speed - (clock_t)(50 * state->level);
    }
    else
    {
        state->movedown_speed = initial_movedown_speed - 500 - (clock_t)(2 * state->level);
    }
}

int single_game(settings_t* sttngs)
{
    clear();

    sys_init_master();

    gamestate_t gamestate;
    init_game_state(&gamestate, sttngs);

    int key = 0;
    int is_placed = 0;
    int is_pressed = 0;
    int is_proj_clr = 0;
    char lastmove = '0';
    int score_prev = 0;
    int is_paused = 0;

    unsigned x_pre_proj, y_pre_proj;
    //time_t seed_for_fig_gen = sys_init_master();       //send this number to connected slave as seed for random figure generator
    Field_t* game_field_tmp = init_field(sttngs->width, sttngs->heigth);
    clock_t time_then = clock_wrapper();
    clock_t time_now;


    Figure_t* current = NULL;
    Figure_t* next = NULL;
    Figure_t* projection = NULL;
    print_field(game_field_tmp);

    while (1)
    {
        is_placed = 0;
        lastmove = '0';

        if (current == NULL)        //for very first figure
        {
            current = get_figure();
            projection = get_figure();
            next = get_figure();
            set_fig_coord(current, game_field_tmp);
            x_pre_proj = 0;
            y_pre_proj = 0;
            print_next_fig_score(game_field_tmp, next, gamestate.score, gamestate.level);
            is_proj_clr = 0;
        }
        else if (next == NULL)      //for each another one figure    getch();
        {
            projection = get_figure();
            next = get_figure();
            set_fig_coord(current, game_field_tmp);
            x_pre_proj = 0;
            y_pre_proj = 0;
            print_next_fig_score(game_field_tmp, next, gamestate.score, gamestate.level);
            is_proj_clr = 0;
        }

        current->x_pre = current->x;
        current->y_pre = current->y;

        key = getch();
        if ((!is_paused) && (key == KEY_UP)) //up arrow
        {
            rotate_figure(current);
            if (check_borders(game_field_tmp, current) == 0)
            {
                unrotate_figure(current);
            }
            is_pressed = 1;
            lastmove = '^';
        }

        if ((!is_paused) && (key == KEY_LEFT)) //left arrow
        {
            --current->x;
            if (check_borders(game_field_tmp, current) == 0)
            {
                current->y = current->y_pre;
                current->x = current->x_pre;
            }
            is_pressed = 1;
            lastmove = '<';
        }

        if ((!is_paused) && (key == KEY_RIGHT)) //right arrow
        {
            ++current->x;
            if (check_borders(game_field_tmp, current) == 0)
            {
                current->y = current->y_pre;
                current->x = current->x_pre;
            }
            is_pressed = 1;
            lastmove = '>';
        }

        if ((!is_paused) && (key == KEY_DOWN))  //down key
        {
            if (sttngs->fast_placedown == 0)
            {
                ++current->y;
                if (check_borders(game_field_tmp, current) == 0)
                {
                    current->y = current->y_pre;
                    current->x = current->x_pre;
                }
                lastmove = 'v';
            }
            else
            {
                place_down(current, game_field_tmp);
                is_placed = 1;
                lastmove = 'x';
            }
        }

        if (key == KEY_END) break;

        if (key == KEY_BACKSPACE) is_paused = (is_paused == 0) ? 1 : 0;

        //some cheat))
        //if(is_pressed)
        //{
        //    time_then = time_now;    //refresh game tick
        //    is_pressed = 0;
        //}

        //print projection
        if ((is_placed == 0) && (sttngs->show_projection == 1))
        {
            cpy_projection(current, projection);
            place_down(projection, game_field_tmp);
            if (projection->y - current->y >= current->heigth)
            {
                is_proj_clr = 0;
                if (is_proj_clr == 0) update_fig_pos_independent_coords(game_field_tmp, projection, x_pre_proj, y_pre_proj, lastmove);
                x_pre_proj = projection->x;
                y_pre_proj = projection->y;
            }
            else if (is_proj_clr == 0)
            {
                clear_fig_pos_independent_coords(game_field_tmp, projection, x_pre_proj, y_pre_proj);
                is_proj_clr = 1;
            }
            else if ((is_proj_clr == 1) && (projection->y - current->y >= current->heigth))
            {
                is_proj_clr = 0;
                x_pre_proj = projection->x;
                y_pre_proj = projection->y;
            }
        }


        //place down timer
        time_now = clock_wrapper();
        if ((is_placed == 0) && (time_now - time_then >= gamestate.movedown_speed))
        {
            if (!is_paused) ++current->y;
            if (check_borders(game_field_tmp, current) == 0)
            {
                current->y = current->y_pre;
                current->x = current->x_pre;
                if (is_pressed && (sttngs->cheat)) is_placed = 0;
                else is_placed = 1;
            }
            //mvprintw(22, 22, "dt: %lld", (long long)(time_now - time_then));
            //mvprintw(23, 22, "t+1: %lld", (long long)(time_now));
            //mvprintw(24, 22, "t-1: %lld", (long long)(time_then));
            time_then = time_now;
            is_pressed = 0;
            lastmove = 'v';
        }
        else if (is_placed == 1)
        {
            time_then = time_now;
        }

        //refresh figure
        update_fig_pos(game_field_tmp, current, lastmove);

        //place figure to the field
        if (is_placed == 1)
        {
            place_figure(game_field_tmp, current);
            score_prev = gamestate.score;
            gamestate.score = gamestate.score + burn_count(game_field_tmp);
            update_level(&gamestate, sttngs, score_prev);
            update_speed(&gamestate);
            clear();
            print_field(game_field_tmp);
            remove_figure(current);
            remove_figure(projection);
            current = next;
            next = NULL;
            if (is_game_over(game_field_tmp) == 1) break;
        }

    }   //end of while loop

    if (next != NULL) remove_figure(next);
    if (current != NULL) remove_figure(current);
    //if (projection != NULL) remove_figure(projection);
    if (game_field_tmp != NULL) remove_field(game_field_tmp);
    clear();
    printw("GG! ur score = %d\n", gamestate.score);
    printw("Press any arrow key to exit\n");
    refresh();
    while (1)
    {
        key = getch();
        if ((key == KEY_UP) || (key == KEY_DOWN) || (key == KEY_LEFT) || (key == KEY_RIGHT)) break;
    }

    return gamestate.score;
}

//multiplayer functions
void* thread_figure_sender(void* thread_data)
{
    pthrData_send_t* data = (pthrData_send_t*)thread_data;
    int not_empty;
    Fig_send_t* fig_send_packed;

    while(1)
    {
        fig_send_packed = (Fig_send_t*)malloc(sizeof(Fig_send_t));
        not_empty = fig_q_pop_packed(&(*(data->figures_queue)), &fig_send_packed, &(data->mtx));
        //not_empty = fig_q_pop_packed(&(data->figures_queue), &fig_send_packed, &(data->mtx));
        if (not_empty == 1)
        {
            write_wrapper(*(data->client_fd), fig_send_packed, sizeof(Fig_send_t));
        }
        else
        {
#ifdef _WIN32
            Sleep(1);
#else
            usleep(1);
#endif
        }
        free(fig_send_packed);
        if (data->stop == 1) break;
    }

    pthread_exit(NULL);
}

int write_fig(int sockfd, Figure_t* figtosend, size_t len)
{
    Fig_send_t* fig_send_packed = (Fig_send_t*)malloc(sizeof(Fig_send_t));
    fig_send_packed->is_placed = figtosend->is_placed;
    fig_send_packed->state = figtosend->state;
    fig_send_packed->type = figtosend->type;
    fig_send_packed->x = figtosend->x;
    fig_send_packed->x_pre = figtosend->x_pre;
    fig_send_packed->y = figtosend->y;
    fig_send_packed->y_pre = figtosend->y_pre;
    int sended = write_wrapper(sockfd, fig_send_packed, sizeof(Fig_send_t));
    free(fig_send_packed);
    return sended;
}

void* thread_figure_getter(void* thread_data)
{
    pthrData_get_t* data = (pthrData_get_t*)thread_data;
    Fig_send_t* fig_get_packed = NULL;
    int bytes;

    while(1)
    {
        //fig_get_packed = (Fig_send_t*)malloc(sizeof(Fig_send_t));
        bytes = read_wrapper3(*(data->client_fd), &fig_get_packed, sizeof(Fig_send_t));
        if ((bytes == 0) || (bytes < 0))
        {
            free(fig_get_packed);
            data->stop = 1;
            break;
        }
        fig_q_push_packed(&(data->figures_queue), &fig_get_packed, &(data->mtx));
        free(fig_get_packed);
        fig_get_packed = NULL;
        if (data->stop == 1) break;
    }

    pthread_exit(NULL);
}

int multiplayer_game(settings_t* sttngs, int server_or_client)
{
    clear();
    gamestate_t gamestate;
    init_game_state(&gamestate, sttngs);

    int key = 0;
    int is_placed = 0;
    int is_pressed = 0;
    int is_proj_clr = 0;
    char lastmove = '0';
    int score_prev = 0;
    int is_paused = 0;
    int my_game_is_over = 0;

    int is_placed_enemy = 0;
    char lastmove_enemy = '0';
    int score_enemy = 0;
    int in_q = 0;
    int in_q_ctr = 0;

    unsigned x_pre_proj, y_pre_proj;
    Field_t* game_field_tmp = init_field(sttngs->width, sttngs->heigth);
    Field_t* game_field_enemy = init_field(sttngs->width, sttngs->heigth);
    int enemy_field_offset = game_field_enemy->width_end + 14;

    Figure_t* enemy_fig = NULL;
    Figure_t* current = NULL;
    Figure_t* next = NULL;
    Figure_t* projection = NULL;

    //network init
    int server, client_fd;

#ifdef _WIN32
    WSADATA d;
    WSAStartup(MAKEWORD(2, 2), &d);
#endif

    if (server_or_client == 1)
    {
        char seed_to_send = sys_init_master(); //send this value to client for use as random seed
        clear();
        mvprintw(10, 10, "Awaiting for connection...");
        refresh();
        int truevar = 1;
        server = socket_wrapper(AF_INET, SOCK_STREAM, 0);
        setsockopt(server, SOL_SOCKET, SO_REUSEADDR, &truevar, sizeof(int));
        struct sockaddr_in addr = {0};
        addr.sin_family = AF_INET;
        addr.sin_port = htons(65431);
        bind_wrapper(server, (struct sockaddr*)&addr, sizeof(addr));
        listen_wrapper(server, 1);
        socklen_t addrlen = sizeof(addr);
        client_fd = accept_wrapper(server, (struct sockaddr*)&addr, &addrlen);
        write_seed(client_fd, seed_to_send, sizeof(char));
    }
    else if (server_or_client == 0)
    {
        char seed_to_get;
        char IP[25] = {0};
        clear();
        deinit_curses();
        while(1)
        {
            clear();
            printw("Enter IP: ");
            get_IP_from_user_input(IP);
            if (IP[0] == 'E')
            {
                remove_field(game_field_tmp);
                remove_field(game_field_enemy);
                clear();
                init_curses();
                refresh();
                return 0;
            }
            if (is_valid_ip(IP) == 1) break;
            for(int ctrip = 0; ctrip < 25; ctrip++)
            {
                IP[ctrip] = 0;
            }
        }
        clear();
        init_curses();
        refresh();
        client_fd = socket_wrapper(AF_INET, SOCK_STREAM, 0);
        struct sockaddr_in addr = {0};
        addr.sin_family = AF_INET;
        addr.sin_port = htons(65431);
        //inet_pton_wrapper(AF_INET, "127.0.0.1", &addr.sin_addr);  //debug
        inet_pton_wrapper(AF_INET, IP, &addr.sin_addr);
        int is_connected = -1;
        while(is_connected == -1)
        {
            is_connected = connect_wrapper(client_fd, (struct sockaddr_in *)(&addr), sizeof(addr));
        }

        read_seed(client_fd, &seed_to_get, sizeof(char));
        sys_init_slave(seed_to_get);
    }

    //end of network init

    //threading init
    Fig_q* figures_queue = NULL;

    mutex_q_get = (pthread_mutex_t*)malloc(sizeof(pthread_mutex_t));
    pthread_mutex_init(mutex_q_get, NULL);

    //*
    pthrData_get_t* thread_args = (pthrData_get_t*)malloc(sizeof(pthrData_get_t));
    thread_args->client_fd = &client_fd;
    thread_args->figures_queue = &figures_queue;
    thread_args->mtx = mutex_q_get;
    thread_args->stop = 0;

    pthread_t* thread_get_fig = (pthread_t*) malloc(sizeof(pthread_t));
    pthread_create(thread_get_fig, NULL, thread_figure_getter, thread_args);
    pthread_detach(*thread_get_fig);
    //end of threading init

    clear();
    refresh();
    print_field(game_field_tmp);
    print_enemy_field(game_field_enemy, 0, enemy_field_offset);

    clock_t time_then = clock_wrapper();
    clock_t time_now;

    while (1)
    {
        key = getch();
        //if ((key == KEY_END) || (thread_args->stop == 1)) break;
        if (key == KEY_END) break;

        if (thread_args->stop == 0)
        {
            enemy_fig = get_figure_norand();
            in_q = fig_q_pop(&figures_queue, &enemy_fig, &mutex_q_get);
            if (in_q == 0)
            {
                in_q_ctr++;
                remove_figure(enemy_fig);
                if ((in_q_ctr >= 1000) && (my_game_is_over == 1)) thread_args->stop = 1;
            }
            else
            {
                in_q_ctr = 0;
                is_placed_enemy = (enemy_fig->is_placed == 0) ? 0 : 1;
                if (enemy_fig->x > enemy_fig->x_pre) lastmove_enemy = '>';
                if (enemy_fig->x < enemy_fig->x_pre) lastmove_enemy = '<';
                if (enemy_fig->y > enemy_fig->y_pre) lastmove_enemy = 'v';

                //refresh enemy figure
                update_fig_pos_enemy(game_field_enemy, enemy_fig, lastmove_enemy, 0, enemy_field_offset);

                //place figure to the field
                if (is_placed_enemy == 1)
                {
                    place_figure(game_field_enemy, enemy_fig);
                    score_enemy = score_enemy + burn_count(game_field_enemy);
                    clear();
                    print_field(game_field_tmp);
                    //if (next != NULL) print_next_fig_score(game_field_tmp, next, gamestate.score, gamestate.level);
                    if (next != NULL) print_next_fig(game_field_tmp, next, gamestate.level);
                    print_score(game_field_tmp, gamestate.score, 0);
                    print_score(game_field_enemy, score_enemy, enemy_field_offset);
                    print_enemy_field(game_field_enemy, 0, enemy_field_offset);
                    //if (is_game_over(game_field_enemy) == 1) break;
                }

                remove_figure(enemy_fig);
                enemy_fig = NULL;
            }
        }


        //////////////////////////////////////

        if (my_game_is_over == 0)
        {
            is_placed = 0;
            lastmove = '0';

            if (current == NULL)        //for very first figure
            {
                current = get_figure();
                projection = get_figure_norand();
                next = get_figure();
                set_fig_coord(current, game_field_tmp);
                x_pre_proj = 0;
                y_pre_proj = 0;
                //print_next_fig_score(game_field_tmp, next, gamestate.score, gamestate.level);
                print_next_fig(game_field_tmp, next, gamestate.level);
                print_score(game_field_tmp, gamestate.score, 0);
                print_score(game_field_enemy, score_enemy, enemy_field_offset);
                is_proj_clr = 0;
            }
            else if (next == NULL)      //for each another one figure
            {
                projection = get_figure_norand();
                next = get_figure();
                set_fig_coord(current, game_field_tmp);
                x_pre_proj = 0;
                y_pre_proj = 0;
                //print_next_fig_score(game_field_tmp, next, gamestate.score, gamestate.level);
                print_next_fig(game_field_tmp, next, gamestate.level);
                print_score(game_field_tmp, gamestate.score, 0);
                print_score(game_field_enemy, score_enemy, enemy_field_offset);
                is_proj_clr = 0;
            }

            current->x_pre = current->x;
            current->y_pre = current->y;

            if ((!is_paused) && (key == KEY_UP)) //up arrow
            {
                rotate_figure(current);
                if (check_borders(game_field_tmp, current) == 0)
                {
                    unrotate_figure(current);
                }
                is_pressed = 1;
                lastmove = '^';

                if (thread_args->stop == 0) write_fig(client_fd, current, sizeof(Figure_t));
            }

            if ((!is_paused) && (key == KEY_LEFT)) //left arrow
            {
                --current->x;
                if (check_borders(game_field_tmp, current) == 0)
                {
                    current->y = current->y_pre;
                    current->x = current->x_pre;
                }
                is_pressed = 1;
                lastmove = '<';

                if (thread_args->stop == 0) write_fig(client_fd, current, sizeof(Figure_t));
            }

            if ((!is_paused) && (key == KEY_RIGHT)) //right arrow
            {
                ++current->x;
                if (check_borders(game_field_tmp, current) == 0)
                {
                    current->y = current->y_pre;
                    current->x = current->x_pre;
                }
                is_pressed = 1;
                lastmove = '>';

                if (thread_args->stop == 0) write_fig(client_fd, current, sizeof(Figure_t));
            }

            if ((!is_paused) && (key == KEY_DOWN))  //down key
            {
                if (sttngs->fast_placedown == 0)
                {
                    ++current->y;
                    if (check_borders(game_field_tmp, current) == 0)
                    {
                        current->y = current->y_pre;
                        current->x = current->x_pre;
                    }
                    lastmove = 'v';
                }
                else
                {
                    place_down(current, game_field_tmp);
                    is_placed = 1;
                    current->is_placed = 1;
                    lastmove = 'x';
                }

                if (thread_args->stop == 0) write_fig(client_fd, current, sizeof(Figure_t));
            }


            if (key == KEY_BACKSPACE) is_paused = (is_paused == 0) ? 1 : 0;


            //print projection
            if ((is_placed == 0) && (sttngs->show_projection == 1))
            {
                cpy_projection(current, projection);
                place_down(projection, game_field_tmp);
                if (projection->y - current->y >= current->heigth)
                {
                    is_proj_clr = 0;
                    if (is_proj_clr == 0) update_fig_pos_independent_coords(game_field_tmp, projection, x_pre_proj, y_pre_proj, lastmove);
                    x_pre_proj = projection->x;
                    y_pre_proj = projection->y;
                }
                else if (is_proj_clr == 0)
                {
                    clear_fig_pos_independent_coords(game_field_tmp, projection, x_pre_proj, y_pre_proj);
                    is_proj_clr = 1;
                }
                else if ((is_proj_clr == 1) && (projection->y - current->y >= current->heigth))
                {
                    is_proj_clr = 0;
                    x_pre_proj = projection->x;
                    y_pre_proj = projection->y;
                }
            }


            //place down timer
            time_now = clock_wrapper();
            if ((is_placed == 0) && (time_now - time_then >= gamestate.movedown_speed))
            {
                if (!is_paused) ++current->y;
                if (check_borders(game_field_tmp, current) == 0)
                {
                    current->y = current->y_pre;
                    current->x = current->x_pre;
                    if (is_pressed && (sttngs->cheat))
                    {
                        current->is_placed = 0;
                        is_placed = 0;
                    }
                    else
                    {
                        current->is_placed = 1;
                        is_placed = 1;
                    }
                }

                if (thread_args->stop == 0) write_fig(client_fd, current, sizeof(Figure_t));

                time_then = time_now;
                is_pressed = 0;
                lastmove = 'v';
            }
            else if (is_placed == 1)
            {
                time_then = time_now;
            }

            //refresh figure
            update_fig_pos(game_field_tmp, current, lastmove);

            //place figure to the field
            if (is_placed == 1)
            {
                place_figure(game_field_tmp, current);
                score_prev = gamestate.score;
                gamestate.score = gamestate.score + burn_count(game_field_tmp);
                update_level(&gamestate, sttngs, score_prev);
                update_speed(&gamestate);
                clear();
                print_field(game_field_tmp);
                print_enemy_field(game_field_enemy, 0, enemy_field_offset);
                print_score(game_field_tmp, gamestate.score, 0);
                print_score(game_field_enemy, score_enemy, enemy_field_offset);
                remove_figure(current);
                remove_figure(projection);
                current = next;
                next = NULL;
                if (is_game_over(game_field_tmp) == 1) my_game_is_over = 1;
            }
        }
        else
        {
            //print_field(game_field_tmp);
            //print score
        }

        if ((thread_args->stop == 1) && (my_game_is_over == 1)) break;

    }   //end of while loop

    thread_args->stop = 1;
    if (next != NULL) remove_figure(next);
    if (current != NULL) remove_figure(current);
    //if (projection != NULL) remove_figure(projection);
    if (game_field_tmp != NULL) remove_field(game_field_tmp);
    if (game_field_enemy != NULL) remove_field(game_field_enemy);
    clear();
    printw("GG! ur score = %d\n", gamestate.score);
    printw("ur enemy score = %d\n", score_enemy);
    printw("Press any arrow key to exit\n");
    refresh();
    while (1)
    {
        key = getch();
        if ((key == KEY_UP) || (key == KEY_DOWN) || (key == KEY_LEFT) || (key == KEY_RIGHT)) break;
    }

#ifdef _WIN32
    Sleep(1);
#else
    usleep(1000);
#endif
    free(thread_get_fig);
    free(thread_args);
    pthread_mutex_destroy(mutex_q_get);
    fig_q_remove(&figures_queue);
    if (server_or_client == 1)
    {
#ifdef _WIN32
        closesocket(client_fd);
        closesocket(server);
        WSACleanup();
#else
        close(client_fd);
        close(server);
#endif
    }
    return gamestate.score;
}

void get_IP_from_user_input(char* IP)
{
#ifdef WIN32
    fflush(stdin);
#endif // WIN32

    int ctr = 0;
    char c;

    while (((c = (char)getch()) != '\n') && (ctr <= 20))
    {
        IP[ctr] = c;
        ctr++;
        if (ctr > 20) break;
    }

    IP[ctr] = '\0';

#ifdef WIN32
    fflush(stdin);
#endif // WIN32
}


int intpow(int val, int power)
{
    int out = val;
    if (val == 0) return 0;
    if (power == 0) return 1;
    for(int i = 1; i < power; i++)
    {
        out = out*val;
    }
    return out;
}

int is_valid_ip(const char * addr)
{
    int out = 0;
    unsigned i = 0;
    unsigned count_point = 0;
    int ip_part = -1;
    unsigned j = 0;
    while(addr[i] != '\0')
    {
        ip_part = -1;
        j = 0;
        while(addr[i] != '\0')
        {
            if ((addr[i] == '.') || (addr[i] == '\0'))
            {
                if (addr[i] == '.') count_point++;
                if (ip_part <= -1) return out;
                ip_part = ip_part / intpow(10, 3 - j);
                if (ip_part > 255) return out; //wrong ip part, exit
                else       //ok
                {
                    i++;
                    break;
                }
            }
            if ((addr[i] < 48) || (addr[i] > 57))
            {
                return out;   //wrong symbol in ip part
            }
            else
            {
                if (ip_part == -1) ip_part = 0;
                if (j > 2) return out;
                //if (((addr[i] - 48) == 0) && (j == 0)) return out;
                ip_part = ip_part + (addr[i] - 48)*intpow(10, 2 - j);
            }
            if (ip_part / intpow(10, 3 - j) > 255)
            {
                return out; //wrong ip part, exit
            }

            i++;
            j++;
        }

    }
    if (count_point == 3) out = 1;
    else out = 0;
    return out;
}

