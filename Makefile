CC = g++
TARGET = a.out
SRCDIR = src
INCDIR = inc
OBJDIR = obj

FLAGS += -g -Wall -std=c++11 
LIBS += -lpthread

SRCS = $(wildcard $(SRCDIR)/*.cpp)
OBJS = $(patsubst $(SRCDIR)/%.cpp, $(OBJDIR)/%.o, $(SRCS))

all : $(TARGET)

$(OBJS) : $(OBJDIR)/%.o : $(SRCDIR)/%.cpp $(PCHFILE)
	$(CC) -c $< -o $@ $(FLAGS) 

$(TARGET) : $(OBJS)
	$(CC) $(OBJS)  -o $(TARGET) $(LIBS)

.PHONY : clean
clean:
	$(RM) $(TARGET)
	$(RM) $(OBJDIR)/*.o

