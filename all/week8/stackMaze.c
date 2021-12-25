#include<stdio.h>
#include<stdlib.h>

#define MAZE_X 6
#define MAZE_Y 6
#define DESTINATION_X 5
#define DESTINATION_Y 5

char dir[4] = { 'N', 'E', 'S', 'W' };
int Mark[MAZE_Y + 1][MAZE_X + 1] = { 0, };
int Maze[MAZE_Y + 1][MAZE_X + 1] = { { 1,1,1,1,1,1,1 },{ 1,0,0,0,0,1,1 },{ 1,1,1,0,1,1,1 },{ 1,1,0,0,0,0,1 },{ 1,1,0,1,1,1,1 },{ 1,1,0,0,0,0,1 },{ 1,1,1,1,1,1,1 } };
typedef struct node {
	int x;
	int y;
	int dirNum;
	char d;
	struct node *next;
}MAZE_STACK;

void initStack(MAZE_STACK *s);
void PUSH(MAZE_STACK *s, int x, int y, char d, int dirNum);
void POP(MAZE_STACK *s);
void printStack(MAZE_STACK *s);
int MOVE(MAZE_STACK *s);
void MAZE(MAZE_STACK *s);

int MOVE(MAZE_STACK *s) {
	MAZE_STACK *temp = s;
	int x, y;
	int a;;
	int b;
	while (temp->next != NULL) {
		temp = temp->next;
	}
	a = temp->x;
	b = temp->y;
	if (a == DESTINATION_X && b == DESTINATION_Y) {
		printf("****ESCAPE****\n");
		return 0;
	}
	if (temp->d == 'N') {
		x = a;
		y = b - 1;
	}
	else if (temp->d == 'E') {
		x = a + 1;
		y = b;
	}
	else if (temp->d == 'S') {
		x = a;
		y = b + 1;
	}
	else if (temp->d == 'W') {
		x = a - 1;
		y = b;
	}
	if (Mark[y][x] == 0 && Maze[y][x] == 0) {
		Mark[y][x] = 1;
		PUSH(s, x, y, dir[0], 0);
		printStack(s);
		MOVE(s);
	}
	else {
		if (temp->d == 'W') {
			POP(s);
			printStack(s);
			MOVE(s);
		}
		else {
			POP(s);
			printStack(s);
			temp->dirNum = temp->dirNum + 1;
			PUSH(s, a, b, dir[temp->dirNum], temp->dirNum);
			printStack(s);
			MOVE(s);
		}
	}
}
void MAZE(MAZE_STACK *s) {
	PUSH(s, 1, 1, dir[s->dirNum], 0);
	MOVE(s);
}
void initStack(MAZE_STACK* s) {
	s->x = NULL;
	s->y = NULL;
	s->d = NULL;
	s->dirNum = NULL;
	s->next = NULL;
}
void PUSH(MAZE_STACK *s, int x, int y, char d, int dirNum) {
	MAZE_STACK *temp;
	temp = (MAZE_STACK *)malloc(sizeof(MAZE_STACK));
	printf("push: (%d, %d, %c)\n", x, y, d);
	while (s->next != NULL) {
		s = s->next;
	}
	temp->x = x;
	temp->y = y;
	temp->d = d;
	temp->dirNum = dirNum;
	temp->next = NULL;
	s->next = temp;
}
void POP(MAZE_STACK *s) {
	while (s->next->next != NULL) {
		s = s->next;
	}
	printf("pop: (%d, %d, %c)\n", s->next->x, s->next->y, s->next->d);
	s->next = NULL;
}
void printStack(MAZE_STACK *s) {
	printf("MAZE_STACK: ");
	while (s->next != NULL) {
		s = s->next;
		printf("(%d, %d, %c)->", s->x, s->y, s->d);
	}
	printf("\n");
}
int main() {
	MAZE_STACK *maze;

	maze = (MAZE_STACK *)malloc(sizeof(MAZE_STACK));
	initStack(maze);
	MAZE(maze);
}
