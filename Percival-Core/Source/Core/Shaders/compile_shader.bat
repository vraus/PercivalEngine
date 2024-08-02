set SHADER_DIR=%~dp0

C:/VulkanSDK/1.3.283.0/Bin/glslc.exe "%SHADER_DIR%simple_shader.vert" -o "%SHADER_DIR%vert.spv"
C:/VulkanSDK/1.3.283.0/Bin/glslc.exe "%SHADER_DIR%simple_shader.frag" -o "%SHADER_DIR%frag.spv"
pause
