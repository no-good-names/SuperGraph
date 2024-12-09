#!/bin/bash -e

cmake -S . -B build -G Ninja
cd build
ninja

