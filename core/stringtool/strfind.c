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

const char* strfind_substr(const char* string, const char* substring) {
  int on = 0;
  const char* index = NULL;
  const char* traverse = substring; // resettable
  while(*string)
  {
    if(on)
    {
      if(!*traverse) return index;
      else if(*traverse == *string)
      {
        traverse++;
      }
      else
      {
        traverse = substring;
        index = NULL;
        on = 0;
      }
    }
    else
    {
      if(*string == *substring)
      {
        on = 1;
        index = string;
        traverse++;
      }
    }
    string++;
  }
  if(!*traverse) return index;
  else return NULL;
}

const char* strfind_seq(const char* string, long* length, int(*check)(int)) {
  int on = 0;
  const char* start = NULL;
  while(*string)
  {
    if(on)
    {
      if(!(*check)(*string)) return start;
      else *length += 1;
    }
    else
    {
      if((*check)(*string))
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