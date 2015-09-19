MAIN=main
CC=gcc -g
SRC=source
TARGET_DIR=target
OBJ_DIR = $(TARGET_DIR)/obj
M32=-m32

INC_FILES= -I/usr/local/include -I/usr/include/libxml2 -I$(SRC)/websvr/inc -I$(SRC)/FH/inc -I$(SRC)/webint/inc 

CFLAGS = $(DEBUG) $(OPTIM) $(M32) -DLINUX -I. $(INC_FILES)

PTHREAD_LIB = -lpthread

LIBS = -L. -L/usr/lib -lm  -lrt  -lcrypt $(LIB_XML_OBJ) \
	$(TARGET_DIR)/lib/libxyssl.a \
	./$(TARGET_DIR)/lib/libshttpd.a 
	

obj: prep $(MAIN).o az_ditributed_sys.o az_db.o az_scheduler.o az_user.o az_utility.o az_resiliency.o

sum: $(OBJ_DIR)/*.o
	$(CC) $(CFLAGS) -o $@ $^ $(PTHREAD_LIB) $(LIBS)
all:sum


lib: prep
	make -f $(SRC)/websvr/Makefile TARGET_DIR=$(TARGET_DIR)

cleanlib:
	make clean -f $(SRC)/websvr/Makefile TARGET_DIR=$(TARGET_DIR)
prep:
	if [ ! -d ${OBJ_DIR} ] ; then \
	   mkdir ${OBJ_DIR} ;\
	fi
	if [ ! -d ${LIB_DIR} ] ; then \
	   mkdir ${LIB_DIR} ;\
	fi
	
	
$(MAIN).o:$(MAIN).c
	$(CC) $(CFLAGS) -c $(MAIN).c -o $(OBJ_DIR)/$@
	
balance_sheet.o :$(SRC)/FH/src/balance_sheet.c
	$(CC) $(CFLAGS) -c $(SRC)/FH/src/balance_sheet.c -o $(OBJ_DIR)/$@
	

clean:
	rm -f *.o sum
