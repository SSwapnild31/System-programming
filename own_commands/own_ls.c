#include<stdio.h>
#include<dirent.h>
#include<unistd.h>
#include<limits.h>

void arg_ls(char *arg);
void no_arg_ls(void);

int main(int argc, char *argv[])
{
	if(argc == 2){
		arg_ls(argv[1]);
		return 0;
	}

	no_arg_ls();

	return 0;
}

void no_arg_ls(void){
	char cwd[PATH_MAX];

	getcwd(cwd, sizeof(cwd));

	DIR *dp = opendir(cwd);

	if(dp == 0){
		perror("opendir");
		return ;
	}

	struct dirent *dir;

	while(dir = readdir(dp)){
		if(dir->d_name[0] != '.'){
			printf("%s\t",dir->d_name);
		}
	}
	printf("\n");
}

void arg_ls(char *arg){
	DIR *dp = opendir(arg);

	if(dp == 0){
		perror("opendir");
		return ;
	}

	struct dirent *dir;

	while(dir = readdir(dp)){
		if(dir->d_name[0] != '.'){
			printf("%s\t",dir->d_name);
		}
	}
	printf("\n");
}
