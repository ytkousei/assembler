#ifndef _FS_H
#define _FS_H

#define BUF_SIZE 256

extern char file_content[BUF_SIZE + 1];

void ReadFile(char *path);
void WriteFile(char *path, char *buf);

#endif
