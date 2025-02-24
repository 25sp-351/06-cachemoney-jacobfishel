// test.c
#include "functions.h"
#include "munit/munit.h"
#include <stdlib.h>

// Test function for billions
static MunitResult
test_convert_number_to_string_billion(const MunitParameter params[],
                                      void *user_data) {
    (void)params;
    (void)user_data;

    long long number = 12345678912345;
    char correct[300] =
        "one hundred twenty-three billion four hundred fifty-six "
        "million seven hundred eighty-nine thousand one hundred "
        "twenty-three dollars and forty-five cents";
    char result[MAX_LEN];
    number_to_words(number, result);

    munit_assert_string_equal(result, correct);
    return MUNIT_OK;
}

// Test function for millions
static MunitResult
test_convert_number_to_string_million(const MunitParameter params[],
                                      void *user_data) {
    (void)params;
    (void)user_data;

    long long number = 45678912345;
    char correct[300] =
        "four hundred fifty-six million seven hundred eighty-nine thousand "
        "one hundred twenty-three dollars and forty-five cents";
    char result[MAX_LEN];
    number_to_words(number, result);

    munit_assert_string_equal(result, correct);
    return MUNIT_OK;
}

// Test function for thousands
static MunitResult
test_convert_number_to_string_thousand(const MunitParameter params[],
                                       void *user_data) {
    (void)params;
    (void)user_data;

    long long number  = 78912345;
    char correct[300] = "seven hundred eighty-nine thousand one hundred "
                        "twenty-three dollars and forty-five cents";
    char result[MAX_LEN];
    number_to_words(number, result);

    munit_assert_string_equal(result, correct);
    return MUNIT_OK;
}

// Test function for hundreds
static MunitResult
test_convert_number_to_string_hundred(const MunitParameter params[],
                                      void *user_data) {
    (void)params;
    (void)user_data;

    long long number  = 12345;
    char correct[300] = "one hundred twenty-three dollars and forty-five cents";
    char result[MAX_LEN];
    number_to_words(number, result);

    munit_assert_string_equal(result, correct);
    return MUNIT_OK;
}

// Test function for cents only
static MunitResult
test_convert_number_to_string_cents(const MunitParameter params[],
                                    void *user_data) {
    (void)params;
    (void)user_data;

    long long number  = 45;
    char correct[300] = "zero dollars and forty-five cents";
    char result[MAX_LEN];
    number_to_words(number, result);

    munit_assert_string_equal(result, correct);
    return MUNIT_OK;
}

// Test function for zero input
static MunitResult
test_convert_number_to_string_empty(const MunitParameter params[],
                                    void *user_data) {
    (void)params;
    (void)user_data;

    long long number  = 0;
    char correct[300] = "zero dollars and zero cents";
    char result[MAX_LEN];
    number_to_words(number, result);

    munit_assert_string_equal(result, correct);
    return MUNIT_OK;
}

// Define the test suite
static MunitTest tests[] = {
    {"/test_convert_number_to_string_billion",
     test_convert_number_to_string_billion, NULL, NULL, MUNIT_TEST_OPTION_NONE,
     NULL},
    {"/test_convert_number_to_string_million",
     test_convert_number_to_string_million, NULL, NULL, MUNIT_TEST_OPTION_NONE,
     NULL},
    {"/test_convert_number_to_string_thousand",
     test_convert_number_to_string_thousand, NULL, NULL, MUNIT_TEST_OPTION_NONE,
     NULL},
    {"/test_convert_number_to_string_hundred",
     test_convert_number_to_string_hundred, NULL, NULL, MUNIT_TEST_OPTION_NONE,
     NULL},
    {"/test_convert_number_to_string_cents",
     test_convert_number_to_string_cents, NULL, NULL, MUNIT_TEST_OPTION_NONE,
     NULL},
    {"/test_convert_number_to_string_empty",
     test_convert_number_to_string_empty, NULL, NULL, MUNIT_TEST_OPTION_NONE,
     NULL},
    {NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL}};

// Test suite configuration
static const MunitSuite suite = {"/test_suite", tests, NULL, 1,
                                 MUNIT_SUITE_OPTION_NONE};

// Main function to run the test suite
int main(int argc, char *argv[MUNIT_ARRAY_PARAM(argc + 1)]) {
    return munit_suite_main(&suite, NULL, argc, argv);
}
