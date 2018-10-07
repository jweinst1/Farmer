cmake_minimum_required(VERSION 3.5)

# Project farmer begins here #
project(farmer)

# Version Tracker #
set(farmer_version_major 0)
set(farmer_version_minor 0)
set(farmer_version_patch 1)
set(farmer_version "${farmer_version_major}.${farmer_version_minor}.${farmer_version_patch}")

# Enables Testing for project #
enable_testing()

add_subdirectory(core)

# Writes build version to receipt file.
file(WRITE ${PROJECT_SOURCE_DIR}/bin/build_receipt.txt "Farmer Build\nVersion ${farmer_version}\n")