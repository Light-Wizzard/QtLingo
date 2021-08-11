#
Write-Host "install Windows" -ForegroundColor DarkGreen
#
if ($Env:PLATFORM -eq "x64")
{
    set PATH=C:\Qt\Tools\$MINGW_64\bin;C:\Qt\$MY_VS_VERSION\$MY_QT_MINGW64\bin;C:\Qt\$MY_VS_VERSION\$MY_QT_MINGW64\;$PATH
    set PATH=C:\Python$PYTHON_VER-x64;$PATH
    call C:\Qt\$MY_VS_VERSION\$MY_QT_MINGW64\bin\qtenv2.bat"
    call "C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Auxiliary\Build\vcvars64.bat"
}
else
{
    set PATH=C:\Qt\Tools\$MINGW_32\bin;C:\Qt\$MY_VS_VERSION\bin;$PATH
    set PATH=C:\Python$PYTHON_VER;$PATH
    call C:\Qt\$MY_VS_VERSION\$MY_QT_MINGW32\bin\qtenv2.bat"
    call "C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Auxiliary\Build\vcvars32.bat"
}

#curl -fsS -o QtInstallerFramework-windows.exe https://download.qt.io/official_releases/qt-installer-framework/$Env:MY_QT_IF_VERSION/QtInstallerFramework-windows-x86-$Env:MY_QT_IF_VERSION.exe

Write-Host "install Windows Completed" -ForegroundColor DarkGreen



