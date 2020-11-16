all: clean reload build exec

mkdir_build:
	[ -d ./cmake-build-debug ] | mkdir -p cmake-build-debug

build:
	cd cmake-build-debug;mingw32-make

exec:
	./cmake-build-debug/MyFirstGame

clean:
	rm -rf cmake-build-debug

reload: mkdir_build
	cd cmake-build-debug;cmake -G "MinGW Makefiles" ..

fast_build:
	cd cmake-build-debug;mingw32-make

run: fast_build exec

lint:
	cd cmake-build-debug;mingw32-make lint

reformat:
	find src/ -iname "*.cpp" | xargs clang-format -i --style=file
	find include/ -iname "*.h" | xargs clang-format -i --style=file