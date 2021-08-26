#!/bin/bash
#
# Last Update: 25 Auguest 2021
#
# I use shell check, delete the ? to run it, but leave that in this files so it does not fail when it sees it.
# shell?check -x scripts/build_script.sh
#
# Original Code is from: https://github.com/linuxdeploy/QtQuickApp TheAssassin
#
# This file is Open Source and I tried my best to make it cut and paste,
# so I am adding the Environment Variables here as well as the OS installer.
#
echo "build_script_mac MacOS";
#
# Debug Information, not always a good idea when not debugging, and thanks to the TheAssassin, this is now working.
# These are the setting you might want to change
declare -ix DEBUGGING;         DEBUGGING=0;          # Set 1=True and 0=False
declare -ix SHOW_PATH;         SHOW_PATH=1;          # Set 1=True and 0=False
declare -ix EXIT_ON_UNDEFINED; EXIT_ON_UNDEFINED=0;  # Set 1=True and 0=False
# Below should be agnostic
# I use a Variable so I can turn it off on exit
if [ "${DEBUGGING}" -eq 1 ]; then set -x; fi
# Exit on error
set -e;
#
# If not defined it will use this as a default
if [ -z "${MY_BIN_PRO_RES_NAME+x}" ]; then
    echo -e "Add MY_BIN_PRO_RES_NAME to your Appveyor Settings Environment Variable with a value from Github value for Binary, pro, and resource Name ";
    if [ "${EXIT_ON_UNDEFINED}" -eq 1 ]; then exit 1; fi
fi
# APPVEYOR_REPO_NAME should always have your GITHUB_USERNAME as the first part / GITHUB_PROJECT, so I split them to use later.
if [ -z "${GITHUB_USERNAME+x}" ] || [ -z "${GITHUB_PROJECT}" ]; then
    OLD_IFS="$IFS"; IFS='/'; read -ra repo_parts <<< "$APPVEYOR_REPO_NAME"; IFS="$OLD_IFS";
    declare -x GITHUB_PROJECT;
    GITHUB_USERNAME="${repo_parts[0]}";  GITHUB_PROJECT="${repo_parts[1]}";
fi
# Set our Artifacts for later
#
#export ARTIFACT_APPIMAGE="${MY_BIN_PRO_RES_NAME}-x86_64.AppImage";
#export ARTIFACT_ZSYNC="${MY_BIN_PRO_RES_NAME}-x86_64.AppImage.zsync";
#export ARTIFACT_QIF="${MY_BIN_PRO_RES_NAME}-Linux-Installer";
# use RAM disk if possible (as in: not building on CI system like Appveyor, and RAM disk is available)
#
#
# switch to build dir
mkdir build;
cd build;
# Make AppDir folder at the BUILD_DIR level, I should not need to do this normally, but I am not able to get cmake to work
if [ -d "AppDir" ]; then rm -r AppDir; fi
mkdir AppDir;
#
echo "cmake build";
DESTDIR=AppDir;
export PATH="/usr/local/sbin:/usr/local/opt/qt5/bin:$PATH";
export PATH="$(brew --prefix qt5)/bin:$PATH";
export CMAKE_PREFIX_PATH="$(brew --prefix qt5)";
#
if [ "${SHOW_PATH}" -eq 1 ]; then echo "PATH=$PATH"; fi
#
PATH="$(brew --prefix qt5)/bin:$PATH" cmake .. -G "Unix Makefiles" -DBUILD_SHARED_LIBS:BOOL=ON -DCMAKE_BUILD_TYPE="${CONFIGURATION}" -DCMAKE_INSTALL_PREFIX="/usr";
#
# build project and install files into AppDir
make -j"$(nproc)";
make install DESTDIR=AppDir
export LD_LIBRARY_PATH="$LD_LIBRARY_PATH:/usr/local/opt/qt5/bin:AppDir";
# make sure Qt plugin finds QML sources so it can deploy the imported files
if [ -d "../qml" ]; then
    export QML_SOURCES_PATHS="../qml";
