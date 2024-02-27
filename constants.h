#ifndef CONSTANTS_H_INCLUDED
#define CONSTANTS_H_INCLUDED

#include <stdlib.h>
#include <time.h>



#ifdef _WIN32
#include "include/curses.h"
#else
#include <ncurses.h>
#endif // _WIN32


#include <sys/types.h>
#ifdef _WIN32
#define _WIN32_WINNT 0x601      //for win7 and above, 0x501 for win xp
#include <WinSock2.h>
#include <ws2tcpip.h>
#include <WS2spi.h>
#pragma comment(lib, "ws2_32.lib")
#else
#include <sys/socket.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <fcntl.h>
#include <netdb.h>
#endif


#ifdef _WIN32
#define HAVE_STRUCT_TIMESPEC
#include "include/pthread.h"
#include <windows.h>
#else
#include <pthread.h>
#endif

extern const unsigned int x_offset;      //core_functions.c
extern const unsigned int y_offset;
extern clock_t initial_movedown_speed;
extern const unsigned int HEIGTH_MAX;
extern const unsigned int HEIGTH_MIN;
extern const unsigned int WIDTH_MAX;
extern const unsigned int WIDTH_MIN;
extern unsigned int random_seed;


#define B_CHR '*'                       //core_functions.c
#define P_CHR 'o'
#define SPCE_CHR ' '
#define BORDER_CHR_H_BOT '-'
#define BORDER_CHR_H_TOP ' '
#define BORDER_CHR_V '|'
#define PLACED_CHR '1'


extern pthread_mutex_t* mutex_q_send;    //queue_fig.c
extern pthread_mutex_t* mutex_q_get;     //queue_fig.c



#pragma pack(push, 1)
typedef struct figtosend                //queue_fig.c
{
    unsigned int x;
    unsigned int y;
    unsigned int x_pre;
    unsigned int y_pre;
    char type;      //T, O, I, L, J, S, Z
    char state;     //>, <, ^, v
    char is_placed;
}   Fig_send_t;
#pragma pack(pop)

#pragma pack(push, 1)
typedef struct node_queue               //queue_fig.c
{
    struct node_queue* next;
    Fig_send_t data;
} Fig_q;
#pragma pack(pop)


typedef struct pthrData_get
{
    pthread_mutex_t* mtx;
    int* client_fd;
    int stop;
    Fig_q* figures_queue;
} pthrData_get_t;

//YES, IT'S ABSOLUTELY THE SAME STRUCTURE, I'M TOO TIRED TO REFACTOR THIS SH1T
typedef struct pthrData_send
{
    pthread_mutex_t* mtx;
    int* client_fd;
    int stop;
    Fig_q* figures_queue;
} pthrData_send_t;


typedef struct Field_t                  //here and below: core_functions.c
{
    unsigned int width_start;
    unsigned int width_end;
    unsigned int heigth_start;
    unsigned int height_end;
    unsigned int width;
    unsigned int height;
    char** field;
} Field_t;

typedef struct Figure_t
{
    unsigned int x;
    unsigned int y;
    unsigned int x_pre;
    unsigned int y_pre;
    unsigned int width;
    unsigned int heigth;
    char type;      //T, O, I, L, J, S, Z
    char state;     //>, <, ^, v
    char is_placed;
    char* field;
} Figure_t;


typedef struct settings
{
    unsigned char show_projection;
    unsigned char fast_placedown;
    unsigned char cheat;
    unsigned int width;
    unsigned int heigth;
    unsigned int start_level;
} settings_t;


typedef struct current_game_state
{
    unsigned int level;
    int score;
    clock_t movedown_speed;
} gamestate_t;


//FIGURES STORED IN MEMORY
//O
extern char O_any[4 * 4];

//I
extern char I_horizontal[4 * 4];
extern char I_vertical[4 * 4];

//T
extern char T_top[4 * 4];
extern char T_right[4 * 4];
extern char T_bot[4 * 4];
extern char T_left[4 * 4];

//L
extern char L_top[4 * 4];
extern char L_right[4 * 4];
extern char L_bot[4 * 4];
extern char L_left[4 * 4];

//J
extern char J_top[4 * 4];
extern char J_right[4 * 4];
extern char J_bot[4 * 4];
extern char J_left[4 * 4];

//S
extern char S_horizontal[4 * 4];
extern char S_vertical[4 * 4];

//Z
extern char Z_horizontal[4 * 4];
extern char Z_vertical[4 * 4];

#endif // CONSTANTS_H_INCLUDED
