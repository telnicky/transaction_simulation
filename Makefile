
all: 
	g++ -g main.cc product.cc warehouse.cc date.cc

run: a.out
	./a.out

a.out:	main.cc product.cc warehouse.cc date.cc
	g++ -g main.cc product.cc warehouse.cc date.cc	