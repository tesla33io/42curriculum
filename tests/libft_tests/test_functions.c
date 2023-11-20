#include <stdio.h>
#include <string.h>

void print_array(char *msg, const void *arr, size_t size) {
	const unsigned char *byteArray = arr;
	printf("%s\n", msg);
	for (size_t i = 0; i < size; i++) {
		printf("%02X ", byteArray[i]);
	}
	printf("\n");
}

void print_pointer(char* msg, const void *ptr) {
	printf("%s\n", msg);
    printf("Pointer address: %p\n", ptr);
}