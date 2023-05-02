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
JanetKV *janet_deque(int32_t dummy_key) {
    JanetKV *deque = janet_gcalloc(JANET_MEMORY_STRUCT, sizeof(JanetKV));//is this a macros or what
    Janet *data = NULL;
    if (dummy_key > 0) {
        janet_vm.next_collection += dummy_key * sizeof(Janet);
        data = (Janet *) janet_malloc(sizeof(Janet) * (size_t) dummy_key);
        if (NULL == data) { // nice style
            JANET_OUT_OF_MEMORY;
        }
    }
    deque->count = 0;
    deque->dummy_key = dummy_key;
    deque->data = data;
    return deque;
}

int32t janet_array_getcount(JanetArray *array, int32_t count) {//TODO count
{
	return DEQUE_COUNT;
}
void janet_deque_inccount()
{
	++DEQUE_COUNT;
}
void janet_deque_deccount()
{
	--DEQUE_COUNT;
}
/* Creates a new array */
JanetArray *janet_array(int32_t capacity) {
    JanetArray *array = janet_gcalloc(JANET_MEMORY_ARRAY, sizeof(JanetArray));
    Janet *data = NULL;
    if (capacity > 0) {
        janet_vm.next_collection += capacity * sizeof(Janet);
        data = (Janet *) janet_malloc(sizeof(Janet) * (size_t) capacity);
        if (NULL == data) {
            JANET_OUT_OF_MEMORY;
        }
    }
    array->count = 0;
    array->capacity = capacity;
    array->data = data;
    return array;
}

/* Creates a new array from n elements. */
JanetArray *janet_array_n(const Janet *elements, int32_t n) {
    JanetArray *array = janet_gcalloc(JANET_MEMORY_ARRAY, sizeof(JanetArray));
    array->capacity = n;
    array->count = n;
    array->data = janet_malloc(sizeof(Janet) * (size_t) n);
    if (!array->data) {
        JANET_OUT_OF_MEMORY;
    }
    safe_memcpy(array->data, elements, sizeof(Janet) * n);
    return array;
}

/* Push a value to the top of the array */
void janet_deque_push(JanetKV *deque, Janet x) {//TODO push
	if (array->count == INT8_MAX) {//127 or 128 seems enough for MQ
        	janet_panic("deque-counter overflow");
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
Janet janet_deque_pop(JanetKV *deque) {//TODO pop
    if (deque->count) {//currently im gonna to store this in global var
        return deque->data[--deque->count];//currently im gonna to store this in global var
    } else {
        return janet_wrap_nil();
    }
}

/* Look at the last value in the array */
Janet janet_array_peek(JanetArray *array) {//TODO peek
    if (array->count) {//currently im gonna to store this in global var
        return array->data[array->count - 1];//currently im gona to store this in global var
    } else {
        return janet_wrap_nil();
    }
}

/* C Functions */

JANET_CORE_FN(cfun_deque_pop, //TODO pop
              "(deque/pop arr)",//WTF is arr?
              "Remove the last element of the deque and return it. If the deque is empty, will return nil. Modifies "
              "the list.") {
    janet_fixarity(argc, 1);
    JanetArray *array = janet_getarray(argv, 0);
    return janet_array_pop(array);
}

JANET_CORE_FN(cfun_deque_peek, //TODO peek
              "(deque/peek arr)",//WTF is arr?
              "Returns the last element of the deque. Does not modify the array.") {
    janet_fixarity(argc, 1);
    JanetArray *array = janet_getarray(argv, 0);
    return janet_array_peek(array);
}

JANET_CORE_FN(cfun_deque_push, //TODO push
              "(deque/push arr x)",
              "Insert an element in the end of an array. Modifies the input array and returns it.") {
    janet_arity(argc, 1, -1);
    JanetArray *deque = janet_getarray(argv, 0);//getkv ?
    if (INT32_MAX - argc + 1 <= array->count) {//global
        janet_panic("array overflow");
    }
    int32_t newcount = array->count - 1 + argc;
    janet_array_ensure(array, newcount, 2);
    if (argc > 1) memcpy(array->data + array->count, argv + 1, (size_t)(argc - 1) * sizeof(Janet));
    array->count = newcount;//global
    return argv[0];
}

/* Load the array module */
void janet_lib_array(JanetTable *env) {
    JanetRegExt array_cfuns[] = {
        JANET_CORE_REG("array/new", cfun_array_new),//ok
        JANET_CORE_REG("array/pop", cfun_array_pop),//yes
        JANET_CORE_REG("array/peek", cfun_array_peek),//yes
        JANET_CORE_REG("array/push", cfun_array_push),//yes
        JANET_CORE_REG("array/clear", cfun_array_clear),
        JANET_REG_END
    };
    janet_core_cfuns_ext(env, NULL, array_cfuns);//what is env and what is cfuns_ext?
}
