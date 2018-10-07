#include <stdio.h>

#include "testing_messages.h"
#include "strfind.h"

static int test_strfind_alpha(void)
{
	long hold = 0;
	const char* found;
	found = strfind_alpha("  \nabc123\n", &hold);
	return hold == 3;
}

static struct test_message_case_t strfind_tests[] = {
	{"test_strfind_alpha -> wrong amount of alpha chars", &test_strfind_alpha}
};

int main(int argc, char const *argv[])
{
	unsigned test_num = sizeof(strfind_tests) / sizeof(struct test_message_case_t);
	TEST_MESSAGE_CASE_LIST(strfind_tests, test_num);
	return 0;
}