#Makefile

#Inside Macro
#	$@:ターゲット名
#	$<:依存ファイルの先頭のファイル名
#	$^:依存ファイルのリスト
#Ver.0.2 (2017/02/03)

CC := gcc
CXX := g++
CFLAGS := -Wall -g -o 
CXXFLAGS := -Wall -g -o
#optimeze option ...実行時にO="-O0", "-O1", "-O2"などを指定
O = -O2
#リンカオプション
LDFLAGS = -lm


all:

%:
	$(CC) $(CFLAGS) $* $*.c $(LDFLAGS) $(O)
%.gc:
	$(CC) $(CFLAGS) $* $*.c $(LDFLAGS) $(O)
%.gp:
	$(CXX) $(CXXFLAGS) $* $*.cpp $(LDFLAGS) $(O)
	

#	gcc -Wall -g -o kadai01 kadai01.c -lm
.PHONY: %.c
%.c: OUTPUT = $*
%.c: 
	$(CC) $(CFLAGS) $(OUTPUT) $< $@ $(O)


	
%.o: %.c
	$(CC) -c $(CFLAGS) $(CPPFLAGS) $@ $<


clean:
	rm -f *~ *.o a.out