output: client.o server1.o netdclient.o netdsrv.o server2.o 
	gcc server1.o -o server1
	gcc client.o -o client
	gcc netdclient.o -o netdclient
	gcc netdsrv.o -o netdsrv
	gcc server2.o -o server2


client.o: client.c define.h
	gcc -c client.c

server1.o: server1.c define.h
	gcc -c server1.c 

netdclient.o: netdclient.c define.h
	gcc -c netdclient.c

netdsrv.o: netdsrv.c define.h
	gcc -c netdsrv.c

server2.o: server2.c define.h
	gcc -c server2.c 

clean:
	rm *.o
