#include <stdlib.h>

#include "pair_sum.h"

// This function campares two integers
int compare_ints(Pointer a ,Pointer b) {
	return *(int*)a-*(int*)b;
}

// Pair sum using map
Pair pair_sum(int target, Vector numbers) {
	Pair my_pair = malloc(sizeof(Pair));

	Map my_map = map_create(compare_ints ,free ,free);

	for (VectorNode current_node = vector_first(numbers); current_node != VECTOR_EOF; current_node = vector_next(numbers ,current_node)) { // Copies the elements of numbers to a map called my_map
		int *node_value = vector_node_value(numbers ,current_node);
		int *key = malloc(sizeof(int));
		int *included = malloc(sizeof(int));

		*included = 1;
		key = node_value;

		map_insert(my_map ,key ,included);
	}

	int a ,b;
	int *b_found;
	for (MapNode current_node_2 = map_first(my_map); current_node_2 != MAP_EOF; current_node_2 = map_next(my_map ,current_node_2)) { // Finds if a+b == target
		int *node_value_2 = map_node_value(my_map ,current_node_2);

		a = *node_value_2;
		b = target-a;
		b_found = map_find(my_map ,&b);
		
		if (b_found != NULL) {
			my_pair->first = a;
			my_pair->second = b;
			
			map_destroy(my_map);
			return my_pair;
		}
	}

	free(my_pair);
	map_destroy(my_map);
	return NULL;
}