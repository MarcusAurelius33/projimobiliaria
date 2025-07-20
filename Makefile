all:
	g++ main.cpp cliente.cpp corretor.cpp imovel.cpp utils.cpp -o imobiliaria

clean: 
	rm imobiliaria