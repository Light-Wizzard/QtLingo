#!/bin/bash
#
# Last Update: 24 Auguest 2021
#
# I use shell check, delete the ? to run it, but leave that in this files so it does not fail when it sees it.
# shell?check -x scripts/build_script.sh
#
# Original Code is from: https://github.com/linuxdeploy/QtQuickApp TheAssassin
#
# This file is Open Source and I tried my best to make it cut and paste,
# so I am adding the Environment Variables here as well as the OS installer.
#
echo "build_script Unix";
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
export ARTIFACT_APPIMAGE="${MY_BIN_PRO_RES_NAME}-x86_64.AppImage";
#export ARTIFACT_ZSYNC="${MY_BIN_PRO_RES_NAME}-x86_64.AppImage.zsync";
export ARTIFACT_QIF="${MY_BIN_PRO_RES_NAME}-Linux-Installer";
# use RAM disk if possible (as in: not building on CI system like Appveyor, and RAM disk is available)
declare TEMP_BASE;
if [ "$CI" == "" ] && [ -d "/dev/shm" ]; then TEMP_BASE="/dev/shm"; else TEMP_BASE="/tmp"; fi
#
echo -e "Make Temp Foler";
#
# building in temporary directory to keep system clean
BUILD_DIR="$(mktemp -d -p "$TEMP_BASE" "${MY_BIN_PRO_RES_NAME}-build-XXXXXX")";
#
# make sure to clean up build dir, even if errors occur
function cleanup()
{
    if [ -d "$BUILD_DIR" ]; then rm -rf "$BUILD_DIR"; fi
    if [ "${DEBUGGING}" -eq 1 ]; then set +x; fi
}
trap "cleanup; exit;" SIGINT SIGTERM
#trap cleanup EXIT;
#
# store repo root as variable
REPO_ROOT="$(readlink -f "$(dirname "$(dirname "$0")")")";
OLD_CWD="$(readlink -f .)";
#
# switch to build dir
pushd "$BUILD_DIR";
# Make AppDir folder at the BUILD_DIR level, I should not need to do this normally, but I am not able to get cmake to work
if [ -d "AppDir" ]; then rm -r AppDir; fi
mkdir -p AppDir;
# x86
if [[ "$APPVEYOR_BUILD_WORKER_IMAGE" == "${MY_OS}" ]] && [[ "$PLATFORM" == "x86" ]]; then
    # Matrix does not show a gcc_32 or 86
    # https://www.appveyor.com/docs/linux-images-software/
    export PATH="${HOME}/Qt/${MY_QT_VERSION}/gcc_64/bin:${HOME}/Qt/${MY_QT_VERSION}/gcc_64/lib:${HOME}/Qt/${MY_QT_VERSION}/gcc_64/include:$PATH";
    export PATH="${HOME}/Qt/${MY_QT_VERSION}/gcc_64/bin:${HOME}/Qt/${MY_QT_VERSION}/clang_64/bin:$PATH";
    if [ ! -d "${HOME}/Qt/${MY_QT_VERSION}/gcc_64/bin" ]; then
        echo "Qt x86 not found: ${HOME}/Qt/${MY_QT_VERSION}/gcc_64/bin";
        ls "${HOME}/Qt/${MY_QT_VERSION}/";
    fi
    if [ ! -f "${HOME}/Qt/${MY_QT_VERSION}/gcc_64/bin/qmake" ]; then echo "Qt x86 qmake not found: ${HOME}/Qt/${MY_QT_VERSION}/gcc_64/bin/qmake"; fi
    if [[ "$MY_PYTHON_REQUIRED" == "true" ]]; then
        export PATH="/usr/lib/python${MY_PYTHON_VER}:/usr/include/python${MY_PYTHON_VER}:$PATH";
        # source ${HOME}/venv${MY_PYTHON_VER}/bin/activate
        # export PATH=${HOME}/venv${MY_PYTHON_VER}:${HOME}/venv${MY_PYTHON_VER}/bin:${HOME}/venv${MY_PYTHON_VER}/lib:$PATH
        if [ ! -d "/usr/lib/python${MY_PYTHON_VER}" ]; then    echo "Python x86 not found: /usr/lib/python${MY_PYTHON_VER}"; fi
        if [ ! -d "/usr/include/python${MY_PYTHON_VER}" ]; then echo "Python x86 include not found: /usr/lib/python${MY_PYTHON_VER}"; fi
    fi
