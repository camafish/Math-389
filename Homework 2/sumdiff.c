#include <stdio.h>
#include <stdlib.h>

//I'm assuming the entered strings are representing positive integers.//

int string_length(char *s) { //stole this from jim fix//
  int i;
  i = 0;
  while (s[i] != '\000') {
	i = i+1;
  }
  return i;
}

int max(int i, int j){
	if (i <= j){return j;} else {return i;}
}

char *sum(char *n, char *m){
	int l1 = string_length(n);
	int l2 = string_length(m);
	int l3 = max(l1,l2);
	
	char *out = malloc(l3 + 2); //+1 because there's at most one more digit in the sum than in either//
	int i = 0;
	while (i < (l3 + 1)){
		out[i] = 48;
		i = i + 1;
	}
	out[l3 + 1] = '\000';	
	
	i = 0;
	while (i < (l3 + 1)){			
		int ndigit = n[l1 - 1 - i] % 48;
		int mdigit = m[l2 - 1 - i] % 48; 
		int odigit = out[l3 - i] % 48; 
				
		if ((ndigit + mdigit + (out[l3 - i] % 48)) < 10) {	
			out[l3 - i] = 48 + ndigit + mdigit + odigit;		
		} else {
			out[l3 - i] = 48 + ((ndigit + mdigit + odigit) % 10);
			out[l3 - 1 - i] = 49;
		}
		i = i + 1;	
	}	
	
	if (out[0] == 48){
		char *out2 = malloc(l3 + 1);
		i = 0;
		while (i < l3){
			out2[i] = out[i + 1];
			i = i + 1;
		} 
		out2[i] = '\000';
		return out2;
	} else {return out;}	
}

//I was only able to get diff working if I assumed that the numbers
// are given in large-small order. I could just find the value of 
// each number given and then order them appropriately, but doing
// that seems to go against the spirit of schoolbook arithmetic 
// using only the symbols themselves. Is there another way?

char *diff(char *n, char *m){
	int l1 = string_length(n);
	int l2 = string_length(m);
	int l3 = max(l1,l2);
	
	char *out = malloc(l3 + 2); 
	int i = 0;
	while (i < (l3 + 1)){
		out[i] = 48;
		i = i + 1;
	}
	out[l3 + 1] = '\000';	
	
	i = 0;
	int carry = 0;
	while (i < (l3 + 1)){
		//printf("%s\n", out);
		
		int ndigit = n[l1 - 1 - i] % 48;
		int mdigit = m[l2 - 1 - i] % 48;
		int odigit = out[l3 - i] % 48; 
		
		printf("%d %d %s\n", ndigit, mdigit, out);
		
		if ((ndigit - mdigit - carry) >= 0) {
			out[l3 - i] = 48 + (ndigit - mdigit - carry);
			if(carry){carry = 0;}
		} else {
			//printf("%d\n", 48 + -(ndigit - mdigit));
			out[l3 - i] = 48 + (ndigit - mdigit - carry + 10);
			carry = 1;
		}
		i = i + 1;
	}
	
	if (out[0] == 48){
		char *out2 = malloc(l3 + 1);
		i = 0;
		while (i < l3){
			out2[i] = out[i + 1];
			i = i + 1;
		} 
		out2[i] = '\000';
		return out2;
	}
	return out;	
}

int main(int argc, char **argv){
	char *n = argv[1];
	char *m = argv[2];	
	
	
	if (n == NULL | m == NULL){printf("Too few arguments!");} else {
		char *s = sum(n, m);
		char *d = diff(n, m);
		printf("The sum is %s.\n", s);
		printf("The difference is %s.\n", d);
	}
}