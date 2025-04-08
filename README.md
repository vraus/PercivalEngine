# Percival Engine

> An OpenSource, C++, Vulkan based custom little game engine
>
> ***Author:** Hadrien "Vraus"*
>
> ***Started Date:** 07/07/2024*

## Introduction

**This is the futur new version of my old previous [Tiny Renderer Engine](https://github.com/vraus/testVulkan)... But now trying to make it correctly using and architecture and a builder.**

This project uses a Core/App architecture.

Percival-Engine builds into a static library and is meant to contain common code intended for use in multiple applications.

Percival-App builds into an executable and links the Percival-Engine static library, as well as provides an include path to Percival-Engine's code.

The `Scripts/` directory contains build scripts for Windows and Linux, and the `Vendor/` directory contains Premake binaries (currently version `5.0-beta2`).

## Sources

+ **Vulkan Related Documentation**
  + [Vulkan](https://www.vulkan.org)
  + [Vulkan's API Documentation](https://docs.vulkan.org/spec/latest/index.html)
  + [Khronos Vulkan Tutorial](https://docs.vulkan.org/tutorial/latest/00_Introduction.html)
  + ["Vulkan Tutorial", Alexander Overvoorde](https://vulkan-tutorial.com)
  + [Writing an efficient Vulkan renderer](https://zeux.io/2020/02/27/writing-an-efficient-vulkan-renderer/)
  + [Khronos Vulkan Registry](https://registry.khronos.org/vulkan/#apispecs)
    + [Vulkan 1.3 Specs](https://registry.khronos.org/vulkan/specs/1.3/html/index.html)
+ **Documentation**
  + [Premake Documentation](https://premake.github.io/docs/)
+ **WebSites**
  + [A Simple ECS System (C++), A. Morlan](https://austinmorlan.com/posts/entity_component_system/)
  + [Computer Graphics Programming](https://scratchapixel.com/index.html)
  + [Introduction to Component Based Architecture in Games](https://www.kodeco.com/2806-introduction-to-component-based-architecture-in-games)
  + [Lode's take on Raycasting](https://lodev.org/cgtutor/raycasting.html)
  + [Awesome Creative Coding](https://project-awesome.org/terkelg/awesome-creative-coding)
  + [Physically based rendering](https://www.pbr-book.org)
  + [Raytracing in One Weekend](https://raytracing.github.io/books/RayTracingInOneWeekend.html)
+ **Books**
  + [(3rd ed) Game Engine Architecture, J. Gregory](Resources/game-engine-architecture-3rded.pdf)
  + [Programmer efficacement en C++, S.Meyers](https://www.dunod.com/sciences-techniques/programmer-efficacement-en-c-42-conseils-pour-mieux-maitriser-c-11-et-c-14)
+ **EBooks**
  + [(2nd ed) Game Engine Architecture, J. Gregory](https://archive.org/details/gameenginearchit0000greg_d9n5)
  + [Mathematics for 3D Game Programming and Computer Graphics](https://canvas.projekti.info/ebooks/Mathematics%20for%203D%20Game%20Programming%20and%20Computer%20Graphics,%20Third%20Edition.pdf)
  + [Core Techniques and Algorithms in Game Engine](https://theswissbay.ch/pdf/Gentoomen%20Library/Algorithms/Core%20Techniques%20and%20Algorithms%20in%20Game%20Programming.pdf)
+ **Videos**
  + [How to Properly Setup C++ Projects](https://www.youtube.com/watch?v=5glH8dGoeCA)
  + [Make Beautiful Desktop Applications in C++](https://www.youtube.com/watch?v=-NJDxf4XwlQ)
  + [Kohi #000: Game Engine Architecture and Overview (Vulkan Game Engine Series)](https://www.youtube.com/watch?v=teg23SJlyl8)
  + [Game Engine Architecture: Bill Clark (CodeLabs Tech Talk 2020)](https://www.youtube.com/watch?v=mUeNqLcx4eI)
+ **GitHub Inspirations**
  + *Game Engines*
    + [anthrax AI Game Engine (GitLab)](https://gitlab.com/svatostop/engine-2-0)
    + [@jkatsanis's Sprite Engine UI](https://github.com/jkatsanis/SpriteEngineUI)
    + [@Dssdiego's Feather](https://github.com/Dssdiego/feather)
  + *ECS Implementations*
    + [@alecthomas's entityx](https://github.com/alecthomas/entityx)
    + [@skypjack's entt](https://github.com/skypjack/entt)
    + [@taurheim's NomadECS](https://github.com/taurheim/NomadECS)
  + *Other*
    + [Build you own](https://github.com/codecrafters-io/build-your-own-x)
      + [Tinyrenderer](https://github.com/ssloy/tinyrenderer/wiki)

## What's Next ?

> Some futur features idea

+ Built-in procedural generation
  + Using Wave Collapse Function Algorithm to generate dunjons maybe ?
    + [example video](https://www.youtube.com/watch?v=qRtrj6Pua2A)
    + Needless to say I love procedural generation ...
  + Using a random heightmap generator with parameter tweeking
    + Using Diamond-Square algorithm to generate the heightmap or other approaches...
+ How to integrate sound in the engine ?
  + Use Wwise to plug the sound ?
  + Or use a [raytracing method for 3D sound rendering](https://www.youtube.com/watch?v=u6EuAUjq92k) ... could be fun!!

## License

+ UNLICENSE for this repository (see `UNLICENSE.txt` for more details)

+ Premake is licensed under BSD 3-Clause (see included LICENSE.txt file for more details)
