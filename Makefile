CC = $(ANDROID_NDK_HOME)/toolchains/llvm/prebuilt/linux-x86_64/bin/aarch64-linux-android21-clang
CFLAGS = -std=c23 -O2 -fPIC

librobloxfflags.so: librobloxfflags.o
	$(CC) -shared -s -o $@ $^