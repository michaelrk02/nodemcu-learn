#!/bin/bash

rm -rf libraries/Quad
rm -rf quad_binary quad_fill quad_gate quad_shift

mkdir -p libraries
cp -R ../libraries/Quad libraries/Quad

cp -R ../quad_binary quad_binary
cp -R ../quad_fill quad_fill
cp -R ../quad_gate quad_gate
cp -R ../quad_shift quad_shift

echo Update complete!
