#include "../headers/cdyar.h"
#include <stdio.h>
//
//
typedef struct mycoolstruct {
    int x;
    int y;
} mycoolstruct;
//
//

int main() {
  NEW_CDYAR_ONHEAP(arr, mycoolstruct, 5);
  if(!arr) {
      fprintf(stderr, "arr failed");
  }
  mycoolstruct s =  {1 ,2};
  size_t count = 50;
  for(size_t i = 0; i<count; i++) {
      cdyar_set(arr, i, &s);
      cdyar_printstatus(arr, stderr);
  }


  printf("capacity: %lu, length: %lu\n", arr->capacity, arr->length);

  mycoolstruct nvalue = {0, 0};
  for(size_t i = 0; i<arr->capacity; i++) {
      cdyar_get(arr, i, &nvalue);
      printf("arr[%i] = %i, %i\n", (int)i, nvalue.x, nvalue.y);
      cdyar_printstatus(arr, stderr);
  }

  cdyar_get(arr, 80, &nvalue);
  cdyar_printstatus(arr, stderr);
  if(*arr->code == CDYAR_ARR_OUT_OF_BOUNDS) {
     printf("works fine.\n");
  }

  DELETE_CDYAR_ONHEAP(arr);
}
