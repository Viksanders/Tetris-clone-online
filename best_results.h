#ifndef BEST_RESULTS_H_INCLUDED
#define BEST_RESULTS_H_INCLUDED

#define NAMESIZE 50
extern const char* settings_filename;
extern const char* results_filename;

typedef struct Note_t
{
    char name[NAMESIZE];
    int score;
    struct Note_t* next;

} Note_t;

int add_best_result(Note_t** note, Note_t** all_notes);
void print_notes(Note_t** all_notes);
void add_new_note(Note_t** note, Note_t** all_notes);
int is_addable_note(int score, Note_t** all_notes);
void delete_all_notes(Note_t** all_notes);
void get_name_from_user_input(Note_t** note);
void write_results_to_file(Note_t** all_notes);
int load_results_form_file(Note_t** all_notes);


#endif // BEST_RESULTS_H_INCLUDED
