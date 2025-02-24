#include "functions.h"
#include "cache.h"

int main() {

    init_cache();
    original_provider = process_money;
    money_to_word_pointer = cache;

    long long money = 0;
    printf("\nEnter number to convert: ");
    // Read input until EOF
    while (scanf("%lld", &money) != EOF)
        // process_money(money);
        (*money_to_word_pointer)(money);

    return 0;
}