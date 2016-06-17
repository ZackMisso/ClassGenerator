CC=clang++
#CC=g++
CFLAGS+= -std=c++11

PROD=lazy

SRCS= $(shell ls *.cpp)
SRCS+= $(shell ls unitTests/*.cpp)

OBJS= $(patsubst %.cpp, %.o, $(SRCS))

all: $(PROD)

$(OBJS): %.o: %.cpp
	$(CC) -c $(CFLAGS) $(CPPFLAGS) $(INCLUDES) $< -o $@

$(PROD): $(OBJS)
	$(CC) -o $(PROD) $^ $(LIBS)

clean:
	rm -f $(PROD)
	rm -f *.o
	rm -f unitTests/*.o
