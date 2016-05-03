#!/bin/sh

OLD_WD=$PWD
cd $(dirname "$0")

docker run --rm -it -v "$PWD:/app" -w /app/build gcc sh -c "gcc -Os -static -o ep ../ep.c; strip -sd ep"
docker build --no-cache -t maxmanuylov/entrypoint build

cd "$OLD_WD"