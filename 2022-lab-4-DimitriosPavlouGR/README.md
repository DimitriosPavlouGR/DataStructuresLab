![run-tests](../../workflows/run-tests/badge.svg)

## Δομές Δεδομένων και Τεχνικές Προγραμματισμού

### Κώδικας Εργαστηρίου 4

Εκφώνηση: https://k08.chatzi.org/labs/lab4/ 

### Άσκηση 2

Η naive heapify έχει time complexity O(nlogn) ,αυτό γιατί κάνουμε n inserts και η κάθε bubble up έχει time complexity O(logn)

Η efficient heapify έχει time complexity O(nlogn) ,αυτό γιατί κάνουμε n inserts και η κάθε bubble down έχει time complexity O(logn) ,
πρακτικά όμως αφού η efficient heapify είναι πιο γρήγορη στα φύλλα ,όπου και βρίσκονται τα περισσότερα στοιχεία ,η bubble_down είναι πιο αποδοτική από την bubble_up.

### Άσκηση 3

Οι πολυπλοκότητες των αλγορίθμων είναι ή εξής.

### Για την υλοποίηση μέσο λίστας έχουμε:

Για την pqueue_create(CompareFunc compare, DestroyFunc destroy_value, Vector values) έχουμε πολυπλοκότητα O(n^2) λόγο της selection sort

Για την naive_initialize_list(PriorityQueue pqueue, Vector values) έχουμε πολυπλοκότητα O(n^2) λόγο της selection sort

Για την pqueue_size(PriorityQueue pqueue) έχουμε πολυπλοκότητα O(1)

Για την pqueue_max(PriorityQueue pqueue) έχουμε πολυπλοκότητα O(1)

Για την pqueue_insert(PriorityQueue pqueue, Pointer value) έχουμε πολυπλοκότητα O(n)

Για την pqueue_remove_max(PriorityQueue pqueue) έχουμε πολυπλοκότητα O(1)

Για την pqueue_set_destroy_value(PriorityQueue pqueue, DestroyFunc destroy_value) έχουμε πολυπλοκότητα O(1)

Για την pqueue_destroy(PriorityQueue pqueue) έχουμε πολυπλοκότητα O(1)


Οπότε οι διαφορές μεταξύ της υλοποίησης μέσο λίστας και σωρού βρίσκονται στον παρακάτω πίνακα

``` 
Υλοποίηση                           Μέσο Heap   Μέσο List    
  
pqueue_create                       O(nlogn)    O(n^2)  
pqueue_size                         O(1)        O(1)  
pqueue_max                          O(1)        O(1)  
pqueue_insert                       O(logn)     O(N)  
pqueue_remove_max                   O(logn)     O(1)  
pqueue_set_destroy_value            O(1)        O(1)  
pqueue_destroy                      O(1)        O(1)    
```
