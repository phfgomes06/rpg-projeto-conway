TARGET = rpg

SRCS = *.cpp \
       construtor-fichas/*.cpp \
       enredo-principal/*.cpp \

all:
	g++ $(SRCS) -o $(TARGET)

clean:
	rm -f $(TARGET)
