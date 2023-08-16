#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

// void printBinary(unsigned int num) {
//     for (int i = 8; i >= 0; i--) {
//         putchar((num & (1 << i)) ? '1' : '0');
//     }
//     putchar('\n');
// }
// int a = 5; // 0101 in binary
// int b = 3; // 0011 in binary

// printf("A: "); printBinary(a);
// printf("B: "); printBinary(b);
// printf("Bitwise & : "); printBinary(a & b);
// printf("Bitwise | : "); printBinary(a | b);
// printf("Bitwise ^ : "); printBinary(a ^ b);
// printf("Bitwise ~ : "); printBinary(~a);
// printf("Bitwise <<: "); printBinary(a << b);
// printf("Bitwise >>: "); printBinary(a >> b);

void handler(int num)
{
	 printf("I wont die!\n");
}

void fork_ex()
{
	// Example 1:
	// int id = fork();
	// if (id == 0)
	// 	printf("Child: %d\n", id);
	// else if (id > 0)
	// 	printf("Main: %d\n", id);
	
	// Example 2:
	// fork();
	// fork();
	// printf("Hello World!\n");
}

int main()
{
	fork_ex();
    return 0;
}