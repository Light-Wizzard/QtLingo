#!/bin/bash
#
# Last Update: 23 Auguest 2021
#
# shell?check -x scripts/install.sh
#
echo "install Unix"
#
if [[ "$APPVEYOR_BUILD_WORKER_IMAGE" = "Ubuntu" ]]; then
#
    # Python
    sudo add-apt-repository ppa:deadsnakes/ppa -y;
    sudo apt-get update -qq && sudo apt-get install -qq;
    if [[ "$MY_UPGRADE_OS" = "true" ]]; then sudo apt-get upgrade -qqy; fi
    # Developer tools, some multimedia and libsqlite3
    # This is what I needed for all my projects to work, and is not optimized for any one of them.
    sudo apt install -qqy build-essential cmake zlib1g-dev;
    sudo apt install -qqy mesa-common-dev libgl1-mesa-dev;
    #sudo apt install -qqy yasm git flex bison checkinstall pkg-config;
    #sudo apt install -qqy libglu1-mesa-dev libegl1-mesa libgles2-mesa-dev software-properties-common;
    #sudo apt install -qqy libncurses5-dev libncursesw5-dev openssl libssl-dev;
    #sudo apt install -qqy libffi-dev libgdbm-dev libdb5.3-dev libbz2-dev libexpat1-dev liblzma-dev tk-dev sqlite3 libsqlite3-dev libsqlite3-dev;
    #sudo apt install -qqy libreadline-dev libgl-dev libpulse-mainloop-glib0 libglfw3-dev freeglut3-dev;
    #sudo apt install -qqy libfreetype6-dev libfontconfig1-dev libdbus-1-dev libxi-dev libgstreamer-plugins-base1.0-0;
    #sudo apt install -qqy libgstreamer1.0-dev libgstreamer-plugins-base1.0-dev libssl1.0.0 glibc patchelf inotify-tools;
    #sudo apt install -qqy gfortran libjpeg8-dev libpng-dev libtiff-dev libavcodec-dev libavformat-dev;
    #sudo apt install -qqy libswscale-dev libdc1394-22-dev libxine2-dev libv4l-dev libatlas-base-dev libfaac-dev libmp3lame-dev;
    #sudo apt install -qqy libtheora-dev libvorbis-dev libxvidcore-dev libopencore-amrnb-dev libopencore-amrwb-dev libavresample-dev;
    #sudo apt install -qqy x264 v4l-utils libprotobuf-dev protobuf-compiler libgoogle-glog-dev libgflags-dev libgphoto2-dev libeigen3-dev;
    # Python
    if [[ "$MY_PYTHON_REQUIRED" = "true" ]]; then sudo apt-get install -qqy python3.9-dev python3-venv; fi
    # Required by LinuxDeploy
    sudo apt-get install -qqy libxcb-icccm4 libxcb-image0 libxcb-keysyms1 libxcb-render-util0 libxcb-xinerama0 libxcb-xkb-dev libxkbcommon-x11-0 libgtk2.0-dev;
    #wget -c -nv "https://download.qt.io/official_releases/qt-installer-framework/$MY_QT_IF_VERSION/QtInstallerFramework-linux-x64-$MY_QT_IF_VERSION.run" -O scripts/QtInstallerFramework-linux.run
#    curl -fsS -o scripts/QtInstallerFramework-linux.run "https://download.qt.io/official_releases/qt-installer-framework/$MY_QT_IF_VERSION/QtInstallerFramework-linux-x64-$MY_QT_IF_VERSION.run";
#    if [ -f scripts/QtInstallerFramework-linux.run ]; then
#        # make it executable
#        chmod +x scripts/QtInstallerFramework-linux.run;
#        ls -las scripts/;
#    else
#        echo -e "Error downloading QtInstallerFramework-linux";
#    fi
fi
#
if [[ "$APPVEYOR_BUILD_WORKER_IMAGE" = "macos" ]]; then
    brew cleanup;
    brew config;
    brew doctor || true;
    brew install qt5 cmake binutils create-dmg openssl@1.1 curl;
    brew link qt5 --force;
    export PATH="/usr/local/opt/qt5/bin:$PATH";
    PATH="$(brew --prefix qt5)/bin:$PATH";
    export CMAKE_PREFIX_PATH="$(brew --prefix qt5)";
    #    curl -fsS -o scripts/QtInstallerFramework-macOS.dmg "https://download.qt.io/official_releases/qt-installer-framework/$MY_QT_IF_VERSION/QtInstallerFramework-macOS-x86_64-$MY_QT_IF_VERSION.dmg";
    #    # make it executable
    #    chmod +x scripts/QtInstallerFramework-macOS.dmg;

fi
