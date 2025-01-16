# build.py - Build script for the project
# Usage: python build.py [clean|build|run]

# NOTE: This script is only for Linux and MacOS. For Windows, you can use the build.bat file.
# NOTE: If you're using Clion, you can use the CMakeLists.txt file to build the project.

import os
from posix import error
from re import sub
import sys
import shutil
import subprocess

# Constants
BUILD_DIR = "build"
SRC_DIR = "src"
CMAKE = "cmake"
MAKE = "make"
NINJA = "ninja"
CMAKE_BUILD_TYPE = "Release"
BUILD_OUTPUT = "/supergraph"

def tool_exists(tool=""):
    return shutil.which(tool) is not None

# Functions
def clean():
    if os.path.exists(BUILD_DIR):
        shutil.rmtree(BUILD_DIR)

def build(run=False):
    if not os.path.exists(BUILD_DIR):
        os.mkdir(BUILD_DIR)

    if tool_exists(NINJA):
        subprocess.run([CMAKE, "-S", ".", "-DCMAKE_BUILD_TYPE=" + CMAKE_BUILD_TYPE, "-B", BUILD_DIR])
        os.chdir(BUILD_DIR)
        subprocess.run([NINJA])
    else:
        subprocess.run([CMAKE, "-S", ".", "-DCMAKE_BUILD_TYPE=" + CMAKE_BUILD_TYPE, "-B", BUILD_DIR, "-G", NINJA])
        os.chdir(BUILD_DIR)
        subprocess.run([MAKE])
    if run == True:
        subprocess.run(["./supergraph"])
    else:
        os.chdir("..")

def main():
    tools = [CMAKE, MAKE]
    for tool in tools:
        if not tool_exists(tool):
            print("Error: " + tool + " not found!")
            sys.exit(1)
    if not os.path.exists("./CMakeLists.txt"):
        print("You're in the wrong dir! Please build in the project dir.")
        sys.exit(1)
    if len(sys.argv) < 2:
        print("Usage: python build.py [clean|build|run]")
        sys.exit(1)

    if sys.argv[1] == "clean":
        clean()
    elif sys.argv[1] == "build":
        build()
    elif sys.argv[1] == "run":
        build(True)

    else:
        print("Usage: python build.py [clean|build|run]")
        sys.exit(1)


if __name__ == "__main__":
    main()
