#include <stdlib.h>
#include <stdio.h>

#include "ADTPriorityQueue.h"
#include "ADTSet.h"

// Compares two given ints
int compare_ints(Pointer a ,Pointer b) {
    return *(int*)a-*(int*)b;
}

// Creates a int using the function rand
int* create_random_int(void) {
    int *random = malloc(sizeof(int));
    *random = rand()%49;
    return random;
}

int main() {
    PriorityQueue pq = pqueue_create(compare_ints ,free ,NULL);
    
    // 1) Inserts 20 random numbers to the priority queue
    
    for (int i = 0; i < 20; i++) {
        pqueue_insert(pq ,create_random_int());
    }

    // 2) Prints the largest number inside the queue and then removes it

    printf(" The queue's elements are :");
    for (int i = 0; i < 20; i++) {
        int *max = pqueue_max(pq);
        printf(" %d " ,*max);
        pqueue_remove_max(pq);
    }
    
    pqueue_destroy(pq); // Frees the priority queue

    // 3) Adds 20 random numbers to the set

    Set my_set = set_create(compare_ints ,free);

    for (int i = 0; i < 20; i++) {
        set_insert(my_set ,create_random_int());
    }

    // 4) Prints the set's elements

    printf("\n\n The set's elements are : ");
    for (SetNode last_node = set_last(my_set); last_node != SET_BOF; last_node = set_previous(my_set ,last_node)) {
        int *set_value = set_node_value(my_set ,last_node);

        printf(" %d " ,*set_value);
    }
    printf("\n\n");
    
    set_destroy(my_set); // Frees the set
}
