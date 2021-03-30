# Discord RPC
Check out their [README](https://github.com/discord/discord-rpc/blob/e6390c8c4190b59f1cc98bcec688e0037b84974d/README.md#from-repo) for building instructions.

Make sure `ENABLE_IO_THREAD` is set to `OFF`. (or your game will crash if you try to reload .asi scripts)

# JSON for Modern C++
You can get it from [here](https://github.com/nlohmann/json/releases/tag/v3.9.1).

Download `json.hpp` and put it into `nlohmann/`.

# ScriptHookRDR2 SDK
You can get it from [here](http://www.dev-c.com/rdr2/scripthookrdr2/).

Put files from `inc/` to `ScriptHookRDR2/inc/` (do not replace `natives.h` and `types.h`)

Put files from `lib/` to `ScriptHookRDR2/lib/`