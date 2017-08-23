
CCFLAGS = -g3 -I/usr/include/python2.7 -fPIC -shared -Iinclude
LIBS = -lhpdf

CC=gcc

.PHONY: all compile depends


OBJS=pyhpdf.c pyhpdf_doc.c pyhpdf_page.c


all: compile


depends:
	apt install -y libhpdf-dev


compile:
	$(CC) $(CCFLAGS) -o _hpdf.so $(OBJS) $(LIBS)


debug:
	gdb -ex r --args python2 01_hpdf_example.py
