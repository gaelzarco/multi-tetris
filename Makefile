game: modules game.cxx
	g++ game.cxx -std=c++23 -fmodules-ts -o game 

modules:
	g++ -std=c++23 -fmodules-ts -x c++-system-header print
	g++ -std=c++23 -fmodules-ts -x c++-system-header raylib.h

clean:
	rm game
	rm -r gcm.cache
