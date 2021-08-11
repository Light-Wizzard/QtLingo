echo "install Windows"

if %platform%==x64
(
    set PATH=C:\Qt\Tools\%MINGW_64%\bin;C:\Qt\%QT5_VERSION%\%QT5_MINGW64%\bin;C:\Qt\%QT5_VERSION%\%QT5_MINGW64%\;%PATH%
    set PATH=C:\Python%PYTHON_VER%-x64;%PATH%
    call C:\Qt\%QT5_VERSION%\%QT5_MINGW64%\bin\qtenv2.bat"
    call "C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Auxiliary\Build\vcvars64.bat"
)
else
(
    set PATH=C:\Qt\Tools\%MINGW_32%\bin;C:\Qt\%QT5_VERSION%\bin;%PATH%
    set PATH=C:\Python%PYTHON_VER%;%PATH%
    call C:\Qt\%QT5_VERSION%\%QT5_MINGW32%\bin\qtenv2.bat"
    call "C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Auxiliary\Build\vcvars32.bat"
)

//curl https://download.qt.io/official_releases/qt-installer-framework/4.1.1/QtInstallerFramework-windows-x86-4.1.1.exe

curl -fsS -o QtInstallerFramework-windows.exe https://download.qt.io/official_releases/qt-installer-framework/%MY_QT_IF_VERSION%/QtInstallerFramework-windows-x86-%MY_QT_IF_VERSION%.exe
