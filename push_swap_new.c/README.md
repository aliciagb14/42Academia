Estructura PushSwap:
----------
Para empezar:
◦ En a tendrás números positivos y/o negativos, nunca duplicados.
◦ En b no habrá nada.

• El objetivo es ordenar los números del stack a en orden ascendente.
• Para hacerlo tienes las siguientes operaciones a tu disposición:
	sa : swap a - intercambia los dos primeros elementos encima del stack a. No hace nada si hay uno o menos elementos.
	
	sb : swap b - intercambia los dos primeros elementos encima del stack b. No hace nada si hay uno o menos elementos.

	ss : swap a y swap b a la vez.

	pa : push a - toma el primer elemento del stack b y lo pone encima del stack a. No hace nada si b está vacío.

	pb : push b - toma el primer elemento del stack a y lo pone encima del stack b. No hace nada si a está vacío.

	ra : rotate a - desplaza hacia arriba todos los elementos del stack a una posición, de forma que el primer elemento se convierte en el último.

	rb : rotate b - desplaza hacia arriba todos los elementos del stack b una posición, de forma que el primer elemento se convierte en el último.

	rr : rotate a y rotate b - desplaza al mismo tiempo todos los elementos del stack
	a y del stack b una posición hacia arriba, de forma que el primer elemento se
	convierte en el último.

	rra : reverse rotate a - desplaza hacia abajo todos los elementos del stack a una
	posición, de forma que el último elemento se 		convierte en el primero.

	rrb : reverse rotate b - desplaza hacia abajo todos los elementos del stack b una
	posición, de forma que el último elemento se convierte en el primero.

	rrr : reverse rotate a y reverse rotate b - desplaza al mismo tiempo todos
	los elementos del stack a y del stack b una posición hacia abajo, de forma que
	el último elemento se convierte en el primero.

Comprobar leaks:
----------
Basta con añadir atexit(valgrind) en mi funcion main y hacer una funcion valgrind de forma:

	void	valgrind(void)
	{
		system("leaks push_swap");
	}

Notas:
----------
1. El system tendrá la siguiente estructura: system("leaks nombreEjecutable")