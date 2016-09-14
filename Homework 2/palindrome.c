#include <stdio.h>
#include <stdlib.h>

int len(int i) {
	int n = 0;
	while (i > 0) {
		i = i / 2;
		n = n + 1;
	}
	return n;
}

int reverse(int i) {
	int n = 0;
	int length = len(i);
	while (i > 0) {
		if (i % 2 == 1) {n = n + (1 << (length - 1));}
		i = i / 2;
		length = length - 1; //I could just recheck len(i) every time but I know its just going down by 1 so why run len again.//
	}
	return n;
}

int is_palindrome(int i){
	return (i == reverse(i));
}
char *bits(int i){
	int n = 1;
	int length = len(i);
	char *out = (char *)malloc(length + 1);

	while (n <= length){
		if (i%2 == 0){out[length - n] = '0';} else {out[length - n] = '1';}
		i = i/2;
		n = n + 1;
	}
	out[n] = (char)0;
	return out;
}

int main() {
	int num;
	char *bitstring;
	
	printf("Enter a number:\n");
	scanf("%d", &num);
	
	printf("The following numbers are binary palindromes:\n");
	
	while (num > 0){
		if (is_palindrome(num)){
			bitstring = bits(num);			
			printf("%d = ", num);
			printf("%s\n", bitstring);
		} 
		num = num - 1;
	}
}