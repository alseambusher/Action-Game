all:
	g++ -lglut -lGLU -lm -lGL main.cpp -o main
	./main `./screensize.sh`
