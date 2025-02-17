all:
	g++ -Wall TimeCode.cpp -o tct

run:
	./tct

try: all run