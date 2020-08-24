iclud :main.o Message.o Serialization.o 
	g++ -o iclud main.o Message.o Serialization.o -lpthread -lboost_serialization

main.o :main.cpp Message.h Serialization.h
	g++ -c main.cpp -lpthread
Message.o : Message.cpp Message.h
	g++ -c Message.cpp -lpthread
Serialization.o : Serialization.cpp Serialization.h Message.h
	g++ -c Serialization.cpp -lpthread -lboost_serialization
clean :
	rm main.o Message.o Serialization.o
