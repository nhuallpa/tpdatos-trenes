# CONFIGURACION
################

# Nombre del ejecutable.
target_kdtree = kdtree
target_kdtree_test = testevoto

# Extensión de los archivos a compilar (c para C, cpp o cc o cxx para C++).
extension = cpp

# CONFIGURACION "AVANZADA"
###########################

# Opciones para el compilador C/C++ en modo ansi.
#CFLAGS = -Wall -ansi -pedantic-errors
CFLAGS = -Wall -ansi -pedantic-errors

# Para valgrind o debug
CFLAGS += -ggdb -DDEBUG

# Opciones para el compilador C++.
#CXXFLAGS = $(CFLAGS) -fno-inline
CXXFLAGS = $(CFLAGS) 

# Opciones del enlazador.
#LDFLAGS


# VARIABLES CALCULADAS A PARTIR DE LA CONFIGURACION
####################################################

# Uso enlazador de c++ si es código no C.
ifeq ($(extension), c)
enlazador = $(CC)
else
enlazador = $(CXX)
endif

# Si no especifica archivos, tomo todos.

fuentes  = $(wildcard ./src/bplustree/*.cpp) \
		$(wildcard ./src/bplustree/exceptions/*.cpp) \
		$(wildcard ./src/bplustree/strategies/*.cpp) \
		$(wildcard ./src/controller/*.cpp) \
		$(wildcard ./src/entidades/horario/exceptions/*.cpp) \
		$(wildcard ./src/entidades/horario/*.cpp) \
		$(wildcard ./src/entidades/*.cpp) \
		$(wildcard ./src/logger/exceptions/*.cpp) \
		$(wildcard ./src/logger/*.cpp) \
		$(wildcard ./src/persistence/*.cpp) \
		$(wildcard ./src/utils/*.cpp) \
		$(wildcard ./Tests/testUnit/*.cpp) \
		$(wildcard ./src/*.cpp)

# REGLAS
#########

.PHONY: all clean

kdtree :$(target_kdtree)
o_files_kdtree = $(patsubst %.$(extension),%.o,$(fuentes))
$(target_kdtree): $(o_files_kdtree)
	$(enlazador) $(LDFLAGS) $(o_files_kdtree) $(LOADLIBES) $(LDLIBS) -o $(target_kdtree)

test :$(target_kdtree_test)
o_files_kdtree = $(patsubst %.$(extension),%.o,$(fuentes))
$(target_kdtree_test): $(o_files_kdtree)
	$(enlazador) $(LDFLAGS) $(o_files_kdtree) $(LOADLIBES) $(LDLIBS) -o $(target_kdtree_test)

all: $(kdtree)

test: $(test)

clean:
	$(RM) -rf $(o_files_kdtree)
