#!/usr/bin/env bash

for i in -O0 -O1 -O2 -O3 -Os -Og; do
	out/time_meas$i
done
