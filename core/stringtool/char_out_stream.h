#ifndef CORE_CHAR_OUT_STREAM_H
#define CORE_CHAR_OUT_STREAM_H

#include <stdio.h>
#include <stdlib.h>

#define CHAR_O_STREAM_CAP(o) (o->space + (o->end - o->buf))

/* Optimized char out stream that expands exponentially
 * Used for potentially very large data/string sizes but one char size
 * append operations.
 */
struct char_o_stream_t {
	size_t space;
	char* end;
	char* buf;
};


struct char_o_stream_t * char_o_stream_new(size_t initial);

/* Expansion function for the char out stream.
 * by default, expands exponentially in capacity.
 * option: CHAR_O_STREAM_EXPAND_DOUBLE
 * if defined, will only double in size, useful for
 * smaller systems or memory tight situations.
 */
void char_o_stream_expand(struct char_o_stream_t* ostr);

void char_o_stream_push(struct char_o_stream_t* ostr, char ch);

/* Resets the memory inside the buffer and sets the sapce back to the capacity.
 * This allows an overwrite and reuse of previously allocated memory.
 */
void char_o_stream_reset(struct char_o_stream_t* ostr);

/* Writes the data in the buffer to some already open file pointer.
 * Works for stdout, stderr, or a file on disk.
 */
void char_o_stream_write(struct char_o_stream_t* ostr, FILE* fp);

void char_o_stream_del(struct char_o_stream_t* ostr);

#endif // CORE_CHAR_OUT_STREAM_H