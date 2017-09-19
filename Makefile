# author:atao 1628025718@qq.com

CC=g++
CFLAGS=-Wall -std=c++11 
DL=-lpthread -lprotobuf -lleveldb
SO=-fPIC -shared
INCLUDE=-Iinclude/

TARGET=ecc.so

SDIR=src

SRCS= $(SDIR)/ecc.cc \
		$(SDIR)/Ecache.cc \
		$(SDIR)/CommonData.pb.cc \
		$(SDIR)/Wrapper.cc

OBJS=$(SRCS:.cc=.o)

$(TARGET):$(OBJS)
	$(CC) $(SO) -o $@ $^ $(DL)

%.o:%.cc
	$(CC) $(INCLUDE) $(CFLAGS) $(SO) -o $@ -c $<

clean:
	rm -f $(TARGET) $(OBJS)
