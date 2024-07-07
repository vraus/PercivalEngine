# Percival Engine

> An OpenSource, C++, Vulkan based custom little game engine
>
> **Author:*Hadrien "Vraus"***
>
> **Date:*07/07/2024***

Percival-Engine builds into a static library and is meant to contain common code intended for use in multiple applications. Percival-App builds into an executable and links the Percival-Engine static library, as well as provides an include path to Percival-Engine's code.

The `Scripts/` directory contains build scripts for Windows and Linux, and the `Vendor/` directory contains Premake binaries (currently version `5.0-beta2`).

## License
- UNLICENSE for this repository (see `UNLICENSE.txt` for more details)
- Premake is licensed under BSD 3-Clause (see included LICENSE.txt file for more details)