fi
# x64
if [[ "$APPVEYOR_BUILD_WORKER_IMAGE" == "${MY_OS}" ]] && [[ "$PLATFORM" == "x64" ]]; then
    export PATH="${HOME}/Qt/${MY_QT_VERSION}/gcc_64/bin:${HOME}/Qt/${MY_QT_VERSION}/gcc_64/lib:${HOME}/Qt/${MY_QT_VERSION}/gcc_64/include:$PATH";
    export PATH="${HOME}/Qt/${MY_QT_VERSION}/gcc_64/bin:${HOME}/Qt/${MY_QT_VERSION}/clang_64/bin:$PATH";
    # Check Qt
    if [ ! -d "${HOME}/Qt/${MY_QT_VERSION}/gcc_64/bin" ]; then echo "Qt x64 not found: ${HOME}/Qt/${MY_QT_VERSION}/gcc_64/bin"; fi
    if [ ! -f "${HOME}/Qt/${MY_QT_VERSION}/gcc_64/bin/qmake" ]; then echo "Qt x64 qmake not found: ${HOME}/Qt/${MY_QT_VERSION}/gcc_64/bin/qmake"; fi
    if [[ "$MY_PYTHON_REQUIRED" = "true" ]]; then
        export PATH="/usr/lib/python${MY_PYTHON_VER}:/usr/include/python${MY_PYTHON_VER}:$PATH";
        # Check Python
        # source ${HOME}/venv${MY_PYTHON_VER}/bin/activate
        # export PATH=${HOME}/venv${MY_PYTHON_VER}:${HOME}/venv${MY_PYTHON_VER}/bin:${HOME}/venv${MY_PYTHON_VER}/lib:$PATH
        if [ ! -d "/usr/lib/python${MY_PYTHON_VER}" ]; then     echo "Python x64 not found: /usr/lib/python${MY_PYTHON_VER}"; fi
        if [ ! -d "/usr/include/python${MY_PYTHON_VER}" ]; then echo "Python x64 include not found: /usr/lib/python${MY_PYTHON_VER}"; fi
    fi
