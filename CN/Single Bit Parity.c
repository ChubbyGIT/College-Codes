#include <stdio.h>
// Function to calculate the parity of a data word
int getParity(unsigned int data) {
 int parity = 0;
 while (data) {
 parity ^= data & 1;
 data >>= 1;
 }
 return parity;
}
// Function to add a parity bit to a data word
unsigned int addParity(unsigned int data) {
 int parity = getParity(data);
 return data | (parity << (sizeof(data) * 8 - 1));
}
// Function to check if a data word has a parity error
int hasParityError(unsigned int data) {
 int parity = getParity(data);
 return (parity ^ (data >> (sizeof(data) * 8 - 1)));
}
int main() {
 unsigned int data = 10110;
 unsigned int codeword = addParity(data);
 printf("Data word: %d\n", data);
 printf("Codeword: %d\n", codeword);
 if (hasParityError(codeword)) {
 printf("Codeword has a parity error.\n");
 } else {
 printf("Codeword does not have a parity error.\n");
 }
 return 0;
}