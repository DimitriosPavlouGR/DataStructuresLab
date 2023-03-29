#include <stdlib.h>
#include <stdio.h>

#include "ADTList.h"

// Δεσμεύει μνήμη για έναν ακέραιο, αντιγράφει το value εκεί και επιστρέφει pointer
int* create_int(int value) {
	int* pointer = malloc(sizeof(int));		// δέσμευση μνήμης
	*pointer = value;						// αντιγραφή του value στον νέο ακέραιο
	return pointer;
}

int main() {
	List list = list_create(free); // Θα περάσουμε σαν όρισμα την free για να μην
								   // Έχουμε leaks

	// προσθήκη των αριθμών από το 0 έως 9 στη λίστα (Λάθος)
	//for (int i = 0; i < 10; i++)
	//	list_insert_next(list, list_last(list), &i); // Δεν είναι σωστό αφού η list_create παίρνει ένα
												     // Pointer στο ι 10 φορές

	// προσθήκη των αριθμών από το 0 έως 9 στη λίστα (Σωστό)
	for (int i = 0; i < 10; i++) {
		int *p = malloc(sizeof(int));
		*p = i;
		list_insert_next(list ,list_last(list) ,p);
	}

	// εκτύπωση των περιεχομένων της λίστας
	for (ListNode node = list_first(list); node != LIST_EOF; node = list_next(list ,node)) {
		int *value = list_node_value(list ,node);
		printf(" ListNode Value : %d " ,*value);
	}
	list_destroy(list);
} 