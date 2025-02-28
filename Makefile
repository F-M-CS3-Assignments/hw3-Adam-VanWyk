all:
	g++ -Wall TimeCode.cpp TimeCodeTests.cpp -o tct
	g++ -Wall TimeCode.cpp NasaLaunchAnalysis.cpp -o nasa

run:
	./nasa

try: all run