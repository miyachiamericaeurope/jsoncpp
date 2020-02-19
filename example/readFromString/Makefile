readfromstring : readfromstring.o
	g++ readfromstring.o -ljsoncpp  -o readfromstring

readfromstring.o: readFromString.cpp
	g++ -c readFromString.cpp -o readfromstring.o -ljsoncpp #-I../../include

clean : 
	rm -r *.o



