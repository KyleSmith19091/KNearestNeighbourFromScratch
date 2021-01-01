run:
	g++ -std=c++14 ./src/*.cpp -I ./include -o main
	./main
	
clean:
	rm *.o prac4
