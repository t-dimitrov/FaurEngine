@echo off

echo Building external dependencies...
echo spdlog...
cmake -S "FaurEngine/external/spdlog/" -B "./Build/spdlog/"

pause
