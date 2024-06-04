
#makefile Billionaire class
CC= clang++
autocomplete-big-list: autocomplete-big-list.o
		$(CC) autocomplete-big-list.o -o autocomplete-big-list

autocomplete-big-list.o: autocomplete-big-list.cpp
		 $(CC) -c autocomplete-big-list.cpp

clean: 
		rm -rf *o autocomplete-big-list.o autocomplete-big-list
