OBJS := \
	main.o \


OUTFILE := cc-validator

.PHONY: all clean

all: $(OUTFILE)

$(OBJS): %.o: %.cpp
	g++ -c -Wall -std=c++14 $< -o $@

$(OUTFILE): $(OBJS)
	g++ $(OBJS) -o $(OUTFILE)

clean:
	rm -f *.o $(OUTFILE)
