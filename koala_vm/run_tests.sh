#!/usr/bin/env bash

set -e
sh build.sh
./build/tests_bin/tests_koala
