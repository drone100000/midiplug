#!/bin/bash -x -e

pushd Builds/MacOSX/
xcodebuild
popd
exec ~/Development/JUCE/extras/audio\ plugin\ host/Builds/MacOSX/build/Debug/Plugin\ Host.app/Contents/MacOS/Plugin\ Host