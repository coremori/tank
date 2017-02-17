START_DIR=${PWD}


all:   build

clean:	
	@rm -rf extern/libmicrohttpd extern/libmicrohttpd-0.9.46 extern/jsoncpp-0.10.5
	@rm -rf bin build 


configure:
	@mkdir -p build 
	@cd "${START_DIR}/extern" && ./configure --prefix="${START_DIR}/extern"
	@cd build && cmake ..



	

build:
	@make -s -j4 -C build
	gcc ./src/launch/ClientAndServer.c -o ./bin/launcher

run: build
	./bin/launcher 
	

test:
	$(info --- Docker don't work because it need python to compilate ---)
	$(info --- Use make for compilate and make run for running ---)
	$(info )
	docker build -t plt-initial -f docker/plt-initial .
	docker build -t plt-build -f docker/plt-build .
	./docker/run_docker_x11.sh plt-build

start-kit: distclean
	@tar -czvf ../plt-start-kit.tar.gz CMakeLists.txt Makefile .gitignore dia2code src docker rapport res

.PHONY: configure build clean run test start-kit
