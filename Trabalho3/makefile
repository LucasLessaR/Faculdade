# UFRJ - Universidade Federal do Rio de Janeiro
# Escola Politecnica
# EEL670 - Linguagens de Programacao - 2020/2
# Prof: Miguel Elias Mitre Campista
# Autor: Lucas Lessa Rodrigues
# Sobre: Arquivo de dependencias para compilacao e linkedicao do programa

CC = g++

LD = $(CC)

CFLAGS = -Wall
LFLAGS = -Wall

TRAB = trabalho3

TRABOBJS = catalogo.o main.o

EXECS = $(TRAB)

LIBS =

ALL = $(LIBS) $(EXECS)

# Regra implicita
.c.o:
	$(CC) $(CFLAGS) -c $<

all: $(ALL)

trabalho3: $(TRABOBJS)
	$(LD) $(LFLAGS) -o $@ $(TRABOBJS)

.PHONY: clean

clean:
	rm -f *.o $(ALL)