fi
#
if [[ $APPVEYOR_BUILD_WORKER_IMAGE == "${MY_OS}" ]]; then
    if [ "${SHOW_PATH}" -eq 1 ]; then echo "PATH=$PATH"; fi
    #
    echo "cmake build";
    DESTDIR=AppDir;
    # tired this without -DCMAKE_BUILD_TYPE=${CONFIGURATION} -DBUILD_SHARED_LIBS=OFF
    cmake "${REPO_ROOT}" -G "Unix Makefiles" -DBUILD_SHARED_LIBS:BOOL=ON -DCMAKE_BUILD_TYPE="${CONFIGURATION}" -DCMAKE_INSTALL_PREFIX="/usr";
    #
    # build project and install files into AppDir
    make -j"$(nproc)";
    make install DESTDIR=AppDir
    # now, build AppImage using linuxdeploy and linuxdeploy-plugin-qt
    # download linuxdeploy and its Qt plugin
    wget -c -nv https://github.com/linuxdeploy/linuxdeploy/releases/download/continuous/linuxdeploy-x86_64.AppImage;
    wget -c -nv https://github.com/linuxdeploy/linuxdeploy-plugin-qt/releases/download/continuous/linuxdeploy-plugin-qt-x86_64.AppImage;
    # make them executable
    chmod +x linuxdeploy*.AppImage;
    export LD_LIBRARY_PATH="$LD_LIBRARY_PATH:${HOME}/Qt/${MY_QT_VERSION}/gcc_64/lib:AppDir";
    # make sure Qt plugin finds QML sources so it can deploy the imported files
    if [ -d "${REPO_ROOT}/qml" ]; then
        export QML_SOURCES_PATHS="${REPO_ROOT}/qml";
    fi
    # ${MY_BIN_PRO_RES_NAME}-$PLATFORM.AppImage
    #export TARGET_APPIMAGE="${MY_BIN_PRO_RES_NAME}-$PLATFORM.AppImage";
    # QtQuickApp does support "make install", but we don't use it because we want to show the manual packaging approach in this example
    # initialize AppDir, bundle shared libraries, add desktop file and icon, use Qt plugin to bundle additional resources, and build AppImage, all in one command
    # env TARGET_APPIMAGE="${MY_BIN_PRO_RES_NAME}-$PLATFORM.AppImage" APPIMAGE_EXTRACT_AND_RUN=1
    ./linuxdeploy-x86_64.AppImage --appdir=AppDir -i "${REPO_ROOT}/desktop/${MY_BIN_PRO_RES_NAME}.svg" -d "${REPO_ROOT}/desktop/${MY_BIN_PRO_RES_NAME}.desktop" --plugin qt --output appimage;
    chmod +x "${MY_BIN_PRO_RES_NAME}"*.AppImage*;
    cp -v "${MY_BIN_PRO_RES_NAME}"*.AppImage* AppDir/usr/bin/;
    cp -v "${APPVEYOR_BUILD_FOLDER}/README.md" AppDir/usr/bin/;
    7z a -tzip -r "${MY_BIN_PRO_RES_NAME}-${MY_OS}-${CONFIGURATION}-${PLATFORM}.zip" AppDir;
    cp "${MY_BIN_PRO_RES_NAME}-${MY_OS}-${CONFIGURATION}-${PLATFORM}.zip" "${OLD_CWD}";
fi
#
# AppImage move to Artifacts
mv "${MY_BIN_PRO_RES_NAME}"*.AppImage* "$OLD_CWD";
#
# Pop Directory for Qt Installer Framework
popd;
#
echo "Preparing for Qt Installer Framework";
#
#
# Copy all the files that Qt Installer Framework needs
ls "${APPVEYOR_BUILD_FOLDER}";
#
# Copy both AppImages to where Qt Installer Framework needs them
# MY_QIF_PACKAGE_URI='packages/com.url.qtappveyor/data'
if [ -f "${APPVEYOR_BUILD_FOLDER}/${ARTIFACT_APPIMAGE}" ]; then
    cp -pv "${APPVEYOR_BUILD_FOLDER}/${ARTIFACT_APPIMAGE}" "${APPVEYOR_BUILD_FOLDER}/${MY_QIF_PACKAGE_URI}/data";
    #cp -pv "${APPVEYOR_BUILD_FOLDER}/${ARTIFACT_ZSYNC}" "${APPVEYOR_BUILD_FOLDER}/${MY_QIF_PACKAGE_URI}/data";
else
    echo -e "Missing ${BUILD_DIR}/${ARTIFACT_APPIMAGE} ";
fi
# The packages/${MY_QIF_PACKAGE_URI}/meta/installscript.qs creates this: cp -v "desktop/${MY_BIN_PRO_RES_NAME}.desktop" "${MY_QIF_PACKAGE_URI}";
cp -v "${APPVEYOR_BUILD_FOLDER}/README.md" "${APPVEYOR_BUILD_FOLDER}/${MY_QIF_PACKAGE_URI}/data";
ls "${APPVEYOR_BUILD_FOLDER}/${MY_QIF_PACKAGE_URI}/data";
#
# I use Qt Installer Framework
# https://download.qt.io/official_releases/qt-installer-framework
#
echo "Running Qt Installer Framework";
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
echo -e "Completed build-script.sh";
################################ End of File ##################################
