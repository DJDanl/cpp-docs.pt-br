---
title: "_utime, _utime32, _utime64, _wutime, _wutime32, _wutime64 | Microsoft Docs"
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
  - "_utime64"
  - "_utime"
  - "_wutime"
  - "_wutime64"
  - "_wutime32"
  - "_utime32"
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
  - "_tutime"
  - "_utime64"
  - "wutime"
  - "utime32"
  - "wutime64"
  - "_utime"
  - "wutime32"
  - "_wutime"
  - "utime"
  - "utime64"
  - "_wutime64"
  - "_utime32"
  - "_tutime64"
  - "_wutime32"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função tutime"
  - "Função utime32"
  - "Função utime64"
  - "Função _utime"
  - "Função _tutime32"
  - "hora [C++], a modificação do arquivo"
  - "Função wutime"
  - "Função _wutime"
  - "Função _wutime32"
  - "Função _tutime64"
  - "Função _tutime"
  - "arquivos [C++], hora da modificação"
  - "Função _wutime64"
  - "Função _utime32"
  - "Função utime"
  - "Função _utime64"
  - "Função wutime64"
  - "Função wutime32"
  - "Função tutime64"
  - "Função tutime32"
ms.assetid: 8d482d40-19b9-4591-bfee-5d7f601d1a9e
caps.latest.revision: 16
caps.handback.revision: 16
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# _utime, _utime32, _utime64, _wutime, _wutime32, _wutime64
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Defina o tempo de modificação do arquivo.  
  
## Sintaxe  
  
```  
int _utime(  
   const char *filename,  
   struct _utimbuf *times   
);  
int _utime32(  
   const char *filename,  
   struct __utimbuf32 *times   
);  
int _utime64(  
   const char *filename,  
   struct __utimbuf64 *times   
);  
int _wutime(  
   const wchar_t *filename,  
   struct _utimbuf *times   
);  
int _wutime32(  
   const wchar_t *filename,  
   struct __utimbuf32 *times   
);  
int _wutime64(  
   const wchar_t *filename,  
   struct __utimbuf64 *times   
);  
```  
  
#### Parâmetros  
 `filename`  
 Ponteiro para uma cadeia de caracteres que contém o caminho ou nome de arquivo.  
  
 `times`  
 Ponteiro para valores de hora armazenado.  
  
