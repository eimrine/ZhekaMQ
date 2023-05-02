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

static const JanetReg cfuns[] = {
	{"khui", cfun_kv_push, "(zhekamq/khui)\nPushes nothing yet."},
	{NULL, NULL, NULL}
};
	
static const JanetReg cfuns[] = {
	{"pizda", cfun_kv_pop, "(zhekamq/pizda)\nPops nothing yet."},
	{NULL, NULL, NULL}
};
	

static const JanetReg cfuns[] = {
	{"yebat", cfun_kv_peek, "(zhekamq/yebat)\nReturns nothing yet."},
	{NULL, NULL, NULL}
};

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

JANET_MODULE_ENTRY(JanetTable *env) {
    janet_cfuns(env, "mymod", cfuns);
}
