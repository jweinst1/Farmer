#include "char_out_stream.h"

struct char_o_stream_t * char_o_stream_new(size_t initial)
{
	struct char_o_stream_t * ostr = malloc(sizeof(struct char_o_stream_t));
	ostr->space = sizeof(char) * initial;
	ostr->buf = malloc(ostr->space);
	ostr->end = ostr->buf;
	return ostr;
}

void char_o_stream_expand(struct char_o_stream_t* ostr)
{
	size_t old_len = ostr->end - ostr->buf;
	size_t cap = CHAR_O_STREAM_CAP(ostr);
#ifdef CHAR_O_STREAM_EXPAND_DOUBLE
	cap *= 2;
#else
	cap *= cap;
#endif
	ostr->buf = realloc(ostr->buf, cap);
	ostr->end = ostr->buf + old_len;
	ostr->space = cap - old_len;
}

void char_o_stream_push(struct char_o_stream_t* ostr, char ch)
{
	if(!(ostr->space)) char_o_stream_expand(ostr);
	*(ostr->end)++ = ch;
	ostr->space--;
}

void char_o_stream_del(struct char_o_stream_t* ostr)
{
	free(ostr->buf);
	free(ostr);
}