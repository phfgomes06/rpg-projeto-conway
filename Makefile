TARGET = rpg

SRCS = main.cpp \
       construtor-fichas/*.cpp \
       enredo-principal/*.cpp \
       funcoes-universais.cpp

all:
	g++ $(SRCS) -o $(TARGET)

clean:
	rm -f $(TARGET)