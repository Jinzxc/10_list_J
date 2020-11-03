#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "linked_night.h"

int main() {
    srand(time(NULL));
    struct mob_node *gang = NULL;

    printf("Printing empty list:\n");
    print_list(gang);

    gang = insert_front(gang, "A", "n", rand()%100);
    gang = insert_front(gang, "B", "n", rand()%100);
    gang = insert_front(gang, "C", "n", rand()%100);
    gang = insert_front(gang, "D", "n", rand()%100);
    gang = insert_front(gang, "E", "n", rand()%100);
    gang = insert_front(gang, "F", "n", rand()%100);
    gang = insert_front(gang, "G", "n", rand()%100);
    gang = insert_front(gang, "H", "n", rand()%100);
    
    printf("Classic Power Ranger enemies:\n");
    print_list(gang);

    gang = remove_node(gang, "H");
    print_list(gang);

    gang = remove_node(gang, "E");
    print_list(gang);

    gang = remove_node(gang, "A");
    print_list(gang);

    printf("Trying to elimnate: Z\n");
    gang = remove_node(gang, "Z");
    print_list(gang);
    
    printf("\n~Nuking the gang~\n");
    gang = free_list(gang);

    printf("All enemies perished:\n");
    print_list(gang);
    return 0;
}