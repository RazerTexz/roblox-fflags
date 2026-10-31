# Roblox FFlags

An Android shared library to override any Roblox FFlag.

## Installation

1. Put [librobloxfflags.so](https://github.com/RazerTexz/robloxfflags/actions/workflows/build.yaml) in `lib/arm64-v8a/`.
2. Add to `com/roblox/client/RobloxApplication.smali` -> `onCreate` after `.registers` or `.locals`:
```smali
const-string v0, "robloxfflags"

invoke-static {v0}, Ljava/lang/System;->loadLibrary(Ljava/lang/String;)V
```
3. Recompile and sign.
