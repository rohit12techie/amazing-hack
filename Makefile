MAIN=az_main
CC=gcc -g
SRC=source
TARGET_DIR=target
OBJ_DIR = $(TARGET_DIR)/obj
M32=-m32

INC_FILES= -I/usr/local/include -I/usr/include/libxml2 -I$(SRC)/include 

CFLAGS = $(DEBUG) $(OPTIM) $(M32) -DLINUX -I. $(INC_FILES)

PTHREAD_LIB = -lpthread

LIBS = -L. -L/usr/lib -lm  -lrt  -lcrypt $(LIB_XML_OBJ) \


obj: prep $(MAIN).o az_server.o az_priority_mgmt.o az_task_mgmt.o az_client.o \
				 az_utility.o az_resiliency.o 

amazing: $(OBJ_DIR)/*.o
	$(CC) $(CFLAGS) -o $@ $^ $(PTHREAD_LIB) $(LIBS)
all:amazing



prep:
	if [ ! -d ${OBJ_DIR} ] ; then \
	   mkdir ${OBJ_DIR} ;\
	fi
	
	
$(MAIN).o:$(MAIN).c
	$(CC) $(CFLAGS) -c $(MAIN).c -o $(OBJ_DIR)/$@
	
az_client.o :$(SRC)/client/az_client.c
	$(CC) $(CFLAGS) -c $(SRC)/client/az_client.c -o $(OBJ_DIR)/$@
	
az_resiliency.o:$(SRC)/resiliency_support/az_resiliency.c
	$(CC) $(CFLAGS) -c $(SRC)/resiliency_support/az_resiliency.c -o $(OBJ_DIR)/$@

az_parser.o:$(SRC)/parser/az_parser.c
	$(CC) $(CFLAGS) -c $(SRC)/parser/az_parser.c -o $(OBJ_DIR)/$@

az_server.o:$(SRC)/server/az_server.c
	$(CC) $(CFLAGS) -c $(SRC)/server/az_server.c -o $(OBJ_DIR)/$@

az_priority_mgmt.o:$(SRC)/scheduler/priority_management/az_priority_mgmt.c
	$(CC) $(CFLAGS) -c $(SRC)/scheduler/priority_management/az_priority_mgmt.c -o $(OBJ_DIR)/$@

az_task_mgmt.o:$(SRC)/scheduler/task_management/az_task_mgmt.c
	$(CC) $(CFLAGS) -c $(SRC)/scheduler/task_management/az_task_mgmt.c -o $(OBJ_DIR)/$@


az_utility.o:$(SRC)/utility/az_utility.c
	$(CC) $(CFLAGS) -c $(SRC)/utility/az_utility.c -o $(OBJ_DIR)/$@


clean:
	rm -f *.o amazing
