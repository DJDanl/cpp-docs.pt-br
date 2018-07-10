---
title: _utime, _utime32, _utime64, _wutime, _wutime32, _wutime64 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-standard-libraries
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
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: cd8737d6391ea1effd50e967008520b2d77707e6
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32417705"
---
# <a name="utime-utime32-utime64-wutime-wutime32-wutime64"></a>_utime, _utime32, _utime64, _wutime, _wutime32, _wutime64

Defina a hora de modificação do arquivo.

## <a name="syntax"></a>Sintaxe

```C
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

### <a name="parameters"></a>Parâmetros

*filename*<br/>
Ponteiro para uma cadeia de caracteres que contém o caminho ou nome de arquivo.

*Vezes*<br/>
Ponteiro para os valores temporais armazenados.

## <a name="return-value"></a>Valor de retorno

Cada uma dessas funções retornará 0 se a hora de modificação do arquivo for alterada. Um valor de retorno de -1 indica um erro. Se um parâmetro inválido for passado, o manipulador de parâmetro inválido será invocado, conforme descrito em [Validação de Parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução é permitida para continuar, essas funções retornam -1 e **errno** é definido como um dos seguintes valores:

|Valor errno|Condição|
|-|-|
**EACCES**|O caminho especifica o diretório ou o arquivo somente leitura
**EINVAL**|Inválido *vezes* argumento
**EMFILE**|Há muitos arquivos abertos (o arquivo deve ser aberto para seu tempo de modificação ser alterado)
**ENOENT**|Caminho ou nome de arquivo não encontrado

Consulte [_doserrno, errno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md) para obter mais informações sobre esses e outros códigos de retorno.

A data de um arquivo poderá ser alterada se tal alteração ocorrer após a meia-noite de 1º de janeiro de 1970 e antes que a data de término da função seja utilizada. **utime** e **wutime** usar um valor de tempo de 64 bits, portanto, a data de término é 23:59:59, 31 de dezembro de 3000, UTC. Se **_USE_32BIT_TIME_T** está definido para forçar o comportamento antigo, a data de término é 23:59:59 18 de janeiro de 2038, UTC. **utime32** ou **wutime32** usar um tipo de tempo de 32 bits, independentemente se **_USE_32BIT_TIME_T** é definida, e sempre ter a data de término anterior. **utime64** ou **wutime64** sempre usar o tipo de tempo de 64 bits, para que a data de término mais recente sempre suportam a essas funções.

## <a name="remarks"></a>Comentários

O **utime** função define a hora de modificação para o arquivo especificado por *filename * *.* O processo deve ter acesso de gravação ao arquivo para alterar a hora. No sistema operacional Windows, você pode alterar o tempo de acesso e a hora de modificação no **utimbuf** estrutura. Se *vezes* é um **nulo** ponteiro, a hora da modificação é definida para a hora local atual. Caso contrário, *vezes* deve apontar para uma estrutura de tipo **utimbuf**, definido em SYS\UTIME. H.

O **utimbuf** estrutura armazena tempos de acesso e modificação de arquivo usados pelo **utime** para alterar as datas de modificação do arquivo. A estrutura tem os seguintes campos, que são do tipo **time_t**:

|Campo||
|-|-|
**actime**|Horário de acesso ao arquivo
**modtime**|Horário de modificação do arquivo

Versões específicas do **utimbuf** estrutura (**_utimebuf32** e **utimbuf64**) são definidos usando as versões de 32 bits e 64 bits do tipo tempo. Elas são usadas nas versões específicas de 32 e 64 bits dessa função. **utimbuf** em si, por padrão usa um tipo de tempo de 64 bits, a menos que **_USE_32BIT_TIME_T** está definido.

**utime** é idêntico ao **futime** exceto que o *filename* argumento de **utime** é um nome de arquivo ou um caminho para um arquivo, em vez de um descritor de arquivo de um Abra o arquivo.

**wutime** é uma versão de caractere largo de **utime**; o *filename* argumento **wutime** é uma cadeia de caracteres largos. Caso contrário, essas funções se comportam de forma idêntica.

### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico

|Rotina TCHAR.H|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|
|---------------------|------------------------------------|--------------------|-----------------------|
|**tutime**|**_utime**|**_utime**|**_wutime**|
|**tutime32**|**_utime32**|**_utime32**|**_wutime32**|
|**tutime64**|**_utime64**|**_utime64**|**_wutime64**|

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalhos necessários|Cabeçalhos opcionais|
|-------------|----------------------|----------------------|
|**utime**, **utime32**, **utime64**|\<sys/utime.h>|\<errno.h>|
|**_utime64**|\<sys/utime.h>|\<errno.h>|
|**_wutime**|\<utime.h> or \<wchar.h>|\<errno.h>|

Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

Este programa usa **utime** para definir a hora de modificação do arquivo para a hora atual.

```C
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

### <a name="sample-output"></a>Saída de Exemplo

```Output
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

[Gerenciamento de Tempo](../../c-runtime-library/time-management.md)<br/>
[asctime, _wasctime](asctime-wasctime.md)<br/>
[ctime, _ctime32, _ctime64, _wctime, _wctime32, _wctime64](ctime-ctime32-ctime64-wctime-wctime32-wctime64.md)<br/>
[_fstat, _fstat32, _fstat64, _fstati64, _fstat32i64, _fstat64i32](fstat-fstat32-fstat64-fstati64-fstat32i64-fstat64i32.md)<br/>
[_ftime, _ftime32, _ftime64](ftime-ftime32-ftime64.md)<br/>
[_futime, _futime32, _futime64](futime-futime32-futime64.md)<br/>
[gmtime, _gmtime32, _gmtime64](gmtime-gmtime32-gmtime64.md)<br/>
[localtime, _localtime32, _localtime64](localtime-localtime32-localtime64.md)<br/>
[Funções _stat, _wstat](stat-functions.md)<br/>
[time, _time32, _time64](time-time32-time64.md)<br/>
