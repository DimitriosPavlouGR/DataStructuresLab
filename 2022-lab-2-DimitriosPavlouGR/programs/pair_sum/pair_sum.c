#include <stdlib.h>

#include "pair_sum.h"

// This function campares two integers
int compare_ints(Pointer a ,Pointer b) {
	return *(int*)a-*(int*)b;
}

// 2)
Pair pair_sum(int target, Vector numbers) {
	Pair my_pair = malloc(sizeof(Pair));

	int *ptr_a ,b;
	int *b_found;

	for (VectorNode current_node = vector_first(numbers); (current_node != VECTOR_EOF ); current_node = vector_next(numbers ,current_node)) {
		ptr_a = vector_node_value(numbers ,current_node);
		b = target-*ptr_a;
		b_found = vector_find(numbers ,&b ,compare_ints);
		
		if (b_found != NULL) {
			my_pair->first = *ptr_a;
			my_pair->second = b;
			
			return my_pair;
		}

	}
	
	free(my_pair);	
	return NULL;
}