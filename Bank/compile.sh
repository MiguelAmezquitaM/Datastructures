
# config
DIRECTORY=src

HEADER_FILES_DIR=$DIRECTORY/Header-Files

SOURCE_FILES_DIR=$DIRECTORY/Source-Files

EXTERNALS_LIBRARIES=~/Documentos/Universidad/Datastructures/Repository/Datastructures/MenuBase/Header-Files

EXTERNALS_LIBRARIES_SOURCE=~/Documentos/Universidad/Datastructures/Repository/Datastructures/MenuBase/Source-Files/**.cpp

MAIN=$DIRECTORY/main.cpp

OUTPUT_DIR=out

rm -rf $OUTPUT_DIR

mkdir $OUTPUT_DIR

g++ -std=c++17 --include-directory=$EXTERNALS_LIBRARIES $EXTERNALS_LIBRARIES_SOURCE --include-directory=$HEADER_FILES_DIR $SOURCE_FILES_DIR/**.cpp $MAIN -o $OUTPUT_DIR/output

./$OUTPUT_DIR/output
