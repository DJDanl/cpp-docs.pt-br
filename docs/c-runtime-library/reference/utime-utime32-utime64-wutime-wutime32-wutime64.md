---
title: _utime, _utime32, _utime64, _wutime, _wutime32, _wutime64 | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: reference
apiname:
- _utime64
- _utime
- _wutime
- _wutime64
- _wutime32
- _utime32
apilocation:
- msvcrt.dll
- msvcr80.dll
- msvcr90.dll
- msvcr100.dll
- msvcr100_clr0400.dll
- msvcr110.dll
- msvcr110_clr0400.dll
- msvcr120.dll
- msvcr120_clr0400.dll
- ucrtbase.dll
- api-ms-win-crt-time-l1-1-0.dll
apitype: DLLExport
f1_keywords:
- _tutime
- _utime64
- wutime
- utime32
- wutime64
- _utime
- wutime32
- _wutime
- utime
- utime64
- _wutime64
- _utime32
- _tutime64
- _wutime32
dev_langs:
- C++
helpviewer_keywords:
- tutime function
- utime32 function
- utime64 function
- _utime function
- _tutime32 function
- time [C++], file modification
- wutime function
- _wutime function
- _wutime32 function
- _tutime64 function
- _tutime function
- files [C++], modification time
- _wutime64 function
- _utime32 function
- utime function
- _utime64 function
- wutime64 function
- wutime32 function
- tutime64 function
- tutime32 function
ms.assetid: 8d482d40-19b9-4591-bfee-5d7f601d1a9e
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: f94c67fe75f5675192dbd0f306d8eef0aace70f5
ms.sourcegitcommit: 6002df0ac79bde5d5cab7bbeb9d8e0ef9920da4a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/14/2018
---
# <a name="utime-utime32-utime64-wutime-wutime32-wutime64"></a>_utime, _utime32, _utime64, _wutime, _wutime32, _wutime64
Defina a hora de modificação do arquivo.  
  
## <a name="syntax"></a>Sintaxe  
  
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
  
#### <a name="parameters"></a>Parâmetros  
 `filename`  
 Ponteiro para uma cadeia de caracteres que contém o caminho ou nome de arquivo.  
  
 `times`  
 Ponteiro para os valores temporais armazenados.  
  
## <a name="return-value"></a>Valor de retorno  
 Cada uma dessas funções retornará 0 se a hora de modificação do arquivo for alterada. Um valor de retorno de -1 indica um erro. Se um parâmetro inválido for passado, o manipulador de parâmetro inválido será invocado, conforme descrito em [Validação de Parâmetro](../../c-runtime-library/parameter-validation.md). Se for permitido que a execução continue, essas funções retornarão -1 e `errno` será definido como um dos valores a seguir:  
  
 `EACCES`  
 O caminho especifica o diretório ou o arquivo somente leitura  
  
 `EINVAL`  
 Argumento `times` inválido  
  
 `EMFILE`  
 Há muitos arquivos abertos (o arquivo deve ser aberto para seu tempo de modificação ser alterado)  
  
 `ENOENT`  
 Caminho ou nome de arquivo não encontrado  
  
 Consulte [_doserrno, errno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md) para obter mais informações sobre esses e outros códigos de retorno.  
  
 A data de um arquivo poderá ser alterada se tal alteração ocorrer após a meia-noite de 1º de janeiro de 1970 e antes que a data de término da função seja utilizada. `_utime` e `_wutime` usam um valor temporal de 64 bits, assim, a data de término será às 23:59:59 de 31 de dezembro de 3000 (UTC). Se `_USE_32BIT_TIME_T` for definido para forçar o comportamento antigo, a data de término será às 23:59:59 de 18 de janeiro de 2038 (UTC). `_utime32` ou `_wutime32` usam um tipo temporal de 32 bits, independentemente de `_USE_32BIT_TIME_T` estar definido e sempre têm a data de término mais antiga. `_utime64` ou `_wutime64` sempre usam o tipo temporal de 64 bits para que essas funções ofereçam suporte à data de término mais recente.  
  
