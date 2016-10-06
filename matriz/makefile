SRC = src
INCLUDE = include
OBJ = obj
BIN = bin
LIB = lib

all: $(BIN)/prueba $(BIN)/menu

$(BIN)/prueba: $(OBJ)/prueba.o $(LIB)/libimagen.a
	g++ $(OBJ)/prueba.o -limagen -o $(BIN)/prueba -L$(LIB)
	
$(BIN)/menu: $(OBJ)/menu.o $(LIB)/libimagen.a
	g++ $(OBJ)/menu.o -limagen -o $(BIN)/menu -L$(LIB)

$(OBJ)/prueba.o: $(SRC)/prueba.cpp $(INCLUDE)/imagen.h $(INCLUDE)/codificar.h
	g++ -c $(SRC)/prueba.cpp -o $(OBJ)/prueba.o -I$(INCLUDE)
	
$(OBJ)/menu.o: $(SRC)/menu.cpp $(INCLUDE)/imagen.h $(INCLUDE)/codificar.h
	g++ -c $(SRC)/menu.cpp -o $(OBJ)/menu.o -I$(INCLUDE)

$(LIB)/libimagen.a: $(OBJ)/imagen.o $(OBJ)/pgm.o $(OBJ)/codificar.o $(OBJ)/byte.o
	ar rvs $(LIB)/libimagen.a $(OBJ)/imagen.o $(OBJ)/pgm.o $(OBJ)/codificar.o $(OBJ)/byte.o
	
$(OBJ)/imagen.o: $(SRC)/imagen.cpp $(INCLUDE)/imagen.h $(INCLUDE)/pgm.h
	g++ -c $(SRC)/imagen.cpp -o $(OBJ)/imagen.o -I$(INCLUDE)

$(OBJ)/pgm.o: $(SRC)/pgm.cpp $(INCLUDE)/pgm.h
	g++ -c $(SRC)/pgm.cpp -o $(OBJ)/pgm.o -I$(INCLUDE)

$(OBJ)/codificar.o: $(SRC)/codificar.cpp $(INCLUDE)/codificar.h $(INCLUDE)/imagen.h $(INCLUDE)/byte.h
	g++ -c $(SRC)/codificar.cpp -o $(OBJ)/codificar.o -I$(INCLUDE)

$(OBJ)/byte.o: $(SRC)/byte.cpp $(INCLUDE)/byte.h
	g++ -c $(SRC)/byte.cpp -o $(OBJ)/byte.o -I$(INCLUDE)

clean:
	@echo "Borrando ficheros objeto, librerías e imágenes generadas..."
	@rm -f $(OBJ)/*.o $(LIB)/* *.pgm

mrproper: clean
	@echo "Borrando ejecutables..."
	@rm -f $(BIN)/*
