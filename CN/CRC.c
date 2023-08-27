#include <stdio.h>
// Function to calculate the CRC of a data word
unsigned int crc(unsigned int data, unsigned int generator) {
 int remainder = 0;
 while (data != 0) {
 if ((data & 1) == 1) {
 remainder = remainder ^ generator;
 }
 data >>= 1;
 generator >>= 1;
 }
 return remainder;
}
// Function to add a CRC code to a data word
unsigned int addCRC(unsigned int data, unsigned int generator) {
 unsigned int crcCode = crc(data, generator);
 return data | crcCode;
}
// Function to check if a data word has a CRC error
int hasCRCError(unsigned int data, unsigned int generator) {
 unsigned int crcCode = crc(data, generator);
 return (crcCode != 0);
}
int main() {
 unsigned int data = 10110;
 unsigned int generator = 0x11;
 unsigned int codeword = addCRC(data, generator);
 printf("Data word: %d\n", data);
 printf("Codeword: %d\n", codeword);
 if (hasCRCError(codeword, generator)) {
 printf("Codeword has an error.\n");
 } else {
 printf("Codeword does not have an error.\n");
 }
 return 0;
}