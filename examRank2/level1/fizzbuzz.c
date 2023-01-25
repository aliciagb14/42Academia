/*	
**	Write a program that prints the numbers from 1 to 100, each separated by a
**	newline.
**	If the number is a multiple of 3, it prints 'fizz' instead.
**	If the number is a multiple of 5, it prints 'buzz' instead.
**	If the number is both a multiple of 3 and a multiple of 5, it prints 'fizzbuzz' instead.
*/

#include <unistd.h>

int ft_print_number(int number){
	char str[10] = "0123456789";
	if (number > 9)
		ft_print_number(number/10);
	write(1, &str[number % 10], 1);
}

int main(int argc, char **argv){
	int number;

	number = 1;
	while(number <= 100){
		if (number % 3 == 0 && number % 5 == 0)
			write(1, "fizbuzz", 7);
		else{
			if ((number % 3) == 0)
				write(1, "fizz", 4);
			else if ((number % 5) == 0)
				write(1, "buzz", 4);
			else{
				ft_print_number(number);		
			}
		}
		number++;
		write(1, "\n", 1);
	}
}