## Valor de retorno  
 Cada uma dessas funções retornará 0 se a hora de modificação do arquivo foi alterada. Um valor de retorno de\-1 indica um erro. Se um parâmetro inválido for passado, o manipulador de parâmetro inválido é invocado, conforme descrito em [Validação do parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução puder continuar, essas funções retornarão \-1 e `errno` é definido como um dos seguintes valores:  
  
 `EACCES`  
 Caminho Especifica o diretório ou arquivo somente leitura  
  
 `EINVAL`  
 Inválido `times` argumento  
  
 `EMFILE`  
 Há muitos arquivos abertos \(o arquivo deve ser aberto para alterar seu tempo de modificação\)  
  
 `ENOENT`  
 Caminho ou nome de arquivo não encontrado  
  
 Consulte [doserrno, errno, sys\_errlist e sys\_nerr](../Topic/errno,%20_doserrno,%20_sys_errlist,%20and%20_sys_nerr.md) para obter mais informações sobre esses e outros, códigos de retorno.  
  
 A data pode ser alterada para um arquivo se a data de alteração for após a meia\-noite de 1º de janeiro de 1970 e antes da data de término da função usada.`_utime` e `_wutime` usar um valor de tempo de 64 bits, portanto, a data de término é 23:59:59, 31 de dezembro de 3000, UTC. Se `_USE_32BIT_TIME_T` é definida para forçar o comportamento antigo, a data de término é 23:59:59 18 de janeiro de 2038, UTC.`_utime32` ou `_wutime32` usar um tipo de tempo de 32 bits independentemente `_USE_32BIT_TIME_T` é definido e sempre ter a data de término anterior.`_utime64` ou `_wutime64` sempre usar o tipo de tempo de 64 bits, para que a data de término posterior sempre suportam a essas funções.  
  
## Comentários  
 O `_utime` função define a hora de modificação do arquivo especificado por `filename`*.* O processo deve ter acesso de gravação para o arquivo para alterar a hora. No sistema operacional Windows, você pode alterar o tempo de acesso e o tempo de modificação no `_utimbuf` estrutura. Se `times` é um `NULL` ponteiro, a hora da modificação é definida para a hora local atual. Caso contrário, `times` deve apontar para uma estrutura do tipo `_utimbuf`, definido em SYS\\UTIME. H.  
  
 O `_utimbuf` estrutura armazena os horários de acesso e modificação de arquivo usados pelo `_utime` para alterar as datas de modificação do arquivo. A estrutura tem os seguintes campos forem do tipo `time_t`:  
  
 `actime`  
 Tempo de acesso a arquivos  
  
 `modtime`  
 Hora da modificação do arquivo  
  
 Versões específicas do `_utimbuf` estrutura \(`_utimebuf32` e `__utimbuf64`\) são definidos usando as versões de 32 bits e 64 bits do tipo hora. Elas são usadas nas versões específicas de 32 bits e 64 bits dessa função.`_utimbuf` próprio por padrão usa um tipo de tempo de 64 bits, a menos que `_USE_32BIT_TIME_T` é definido.  
  
 `_utime` é idêntico ao `_futime` exceto que o `filename` argumento de `_utime` é um nome de arquivo ou um caminho para um arquivo, em vez de um descritor de arquivo de um arquivo aberto.  
  
 `_wutime` é uma versão de caractere largo de `_utime`; o `filename` argumento `_wutime` é uma cadeia de caracteres largos. Essas funções se comportam de forma idêntica caso contrário.  
  
### Mapeamentos de rotina de texto genérico  
  
|TCHAR. Rotina H|Unicode e MBCS não definidos|MBCS definido|Unicode definido|  
|---------------------|----------------------------------|-------------------|----------------------|  
|`_tutime`|`_utime`|`_utime`|`_wutime`|  
|`_tutime32`|`_utime32`|`_utime32`|`_wutime32`|  
|`_tutime64`|`_utime64`|`_utime64`|`_wutime64`|  
  
## Requisitos  
  
|Rotina|Cabeçalhos necessários|Cabeçalhos opcionais|  
|------------|----------------------------|--------------------------|  
|`_utime`, `_utime32`, `_utime64`|\< sys\/utime.h \>|\< errno. h \>|  
|`_utime64`|\< sys\/utime.h \>|\< errno. h \>|  
|`_wutime`|\< utime.h \> ou \< WCHAR \>|\< errno. h \>|  
  
 Para obter informações adicionais sobre compatibilidade, consulte [compatibilidade](../../c-runtime-library/compatibility.md) na introdução.  
  
## Exemplo  
 Esse programa usa `_utime` para definir a hora de modificação do arquivo para a hora atual.  
  
```  
// crt_utime.c  
#include <stdio.h>  
#include <stdlib.h>  
#include <sys/types.h>  
#include <sys/utime.h>  
#include <time.h>  
  
int main( void )  
{  
   struct tm tma = {0}, tmm = {0};  
   struct _utimbuf ut;  
  
   // Fill out the accessed time structure  
   tma.tm_hour = 12;  
   tma.tm_isdst = 0;  
   tma.tm_mday = 15;  
   tma.tm_min = 0;  
   tma.tm_mon = 0;  
   tma.tm_sec = 0;  
   tma.tm_year = 103;  
  
   // Fill out the modified time structure  
   tmm.tm_hour = 12;  
   tmm.tm_isdst = 0;  
   tmm.tm_mday = 15;  
   tmm.tm_min = 0;  
   tmm.tm_mon = 0;  
   tmm.tm_sec = 0;  
   tmm.tm_year = 102;  
  
   // Convert tm to time_t  
   ut.actime = mktime(&tma);  
   ut.modtime = mktime(&tmm);  
  
   // Show file time before and after  
   system( "dir crt_utime.c" );  
   if( _utime( "crt_utime.c", &ut ) == -1 )  
      perror( "_utime failed\n" );  
   else  
      printf( "File time modified\n" );  
   system( "dir crt_utime.c" );  
}  
```  
  
## Saída de exemplo  
  
```  
Volume in drive C has no label.  
 Volume Serial Number is 9CAC-DE74  
  
 Directory of C:\test  
  
01/09/2003  05:38 PM               935 crt_utime.c  
               1 File(s)            935 bytes  
               0 Dir(s)  20,742,955,008 bytes free  
File time modified  
 Volume in drive C has no label.  
 Volume Serial Number is 9CAC-DE74  
  
 Directory of C:\test  
  
01/15/2002  12:00 PM               935 crt_utime.c  
               1 File(s)            935 bytes  
               0 Dir(s)  20,742,955,008 bytes free  
```  
  
## Equivalência do .NET Framework  
 Não aplicável. Para chamar a função C padrão, use `PInvoke`. Para obter mais informações, consulte [exemplos de invocação de plataforma](../Topic/Platform%20Invoke%20Examples.md).  
  
## Consulte também  
 [Gerenciamento de tempo](../../c-runtime-library/time-management.md)   
 [asctime, \_wasctime](../../c-runtime-library/reference/asctime-wasctime.md)   
 [ctime, \_ctime32, \_ctime64, \_wctime, \_wctime32, \_wctime64](../../c-runtime-library/reference/ctime-ctime32-ctime64-wctime-wctime32-wctime64.md)   
 [\_fstat, \_fstat32, \_fstat64, \_fstati64, \_fstat32i64, \_fstat64i32](../../c-runtime-library/reference/fstat-fstat32-fstat64-fstati64-fstat32i64-fstat64i32.md)   
 [\_ftime, \_ftime32, \_ftime64](../../c-runtime-library/reference/ftime-ftime32-ftime64.md)   
 [\_futime, \_futime32, \_futime64](../../c-runtime-library/reference/futime-futime32-futime64.md)   
 [gmtime, \_gmtime32, \_gmtime64](../../c-runtime-library/reference/gmtime-gmtime32-gmtime64.md)   
 [localtime, \_localtime32, \_localtime64](../../c-runtime-library/reference/localtime-localtime32-localtime64.md)   
 [Funções \_stat, \_wstat](../../c-runtime-library/reference/stat-functions.md)   
 [time, \_time32, \_time64](../Topic/time,%20_time32,%20_time64.md)