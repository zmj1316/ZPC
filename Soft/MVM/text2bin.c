#include<string.h>
#include<stdio.h>

typedef unsigned char byte;
typedef unsigned long int word;

int main(int argc,char* argv[]){
	char infilename[256];
	char outfilename[256];
	FILE* fp;
	FILE* out;
	word data;
	if(argc<2){
		printf("Lack input file!...");
		return 1;
	}
	strcpy(infilename,argv[1]);
	if(argc>=3){
		strcpy(outfilename,argv[2]);
	}
	else{
		strcpy(outfilename,"out.bin");
	}
	fp=fopen(infilename,"r");
	if(!fp){
		printf("Input file not found!...");
		return 1;
	}
	out=fopen(outfilename,"wb");
	while(fscanf(fp,"%X",&data)!=-1){
		byte* p=(byte*)(&data);
		fwrite(p+3,sizeof(byte),1,out);
		fwrite(p+2,sizeof(byte),1,out);
		fwrite(p+1,sizeof(byte),1,out);
		fwrite(p+0,sizeof(byte),1,out);
	}
	fclose(fp);
	fclose(out);
}
