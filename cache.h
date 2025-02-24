#ifndef CACHE_H
#define CACHE_H

#define MEMOIZATION_LIMIT 150000
#define MAX_LEN 500
#define NOT_PRESENT -1

typedef char (*char_func_ptr)(long);

extern long results[MEMOIZATION_LIMIT][MAX_LEN];

extern char_func_ptr original_provider;
extern char_func_ptr money_to_word_pointer;

long long *cache(long val);
void init_cache();



#endif