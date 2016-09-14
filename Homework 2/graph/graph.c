#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "myMath.h"

int p;
int height;
float xscale;
float yscale;

void clearGraph (char **g){
	int x;
	int y;
	
	for (x = 0; x < 2*height; x++){
		for (y = 0; y < 2*height; y++){
			if (x == height && y == height){
				g[x][y] = 43;
			} else {
				if (x == height){
					g[x][y] = 45;
				} else {
					if (y == height){
						g[x][y] = 124;
					} else {
						g[x][y] = 32;
					}
				}
			}
		}
	}	
}
	
void printGraph (char **g){
	int row;	
	for (row = 0; row < 2*height; row++){
		printf("%s\n", g[2*height - row]);
	}
}	

void plot (char **g, int x, int y, char p){
	if (x > -20 && x < 20 && y > -20 && y < 20) { 
		g[y + height][x + height] = p;
	} 
}

int main() {
	while (1){
		char choice;
		printf("Hello! Would you like to view a (1)preset or (2)custom graph?\n");
		scanf("%s", &choice);
		if (choice == '1'){
			p = 1;
			height = 20;
			xscale = 1;
			yscale = 1;		
		} else {
			printf("Enter an integer power: ");
			scanf("%d",&p); 
			printf("Enter graph size (integer): ");
			scanf("%d", &height);	
			printf("Enter x axis scale (real): ");
			scanf("%f", &xscale);
			printf("Enter y axis scale (real): ");
			scanf("%f", &yscale);
		}
		char **graph = malloc((2*height + 1)* sizeof(char *));
		int i;
		for (i = 0; i < (2*height + 1); i ++){
			graph[i] = malloc(2*height + 1);
		}
		clearGraph(graph);
		for (i = -height; i < height; i++){
			int x = (int)round(xscale*i);
			int y = (int)round(yscale*(powerOf(sin(x), p)));
			plot(graph, x, y, 'X');
		} 			  
		printGraph(graph);
		clearGraph(graph);
	}
}	
    
   
  
