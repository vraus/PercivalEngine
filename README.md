# Percival Engine

> An OpenSource, C++, Vulkan based custom little game engine
>
> **Author:*Hadrien "Vraus"***
>
> **Date:*07/07/2024***

Percival-Engine builds into a static library and is meant to contain common code intended for use in multiple applications. Percival-App builds into an executable and links the Percival-Engine static library, as well as provides an include path to Percival-Engine's code.

The `Scripts/` directory contains build scripts for Windows and Linux, and the `Vendor/` directory contains Premake binaries (currently version `5.0-beta2`).

## Sources

+ Vulkan Related Documentation
    + [Vulkan](https://www.vulkan.org)
    + [Vulkan's API Documentation](https://docs.vulkan.org/spec/latest/index.html)
    + [Khronos Vulkan Tutorial](https://docs.vulkan.org/tutorial/latest/00_Introduction.html)
    + ["Vulkan Tutorial", Alexander Overvoorde](https://vulkan-tutorial.com)
    + [Writing an efficient Vulkan renderer](https://zeux.io/2020/02/27/writing-an-efficient-vulkan-renderer/)
+ Documentation
    + [Premake Documentation](https://premake.github.io/docs/)
+ WebSites
    + [A Simple ECS System (C++), A. Morlan](https://austinmorlan.com/posts/entity_component_system/)
    + [Computer Graphics Programming](https://scratchapixel.com/index.html)
    + [Introduction to Component Based Architecture in Games](https://www.kodeco.com/2806-introduction-to-component-based-architecture-in-games)
    + [Awesome Creative Coding](https://project-awesome.org/terkelg/awesome-creative-coding)
+ Books
    + [(3rd ed) Game Engine Architecture, J. Gregory](Resources/game-engine-architecture-3rded.pdf)
    + [Programmer efficacement en C++, S.Meyers](https://www.dunod.com/sciences-techniques/programmer-efficacement-en-c-42-conseils-pour-mieux-maitriser-c-11-et-c-14)
+ EBooks
    + [(2nd ed) Game Engine Architecture, J. Gregory](https://archive.org/details/gameenginearchit0000greg_d9n5)
    + [Mathematics for 3D Game Programming and Computer Graphics](https://canvas.projekti.info/ebooks/Mathematics%20for%203D%20Game%20Programming%20and%20Computer%20Graphics,%20Third%20Edition.pdf)
    + [Core Techniques and Algorithms in Game Engine](https://theswissbay.ch/pdf/Gentoomen%20Library/Algorithms/Core%20Techniques%20and%20Algorithms%20in%20Game%20Programming.pdf)
+ Videos
    + [How to Properly Setup C++ Projects](https://www.youtube.com/watch?v=5glH8dGoeCA)
    + [Kohi #000: Game Engine Architecture and Overview (Vulkan Game Engine Series)](https://www.youtube.com/watch?v=teg23SJlyl8)
    + [Game Engine Architecture: Bill Clark (CodeLabs Tech Talk 2020)](https://www.youtube.com/watch?v=mUeNqLcx4eI)

## License
- UNLICENSE for this repository (see `UNLICENSE.txt` for more details)
- Premake is licensed under BSD 3-Clause (see included LICENSE.txt file for more details)
