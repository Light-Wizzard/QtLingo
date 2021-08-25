#
# 23 Auguest 2021
#
#$env:MY_MAKE = "qmake.exe $env:APPVEYOR_BUILD_FOLDER\$env:MY_BIN_PRO_RES_NAME.pro CONFIG+=$env:CONFIGURATION CONFIG+=x86_64"
#Invoke-Expression $env:MY_MAKE
#$env:CMAKEGENERATOR = "MinGW Makefiles"
#$env:CMAKEGENERATOR = "NMake Makefiles"
#$env:CMAKEGENERATOR = "Visual Studio 16 2019"
#$env:CMAKEGENERATOR = "Unix Makefiles"
# 32 Bit only
# ! C:\msys64\mingw32\bin\i686-w64-mingw32-g++.exe
# ! C:\msys64\mingw64\bin\x86_64-w64-mingw32-g++.exe
#
#$env:CC="C:\msys64\mingw64\bin\x86_64-w64-mingw32-gcc.exe"
#$env:CXX="C:\msys64\mingw64\bin\x86_64-w64-mingw32-g++.exe"
#$env:CC="clang-cl -mrtm"
#$env:CXX="clang-cl -mrtm"
#$env:CMAKE_CXX_COMPILER="C:\Program Files\LLVM\bin\clang-cl"
# -DCMAKE_PREFIX_PATH="$env:CMAKE_PATH_PREFIX" $env:CMAKE_PATH_PREFIX = "C:\Qt\$env:MY_QT_VERSION\msvc$env:MY_VS_VERSION_64\lib\cmake"
#$env:MY_MAKE = "cmake -A x64 -G $env:CMAKEGENERATOR -DCMAKE_PREFIX_PATH=$env:CMAKE_PATH_PREFIX -DCMAKE_BUILD_TYPE=$env:CONFIGURATION -DCMAKE_INSTALL_PREFIX=AppDir .."
#cmd /c cmake -G "MinGW Makefiles" -DCMAKE_PREFIX_PATH="$env:CMAKE_PATH_PREFIX" -DCMAKE_INSTALL_PREFIX=AppDir -DCMAKE_C_COMPILER=/c/MinGW/bin/gcc.exe -DCMAKE_CXX_COMPILER=/c/MinGW/bin/g++.exe ..
# $env:ProgramFiles\LLVM\bin $env:ProgramFiles(x86)\LLVM\bin\clang.exe
# "C:\MeineProgramme\Ninja\bin"
#cmake -E env LDFLAGS="-fuse-ld=lld-link" PATH="<path\to\ninja>"
#cmake .. -G "Ninja" -Bbuild -DCMAKE_C_COMPILER:PATH="$env:ProgramFiles(x86)\LLVM\bin\clang.exe" -DCMAKE_CXX_COMPILER:PATH="$env:ProgramFiles(x86)\LLVM\bin\clang.exe" -DCMAKE_C_COMPILER_ID="Clang" -DCMAKE_CXX_COMPILER_ID="Clang" -DCMAKE_SYSTEM_NAME="Generic"
#cmd /c cmake .. -G "Ninja" -DBUILD_SHARED_LIBS=OFF -DCMAKE_TOOLCHAIN_FILE="c:/tools/vcpkg/scripts/buildsystems/vcpkg.cmake" -T "LLVM"  -DCMAKE_LINKER="$env:LLD_LINK" -DCMAKE_INSTALL_PREFIX="AppDir"
#cmd /c cmake .. -G "Ninja" -Bbuild -DCMAKE_C_FLAGS=TRUE -DCMAKE_CXX_FLAGS=TRUE -DCMAKE_C_COMPILER="C:/Program Files/LLVM/bin/clang.exe" -DCMAKE_CXX_COMPILER="C:/Program Files/LLVM/bin/clang.exe" -DCMAKE_LINKER="C:/Program Files/LLVM/bin/lld-link.exe"
If ($env:PLATFORM -eq "x64") {
    Write-Host "build_script Windows QT x64" -ForegroundColor Yellow
    $env:MY_BUILD_GOOD = "false"
    Set-Location -Path "$env:APPVEYOR_BUILD_FOLDER"
    New-Item -Path $env:APPVEYOR_BUILD_FOLDER -Name "build" -ItemType Directory
    Set-Location -Path "build"
    $env:BUILD_ROOT = "$env:APPVEYOR_BUILD_FOLDER\build"
    $env:CC="C:\Qt\Tools\$env:MY_QT_TOOLS_MINGW64\bin\gcc.exe"
    $env:CXX="C:\Qt\Tools\$env:MY_QT_TOOLS_MINGW64\bin\g++.exe"
    cmd /c cmake .. -G "MinGW Makefiles" -DBUILD_SHARED_LIBS=OFF -DCMAKE_INSTALL_PREFIX="AppDir"
    If ($?) {
        mingw32-make
        If ($?) {
            mingw32-make VERBOSE=1 all
            If ($?) {
                Test-Path -Path AppDir\$env:MY_BIN_PRO_RES_NAME.exe -PathType Leaf
                If ($?) {
                    $env:MY_BUILD_GOOD = "true"
                }
            }
        }
    }
}
ElseIf ($env:PLATFORM -eq "x86") {
    Write-Host "build_script Windows QT x86" -ForegroundColor Yellow
    $env:MY_BUILD_GOOD = "false"
    Set-Location -Path "$env:APPVEYOR_BUILD_FOLDER"
    New-Item -Path $env:APPVEYOR_BUILD_FOLDER -Name "build" -ItemType Directory
    Set-Location -Path "build"
    $env:BUILD_ROOT = "$env:APPVEYOR_BUILD_FOLDER\build"
    $env:CC="C:\Qt\Tools\$env:MY_QT_TOOLS_MINGW32\bin\gcc.exe"
    $env:CXX="C:\Qt\Tools\$env:MY_QT_TOOLS_MINGW32\bin\g++.exe"
    cmd /c cmake .. -G "MinGW Makefiles" -DBUILD_SHARED_LIBS=OFF -DCMAKE_INSTALL_PREFIX=-DCMAKE_INSTALL_PREFIX="$env:APPVEYOR_BUILD_FOLDER/AppDir"
    If ($?) {
        mingw32-make -j2
        Get-ChildItem -File
        If ($?) {
            mingw32-make all
            Get-ChildItem -File
            If ($?) {
                Test-Path -Path "$env:APPVEYOR_BUILD_FOLDER\build\$env:MY_BIN_PRO_RES_NAME.exe" -PathType Leaf
                If ($?) {
                    Write-Host "File exist copying to AppDir folder"
                    New-Item -Path "$env:APPVEYOR_BUILD_FOLDER" -Name "AppDir" -ItemType Directory
                    Get-ChildItem -Path "$env:APPVEYOR_BUILD_FOLDER" -Directory
                    Copy-Item "$env:APPVEYOR_BUILD_FOLDER\build\$env:MY_BIN_PRO_RES_NAME.exe" -Destination "$env:APPVEYOR_BUILD_FOLDER\AppDir"
                    Get-ChildItem -Path "$env:APPVEYOR_BUILD_FOLDER\AppDir" -File
                    $env:MY_BUILD_GOOD = "true"
                }
            }
        }
    }
}
#
If ($env:MY_BUILD_GOOD -eq "true") {
    $currentDirectory = [System.AppDomain]::CurrentDomain.BaseDirectory.TrimEnd('\')
    If ($currentDirectory -eq $PSHOME.TrimEnd('\')) {
        $currentDirectory = $PSScriptRoot
    }
    Write-Host "After Windows build $env:currentDirectory"
    #Get-ChildItem -Path "$env:APPVEYOR_BUILD_FOLDER\AppDir"
    Copy-Item "C:\Qt\Tools\QtCreator\bin\plugins\platforms\*" -Destination "$env:APPVEYOR_BUILD_FOLDER\AppDir" -Recurse
    Invoke-Expression "windeployqt $env:APPVEYOR_BUILD_FOLDER\AppDir\$env:MY_BIN_PRO_RES_NAME.exe --verbose=2"
    Invoke-Expression "7z a -tzip $env:MY_BIN_PRO_RES_NAME-$env:MY_OS-$env:CONFIGURATION-$env:PLATFORM.zip $env:APPVEYOR_BUILD_FOLDER\AppDir -r"
    Copy-Item "$env:APPVEYOR_BUILD_FOLDER\build\$env:MY_BIN_PRO_RES_NAME-$env:MY_OS-$env:CONFIGURATION-$env:PLATFORM.zip" -Destination "$env:APPVEYOR_BUILD_FOLDER\"
    Copy-Item "*.zip" -Destination "$env:APPVEYOR_BUILD_FOLDER\"
    Set-Location -Path "$env:APPVEYOR_BUILD_FOLDER"
    Write-Host "Completed-Build Windows"
}

#Get-ChildItem -Path "$env:APPVEYOR_BUILD_FOLDER" -Recurse –File
