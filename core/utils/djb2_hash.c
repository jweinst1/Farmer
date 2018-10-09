#include "djb2_hash.h"

unsigned long djb2_hash_str(char *string) 
{
    unsigned long hash = 5381;
    int c;

    while ((c = *string++))
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

    return hash;
}