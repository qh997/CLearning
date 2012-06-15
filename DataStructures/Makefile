
TARGET := exp03
OBJECT := expxx.o
OBJECT += $(TARGET).o
ifeq ($(TARGET), exp02)
OBJECT += exp02/seqlist.o exp02/linkedlist.o
endif
ifeq ($(TARGET), exp03)
OBJECT += exp03/seqstack.o exp03/linkedqueue.o exp03/seqqueue.o
endif

ifneq ($(CC), gcc)
CC := gcc
endif
CFLAGS := -std=c99
#define compile_c99
#    $(CC) -std=c99
#endef

NAME ?= gengs

$(warning : I am here!)

#exp02.o: exp02.c mydef.h expxx.h
#	$(compile_c99) -c exp02.c

#expxx.o: expxx.c expxx.h
#	$(compile_c99) -c expxx.c

#exp02/seqlist.o: exp02/seqlist.c exp02/seqlist.h mydef.h
#	cd exp02; \
#	$(compile_c99) -c seqlist.c; \
#	cd -

#EXP02_H = $(vpath %.h ./exp02)

#exp02/linkedlist.o: exp02/linkedlist.c $(EXP02_H) mydef.h
#	cd exp02; \
#	$(compile_c99) -c linkedlist.c; \
#	cd -

.PHONY: all clean show

all: show clean run

clean:
	-rm $(OBJECT) run

show:
	@echo "TARGET : $(TARGET)"
	@echo "Make command : ${MAKE}"
	@echo "Make level : ${MAKELEVEL}"
	@echo "Compiler : ${CC}"
	@echo "Hello ${NAME}"
	@echo $(subst changxy, gengs, Hello changxy)
	@echo "NAME is come from : $(origin NAME)"
	@echo "CFLAGS : $(CFLAGS)"
 
run: $(OBJECT)
	@echo
	@echo 'make run'
	$(CC) $(CFLAGS) $^ -o $@