fi
#
DYLD_LIBRARY_PATH="/usr/local/opt/qt5/lib:$DYLD_LIBRARY_PATH";
#
macdeployqt "${MY_BIN_PRO_RES_NAME}.app" -dmg -verbose=2;
chmod +x "${MY_BIN_PRO_RES_NAME}"*.dmg*;
cp -v "${MY_BIN_PRO_RES_NAME}"*.dmg* AppDir/usr/bin/;
cp -v "${APPVEYOR_BUILD_FOLDER}/README.md" AppDir/usr/bin/;
7z a -tzip -r "${MY_BIN_PRO_RES_NAME}-${MY_OS}-${CONFIGURATION}-${PLATFORM}.zip" AppDir;
cp "${MY_BIN_PRO_RES_NAME}-${MY_OS}-${CONFIGURATION}-${PLATFORM}.zip" ../;
#
#
# cd Directory for Qt Installer Framework
cd ..;
#
#echo "Preparing for Qt Installer Framework";
#
#
# Copy all the files that Qt Installer Framework needs
#ls "${APPVEYOR_BUILD_FOLDER}";
#
# Copy both AppImages to where Qt Installer Framework needs them
# MY_QIF_PACKAGE_URI='packages/com.url.qtappveyor/data'
#if [ -f "${APPVEYOR_BUILD_FOLDER}/${ARTIFACT_APPIMAGE}" ]; then
#    cp -pv "${APPVEYOR_BUILD_FOLDER}/${ARTIFACT_APPIMAGE}" "${APPVEYOR_BUILD_FOLDER}/${MY_QIF_PACKAGE_URI}/data";
#    #cp -pv "${APPVEYOR_BUILD_FOLDER}/${ARTIFACT_ZSYNC}" "${APPVEYOR_BUILD_FOLDER}/${MY_QIF_PACKAGE_URI}/data";
#else
#    echo -e "Missing ${BUILD_DIR}/${ARTIFACT_APPIMAGE} ";
#fi
# The packages/${MY_QIF_PACKAGE_URI}/meta/installscript.qs creates this: cp -v "desktop/${MY_BIN_PRO_RES_NAME}.desktop" "${MY_QIF_PACKAGE_URI}";
#cp -v "${APPVEYOR_BUILD_FOLDER}/README.md" "${APPVEYOR_BUILD_FOLDER}/${MY_QIF_PACKAGE_URI}/data";
#ls "${APPVEYOR_BUILD_FOLDER}/${MY_QIF_PACKAGE_URI}/data";
#
# I use Qt Installer Framework
# https://download.qt.io/official_releases/qt-installer-framework
#
#echo "Running Qt Installer Framework";
#"${APPVEYOR_BUILD_FOLDER}/scripts/QtInstallerFramework-linux.run" -c "${APPVEYOR_BUILD_FOLDER}/config/config.xml" -p "${APPVEYOR_BUILD_FOLDER}/packages" "${ARTIFACT_QIF}";
#declare -i BINARY_CREATOR_INSTALLED; BINARY_CREATOR_INSTALLED=0;
#declare MyQtInstallerFramework; MyQtInstallerFramework="binarycreator";
#
#echo "First Check fails for find it";
#if command -v "$MyQtInstallerFramework" &> /dev/null; then BINARY_CREATOR_INSTALLED=1; echo "MyQtInstallerFramework=$MyQtInstallerFramework"; fi
#
#echo "Second Check fails with error code";
#if [ "$BINARY_CREATOR_INSTALLED" -eq 0 ]; then
#    MyQtInstallerFramework="$(type -p binarycreator)";
#    if [ -n "$MyQtInstallerFramework" ]; then
#        if command -v "$MyQtInstallerFramework" &> /dev/null; then
#            BINARY_CREATOR_INSTALLED=1;
#            echo "MyQtInstallerFramework=$MyQtInstallerFramework";
#        fi
#    fi
#fi
#
#if [ "$BINARY_CREATOR_INSTALLED" -eq 1 ]; then
#    "$MyQtInstallerFramework" -c "${APPVEYOR_BUILD_FOLDER}/config/config.xml" -p "${APPVEYOR_BUILD_FOLDER}/packages" "${ARTIFACT_QIF}";
#fi
#
echo -e "Completed build_script_mac.sh";
################################ End of File ##################################
