make re
VALGRIND="valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --log-file=leaks.log"
$VALGRIND ./pipex infile.txt cat wc outfile.txt