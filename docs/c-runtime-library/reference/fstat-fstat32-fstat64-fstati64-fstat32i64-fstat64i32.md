---
title: "_fstat, _fstat32, _fstat64, _fstati64, _fstat32i64, _fstat64i32 | Microsoft Docs"
ms.custom: ""
ms.date: "12/15/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
apiname: 
  - "_fstat32"
  - "_fstat64"
  - "_fstati64"
  - "_fstat"
  - "_fstat64i32"
  - "_fstat32i64"
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
  - "api-ms-win-crt-filesystem-l1-1-0.dll"
apitype: "DLLExport"
f1_keywords: 
  - "_fstat32i64"
  - "fstat"
  - "fstat64i32"
  - "_fstat64"
  - "_fstati64"
  - "fstat64"
  - "_fstat32"
  - "fstat32i64"
  - "fstati64"
  - "_fstat"
  - "fstat32"
  - "_fstat64i32"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função _fstat64"
  - "Função fstati64"
  - "Função _fstat64i32"
  - "Função _fstat32i64"
  - "Função _fstat32"
  - "informações do arquivo"
  - "Função fstat64i32"
  - "Função fstat32"
  - "Função fstat"
  - "Função fstat64"
  - "Função _fstat"
  - "Função _fstati64"
  - "Função fstat32i64"
ms.assetid: 088f5e7a-9636-4cf7-ab8e-e28d2aa4280a
caps.latest.revision: 23
caps.handback.revision: 23
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# _fstat, _fstat32, _fstat64, _fstati64, _fstat32i64, _fstat64i32
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Obtém informações sobre um arquivo aberto.  
  
## Sintaxe  
  
```  
int _fstat(   
   int fd,  
   struct _stat *buffer   
);  
int _fstat32(   
   int fd,  
   struct __stat32 *buffer   
);  
int _fstat64(   
   int fd,  
   struct __stat64 *buffer   
);  
int _fstati64(   
   int fd,  
   struct _stati64 *buffer   
);  
int _fstat32i64(   
   int fd,  
   struct _stat32i64 *buffer   
);  
int _fstat64i32(   
   int fd,  
   struct _stat64i32 *buffer   
);  
```  
  
#### Parâmetros  
 `fd`  
 Descritor de arquivo do arquivo aberto.  
  
 `buffer`  
 Ponteiro para a estrutura para armazenar os resultados.  
  
