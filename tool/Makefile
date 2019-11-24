main:main.o child.o
	gcc $^ -o $@
%.o:%.c
	gcc $< -o $@

.PHONY:clean
clean:
	rm -f main
