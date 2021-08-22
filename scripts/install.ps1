# [-BackgroundColor {Black | DarkBlue | DarkGreen | DarkCyan | DarkRed | DarkMagenta | DarkYellow | Gray | DarkGray | Blue | Green | Cyan | Red | Magenta | Yellow | White}]
# [-ForegroundColor {Black | DarkBlue | DarkGreen | DarkCyan | DarkRed | DarkMagenta | DarkYellow | Gray | DarkGray | Blue | Green | Cyan | Red | Magenta | Yellow | White}]

If ($env:PLATFORM -eq "x64" -And $env:MY_COMPILER -eq "Qt") {
    Write-Host "install Windows QT x64" -ForegroundColor Yellow
    $env:Path += ";C:\Qt\Tools\$env:MY_QT_MINGW64\bin"
    $env:Path += ";C:\Qt\$env:MY_QT_VERSION\$env:MY_QT_MINGW64\bin"
    $env:Path += ";C:\Qt\$env:MY_QT_VERSION\$env:MY_QT_MINGW64"
    $env:Path += ";C:\Python$env:MY_PYTHON_VER-x64"
    $env:Path += ";C:\MINGW\bin\"
    $env:MY_QT_BAT = "C:\Qt\$env:MY_QT_VERSION\$env:MY_QT_MINGW64\bin\qtenv2.bat"
    Invoke-Expression $env:MY_QT_BAT
    #$env:MY_VS_BAT = "C:\PROGRA~2\MICROS~3\2019\COMMUN~1\VC\AUXILI~1\Build\vcvars64.bat"
    $env:MY_VS_BAT = "C:\Program Files (x86)\Microsoft Visual Studio\$env:MY_VS_VERSION\Community\VC\Auxiliary\Build\vcvars64.bat"
    #Invoke-Expression $env:MY_VS_BAT
    #iex $env:MY_VS_BAT
    #Invoke-Expression "C:\PROGRA~2\MICROS~3\2019\COMMUN~1\VC\AUXILI~1\Build\vcvars64.bat"
    #iex "C:\PROGRA~2\MICROS~3\2019\COMMUN~1\VC\AUXILI~1\Build\vcvars64.bat"
    cmd /c call $env:MY_VS_BAT
}
ElseIf ($env:PLATFORM -eq "x86" -And $env:MY_COMPILER -eq "Qt") {
    Write-Host "install Windows QT x86" -ForegroundColor Magenta
    $env:Path += ";C:\Qt\Tools\$env:MY_QT_MINGW32\bin"
    $env:Path += ";C:\Qt\$env:MY_QT_VERSION\$env:MY_QT_MINGW32\bin"
    $env:Path += ";C:\Qt\$env:MY_QT_VERSION\$env:MY_QT_MINGW32"
    $env:Path += ";C:\Python$env:MY_PYTHON_VER"
    $env:Path += ";C:\MINGW\bin\"
    $env:MY_QT_BAT = "C:\Qt\$env:MY_QT_VERSION\$env:MY_QT_MINGW64\bin\qtenv2.bat"
    #$env:MY_VS_BAT = "C:\PROGRA~2\MICROS~3\2019\COMMUN~1\VC\AUXILI~1\Build\vcvars32.bat"
    Invoke-Expression $env:MY_QT_BAT
    #Invoke-Expression $MY_VS_BAT
    cmd /c call "C:\Program Files (x86)\Microsoft Visual Studio\$env:MY_VS_VERSION\Community\VC\Auxiliary\Build\vcvars32.bat"
}
ElseIf ($env:PLATFORM -eq "x64" -And $env:MY_COMPILER -eq "Vs") {
    Write-Host "install Windows VS x64" -ForegroundColor DarkYellow
    $env:Path += ";C:\Qt\Tools\$env:MY_QT_MINGW64\bin"
    $env:Path += ";C:\Qt\$env:MY_QT_VERSION\msvc$env:MY_VS_VERSION_64\bin"
    $env:Path += ";C:\Python$env:MY_PYTHON_VER-x64"
    $env:Path += ";C:\MINGW\bin\"
    Invoke-Expression "C:\Qt\$env:MY_QT_VERSION\$env:MY_QT_MINGW64\bin\qtenv2.bat"
    cmd /c call "C:\Program Files (x86)\Microsoft Visual Studio\$env:MY_VS_VERSION\Community\VC\Auxiliary\Build\vcvars64.bat"
}
ElseIf ($env:PLATFORM -eq "x86" -And $env:MY_COMPILER -eq "Vs") {
    Write-Host "install Windows VS x86" -ForegroundColor DarkMagenta
    $env:Path += ";C:\Qt\Tools\$env:MY_QT_MINGW32\bin"
    $env:Path += ";C:\Qt\$env:MY_QT_VERSION\$env:MY_QT_MINGW32\bin"
    $env:Path += ";C:\Qt\$env:MY_QT_VERSION\$env:MY_QT_MINGW32"
    $env:Path += ";C:\Python$env:MY_PYTHON_VER"
    $env:Path += ";C:\MINGW\bin\"
    Invoke-Expression "C:\Qt\$env:MY_QT_VERSION\msvc$env:MY_VS_VERSION\bin\qtenv2.bat"
    cmd /c call "C:\Program Files (x86)\Microsoft Visual Studio\$env:MY_VS_VERSION\Community\VC\Auxiliary\Build\vcvars32.bat"
}
