#ifndef H_CDYAR_MACROS
#define H_CDYAR_MACROS

// quality of life macros to make using cdyar easier
#define NEW_CDYAR(name, type, capacity)                                        \
  cdyar_darray name;                                                           \
  cdyar_narr(sizeof(type), capacity, CDYAR_DEFAULT_RESIZE_POLICY,              \
             cdyar_generic_typehandler, CDYAR_ARR_AUTO_RESIZE, &name);

#define NEW_CDYAR_ONHEAP(name, type, capacity)                                 \
  cdyar_darray *name = malloc(sizeof(cdyar_darray));                           \
  cdyar_narr(sizeof(type), capacity, CDYAR_DEFAULT_RESIZE_POLICY,              \
             cdyar_generic_typehandler, CDYAR_ARR_AUTO_RESIZE, name);

#define DELETE_CDYAR(name) cdyar_darr(name)
#define DELETE_CDYAR_ONHEAP(name) cdyar_darr(name); free(name)
#endif
