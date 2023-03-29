///////////////////////////////////////////////////////////
//
// Υλοποίηση του ADT Priority Queue μέσω ταξινομημένης λίστας.
//
///////////////////////////////////////////////////////////

#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include "ADTPriorityQueue.h"
#include "ADTList.h"			// Η υλοποίηση του PriorityQueue χρησιμοποιεί List
#include "common_types.h"

// Ενα PriorityQueue είναι pointer σε αυτό το struct
struct priority_queue {
	List list;		// η λίστα στην οποία αποθηκεύουμε τα στοιχεία
	CompareFunc compare;
	// ...
};



// Βοηθητικές συναρτήσεις //////////////////////////////////////////////////////////////////

// Αρχικοποιεί την ταξινομημένη λίστα από τα στοιχεία του vector values.

static void naive_initialize_list(PriorityQueue pqueue, Vector values) {
	// Απλά κάνουμε insert τα στοιχεία ένα ένα (όπως η naive_heapify).
	// Προαιρετικά: sort τα στοιχεία και εισαγωγή όλα μαζί (πιο αποδοτικό).
	// ...

	// Using selection sort ,we first sort the vector
	// Then we add the elements one by one to the list
	for (int i = 0; i < vector_size(values); i++) {
		int min_position = i;

		CompareFunc compare = pqueue->compare;

		for (int j = i; j < vector_size(values); j++) {
			if (compare(vector_get_at(values ,j) ,vector_get_at(values ,min_position)) < 0) {
				min_position = j;
			}
		}

		Pointer temp = vector_get_at(values ,i);
		vector_set_at(values ,i ,vector_get_at(values ,min_position));
		vector_set_at(values ,min_position ,temp);
	}
	

	for (VectorNode node = vector_first(values); node != VECTOR_EOF; node = vector_next(values ,node)) {
		list_insert_next(pqueue->list ,LIST_BOF ,vector_node_value(values ,node));
	}

}


// Συναρτήσεις του ADTPriorityQueue ////////////////////////////////////////////////////////

PriorityQueue pqueue_create(CompareFunc compare, DestroyFunc destroy_value, Vector values) {
	PriorityQueue pqueue = malloc(sizeof(*pqueue));

	// Για την κλήση της συνάρτησης destroy_value, την περνάμε απλά στη list_create
	// οπότε θα καλείται αυτόματα όταν το στοιχείο αφαιρεθεί από τη λίστα.
	pqueue->list = list_create(destroy_value);

	// The function used for comparing the values given
	pqueue->compare = compare;
	// ...

	// Αν values != NULL, αρχικοποιούμε την ταξινομημένη λίστα.
	if (values != NULL)
		naive_initialize_list(pqueue, values);

	return pqueue;
}

int pqueue_size(PriorityQueue pqueue) {
	// Returns the size of the queue which happens to be the size of the list
	// Representing the queue
	return list_size(pqueue->list);
}

Pointer pqueue_max(PriorityQueue pqueue) {
	// The greatest element is the first element of the list
	return list_node_value(pqueue->list ,list_first(pqueue->list));
}

void pqueue_insert(PriorityQueue pqueue, Pointer value) {
	// Checks if the list has only one element
	CompareFunc compare = pqueue->compare;
	
	// If the list contains zero elements ,the element will be inserted to the top of the queue
	if (!list_size(pqueue->list)) {
		list_insert_next(pqueue->list ,LIST_BOF ,value);
		return;
	}

	// Looks for the first element that's less than the value given
	// If such an element is found ,the value will be inserted behind the element that's less than the value
	// This ensures that the list is sorted
	//
	// If the value is less than any of the elements in the least ,then it will be inserted to the end of the list
	ListNode last_node = LIST_BOF;
	for (ListNode node = list_first(pqueue->list); ; node = list_next(pqueue->list ,node)) {

		Pointer a = list_node_value(pqueue->list ,node);
		Pointer b = value;

		if (compare(a ,b) < 0) {
			list_insert_next(pqueue->list ,last_node ,b);
			break;
		} else if (list_next(pqueue->list ,node) == LIST_EOF) {
			list_insert_next(pqueue->list ,node , b);
			break;
		}

		last_node = node;
	}
}

void pqueue_remove_max(PriorityQueue pqueue) {
	// The max element is located to the start of the list ,because the list is sorted
	list_remove_next(pqueue->list ,LIST_BOF);
}

DestroyFunc pqueue_set_destroy_value(PriorityQueue pqueue, DestroyFunc destroy_value) {
	// Απλά καλούμε την αντίστοιχη συνάρτηση της λίστας
	return list_set_destroy_value(pqueue->list, destroy_value);
}

void pqueue_destroy(PriorityQueue pqueue) {
	// Destroys the list and deallocates the memory used for the queue
	list_destroy(pqueue->list);
	free(pqueue);
}
