C64 = $(ANDROID_NDK_HOME)/toolchains/llvm/prebuilt/linux-x86_64/bin/aarch64-linux-android21-clang

librobloxfflags.so: src/main.o
	$(C64) -shared -s $^ -o $@

%.o: %.c
	$(C64) -c -std=c23 -O2 -fPIC $^ -o $@