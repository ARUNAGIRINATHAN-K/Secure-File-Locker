// File: include/utils.h
#ifndef UTILS_H
#define UTILS_H

void extractFilename(const char *path, char *filename);
void appendMetadata(const char *metaFile, const char *username, const char *filename);
void listEncryptedFiles(const char *username);

#endif
