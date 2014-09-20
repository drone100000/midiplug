#!/bin/bash -x -e

pushd Builds/MacOSX/
xcodebuild -arch i386
popd
exec /Applications/Ableton\ Live\ 9\ Trial.app/Contents/MacOS/Live