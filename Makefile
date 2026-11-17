CLANG = $(ANDROID_NDK_HOME)/toolchains/llvm/prebuilt/linux-x86_64/bin/aarch64-linux-android21-clang

librobloxfflags.so: librobloxfflags.o
	$(CLANG) -shared -s -o $@ $^

%.o: %.c
	$(CLANG) -std=c23 -O2 -fPIC -c $< -o $@
