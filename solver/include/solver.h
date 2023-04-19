/*
** EPITECH PROJECT, 2022
** B-CPE-200-RUN-2-1-dante-clement-antoine.xavier [WSL : Fedora]
** File description:
** solver.h
*/

#ifndef _SOLVER_H_
    #define _SOLVER_H_

    #include <sys/stat.h>

typedef struct position_s {
    int x;
    int y;
} position_t;

int equal_position(position_t pos1, position_t pos2);

typedef struct stack_s {
    position_t *position;
    int size;
} stack_t;

stack_t *init_stack(void);
int add_to_stack(stack_t *stack, position_t position);
int remove_from_stack(stack_t *stack, position_t *position);
void terminate_stack(stack_t *stack);
void print_stack(stack_t *stack);
position_t get_stack_head(stack_t *stack);

typedef struct solver_s {
    char *file_path;
    struct stat metadata;
    char *buffer;
    int buffer_size;
    char **maze;
    unsigned char **visited;
    int height;
    int width;
    stack_t *path;
    double **distances;
} solver_t;

solver_t *init_solver(int argc, char **argv);
void terminate_solver(solver_t *solver);
int init_solver_objects(solver_t *solver);
int read_file(solver_t *solver);
int check_maze(solver_t *solver);
int print_maze(solver_t *solver);
int solve_maze(solver_t *solver);
void add_path_to_maze(solver_t *solver);
double calcul_distance(int x1, int y1, int x2, int y2);
int init_solver_array(solver_t *solver);

#endif
