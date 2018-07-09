.PHONY: default
default: build;

build:
	g++ -W -Wall -pedantic -o test main.cpp 
