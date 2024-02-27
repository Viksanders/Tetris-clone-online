#ifndef QUEUE_FIG_H_INCLUDED
#define QUEUE_FIG_H_INCLUDED

#include "constants.h"


void fig_q_push(struct node_queue** first, Figure_t** fig, pthread_mutex_t** mutex_q);            //mem alloc here
void fig_q_push_packed(struct node_queue** first, Fig_send_t** fig, pthread_mutex_t** mutex_q);   //mem alloc here
void fig_q_repack(Figure_t** fig, char type, char state);                                         //same as draw_figure() from "core_functions.h"
int fig_q_pop(struct node_queue** first, Figure_t** fig, pthread_mutex_t** mutex_q);              //free here
int fig_q_pop_packed(struct node_queue** first, Fig_send_t** fig, pthread_mutex_t** mutex_q);     //free here
void fig_q_remove(struct node_queue** first);                                                    //delete all queue


#endif // QUEUE_FIG_H_INCLUDED
