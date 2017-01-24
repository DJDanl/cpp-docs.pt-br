---
title: "_futime, _futime32, _futime64 | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
apiname: 
  - "_futime64"
  - "_futime32"
  - "_futime"
apilocation: 
  - "msvcrt.dll"
  - "msvcr80.dll"
  - "msvcr90.dll"
  - "msvcr100.dll"
  - "msvcr100_clr0400.dll"
  - "msvcr110.dll"
  - "msvcr110_clr0400.dll"
  - "msvcr120.dll"
  - "msvcr120_clr0400.dll"
  - "ucrtbase.dll"
  - "api-ms-win-crt-time-l1-1-0.dll"
apitype: "DLLExport"
f1_keywords: 
  - "futime"
  - "_futime"
  - "futime64"
  - "_futime64"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função _futime"
  - "Função futime32"
  - "Função futime64"
  - "hora da modificação do arquivo [C++]"
  - "Função _futime64"
  - "Função futime"
  - "Função _futime32"
ms.assetid: b942ce8f-5cc7-4fa8-ab47-de5965eded53
caps.latest.revision: 21
caps.handback.revision: 19
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# _futime, _futime32, _futime64
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Define a hora da alteração em um arquivo aberto.  
  
## Sintaxe  
  
```  
int _futime(   
   int fd,  
   struct _utimbuf *filetime   
);  
int _futime32(   
   int fd,  
   struct __utimbuf32 *filetime   
);  
int _futime64(   
   int fd,  
   struct __utimbuf64 *filetime   
);  
```  
  
#### Parâmetros  
 `fd`  
 O descritor de Arquivo para o arquivo aberto.  
  
 `filetime`  
 Ponteiro para a estrutura que contém a nova data de modificação.  
  
## Valor de retorno  
 Retornará 0 se com êxito.  Se ocorrer um erro, o manipulador inválido do parâmetro será chamado, conforme descrito em [Validação do parâmetro](../../c-runtime-library/parameter-validation.md).  Se a execução for permitida continuar, a função retornará – 1 e `errno` é definido como `EBADF`, indicando um descritor de arquivo inválido, ou a `EINVAL`, indicando um parâmetro inválido.  
  
## Comentários  
 A rotina de `_futime` define a data de modificação e a hora de acesso no arquivo aberto associado a `fd`*.* `_futime` é idêntico a [\_utime](../../c-runtime-library/reference/utime-utime32-utime64-wutime-wutime32-wutime64.md), exceto que o argumento é o descritor de arquivo de um arquivo aberto, em vez do nome de um arquivo ou um caminho para um arquivo.  A estrutura de `_utimbuf` contém campos por novos data e hora de acesso de alteração.  Os campos devem conter valores válidos.  `_utimbuf32` e `_utimbuf64` são idênticos a `_utimbuf` com exceção do uso de tipos de 32 bits e de 64 bits de tempo, respectivamente.  `_futime` e `_utimbuf` usam um tipo de 64 bits de tempo e `_futime` é idêntico em comportamento a `_futime64`.  Se você precisar forçar o antigo comportamento, defina `_USE_32BIT_TIME_T`.  Isso faz com `_futime` seja idêntico em comportamento a `_futime32` e faz com que a estrutura de `_utimbuf` use o tipo de 32 bits de tempo, tornando\-a equivalente a `__utimbuf32`.  
  
 `_futime64`, que usa a estrutura de `__utimbuf64` , pode ler e modificar datas de arquivo a 23:59: o 31 de dezembro, 59, 3000, UTC; considerando que uma chamada a `_futime32` falhará se a data no arquivo for posterior ao 19:14: 7 de janeiro de 18, 2038, UTC.  A meia\-noite, o 1º de janeiro de 1970, é o limite inferior do intervalo de datas para essas funções.  
  
## Requisitos  
  
|Função|Cabeçalho necessário|Cabeçalho opcional|  
|------------|--------------------------|------------------------|  
|`_futime`|\<o sistema\/utime.h\>|\<errno.h\>|  
|`_futime32`|\<o sistema\/utime.h\>|\<errno.h\>|  
|`_futime64`|\<o sistema\/utime.h\>|\<errno.h\>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## Exemplo  
  
```  
// crt_futime.c  
// This program uses _futime to set the  
// file-modification time to the current time.  
  
#include <stdio.h>  
#include <stdlib.h>  
#include <fcntl.h>  
#include <io.h>  
#include <sys/types.h>  
#include <sys/stat.h>  
#include <sys/utime.h>  
#include <share.h>  
  
int main( void )  
{  
   int hFile;  
  
   // Show file time before and after.   
   system( "dir crt_futime.c_input" );  
  
   _sopen_s( &hFile, "crt_futime.c_input", _O_RDWR, _SH_DENYNO, 0 );  
  
   if( _futime( hFile, NULL ) == -1 )  
      perror( "_futime failed\n" );  
   else  
      printf( "File time modified\n" );  
  
   _close (hFile);  
  
   system( "dir crt_futime.c_input" );  
}  
```  
  
## Entrada: crt\_futime.c\_input  
  
```  
Arbitrary file contents.  
```  
  
### Saída de Exemplo  
  
```  
Volume in drive Z has no label.  
 Volume Serial Number is 5C68-57C1  
  
 Directory of Z:\crt  
  
03/25/2004  10:40 AM                24 crt_futime.c_input  
               1 File(s)             24 bytes  
               0 Dir(s)  24,268,476,416 bytes free  
 Volume in drive Z has no label.  
 Volume Serial Number is 5C68-57C1  
  
 Directory of Z:\crt  
  
03/25/2004  10:41 AM                24 crt_futime.c_input  
               1 File(s)             24 bytes  
               0 Dir(s)  24,268,476,416 bytes free  
File time modified  
```  
  
## Equivalência do .NET Framework  
  
-   [System::IO::File::SetLastAccessTime](https://msdn.microsoft.com/en-us/library/system.io.file.setlastaccesstime.aspx)  
  
-   [System::IO::File::SetLastWriteTime](https://msdn.microsoft.com/en-us/library/system.io.file.setlastwritetime.aspx)  
  
-   [System::IO::File::SetCreationTime](https://msdn.microsoft.com/en-us/library/system.io.file.setcreationtime.aspx)  
  
## Consulte também  
 [Gerenciamento de tempo](../../c-runtime-library/time-management.md)