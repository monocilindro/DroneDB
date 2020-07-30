![ddb-logo-banner](https://user-images.githubusercontent.com/1951843/86480474-0fcc4280-bd1c-11ea-8663-a7a37f631565.png)

![license](https://img.shields.io/github/license/uav4geo/DroneDB) ![commits](https://img.shields.io/github/commit-activity/m/uav4geo/DroneDB) ![languages](https://img.shields.io/github/languages/top/uav4geo/DroneDB) ![Docs](https://github.com/uav4geo/DroneDB/workflows/Docs/badge.svg) ![C/C++ CI](https://github.com/DroneDB/DroneDB/workflows/C/C++%20CI/badge.svg) ![NodeJS CI](https://github.com/DroneDB/DroneDB/workflows/NodeJS%20CI/badge.svg)

DroneDB is a toolset for easily managing and sharing aerial datasets. It can index and extract useful information from the EXIF/XMP tags of aerial images to display things like image footprint, flight path and image GPS location. It has timezone-aware date parsing capabilities, a camera sensor database and a DSM lookup system.

![image](https://user-images.githubusercontent.com/1951843/66138811-3dd5f800-e5cd-11e9-816d-a0efa39ccca5.png)

![image](https://user-images.githubusercontent.com/1951843/68077866-001de800-fda2-11e9-895f-b5840d9d047d.png)

DroneDB is in early development stages and is targeted at GIS developers and early adopters. It is not ready for mainstream use. To contribute to the project, please see the [contributing guidelines](CONTRIBUTING.md).

## Documentation

For usage and examples see https://docs.dronedb.app

## Building

Requirements:
 * sqlite3
 * spatialite
 * cmake
 * libgeos
 * g++ >= 10.1.0 (very important! :warning: g++ 8 has a [bug](https://gcc.gnu.org/bugzilla/show_bug.cgi?id=90050) in the stdc++fs library that will prevent the software from running properly)
 * GDAL >= 2.1
 
On Ubuntu you can simply execute this script to install the dependencies:

```bash
scripts/ubuntu_deps.sh
```

Then:

```bash
git clone --recurse-submodules https://github.com/uav4geo/DroneDB ddb
cd ddb
mkdir build && cd build
cmake .. && make
```

