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

#endif // CORE_STR_FIND_H