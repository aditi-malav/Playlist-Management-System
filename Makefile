CXX = g++


all:
	$(CXX) main.cpp playlist.cpp -o playlist

clean:
	rm -f playlist
