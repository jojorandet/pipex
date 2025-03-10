make re
VALGRIND="valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --track-fds=yes --trace-children=yes"
$VALGRIND  ./pipex infile.txt "echo salut" "wc -l" outfile.txt