1. test_convert_number_to_string_billion
        This test converts Numbers in the billions to its word equivalent
    input: long long number 12345678912345
    Expected output: "one hundred twenty-three billion four hundred fifty-six million seven hundred eighty-nine thousand one hundred twenty-three dollars and forty-five cents

2. test_convert_number_to_string_million
        This test converts Numbers in the millions to its word equivalent
    input: long long number 45678912345
    Expected output: four hundred fifty-six million seven hundred eighty-nine thousand one hundred twenty-three dollars and forty-five cents

3. test_convert_number_to_string_thousand
        This test converts Numbers in the thousands to its word equivalent
    input: long long number 78912345
    Expected output: seven hundred eighty-nine thousand one hundred twenty-three dollars and forty-five cents

4. test_convert_number_to_string_hundred
        This test converts Numbers in the hundreds to its word equivalent
    input: long long number 12345
    Expected output: one hundred twenty-three dollars and forty-five cents

5. test_convert_number_to_string_cents
        This test converts Numbers in the cents to its word equivalent
    input: long long number 45
    Expected output: zero dollars and forty-five cents

5. test_convert_number_to_string_empty
        This test converts an empty number to a word
    input: long long number
    Expected output: zero dollars and zero cents
 
