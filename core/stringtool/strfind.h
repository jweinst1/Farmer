#ifndef CORE_STR_FIND_H
#define CORE_STR_FIND_H

#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* Finds where an alpha sequence starts in string.
 * if not found, returns null.
 * if found, also puts the number of characters in the alpha sequence in 
 * length.
 */
const char* strfind_alpha(const char* string, long* length);

/* Finds substring within string, and returns pointer
 * to start of substring.
 * returns NULL if not found.
 */
const char* strfind_substr(const char* string, const char* substring);

/* Finds the sequence of characters that pass the check function.
 * check : pointer to function that takes one int and returns an int.
 * length: the length of the sequence found.
 * string: the target string.
 * returns : start of found sequence, otherwise NULL.
 */
const char* strfind_seq(const char* string, long* length, int(*check)(int));

#endif // CORE_STR_FIND_H