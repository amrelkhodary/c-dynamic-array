// #include "../headers/cdyar_darray.h"
// #include "../headers/cdyar_types.h"
// #include <stdio.h>


// typedef struct mycoolstruct {
//     int x;
//     int y;
// } mycoolstruct;


// CDYAR_DEFINE_TYPE_HANDLER(mycoolstruct, mycoolstruct)

int main() {
  /*
  cdyar_returncode code;
  cdyar_darray* arr = cdyar_narr(sizeof(mycoolstruct), 5, CDYAR_DEFAULT_RESIZE_POLICY,
                                cdyar_mycoolstruct_typehandler, 0, &code);

  mycoolstruct s =  {1 ,2};
  size_t length = arr->length * 10;
  for(size_t i = 0; i<length; i++) {
      cdyar_set(arr, i, &s, &code);
  }



  mycoolstruct nvalue = {0, 0};
  for(size_t i = 0; i<arr->length; i++) {
      cdyar_get(arr, i, &nvalue, &code);
      printf("arr[%i] = %i, %i\n", (int)i, nvalue.x, nvalue.y);
  }

  cdyar_get(arr, 80, &nvalue, &code);
  if(code == CDYAR_ARR_OUT_OF_BOUNDS) {
     printf("works fine.\n");
  }
  cdyar_darr(arr, &code);
  */
}