## <a name="remarks"></a>Comentários  
 A função `_utime` define a modificação da hora do arquivo especificado por `filename`*.* O processo deve ter acesso de gravação ao arquivo para alterar a hora. No sistema operacional Windows, é possível alterar os horários de acesso e de modificação na estrutura `_utimbuf`. Se `times` for um ponteiro `NULL`, a modificação da hora será definida como o horário local atual. Caso contrário, `times` deve apontar para uma estrutura do tipo `_utimbuf`, definida em SYS\UTIME.H.  
  
 A estrutura `_utimbuf` armazena os horários de acesso e modificação usados por `_utime` para alterar datas de modificação dos arquivos. A estrutura tem os seguintes campos, ambos do tipo `time_t`:  
  
 `actime`  
 Horário de acesso ao arquivo  
  
 `modtime`  
 Horário de modificação do arquivo  
  
 Versões específicas da estrutura `_utimbuf` (`_utimebuf32` e `__utimbuf64`) são definidas usando as versões de 32 e 64 bits do tipo temporal. Elas são usadas nas versões específicas de 32 e 64 bits dessa função. O `_utimbuf`, por padrão, usa um tipo temporal de 64 bits, a menos que `_USE_32BIT_TIME_T` esteja definido.  
  
 `_utime` é idêntico a `_futime`, exceto se o argumento `filename` de `_utime` for um nome de arquivo ou caminho para um arquivo, em vez de um descritor de arquivo de um arquivo aberto.  
  
 A função `_wutime` é uma versão de caractere largo da função `_utime`; o argumento `filename` para `_wutime` é uma cadeia de caracteres larga. Caso contrário, essas funções se comportam de forma idêntica.  
  
### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico  
  
|Rotina TCHAR.H|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|  
|---------------------|------------------------------------|--------------------|-----------------------|  
|`_tutime`|`_utime`|`_utime`|`_wutime`|  
|`_tutime32`|`_utime32`|`_utime32`|`_wutime32`|  
|`_tutime64`|`_utime64`|`_utime64`|`_wutime64`|  
  
## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalhos necessários|Cabeçalhos opcionais|  
|-------------|----------------------|----------------------|  
|`_utime`, `_utime32`, `_utime64`|\<sys/utime.h>|\<errno.h>|  
|`_utime64`|\<sys/utime.h>|\<errno.h>|  
|`_wutime`|\<utime.h> or \<wchar.h>|\<errno.h>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## <a name="example"></a>Exemplo  
 Esse programa usa `_utime` para definir a hora de modificação do arquivo como a hora atual.  
  
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
  
## <a name="sample-output"></a>Saída de Exemplo  
  
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
  
## <a name="see-also"></a>Consulte também  
 [Gerenciamento de Tempo](../../c-runtime-library/time-management.md)   
 [asctime, _wasctime](../../c-runtime-library/reference/asctime-wasctime.md)   
 [ctime, _ctime32, _ctime64, _wctime, _wctime32, _wctime64](../../c-runtime-library/reference/ctime-ctime32-ctime64-wctime-wctime32-wctime64.md)   
 [_fstat, _fstat32, _fstat64, _fstati64, _fstat32i64, _fstat64i32](../../c-runtime-library/reference/fstat-fstat32-fstat64-fstati64-fstat32i64-fstat64i32.md)   
 [_ftime, _ftime32, _ftime64](../../c-runtime-library/reference/ftime-ftime32-ftime64.md)   
 [_futime, _futime32, _futime64](../../c-runtime-library/reference/futime-futime32-futime64.md)   
 [gmtime, _gmtime32, _gmtime64](../../c-runtime-library/reference/gmtime-gmtime32-gmtime64.md)   
 [localtime, _localtime32, _localtime64](../../c-runtime-library/reference/localtime-localtime32-localtime64.md)   
 [Funções _stat, _wstat](../../c-runtime-library/reference/stat-functions.md)   
 [time, _time32, _time64](../../c-runtime-library/reference/time-time32-time64.md)