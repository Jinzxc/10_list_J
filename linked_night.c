#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "linked_night.h"

void reveal_mob(struct mob_node *mb) {
    printf("%s ", mb->name);
}

void change_mob(struct mob_node *mb, char *nm, char *sp, int lvl) {
    strncpy(mb->name, nm, sizeof(mb->name) - 1);
    strncpy(mb->species, sp, sizeof(mb->species) - 1);
    mb->level = lvl;
}

struct mob_node *new_mob_node(char *nm, char *sp, int lvl) {
    struct mob_node *mb = malloc(sizeof(struct mob_node));
    strncpy(mb->name, nm, sizeof(mb->name) - 1);
    strncpy(mb->species, sp, sizeof(mb->species) - 1);
    mb->level = lvl;
    return mb;
}

void print_list(struct mob_node *node) {
    printf("[ ");
    while(node) {
        reveal_mob(node);
        node = node->next;
    }

    printf("]\n");
}

struct mob_node *insert_front(struct mob_node *node, char *nm, char *sp, int lvl) {
    struct mob_node *mb_nd = new_mob_node(nm, sp, lvl);
    mb_nd->next = node;
    return mb_nd;
}

struct mob_node *free_list(struct mob_node *node) {
    struct mob_node *tmp;
    while(node) {
        printf("freeing: %s\n", node->name);
        tmp = node->next;
        free(node);
        node = tmp;
    }

    return node; 
}

struct mob_node *remove_node(struct mob_node *front, char *nm) {
    struct mob_node *last = front;
    struct mob_node *f = front;

    if(!strcmp(front->name, nm)) {
        printf("freeing: %s\n", front->name);
        last = front->next;
        free(front);

        return last;
    }

    while(front) {
        if(!strcmp(front->name, nm)) {
            printf("freeing: %s\n", front->name);
            last->next = front->next;
            free(front);
            break;
        }
        
        last = front;
        front = front->next;
    }

    return f;
}