
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "array.h"

int basic_array_init_capacity = 8;
int basic_array_growth_factor = 2;

BasicArray *basic_array_new()
{
  BasicArray *arr = malloc(sizeof(BasicArray));
  arr->data = malloc(sizeof(int)*basic_array_init_capacity);
  arr->size = 0;
  arr->capacity = 8;
  return arr;
}

int basic_array_size(BasicArray *array)
{
  return array->size;
}

int basic_array_capacity(BasicArray *array)
{
  return array->capacity;
}

bool basic_array_is_empty(BasicArray *array)
{
  if (array->size)
    return false;
  return true;
}

int basic_array_element_at(BasicArray *array, int index)
{
  if (index < 0 || array->size > index) {
    printf("ERROR: array index out of bounds\n");
    exit(0);
  }
  return array->data[index];
}

void basic_array_push(BasicArray *array, int element)
{
  if (array->size == array->capacity) {
    basic_array_resize(array, (array->capacity)*basic_array_growth_factor);
  }
  array->data[array->size] = element;
  array->size++;
}

void basic_array_insert(BasicArray *array, int index, int value)
{
  if (index < 0 || index >= array->size) {
    printf("ERROR: arrray index out of bounds\n");
    exit(0);
  }

  int *new_data = malloc(sizeof(int)*(array->capacity));

  for (int i = 0; i < index; i++) {
    new_data[i] = array->data[i];
  }

  new_data[index] = value;

  for(int i = index+1; i < array->size+1; i++) {
    new_data[i] = array->data[i-1];
  }
  
  free(array->data);
  array->size++;
  array->data = new_data;
}

void basic_array_prepend(BasicArray *array, int index, int value)
{
  if (array->size == array->capacity)
    basic_array_resize(array, array->capacity*basic_array_growth_factor);
  
  if (index < 0 || index >= array->size) {
    printf("ERROR: prepending index out of array's bounds\n");
    exit(0);
  }
  
  int *new_data = malloc(sizeof(int)*array->capacity);

  for (int i = 0; i < index; i++) {
    new_data[i] = array->data[i];
  }
  
  new_data[index] = value;

  for (int i = index+1; i < array->size+1; ++i) {
    new_data[i] = array->data[i-1];
  }
  
  free(array->data);
  array->data = new_data;
  array->size++;
}

void basic_array_pop(BasicArray *array)
{
  /*
   * TODO: O(n) to O(1)
   */
  int *new_data = malloc(sizeof(int)*array->capacity);

  for (int i = 0; i < array->size; ++i) {
    new_data[i+1] = array->data[i];
  }

  free(array->data);
  array->data = new_data;
  array->size--;
}

void basic_array_element_delete(BasicArray *array, int index)
{
  if (index < 0 || index >= array->size) {
    printf("ERROR: array index out of bounds\n");
    exit(0);
  }
  int *new_data = (int *)(malloc(sizeof(int)*array->capacity));
  for (int i = 0; i < index; ++i) {
    new_data[i] = array->data[i];
  }
  for (int i = index; i < array->size+1; ++i) {
    new_data[i] = array->data[i+1];
  }
  free(array->data);
  array->data = new_data;
  array->size--;
}

int basic_array_find(BasicArray *array, int value)
{
  for (int i = 0; i < array->size; ++i) {
    if (array->data[i] == value)
      return i;
  }
  return -1;
}

void basic_array_resize(BasicArray *array, int new_capacity)
{
  if (array->capacity > new_capacity) return;

  else {
    int *new_data = malloc(sizeof(int)*new_capacity);
    if (!new_data) {
      printf("ERROR: memory allocation");
    }

    for (int i = 0; i < array->size; i++) {
      new_data[i] = array->data[i];
    }
    
    free(array->data);
    array->data = new_data;
    array->capacity = new_capacity;
  }
}

void basic_array_debug_data_printer(BasicArray *array)
{
  printf("size: %d\n", array->size);
  printf("capacity: %d\n", array->capacity);
  printf("first few elements:\n");
  for (int i = 0; i < array->size || i < array->size; i++)
    printf("%d: \t%d\n", i, array->data[i]);
  printf("********************************************\n");
}

