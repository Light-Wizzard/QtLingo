#
# 23 Auguest 2021
#
# [-BackgroundColor {Black | DarkBlue | DarkGreen | DarkCyan | DarkRed | DarkMagenta | DarkYellow | Gray | DarkGray | Blue | Green | Cyan | Red | Magenta | Yellow | White}]
# [-ForegroundColor {Black | DarkBlue | DarkGreen | DarkCyan | DarkRed | DarkMagenta | DarkYellow | Gray | DarkGray | Blue | Green | Cyan | Red | Magenta | Yellow | White}]

If ($env:PLATFORM -eq "x64") {
    Write-Host "install Windows QT x64" -ForegroundColor Yellow
    $env:Path += ";C:\Qt\Tools\$env:MY_QT_MINGW64\bin"
    $env:Path += ";C:\Qt\$env:MY_QT_VERSION\$env:MY_QT_MINGW64\bin"
    $env:Path += ";C:\Qt\$env:MY_QT_VERSION\$env:MY_QT_MINGW64"
    $env:Path += ";C:\Qt\$env:MY_QT_VERSION\$env:MY_QT_MINGW64\lib\cmake\Qt5"
    $env:Path += ";C:\Python$env:MY_PYTHON_VER-x64"
    $env:Path += ";C:\MINGW;C:\MINGW\bin;C:\MinGW\msys\1.0;C:\msys64"
    $env:Path += ";C:\Strawberry\perl\bin"
    $env:MSYSTEM = "MINGW64"  # Start a 64 bit Mingw environment
    $env:MY_QT_BAT = "C:\Qt\$env:MY_QT_VERSION\$env:MY_QT_MINGW64\bin\qtenv2.bat"
    Invoke-Expression $env:MY_QT_BAT
    $env:MY_VS_BAT = "C:\Program Files (x86)\Microsoft Visual Studio\$env:MY_VS_VERSION\Community\VC\Auxiliary\Build\vcvars64.bat"
    cmd /c call $env:MY_VS_BAT
    $env:QTDIR     *= "C:\Qt\$env:MY_QT_VERSION\$env:MY_QT_MINGW64;C:\Qt\$env:MY_QT_VERSION\$env:MY_QT_MINGW64\bin;C:\MINGW;C:\MINGW\bin"
    $env:QMAKESPEC *= "win32-g++"
    $env:LANG      *= "en"
}
ElseIf ($env:PLATFORM -eq "x86") {
    Write-Host "install Windows QT x86" -ForegroundColor Yellow
    $env:Path += ";C:\Qt\Tools\$env:MY_QT_MINGW32\bin"
    $env:Path += ";C:\Qt\$env:MY_QT_VERSION\$env:MY_QT_MINGW32\bin"
    $env:Path += ";C:\Qt\$env:MY_QT_VERSION\$env:MY_QT_MINGW32"
    $env:Path += ";C:\Qt\$env:MY_QT_VERSION\$env:MY_QT_MINGW32\lib\cmake\Qt5"
    $env:Path += ";C:\Python$env:MY_PYTHON_VER"
    $env:Path += ";C:\MINGW;C:\MINGW\bin"
    $env:Path += ";C:\Strawberry\perl\bin"
    $env:QTDIR     *= "C:\Qt\$env:MY_QT_VERSION\$env:MY_QT_MINGW32;C:\Qt\$env:MY_QT_VERSION\$env:MY_QT_MINGW32\bin;C:\MINGW;C:\MINGW\bin"
    $env:QMAKESPEC *= "win32-g++"
    $env:LANG      *= "en"
    $env:MY_QT_BAT = "C:\Qt\$env:MY_QT_VERSION\$env:MY_QT_MINGW32\bin\qtenv2.bat"
    Invoke-Expression $env:MY_QT_BAT
    cmd /c call "C:\Program Files (x86)\Microsoft Visual Studio\$env:MY_VS_VERSION\Community\VC\Auxiliary\Build\vcvars32.bat"
}
