@echo off
for /r %%i in (*.frag) do %VULKAN_SDK%/Bin/glslangValidator.exe -V %%i -o %%~niFrag.spv
for /r %%i in (*.vert) do %VULKAN_SDK%/Bin/glslangValidator.exe -V %%i -o %%~niVert.spv
move *.spv Compiled
pause
EXIT /B %ERRORLEVEL%