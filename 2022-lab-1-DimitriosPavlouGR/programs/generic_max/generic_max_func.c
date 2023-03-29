typedef void* Pointer;
typedef int (*CompareFunc)(Pointer a, Pointer b);
Pointer generic_max(Pointer a, Pointer b, CompareFunc comp) {
    // Καλούμε την comp για να μας συγκρίνει τους αριθμούς, επιστρέφουμε a ή b ανάλογα
    if(comp(a, b) > 0)
        return a;
    else
        return b;
}