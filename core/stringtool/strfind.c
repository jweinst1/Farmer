#include "strfind.h"


const char* strfind_alpha(const char* string, long* length) {
  int on = 0;
  const char* start = NULL;
  while(*string)
  {
    if(on)
    {
      if(!isalpha(*string)) return start;
      else *length += 1;
    }
    else
    {
      if(isalpha(*string))
      {
        on = 1;
        *length = 1;
        start = string;
      }
    }
    string++;
  }
  return start;
}