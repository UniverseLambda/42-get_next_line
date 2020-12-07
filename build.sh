gcc -fsanitize=address -Wall -Wextra -Werror -DBUFFER_SIZE=1000000000 debug.c main.c -o gln_main
