@echo off

::: ______ ___  _   _______  ____________ _____   ___ _____ _____ _____ 
::: |  ___/ _ \| | | | ___ \ | ___ \ ___ \  _  | |_  |  ___/  __ \_   _|
::: | |_ / /_\ \ | | | |_/ / | |_/ / |_/ / | | |   | | |__ | /  \/ | |  
::: |  _||  _  | | | |    /  |  __/|    /| | | |   | |  __|| |     | |  
::: | |  | | | | |_| | |\ \  | |   | |\ \\ \_/ /\__/ / |___| \__/\ | |  
::: \_|  \_| |_/\___/\_| \_| \_|   \_| \_|\___/\____/\____/ \____/ \_/  
:::                                                                    
:::                                                                    
for /f "delims=: tokens=*" %%A in ('findstr /b ::: "%~f0"') do @echo(%%A

set "buildFolderPath=Build\"

if exist "%buildFolderPath%" (
	echo Build folder already exists. Deleting...
	rmdir /s /q "%buildFolderPath%"
)

echo Creating "Build/" directory
mkdir "%buildFolderPath%"
cd /d "%buildFolderPath%"

cmake ../

pause