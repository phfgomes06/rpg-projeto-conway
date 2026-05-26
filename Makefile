TARGET = rpg

SRCS = main.cpp \
       construtor-fichas/*.cpp \
       funcoes-luta/*.cpp \
       funcoes-universais/*.cpp \
       inimigos/*.cpp \
       enredo-principal/*.cpp \

all:
	g++ $(SRCS) -o $(TARGET)

clean:
	rm -f $(TARGET)
