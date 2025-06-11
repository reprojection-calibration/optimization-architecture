FROM ubuntu:24.04 AS configuration-stage

ARG DEBIAN_FRONTEND=noninteractive

SHELL ["/bin/bash", "-c"]
WORKDIR /buildroot


FROM configuration-stage AS base-stage

ARG INSTALL_BUILD_DEPENDENCIES=building/install_scripts/install_build_dependencies.sh
RUN --mount=type=bind,source=${INSTALL_BUILD_DEPENDENCIES},target=/temporary/${INSTALL_BUILD_DEPENDENCIES} \
    /temporary/${INSTALL_BUILD_DEPENDENCIES}


FROM base-stage AS build-stage

ARG BUILD_LIBRARY=building/scripts/build_library.sh
RUN --mount=type=bind,source=${BUILD_LIBRARY},target=/temporary/${BUILD_LIBRARY} \
    --mount=type=bind,source=code/,target=/temporary/code \
    /temporary/${BUILD_LIBR


FROM base-stage AS development-stage