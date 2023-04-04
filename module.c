static Janet cfun(int32_t argc, Janet *argv) {
        janet_fixarity(argc, 1);

        const Janet *argv_copy = janet_tuple_n(argv, argc);
  
      
        /* A mutable associative data type. Backed by a hashtable. */
        struct JanetTable {
            JanetGCObject gc;
            int32_t dummy;
            ??? prev;
            ??? next;
            JanetKV *data;
            JanetTable *proto;
        };
        typedef struct JanetTable JanetTable;
}
