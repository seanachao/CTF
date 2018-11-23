#include <iostream>
#include<windows.h>
#include<stdio.h>
//typedef VOID (*PFUNMSG)(char *);
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
typedef __int64(__fastcall *f)(__int64 buff, unsigned __int64 len);
__int64(*func)(__int64 buff, unsigned __int64 len);
void len()
{
    int i;
    unsigned long long  result;
    for (i = 0;i<50; i++)
    {
    	long long a;
    	a= (long long)&i;
        result = func(a, 4);
        //printf("%x\n",a);
        if (result == 0xD31580A28DD8E6C4)
        
        {/*0D31580A28DD8E6C4h*/
            printf("Len is %dn", i);
            return ;
        }
    }
    printf("Not found the lenn");
    return;
}
void flag(){
	char buffer[100];
	unsigned long long i;
	for ( i =1200000000;i<=10000000004;i++){
		//sprintf(buffer,"%d",i);
		sprintf(buffer, "%0.10llu", i);
		unsigned long long res =10;
		res = func((long long)buffer,10);
		if (i % 100000 == 0)
        {
            printf("%0.10llun\n", i);
        }
		if (res == 0x1CCB25A666AC646B){
			printf("flag is %lld \n",i);
			break;
		}
		//printf("%s\n",buffer);
	}
}
int main(int argc, char *argv[]) {
	printf("HEllo world\n");
	HINSTANCE hDll = LoadLibrary(TEXT("reverse.dll"));
	if(hDll == NULL){
		MessageBox(NULL,"FirstDll.dll 不存在","Dll failed to load",MB_OK);
		return 1; 
	} 
	MessageBox(NULL,"Hi I'm here","Hello",MB_OK);
	printf("Dll base is %llxn",hDll);
	printf("success\n");
	func = ((f)((char*)hDll + 0x17A0));
	printf("Dll base is %llxn",hDll);
	printf("success\n");
	len();
	flag();
}