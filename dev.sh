make re
VALGRIND="valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --log-file=leaks.log --track-fds=yes --trace-children=yes"
$VALGRIND ./pipex infile.txt "grep o" "wc -l" outfile.txt