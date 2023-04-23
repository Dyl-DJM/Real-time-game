CFLAGS = -ansi -Wall -Wextra
CC = gcc
BIN = bin/
SRC = src/
INC = include/


tempsreel: $(BIN)Main.o $(BIN)aide.o $(BIN)temps.o $(BIN)gestion_fichier.o $(BIN)config_stdin.o $(BIN)tas.o $(BIN)Niveau.o $(BIN)graphique.o
	$(CC) -o tempsreel $(BIN)Main.o $(BIN)aide.o $(BIN)temps.o $(BIN)gestion_fichier.o $(BIN)config_stdin.o $(BIN)tas.o $(BIN)Niveau.o $(BIN)graphique.o

$(BIN)Main.o: $(SRC)Main.c
	$(CC) -c $(SRC)Main.c $(CFLAGS) -o $(BIN)Main.o 



$(BIN)aide.o: $(SRC)aide.c $(INC)aide.h
	$(CC) -c $(SRC)aide.c $(CFLAGS) -o $(BIN)aide.o

$(BIN)graphique.o: $(SRC)graphique.c $(INC)graphique.h
	$(CC) -c $(SRC)graphique.c $(CFLAGS) -o $(BIN)graphique.o



$(BIN)tas.o : $(SRC)tas.c $(INC)tas.h $(INC)aide.h
	$(CC) -c $(SRC)tas.c $(CFLAGS) -o $(BIN)tas.o


$(BIN)config_stdin.o : $(SRC)config_stdin.c $(INC)config_stdin.h
	$(CC) -c $(SRC)config_stdin.c $(CFLAGS) -o $(BIN)config_stdin.o


$(BIN)temps.o : $(SRC)temps.c $(INC)temps.h
	$(CC) -c $(SRC)temps.c $(CFLAGS) -o $(BIN)temps.o


$(BIN)gestion_fichier.o : $(SRC)gestion_fichier.c $(INC)gestion_fichier.h
	$(CC) -c $(SRC)gestion_fichier.c $(CFLAGS) -o $(BIN)gestion_fichier.o

$(BIN)Niveau.o : $(SRC)Niveau.c $(INC)Niveau.h
	$(CC) -c $(SRC)Niveau.c $(CFLAGS) -o $(BIN)Niveau.o

#Ici on définie le mot clé clean
#pour nettoyer le dossier des fichiers .o et executables
clean:
	rm -f $(BIN)*.o tempsreel