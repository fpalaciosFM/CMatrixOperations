CDEPENDENCIES = Source/matrix.c Source/matrio.c Source/elementary.c Source/LU.c
MAIN_EXEC = CMatrixOperations

$(MAIN_EXEC): main.c $(CDEPENDENCIES)
	gcc -o $(MAIN_EXEC) main.c $(CDEPENDENCIES)

run:
	./$(MAIN_EXEC)