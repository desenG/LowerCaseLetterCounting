OBJS=FileHelper.o main.o 
CC=g++
INCPATH=.
CFLAGS=-Wall -I$(INCPATH)

.c.o:
	$(CC) $(CFLAGS) -c $<

app: $(OBJS)
	$(CC) $(CFLAGS) -o app $(OBJS)	

cleanall:
	-rm -f *.o app