#!/bin/bash

#Build Script for DataRecordTool

PROJECT_NAME="Data Record Tool"
BUILD_DIR=build

if [[ -d ${BUILD_DIR} ]] ; then
	cmd="cd ${BUILD_DIR}"
	echo "${cmd}"
	${cmd}

	cmd="cmake .."

	echo "${cmd}"
	${cmd}

	cmd="make"
	echo "${cmd}"
	${cmd}

	echo "Build ${PROJECT_NAME} Done"
fi

