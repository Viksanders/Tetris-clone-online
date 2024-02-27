#include "queue_fig.h"

pthread_mutex_t* mutex_q_send;
pthread_mutex_t* mutex_q_get;

void fig_q_push(struct node_queue** first, Figure_t** fig, pthread_mutex_t** mutex_q)
{
    pthread_mutex_lock(*mutex_q);
    if(*first == NULL)
    {
        *first = (struct node_queue*)malloc(sizeof(struct node_queue));
        (*first)->next = NULL;

        (*first)->data.state = (*fig)->state;
        (*first)->data.type = (*fig)->type;
        (*first)->data.x = (*fig)->x;
        (*first)->data.x_pre = (*fig)->x_pre;
        (*first)->data.y = (*fig)->y;
        (*first)->data.y_pre = (*fig)->y_pre;
        (*first)->data.is_placed = (*fig)->is_placed;
    }
    else
    {
        struct node_queue* loop_ptr = *first;
        while(loop_ptr->next != NULL)
        {
            loop_ptr = loop_ptr->next;
        }
        loop_ptr->next = (struct node_queue*)malloc(sizeof(struct node_queue));
        loop_ptr->next->next = NULL;

        loop_ptr->next->data.state = (*fig)->state;
        loop_ptr->next->data.type = (*fig)->type;
        loop_ptr->next->data.x = (*fig)->x;
        loop_ptr->next->data.x_pre = (*fig)->x_pre;
        loop_ptr->next->data.y = (*fig)->y;
        loop_ptr->next->data.y_pre = (*fig)->y_pre;
        loop_ptr->next->data.is_placed = (*fig)->is_placed;
    }
    pthread_mutex_unlock(*mutex_q);
}

void fig_q_push_packed(struct node_queue** first, Fig_send_t** fig, pthread_mutex_t** mutex_q)
{
    pthread_mutex_lock(*mutex_q);
    if(*first == NULL)
    {
        *first = (struct node_queue*)malloc(sizeof(struct node_queue));
        (*first)->next = NULL;

        (*first)->data.state = (*fig)->state;
        (*first)->data.type = (*fig)->type;
        (*first)->data.x = (*fig)->x;
        (*first)->data.x_pre = (*fig)->x_pre;
        (*first)->data.y = (*fig)->y;
        (*first)->data.y_pre = (*fig)->y_pre;
        (*first)->data.is_placed = (*fig)->is_placed;
    }
    else
    {
        struct node_queue* loop_ptr = *first;
        while(loop_ptr->next != NULL)
        {
            loop_ptr = loop_ptr->next;
        }
        loop_ptr->next = (struct node_queue*)malloc(sizeof(struct node_queue));
        loop_ptr->next->next = NULL;

        loop_ptr->next->data.state = (*fig)->state;
        loop_ptr->next->data.type = (*fig)->type;
        loop_ptr->next->data.x = (*fig)->x;
        loop_ptr->next->data.x_pre = (*fig)->x_pre;
        loop_ptr->next->data.y = (*fig)->y;
        loop_ptr->next->data.y_pre = (*fig)->y_pre;
        loop_ptr->next->data.is_placed = (*fig)->is_placed;
    }
    pthread_mutex_unlock(*mutex_q);
}


void fig_q_repack(Figure_t** fig, char type, char state)
{
    (*fig)->type = type;
    (*fig)->state = state;
    if (type == 'O') (*fig)->field = O_any;
    else if (type == 'I')
    {
        if ((state == '<') || (state == '>')) (*fig)->field = I_horizontal;
        else if ((state == 'v') || (state == '^')) (*fig)->field = I_vertical;
    }
    else if (type == 'T')
    {
        if (state == '^') (*fig)->field = T_top;
        else if (state == '>') (*fig)->field = T_right;
        else if (state == 'v') (*fig)->field = T_bot;
        else if (state == '<') (*fig)->field = T_left;
    }
    else if (type == 'L')
    {
        if (state == '^') (*fig)->field = L_top;
        else if (state == '>') (*fig)->field = L_right;
        else if (state == 'v') (*fig)->field = L_bot;
        else if (state == '<') (*fig)->field = L_left;
    }
    else if (type == 'J')
    {
        if (state == '^') (*fig)->field = J_top;
        else if (state == '>') (*fig)->field = J_right;
        else if (state == 'v') (*fig)->field = J_bot;
        else if (state == '<') (*fig)->field = J_left;
    }
    else if (type == 'S')
    {
        if ((state == '<') || (state == '>')) (*fig)->field = S_horizontal;
        else if ((state == 'v') || (state == '^')) (*fig)->field = S_vertical;
    }
    else if (type == 'Z')
    {
        if ((state == '<') || (state == '>')) (*fig)->field = Z_horizontal;
        else if ((state == 'v') || (state == '^')) (*fig)->field = Z_vertical;
    }
}


int fig_q_pop(struct node_queue** first, Figure_t** fig, pthread_mutex_t** mutex_q)
{
    pthread_mutex_lock(*mutex_q);
    if(*first == NULL)
    {
        pthread_mutex_unlock(*mutex_q);
        return 0;   //empty
    }
    else
    {
        struct node_queue* temp = *first;
        *first = temp->next;

        (*fig)->state = temp->data.state;
        (*fig)->type = temp->data.type;
        (*fig)->x = temp->data.x;
        (*fig)->x_pre = temp->data.x_pre;
        (*fig)->y = temp->data.y;
        (*fig)->y_pre = temp->data.y_pre;
        (*fig)->is_placed = temp->data.is_placed;

        fig_q_repack(fig, temp->data.type, temp->data.state);

        free(temp);
        pthread_mutex_unlock(*mutex_q);
        return 1;
    }
}

int fig_q_pop_packed(struct node_queue** first, Fig_send_t** fig, pthread_mutex_t** mutex_q)
{
    pthread_mutex_lock(*mutex_q);
    if(*first == NULL)
    {
        pthread_mutex_unlock(*mutex_q);
        return 0;   //empty
    }
    else
    {
        struct node_queue* temp = *first;
        *first = temp->next;

        (*fig)->state = temp->data.state;
        (*fig)->type = temp->data.type;
        (*fig)->x = temp->data.x;
        (*fig)->x_pre = temp->data.x_pre;
        (*fig)->y = temp->data.y;
        (*fig)->y_pre = temp->data.y_pre;
        (*fig)->is_placed = temp->data.is_placed;

        free(temp);
        pthread_mutex_unlock(*mutex_q);
        return 1;
    }
}


void fig_q_remove(struct node_queue** first)
{
    if(*first == NULL)
    {
        return;
    }
    else
    {
        struct node_queue* loop_ptr = *first;
        while(loop_ptr != NULL)
        {
            struct node_queue* temp = loop_ptr;
            loop_ptr = loop_ptr->next;
            free(temp);
        }
    }
    //(*first) = NULL;
}



