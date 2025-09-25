#include <iostream>
#include <cassert>

constexpr static int is_vowel(char c) {
	return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

void test_is_vowel() {
	assert(is_vowel('a') == 1);
	assert(is_vowel('e') == 1);
	assert(is_vowel('i') == 1);
	assert(is_vowel('o') == 1);
	assert(is_vowel('u') == 1);
	assert(is_vowel('b') == 0);
	assert(is_vowel('c') == 0);
	assert(is_vowel('d') == 0);
	assert(is_vowel('f') == 0);
	assert(is_vowel('g') == 0);
}
int main() {
	std::cout << "Running tests..." << std::endl;
	test_is_vowel();
	std::cout << "All tests passed!" << std::endl;
	return 0;
}
