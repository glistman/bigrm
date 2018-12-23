#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
#include <stdbool.h>
#include <string.h>

bool isNotLink(char *file);

void deleteFile(char* directoryPath, char* fileName);

int main(int c, char *argv[]){
	char *directoryPath = argv[1];
	printf("Directory:%s\n", directoryPath);
	DIR *directory = opendir (directoryPath);
	struct dirent *ent;

	while ((ent = readdir (directory)) != NULL){
		char *fileName = ent->d_name;
		if (isNotLink(fileName)){
			deleteFile(directoryPath, fileName);
		}
	}
	
	closedir (directory);

	return 0;
}

bool isNotLink(char *fileName){
	return (strcmp(fileName, ".") != 0) && (strcmp(fileName, "..") != 0);
}

void deleteFile(char *directoryPath, char *fileName){
	char *file = malloc(strlen(directoryPath) + strlen(fileName) + 1);
	strcpy(file, directoryPath);
	strcat(file, fileName);
	int result = remove(file);
	printf(">>>Remove filel:%s>>%d\n", file, 0);
	free(file);
}