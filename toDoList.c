#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct ToDo {
	struct Task *head;
	struct Task *tail;
};

struct Task {
    char *name;
    struct Task *next;
};

struct Task* task_new(const char *name){
    struct Task *t = malloc(sizeof(struct Task));
    if (t!=NULL){
        t->name = strdup(name);
        t->next = NULL;

    }
    return t;

}

void task_free(struct Task *task){
    if (task != NULL){
        free(task->name);
        free(task);
    }
}


struct ToDo* todo_new(){
    struct ToDo *t = malloc(sizeof(struct ToDo));
    if (t!=NULL){
        t->head = NULL;
        t->tail = NULL;
    }
}

void todo_add(struct ToDo* t, struct Task* task){
    if (t->head == NULL && t->tail == NULL){
        t->head = task;
        t->tail = task;
    }
    else{
        t->tail->next = task; 
        t->tail = task;
    }
}

void todo_print(struct ToDo* t){
    struct Task* current = t->head;
    while (current != NULL){
        printf("Task: %s\n", current->name);
        current = current -> next;
    }
}

void todo_free(struct ToDo* t){
    struct Task* current = t->head;
    struct Task* next_tmp;
    while (current != NULL){
        next_tmp = current->next;
        free(current);
        current = next_tmp;
        
    }
    free(t);
}


int main(){
    struct ToDo* todo = todo_new();

    struct Task *t1 = task_new("Pobieramy eTrapeeza");

    struct Task *t2 = task_new("Nauka do kolokwium z matematyki");

    struct Task *t3 = task_new("pisanie kolokwium");

    todo_add(todo, t1);
    todo_print(todo); //etrapez
    todo_add(todo,t2);
    todo_print(todo); //etrapez, nauka
    todo_add(todo,t3);
    todo_print(todo); //etrapez nauka kolos

    printf("Robimy: %s\n", todo->head->name);
    //todo_remove(todo); //usuniecie todo->head
    todo_print(todo); // nauka, kolowium


    todo_free(todo); // <---task_free();
    return 0;
}