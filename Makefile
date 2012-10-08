all:
	g++ -lglut -lGLU -lm main.cpp -o main
	./main `./screensize.sh`
