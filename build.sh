#!/bin/bash

set -ueo pipefail

function compile()
{
    cmd="$(gcc ./src/main.c ./src/Graph.c ./include/Graph.h -o ./debug/target/test)"

    echo $cmd;
}

compile