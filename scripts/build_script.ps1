Write-Host "build_script Windows"
#
cd $APPVEYOR_BUILD_FOLDER
mkdir build
cd build
mkdir AppDir
# FIXME x86
if ($Env:PLATFORM -eq "x64")
{
    qmake -v && qmake ..\$MY_BIN_PRO_RES_NAME.pro CONFIG+=$configuration CONFIG+=c++11 DESTDIR=$cd && mingw32-make && mingw32-make install INSTALL_ROOT=AppDir
}
else
{
    qmake -v && qmake ..\$MY_BIN_PRO_RES_NAME.pro CONFIG+=$configuration CONFIG+=c++11 DESTDIR=$cd && mingw32-make && mingw32-make install INSTALL_ROOT=AppDir
}
Write-Host "after_build Windows" -ForegroundColor Cyan
dir
#
copy "$APPVEYOR_BUILD_FOLDER\build\$MY_BIN_PRO_RES_NAME.exe" "AppDir\$MY_BIN_PRO_RES_NAME-$MY_OS-$CONFIGURATION-$PLATFORM.exe"
#
windeployqt "AppDir/$MY_BIN_PRO_RES_NAME.exe" --verbose=2
#
#mv $MY_BIN_PRO_RES_NAME.exe $MY_BIN_PRO_RES_NAME-$PLATFORM.exe
Copy-Item -Path "$MY_BIN_PRO_RES_NAME.exe" -Destination "$MY_BIN_PRO_RES_NAME-$PLATFORM.exe" -Force
#
# The packages/${MY_QIF_PACKAGE_URI}/meta/installscript.qs creates this: copy -v "desktop/${MY_BIN_PRO_RES_NAME}.desktop" "${MY_QIF_PACKAGE_URI}";

Copy-Item -Path "${APPVEYOR_BUILD_FOLDER}/desktop/${MY_BIN_PRO_RES_NAME}.png" -Destination "${APPVEYOR_BUILD_FOLDER}/${MY_QIF_PACKAGE_URI}/data" -Force
Copy-Item -Path "${APPVEYOR_BUILD_FOLDER}/desktop/${MY_BIN_PRO_RES_NAME}.svg" -Destination "${APPVEYOR_BUILD_FOLDER}/${MY_QIF_PACKAGE_URI}/data" -Force
Copy-Item -Path "${APPVEYOR_BUILD_FOLDER}/desktop/${MY_BIN_PRO_RES_NAME}.ico" -Destination "${APPVEYOR_BUILD_FOLDER}/${MY_QIF_PACKAGE_URI}/data" -Force

#copy -v "${APPVEYOR_BUILD_FOLDER}/desktop/${MY_BIN_PRO_RES_NAME}.png" "${APPVEYOR_BUILD_FOLDER}/${MY_QIF_PACKAGE_URI}/data";
#copy -v "${APPVEYOR_BUILD_FOLDER}/desktop/${MY_BIN_PRO_RES_NAME}.svg" "${APPVEYOR_BUILD_FOLDER}/${MY_QIF_PACKAGE_URI}/data";
#copy -v "${APPVEYOR_BUILD_FOLDER}/desktop/${MY_BIN_PRO_RES_NAME}.ico" "${APPVEYOR_BUILD_FOLDER}/${MY_QIF_PACKAGE_URI}/data";

Copy-Item -Path "${APPVEYOR_BUILD_FOLDER}/usr/share/icons" -Destination "${APPVEYOR_BUILD_FOLDER}/${MY_QIF_PACKAGE_URI}/icons" -recurse -Force
#rsync -Ravr "${APPVEYOR_BUILD_FOLDER}/usr/share/icons" "${APPVEYOR_BUILD_FOLDER}/${MY_QIF_PACKAGE_URI}/icons"

ls "${APPVEYOR_BUILD_FOLDER}/${MY_QIF_PACKAGE_URI}/data";
#
Write-Host "Running Qt Installer Framework" -ForegroundColor Cyan
if ($Env:PLATFORM -eq "x64")
{
    export ARTIFACT_APPIMAGE="${MY_BIN_PRO_RES_NAME}-x64.exe"
}
else
{
    export ARTIFACT_APPIMAGE="${MY_BIN_PRO_RES_NAME}-x86.exe"
}
#
export ARTIFACT_QIF="${MY_BIN_PRO_RES_NAME}-Linux-Installer"
#
#7z a -tzip "$MY_BIN_PRO_RES_NAME-$MY_OS-$CONFIGURATION-$PLATFORM.zip" AppDir -r

Copy-Item -Path "$APPVEYOR_BUILD_FOLDER\build\$MY_BIN_PRO_RES_NAME-$MY_OS-$CONFIGURATION-$PLATFORM.zip" -Destination "$APPVEYOR_BUILD_FOLDER" -recurse -Force
#copy "$APPVEYOR_BUILD_FOLDER\build\$MY_BIN_PRO_RES_NAME-$MY_OS-$CONFIGURATION-$PLATFORM.zip" "$APPVEYOR_BUILD_FOLDER"

Write-Host APPVEYOR_BUILD_FOLDER=$APPVEYOR_BUILD_FOLDER -ForegroundColor Cyan
#
Copy-Item -Path "$APPVEYOR_BUILD_FOLDER\build\AppDir" -Destination "$APPVEYOR_BUILD_FOLDER\$MY_QIF_PACKAGE_URI" -recurse -Force
#xcopy /s /e /f "$APPVEYOR_BUILD_FOLDER\build\AppDir" "$APPVEYOR_BUILD_FOLDER\$MY_QIF_PACKAGE_URI"
#C:\Qt\Tools\QtInstallerFramework\3.2\bin\binarycreator.exe --offline-only -c "$APPVEYOR_BUILD_FOLDER\config\config.xml" -p "$APPVEYOR_BUILD_FOLDER\packages" "$MY_BIN_PRO_RES_NAME-Windows-Installer.exe"
#7z a -tzip "$MY_BIN_PRO_RES_NAME-Windows-$PLATFORM-Installer.zip" "$MY_BIN_PRO_RES_NAME-Windows-Installer.exe"
#

Copy-Item -Path "$MY_BIN_PRO_RES_NAME-Windows-$PLATFORM-Installer.zip" -Destination "$APPVEYOR_BUILD_FOLDER" -Force
#copy *.zip $APPVEYOR_BUILD_FOLDER

Copy-Item -Path "$MY_BIN_PRO_RES_NAME-$PLATFORM.exe" -Destination "$APPVEYOR_BUILD_FOLDER" -recurse -Force
#copy *.exe $APPVEYOR_BUILD_FOLDER

cd $APPVEYOR_BUILD_FOLDER
#
dir
Write-Host "Completed-Build Windows" -ForegroundColor DarkGreen