## Valor de retorno  
 Retorna 0 se as informações de status do arquivo são obtidas. Um valor de retorno de\-1 indica um erro. Se o descritor de arquivo é inválido ou `buffer` é `NULL`, o manipulador de parâmetro inválido é invocado, conforme descrito em [Validação do parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução puder continuar, `errno` é definido como `EBADF`, no caso de um descritor de arquivo inválido, ou a `EINVAL`, se `buffer` é `NULL`.  
  
## Comentários  
 O `_fstat` função obtém informações sobre o arquivo aberto associado `fd` e o armazena na estrutura apontada por `buffer`. O `_stat` estrutura, definida em SYS\\Stat.h, contém os seguintes campos.  
  
 `st_atime`  
 Hora do último acesso de arquivo.  
  
 `st_ctime`  
 Hora de criação do arquivo.  
  
 `st_dev`  
 Se um dispositivo, `fd`; caso contrário, 0.  
  
 `st_mode`  
 Máscara de bits para informações sobre o modo de arquivo. O `_S_IFCHR` bit é definido se `fd` refere\-se a um dispositivo. O `_S_IFREG` bit é definido se `fd` refere\-se a um arquivo comum. Os bits de leitura\/gravação estão definidos de acordo com o modo de permissão do arquivo.`_S_IFCHR` e outras constantes estão definidos no SYS\\Stat.h.  
  
 `st_mtime`  
 Hora da última modificação do arquivo.  
  
 `st_nlink`  
 Sempre 1 em sistemas de arquivos não NTFS.  
  
 `st_rdev`  
 Se um dispositivo, `fd`; caso contrário, 0.  
  
 `st_size`  
 Tamanho do arquivo em bytes.  
  
 Se `fd` refere\-se a um dispositivo, o `st_atime`, `st_ctime`, `st_mtime`, e `st_size` campos não são significativos.  
  
 Como Stat.h usa o [dev\_t](../../c-runtime-library/standard-types.md) tipo, que é definido em Types.h, você deve incluir Types.h antes de Stat.h em seu código.  
  
 `_fstat64`, que usa o `__stat64` estrutura, permite que as datas de criação do arquivo a ser expressa backup por meio de 23:59:59 31 de dezembro de 3000, UTC; enquanto as outras funções apenas representam datas até 23:59:59 18 de janeiro de 2038, UTC. Meia\-noite de 1º de janeiro de 1970, é o limite inferior do intervalo de datas para todas essas funções.  
  
 Variações dessas funções oferecem suporte a tipos de tempo de 32 bits ou 64 bits e tamanhos de arquivo de 32 bits ou 64 bits. O primeiro sufixo numérico \(`32` ou `64`\) indica o tamanho do tempo tipo usado; o segundo sufixo é `i32` ou `i64`, indicando se o tamanho do arquivo é representado como um inteiro de 32 bits ou 64 bits.  
  
 `_fstat` é equivalente a `_fstat64i32`, e `struct``_stat` contém a hora de 64 bits. Isso é verdadeiro, a menos que `_USE_32BIT_TIME_T` é definido, caso em que o comportamento antigo está em vigor; `_fstat` usa um tempo de 32 bits, e `struct``_stat` contém a hora de 32 bits. O mesmo é verdadeiro para `_fstati64`.  
  
### Tipo de tempo e variações de tipo de comprimento de arquivo de STAT  
  
|Funções|\_USE\_32BIT\_TIME\_T definido?|Tipo de tempo|Tipo de tamanho de arquivo|  
|-------------|-------------------------------------|-------------------|--------------------------------|  
|`_fstat`|Não definido|64 bits|32 bits|  
|`_fstat`|Definido|32 bits|32 bits|  
|`_fstat32`|Não é afetada pela definição de macro|32 bits|32 bits|  
|`_fstat64`|Não é afetada pela definição de macro|64 bits|64 bits|  
|`_fstati64`|Não definido|64 bits|64 bits|  
|`_fstati64`|Definido|32 bits|64 bits|  
|`_fstat32i64`|Não é afetada pela definição de macro|32 bits|64 bits|  
|`_fstat64i32`|Não é afetada pela definição de macro|64 bits|32 bits|  
  
## Requisitos  
  
|Função|Cabeçalho necessário|  
|------------|--------------------------|  
|`_fstat`|\< sys\/stat.h \> e \< sys\/types.h \>|  
|`_fstat32`|\< sys\/stat.h \> e \< sys\/types.h \>|  
|`_fstat64`|\< sys\/stat.h \> e \< sys\/types.h \>|  
|`_fstati64`|\< sys\/stat.h \> e \< sys\/types.h \>|  
|`_fstat32i64`|\< sys\/stat.h \> e \< sys\/types.h \>|  
|`_fstat64i32`|\< sys\/stat.h \> e \< sys\/types.h \>|  
  
 Para obter informações de compatibilidade, consulte [compatibilidade](../../c-runtime-library/compatibility.md) na introdução.  
  
## Exemplo  
  
```  
// crt_fstat.c  
// This program uses _fstat to report  
// the size of a file named F_STAT.OUT.  
  
#include <io.h>  
#include <fcntl.h>  
#include <time.h>  
#include <sys/types.h>  
#include <sys/stat.h>  
#include <stdio.h>  
#include <stdlib.h>  
#include <string.h>  
#include <errno.h>  
#include <share.h>  
  
int main( void )  
{  
   struct _stat buf;  
   int fd, result;  
   char buffer[] = "A line to output";  
   char timebuf[26];  
   errno_t err;  
  
   _sopen_s( &fd,  
             "f_stat.out",  
             _O_CREAT | _O_WRONLY | _O_TRUNC,  
             _SH_DENYNO,  
             _S_IREAD | _S_IWRITE );  
   if( fd != -1 )  
      _write( fd, buffer, strlen( buffer ) );  
  
   // Get data associated with "fd":   
   result = _fstat( fd, &buf );  
  
   // Check if statistics are valid:   
   if( result != 0 )  
   {  
      if (errno == EBADF)  
        printf( "Bad file descriptor.\n" );  
      else if (errno == EINVAL)  
        printf( "Invalid argument to _fstat.\n" );  
   }  
   else  
   {  
      printf( "File size     : %ld\n", buf.st_size );  
      err = ctime_s(timebuf, 26, &buf.st_mtime);  
      if (err)  
      {  
         printf("Invalid argument to ctime_s.");  
         exit(1);  
      }  
      printf( "Time modified : %s", timebuf );  
   }  
   _close( fd );  
}  
```  
  
```Output  
Tamanho do arquivo: 16 tempo modificado: 07 de maio de quarta-feira 15:25:11 2003  
```  
  
## Equivalência do .NET Framework  
 Não aplicável. Para chamar a função C padrão, use `PInvoke`. Para obter mais informações, consulte [exemplos de invocação de plataforma](../Topic/Platform%20Invoke%20Examples.md).  
  
## Consulte também  
 [Manipulação de arquivos](../../c-runtime-library/file-handling.md)   
 [\_access, \_waccess](../../c-runtime-library/reference/access-waccess.md)   
 [\_chmod, \_wchmod](../../c-runtime-library/reference/chmod-wchmod.md)   
 [\_filelength, \_filelengthi64](../../c-runtime-library/reference/filelength-filelengthi64.md)   
 [Funções \_stat, \_wstat](../../c-runtime-library/reference/stat-functions.md)