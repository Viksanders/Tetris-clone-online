#ifndef CORE_FUCNTIONS_H_INCLUDED
#define CORE_FUCNTIONS_H_INCLUDED

#include "constants.h"
#include "queue_fig.h"
#include "net_functions.h"

clock_t clock_wrapper();   //cross-platform clock() function for Linux/win32
void srand_wrapper(unsigned int rand_seed);		//cross-platform random numbers generation
int rand_wrapper();
char sys_init_master();		//generating random seed at server side for both player's figures to be the same
void sys_init_slave(char seed);	//see the description above
void init_curses();
void deinit_curses();
Field_t* init_field(unsigned int width, unsigned int height);
void remove_field(Field_t* fld);		//free(field_var)
void print_field(Field_t* fld);
void print_enemy_field(Field_t* fld, int y, int x);	//multiplayer only
void print_fig(Figure_t* fig);          //debug only
void cpy_projection(Figure_t* fig, Figure_t* proj);
void place_down(Figure_t* fig, Field_t* fld);
void draw_figure(Figure_t* fig, char type, char state);
void rotate_figure(Figure_t* fig);
void unrotate_figure(Figure_t* fig);
void remove_figure(Figure_t* fig);
Figure_t* get_figure();                 //memory alloc here, has random call
Figure_t* get_figure_norand();          //memory alloc here, no random call
void set_fig_coord(Figure_t* fig, Field_t* fld);
void field_cpy(Field_t* from, Field_t* to);	//debug
void place_figure_to_field(Field_t* fld, Figure_t* fig);
int check_borders(Field_t* fld, Figure_t* fig);
void update_fig_pos(Field_t* fld, Figure_t* fig, char lastmove);        //for ordinary figure
void update_fig_pos_enemy(Field_t* fld, Figure_t* fig, char lastmove, int y, int x);    //for network figure
void update_fig_pos_independent_coords(Field_t* fld, Figure_t* fig, unsigned int x_pre, unsigned int y_pre, char lastmove);     //for projecticle
void clear_fig_pos_independent_coords(Field_t* fld, Figure_t* fig, unsigned int x_pre, unsigned int y_pre);    //for projecticle
void print_next_fig_score(Field_t* fld, Figure_t* fig, int score, unsigned int level);
void print_next_fig(Field_t* fld, Figure_t* fig, unsigned int level);
void print_score(Field_t* fld, int score, int enemy_field_offset);
void place_figure(Field_t* fld, Figure_t* fig);
int burn_count(Field_t* fld);    //функция пробегает по полю и возвращает количество сток, полностью заполненных B_CHR символом
int is_game_over(Field_t* fld);
void set_default_settings(settings_t* sttngs);
void init_game_state(gamestate_t* state, settings_t* sttngs);
void update_level(gamestate_t* state, settings_t* sttngs, int score_prev);
void update_speed(gamestate_t* state);
int single_game(settings_t* sttngs);

//multiplayer functions
void* thread_figure_sender(void* thread_data);	//Old version relic. Unused in this version, send() function is non-blocking (but recv() is not) 
void* thread_figure_getter(void* thread_data);	//some recv() call inside
int write_fig(int sockfd, Figure_t* figtosend, size_t len);		//replacement of thread_figure_sender(void* thread_data), send()/write() call inside
int multiplayer_game(settings_t* sttngs, int server_or_client);
void get_IP_from_user_input(char* IP);
int intpow(int val, int power);     //used in is_valid_ip() fcn
int is_valid_ip(const char * addr); //check IP address

#endif // CORE_FUCNTIONS_H_INCLUDED
