#include "../headers/cdyar_error.h"
#include "../headers/cdyar_darray.h"

// define error messages the correspond to the different error codes
const char *CDYAR_ERR_MESSAGES[CDYAR_ERR_CODE_COUNT] = {
    "successful.\n",
    "failed.\n",
    "memory error.\n",
    "invalid input.\n",
    "arr out of bounds.\n",
    "invalid index range for the array's resize policy.\n",
    "values or calculations working on type size_t have overflowed.\n",
    "values or calculations working on type unsigned int have overflowed.\n",
    "dynamic array does not exist.\n",
    "corrupted dynamic array.\n",
    "arithmeitc operation involved a value or resulted in a value that is not "
    "a valid number. (NaN)\n",
    "passed a negative exponent to a function that expects positive "
    "exponenets.\n"};

const char *cdyar_geterrmsg(cdyar_returncode *code) {
  // check that code is not null
  CDYAR_CHECK_CODE(code);

  // check that code is within the allowed range
  if (!(*code < CDYAR_ERR_CODE_COUNT)) {
    return NULL;
  }

  // return the corresponding error message
  return CDYAR_ERR_MESSAGES[*code];
}

cdyar_returncode cdyar_printerrmsg(cdyar_returncode *code, FILE *destination) {
  // check that code is not null
  CDYAR_CHECK_CODE(code);

  // check that the destination exists
  if (!destination) {
    return CDYAR_INVALID_INPUT;
  }

  // check that the destination is not stdin
  if (destination == stdin) {
    return CDYAR_INVALID_INPUT;
  }

  // get the corresponding error message
  const char *errmsg = cdyar_geterrmsg(code);
  if (!errmsg) {
    return CDYAR_INVALID_INPUT;
  }

  fprintf(destination, "cdyar error: %s", errmsg);
  return CDYAR_SUCCESSFUL;
}

cdyar_returncode cdyar_printstatus(cdyar_darray *arr, FILE *destination) {
  // check that arr is not null
  if (!arr) {
    return CDYAR_DYNAMIC_ARR_DOES_NOT_EXIST;
  }

  //print that error message to specified file or stream
  return cdyar_printerrmsg(arr->code , destination);
}
