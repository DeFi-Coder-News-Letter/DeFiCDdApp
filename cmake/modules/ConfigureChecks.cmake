include(CheckIncludeFiles)
include(CheckSymbolExists)
include(CheckFunctionExists)
include(CheckLibraryExists)
include(CheckCXXSourceCompiles)
include(TestBigEndian)

check_function_exists(stat64 HAVE_STAT64)

check_include_files(sys/vfs.h HAVE_SYS_VFS_H)
check_include_files(sys/statvfs.h HAVE_SYS_STATVFS_H)
check_include_files(byteswap.h HAVE_BYTESWAP_H)

test_big_endian(WORDS_BIGENDIAN)
