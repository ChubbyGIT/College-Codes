#include <stdio.h>
// Function to calculate the parity of a row
int getRowParity(unsigned int row) {
 int parity = 0;
 while (row) {
 parity ^= row & 1;
 row >>= 1;
 }
 return parity;
}
// Function to calculate the parity of a column
int getColumnParity(unsigned int column) {
 int parity = 0;
 while (column) {
 parity ^= column & 1;
 column >>= 1;
 }
 return parity;
}
// Function to add a row and column parity bit to a data word
unsigned int add2DParity(unsigned int data) {
 int rowParity = getRowParity(data);
 int columnParity = getColumnParity(data);
 return data | (rowParity << (sizeof(data) * 8 - 1)) | (columnParity << (sizeof(data) * 8 - 2));
}
// Function to check if a data word has a 2D parity error
int has2DParityError(unsigned int data) {
 int rowParity = getRowParity(data);
 int columnParity = getColumnParity(data);
 return (rowParity ^ (data >> (sizeof(data) * 8 - 1))) | (columnParity ^ (data >> (sizeof(data) * 8 - 2)));
}
int main() {
 unsigned int data = 10110;
 unsigned int codeword = add2DParity(data);
 printf("Data word: %d\n", data);
 printf("Codeword: %d\n", codeword);
 if (has2DParityError(codeword)) {
 printf("Codeword has a 2D parity error.\n");
 } else {
 printf("Codeword does not have a 2D parity error.\n");
 }
 return 0;
}