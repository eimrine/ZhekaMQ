#ifndef JANET_AMALG
#include "features.h"
#include <janet.h>
#include "gc.h"
#include "util.h"
#include "state.h"
#endif

#include <string.h>

//global values
JanetKV DEQUE_HEAD = NULL;
JanetKV DEQUE_TAIL = NULL;
int32_t DEQUE_COUNT = 0;

/* Creates a new struct */
JanetKV *janet_kv(int32_t dummy_key) {
    JanetKV *kv = janet_gcalloc(JANET_MEMORY_STRUCT, sizeof(JanetKV));//is this a macros or what
    Janet *data = NULL;
    if (dummy_key > 0) {
        janet_vm.next_collection += dummy_key * sizeof(Janet);
        data = (Janet *) janet_malloc(sizeof(Janet) * (size_t) dummy_key);
        if (NULL == data) { // nice style
            JANET_OUT_OF_MEMORY;
        }
    }
    kv->count = 0;
    kv->dummy_key = dummy_key;
    kv->data = data;
    return kv;
}

int32t janet_array_getcount(JanetArray *array, int32_t count) {//TODO count
{
	return DEQUE_COUNT;
}
void janet_kv_inccount()
{
	++DEQUE_COUNT;
}
void janet_kv_deccount()
{
	--DEQUE_COUNT;
}

/*yes*/

/* Push a value to the top of the array */
void janet_array_push(JanetArray *array, Janet x) {//TODO push
	if (array->count == INT8_MAX) {//127 or 128 seems enough for MQ
        	janet_panic("array overflow");
    	}
        int32_t userinput_length;
        int32_t userinput;
        struct data * text_container;
        text_container = (struct data *) malloc(userinput_length);
        struct node * node_creating;
        node_creating = (struct node *) malloc(sizeof(struct node));
        printf("\nUser, please enter some int value\t");
        scanf("%d", &userinput);
        if (NULL != HEAD && NULL != TAIL/* && NULL == HEAD -> next && NULL == TAIL -> prev*/) //non-first
        {//this block is STRICTLY first
                printf("\n~~~non-first~~~");
                //struct node * prevHEAD = HEAD;
                //prevHEAD -> prev = NULL;

                HEAD -> prev = node_creating;
                node_creating -> prev = NULL;
                node_creating -> next = /*prev*/HEAD;


                node_creating -> dummy = userinput;

                HEAD = node_creating;
                printf("\nshow 2nd value=\t");
                printf("%d",node_creating->dummy);
                printf("\tgo 2nd next\n");
        }

        if (NULL == HEAD && NULL == TAIL) //apply first elt
        {//this block is STRICTLY second
                node_creating -> next = NULL;
                node_creating -> prev = NULL;
                node_creating -> dummy = userinput;
                TAIL = HEAD = node_creating;
                printf("\nshow 1st value=\t");
                printf("%d",node_creating->dummy);
                printf("\tgo 1st next\n");
        }
        printf("\n~~~lets print head");
        printf("%d\n", HEAD -> dummy);
        printf("\n~~~lets print TAIL");
        printf("%d\n", TAIL -> dummy);
        printf("\nZBS!~~~");
	janet_kv_inccount();   
}

/* Pop a value from the top of the array */
Janet janet_array_pop(JanetArray *array) {//TODO pop
    if (array->count) {
        return array->data[--array->count];
    } else {
        return janet_wrap_nil();
    }
}

/* Look at the last value in the array */
Janet janet_array_peek(JanetArray *array) {//TODO peek
    if (array->count) {
        return array->data[array->count - 1];
    } else {
        return janet_wrap_nil();
    }
}

/* C Functions */

JANET_CORE_FN(cfun_array_new,//first function
              "(array/new capacity)",
              "Creates a new empty array with a pre-allocated capacity. The same as "
              "`(array)` but can be more efficient if the maximum size of an array is known.") {
    janet_fixarity(argc, 1);
    int32_t cap = janet_getinteger(argv, 0);
    JanetArray *array = janet_array(cap);//here
    return janet_wrap_array(array);
}

JANET_CORE_FN(cfun_array_new_filled,//NO
              "(array/new-filled count &opt value)",
              "Creates a new array of `count` elements, all set to `value`, which defaults to nil. Returns the new array.") {
    janet_arity(argc, 1, 2);
    int32_t count = janet_getnat(argv, 0);
    Janet x = (argc == 2) ? argv[1] : janet_wrap_nil();
    JanetArray *array = janet_array(count);
    for (int32_t i = 0; i < count; i++) {
        array->data[i] = x;
    }
    array->count = count;
    return janet_wrap_array(array);
}

JANET_CORE_FN(cfun_array_fill,//NO
              "(array/fill arr &opt value)",
              "Replace all elements of an array with `value` (defaulting to nil) without changing the length of the array. "
              "Returns the modified array.") {
    janet_arity(argc, 1, 2);
    JanetArray *array = janet_getarray(argv, 0);
    Janet x = (argc == 2) ? argv[1] : janet_wrap_nil();
    for (int32_t i = 0; i < array->count; i++) {
        array->data[i] = x;
    }
    return argv[0];
}

JANET_CORE_FN(cfun_array_pop, //TODO pop
              "(array/pop arr)",
              "Remove the last element of the array and return it. If the array is empty, will return nil. Modifies "
              "the input array.") {
    janet_fixarity(argc, 1);
    JanetArray *array = janet_getarray(argv, 0);
    return janet_array_pop(array);
}

JANET_CORE_FN(cfun_array_peek, //TODO peek
              "(array/peek arr)",
              "Returns the last element of the array. Does not modify the array.") {
    janet_fixarity(argc, 1);
    JanetArray *array = janet_getarray(argv, 0);
    return janet_array_peek(array);
}

JANET_CORE_FN(cfun_array_push, //TODO push
              "(array/push arr x)",
              "Insert an element in the end of an array. Modifies the input array and returns it.") {
    janet_arity(argc, 1, -1);
    JanetArray *array = janet_getarray(argv, 0);
    if (INT32_MAX - argc + 1 <= array->count) {
        janet_panic("array overflow");
    }
    int32_t newcount = array->count - 1 + argc;
    janet_array_ensure(array, newcount, 2);
    if (argc > 1) memcpy(array->data + array->count, argv + 1, (size_t)(argc - 1) * sizeof(Janet));
    array->count = newcount;
    return argv[0];
}

JANET_CORE_FN(cfun_array_ensure,//NO
              "(array/ensure arr capacity growth)",
              "Ensures that the memory backing the array is large enough for `capacity` "
              "items at the given rate of growth. `capacity` and `growth` must be integers. "
              "If the backing capacity is already enough, then this function does nothing. "
              "Otherwise, the backing memory will be reallocated so that there is enough space.") {
    janet_fixarity(argc, 3);
    JanetArray *array = janet_getarray(argv, 0);
    int32_t newcount = janet_getinteger(argv, 1);
    int32_t growth = janet_getinteger(argv, 2);
    if (newcount < 1) janet_panic("expected positive integer");
    janet_array_ensure(array, newcount, growth);
    return argv[0];
}

JANET_CORE_FN(cfun_array_slice,//NO
              "(array/slice arrtup &opt start end)",
              "Takes a slice of array or tuple from `start` to `end`. The range is half open, "
              "[start, end). Indexes can also be negative, indicating indexing from the "
              "end of the array. By default, `start` is 0 and `end` is the length of the array. "
              "Note that index -1 is synonymous with index `(length arrtup)` to allow a full "
              "negative slice range. Returns a new array.") {
    JanetView view = janet_getindexed(argv, 0);
    JanetRange range = janet_getslice(argc, argv);
    JanetArray *array = janet_array(range.end - range.start);
    if (array->data)
        memcpy(array->data, view.items + range.start, sizeof(Janet) * (range.end - range.start));
    array->count = range.end - range.start;
    return janet_wrap_array(array);
}

JANET_CORE_FN(cfun_array_concat,//NO
              "(array/concat arr & parts)",
              "Concatenates a variable number of arrays (and tuples) into the first argument, "
              "which must be an array. If any of the parts are arrays or tuples, their elements will "
              "be inserted into the array. Otherwise, each part in `parts` will be appended to `arr` in order. "
              "Return the modified array `arr`.") {
    int32_t i;
    janet_arity(argc, 1, -1);
    JanetArray *array = janet_getarray(argv, 0);
    for (i = 1; i < argc; i++) {
        switch (janet_type(argv[i])) {
            default:
                janet_array_push(array, argv[i]);
                break;
            case JANET_ARRAY:
            case JANET_TUPLE: {
                int32_t j, len = 0;
                const Janet *vals = NULL;
                janet_indexed_view(argv[i], &vals, &len);
                if (array->data == vals) {
                    int32_t newcount = array->count + len;
                    janet_array_ensure(array, newcount, 2);
                    janet_indexed_view(argv[i], &vals, &len);
                }
                for (j = 0; j < len; j++)
                    janet_array_push(array, vals[j]);
            }
            break;
        }
    }
    return janet_wrap_array(array);
}

JANET_CORE_FN(cfun_array_insert,//WTF
              "(array/insert arr at & xs)",
              "Insert all `xs` into array `arr` at index `at`. `at` should be an integer between "
              "0 and the length of the array. A negative value for `at` will index backwards from "
              "the end of the array, such that inserting at -1 appends to the array. "
              "Returns the array.") {
    size_t chunksize, restsize;
    janet_arity(argc, 2, -1);
    JanetArray *array = janet_getarray(argv, 0);
    int32_t at = janet_getinteger(argv, 1);
    if (at < 0) {
        at = array->count + at + 1;
    }
    if (at < 0 || at > array->count)
        janet_panicf("insertion index %d out of range [0,%d]", at, array->count);
    chunksize = (argc - 2) * sizeof(Janet);
    restsize = (array->count - at) * sizeof(Janet);
    if (INT32_MAX - (argc - 2) < array->count) {
        janet_panic("array overflow");
    }
    janet_array_ensure(array, array->count + argc - 2, 2);
    if (restsize) {
        memmove(array->data + at + argc - 2,
                array->data + at,
                restsize);
    }
    safe_memcpy(array->data + at, argv + 2, chunksize);
    array->count += (argc - 2);
    return argv[0];
}

JANET_CORE_FN(cfun_array_remove,//WTF
              "(array/remove arr at &opt n)",
              "Remove up to `n` elements starting at index `at` in array `arr`. `at` can index from "
              "the end of the array with a negative index, and `n` must be a non-negative integer. "
              "By default, `n` is 1. "
              "Returns the array.") {
    janet_arity(argc, 2, 3);
    JanetArray *array = janet_getarray(argv, 0);
    int32_t at = janet_getinteger(argv, 1);
    int32_t n = 1;
    if (at < 0) {
        at = array->count + at + 1;
    }
    if (at < 0 || at > array->count)
        janet_panicf("removal index %d out of range [0,%d]", at, array->count);
    if (argc == 3) {
        n = janet_getinteger(argv, 2);
        if (n < 0)
            janet_panicf("expected non-negative integer for argument n, got %v", argv[2]);
    }
    if (at + n > array->count) {
        n = array->count - at;
    }
    memmove(array->data + at,
            array->data + at + n,
            (array->count - at - n) * sizeof(Janet));
    array->count -= n;
    return argv[0];
}

JANET_CORE_FN(cfun_array_trim,//WTF
              "(array/trim arr)",
              "Set the backing capacity of an array to its current length. Returns the modified array.") {
    janet_fixarity(argc, 1);
    JanetArray *array = janet_getarray(argv, 0);
    if (array->count) {
        if (array->count < array->capacity) {
            Janet *newData = janet_realloc(array->data, array->count * sizeof(Janet));
            if (NULL == newData) {
                JANET_OUT_OF_MEMORY;
            }
            array->data = newData;
            array->capacity = array->count;
        }
    } else {
        array->capacity = 0;
        janet_free(array->data);
        array->data = NULL;
    }
    return argv[0];
}

JANET_CORE_FN(cfun_array_clear,//WTF
              "(array/clear arr)",
              "Empties an array, setting it's count to 0 but does not free the backing capacity. "
              "Returns the modified array.") {
    janet_fixarity(argc, 1);
    JanetArray *array = janet_getarray(argv, 0);
    array->count = 0;
    return argv[0];
}

/* Load the array module */
void janet_lib_array(JanetTable *env) {
    JanetRegExt array_cfuns[] = {
        JANET_CORE_REG("array/new", cfun_array_new),//ok
        JANET_CORE_REG("array/new-filled", cfun_array_new_filled),
        JANET_CORE_REG("array/fill", cfun_array_fill),
        JANET_CORE_REG("array/pop", cfun_array_pop),//yes
        JANET_CORE_REG("array/peek", cfun_array_peek),//yes
        JANET_CORE_REG("array/push", cfun_array_push),//yes
        JANET_CORE_REG("array/ensure", cfun_array_ensure),
        JANET_CORE_REG("array/slice", cfun_array_slice),
        JANET_CORE_REG("array/concat", cfun_array_concat),
        JANET_CORE_REG("array/insert", cfun_array_insert),
        JANET_CORE_REG("array/remove", cfun_array_remove),//maybe
        JANET_CORE_REG("array/trim", cfun_array_trim),
        JANET_CORE_REG("array/clear", cfun_array_clear),
        JANET_REG_END
    };
    janet_core_cfuns_ext(env, NULL, array_cfuns);//what is env and what is cfuns_ext?
}
