
#ifndef _ARRAY_
#define _ARRAY_

#include <stdbool.h>

extern int basic_array_init_capacity;
extern int basic_array_growth_factor;

typedef struct BasicArray {
  int *data;
  int size;
  int capacity;
} BasicArray;

BasicArray *basic_array_new();

int basic_array_size(BasicArray *array);

int basic_array_capacity(BasicArray *array);

bool basic_array_is_empty(BasicArray *array);

int basic_array_element_at(BasicArray *array, int index);

void basic_array_push(BasicArray *array, int element);

void basic_array_insert(BasicArray *array, int index, int value);

void basic_array_prepend(BasicArray *array, int index, int value);

void basic_array_pop(BasicArray *array);

void basic_array_element_delete(BasicArray *array, int index);

int basic_array_find(BasicArray *array, int value);

void basic_array_resize(BasicArray *array, int size);

void basic_array_debug_data_printer(BasicArray *array);

#endif
