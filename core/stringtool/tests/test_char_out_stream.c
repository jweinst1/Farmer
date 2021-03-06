#include "testing_messages.h"
#include "char_out_stream.h"


static int test_char_o_stream_expand(void)
{
	struct char_o_stream_t * stream;
	size_t correct_size;
	stream = char_o_stream_new(20);
	char_o_stream_expand(stream);
	correct_size = CHAR_O_STREAM_CAP(stream);
	char_o_stream_del(stream);
	return correct_size == 400;
}

static int test_char_o_stream_push(void)
{
	struct char_o_stream_t * stream;
	size_t correct_space;
	stream = char_o_stream_new(20);
	char_o_stream_push(stream, 'h');
	char_o_stream_push(stream, 'g');
	correct_space = stream->space;
	return correct_space == 18 && *(stream->end - 1) == 'g';
}

static int test_char_o_stream_write(void)
{
	struct char_o_stream_t * stream;
	stream = char_o_stream_new(20);
	char_o_stream_push(stream, 'h');
	char_o_stream_push(stream, 'e');
	char_o_stream_push(stream, '\n');
	puts("**** test_char_o_stream_write, below should be 'he' *****");
	char_o_stream_write(stream, stdout);
	char_o_stream_del(stream);
	return 1;
}

static struct test_message_case_t char_o_stream_tests[] = {
	{"test_char_o_stream_expand -> improper increase of capacity", &test_char_o_stream_expand},
	{"test_char_o_stream_push -> improper end ptr and space", &test_char_o_stream_push},
	{"test_char_o_stream_write -> file I/O error likely", &test_char_o_stream_write}
};

int main(int argc, char const *argv[])
{
	unsigned test_num = sizeof(char_o_stream_tests) / sizeof(struct test_message_case_t);
	TEST_MESSAGE_CASE_LIST(char_o_stream_tests, test_num);
	return 0;
}