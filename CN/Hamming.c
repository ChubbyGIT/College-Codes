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
// Function to calculate the Hamming code for a data word
unsigned int hammingCode(unsigned int data) {
 int parityBits[7];
 int i;
 // Calculate the parity bits
 for (i = 0; i < 7; i++) {
 parityBits[i] = getParity(data >> (i * 2));
 }
 // Combine the data bits and the parity bits to form the Hamming code
 unsigned int hammingCode = data;
 for (i = 0; i < 7; i++) {
 hammingCode |= (parityBits[i] << (i * 2));
 }
 return hammingCode;
}
// Function to check if a Hamming code has an error
int hasHammingError(unsigned int hammingCode) {
 int i;
 // Check each parity bit
 for (i = 0; i < 7; i++) {
 if (hasParityError(hammingCode >> (i * 2))) {
 return 1;
 }
 }
 return 0;
}
// Function to correct a Hamming code error
unsigned int correctHammingError(unsigned int hammingCode) {
 int i, errorPosition;
 // Find the position of the error
 for (i = 0; i < 7; i++) {
 if (hasParityError(hammingCode >> (i * 2))) {
 errorPosition = i;
 break;
 }
 }
 // Flip the bit at the error position
 hammingCode ^= (1 << (errorPosition * 2));
 return hammingCode;
}
int main() {
 unsigned int data = 10110;
 unsigned int codeword = hammingCode(data);
 printf("Data word: %d\n", data);
 printf("Codeword: %d\n", codeword);
 if (hasHammingError(codeword)) {
 printf("Codeword has an error.\n");
 codeword = correctHammingError(codeword);
 printf("Corrected codeword: %d\n", codeword);
 } else {
 printf("Codeword does not have an error.\n");
 }
 return 0;
}