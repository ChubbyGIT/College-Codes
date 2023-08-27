#include <stdio.h>
// Function to calculate the checksum of a data word
unsigned int checksum(unsigned int data) {
 int sum = 0;
 while (data != 0) {
 sum += data & 1;
 data >>= 1;
 }
 return sum;
}
// Function to add a checksum to a data word
unsigned int addChecksum(unsigned int data) {
 unsigned int checksumCode = checksum(data);
 return data | checksumCode;
}
// Function to check if a data word has a checksum error
int hasChecksumError(unsigned int data) {
 unsigned int checksumCode = checksum(data);
 return (checksumCode != 0);
}
// Function to correct a checksum error
unsigned int correctChecksumError(unsigned int data) {
 unsigned int checksumCode = checksum(data);
 while (hasChecksumError(data)) {
 data ^= 1;
 }
 return data;
}
int main() {
 unsigned int data = 10110;
 unsigned int codeword = addChecksum(data);
 printf("Data word: %d\n", data);
 printf("Codeword: %d\n", codeword);
 if (hasChecksumError(codeword)) {
 printf("Codeword has an error.\n");
 codeword = correctChecksumError(codeword);
 printf("Corrected codeword: %d\n", codeword);
 } else {
 printf("Codeword does not have an error.\n");
 }
 return 0;
}