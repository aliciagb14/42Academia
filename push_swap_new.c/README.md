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
	
Caracteristicas para evaluar eficiencia:
----------
push_swap grading - need 6 points to pass
3 Numbers:
1 Point <= 3 Moves
5 Numbers:

1 Point <= 12 Moves
100 Numbers:

5 Points < 700 Moves
4 Points < 900 Moves
3 Points < 1100 Moves
2 Points < 1300 Moves
1 Points < 1500 Moves
500 Numbers:

5 Points < 5500 Moves
4 Points < 7000 Moves
3 Points < 8500 Moves
2 Points < 10000 Moves
1 Points < 11500 Moves

Notas:
----------
1. El system tendrá la siguiente estructura: system("leaks nombreEjecutable")
2. Podemos probar con 500 numeros los leaks: make &&  ./push_swap 447 861 130 354 453 456 885 221 727 66 51 559 231 64 510 374 151 204 71 76 852 552 686 360 238 738 560 47 532 509 719 531 237 770 38 984 744 399 175 119 668 265 263 807 438 248 554 982 810 444 289 362 161 717 214 195 757 107 905 90 573 564 775 891 883 406 876 207 2 455 232 371 169 227 614 355 146 742 693 877 756 938 488 845 239 945 348 261 172 39 828 44 408 446 492 34 287 829 918 643 711 927 429 339 779 157 657 615 396 823 433 209 674 388 692 281 1 791 101 683 555 123 338 637 306 387 422 609 345 812 700 640 311 897 646 202 144 191 60 62 258 84 835 582 568 589 98 401 109 259 318 419 663 234 56 424 680 381 608 783 587 840 635 290 436 688 569 882 802 851 594 959 606 255 677 832 781 800 35 884 753 153 500 386 671 329 537 316 501 402 122 420 902 716 24 162 75 264 407 49 279 106 745 252 917 449 904 530 556 863 19 619 297 724 703 91 892 274 159 236 430 857 607 907 479 327 367 681 326 898 7 12 603 485 192 723 811 28 588 626 788 398 670 254 305 577 633 543 302 824 480 954 138 418 78 914 533 888 930 366 403 925 889 763 454 562 618 478 283 208 280 333 498 257 874 365 487 795 632 896 94 586 152 521 706 527 284 61 315 612 164 322 245 96 769 243 21 435 428 862 395 421 853 189 426 346 761 351 786 490 286 293 92 684 229 58 149 220 110 847 722 689 565 89 822 165 708 277 858 672 825 437 313 976 593 725 179 605 887 230 336 735 613 978 414 675 32 793 903 821 803 491 217 223 114 760 134 584 340 210 718 520 53 219 860 310 139 541 746 712 647 20 967 372 900 5 206 188 921 241 95 273 370 558 328 321 705 539 359 638 10 990 992 729 749 736 296 276 86 3 743 156 576 699 854 517 798 814 796 475 998 307 294 330 452 266 939 980 721 216 295 470 439 792 831 748 262 77 567 228 813 855 423 213 272 604 335 754 324 309 312 13 342 740 579 275 163 940 985 623 142 690 598 707 127 597 975 578 16 389 799 270 694 45 774 112 379 655 282 731 710 380 73 83 875 929 147 872 393 849 52 440 115 278 868 616 137 314 482 126 180 412 923 515 658 462 864 524 771 235
