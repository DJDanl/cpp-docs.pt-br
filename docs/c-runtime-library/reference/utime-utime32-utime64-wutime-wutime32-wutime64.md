---
title: _utime, _utime32, _utime64, _wutime, _wutime32, _wutime64
ms.date: 4/2/2020
api_name:
- _utime64
- _utime
- _wutime
- _wutime64
- _wutime32
- _utime32
- _o__utime32
- _o__utime64
- _o__wutime32
- _o__wutime64
api_location:
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
- api-ms-win-crt-private-l1-1-0.dll
api_type:
- DLLExport
topic_type:
- apiref
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
ms.openlocfilehash: dbff557cd116eb1df44f015b17716408c8dc54c2
ms.sourcegitcommit: 5a069c7360f75b7c1cf9d4550446ec2fa2eb2293
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2020
ms.locfileid: "82912125"
---
# <a name="_utime-_utime32-_utime64-_wutime-_wutime32-_wutime64"></a>_utime, _utime32, _utime64, _wutime, _wutime32, _wutime64

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

*nome do arquivo*<br/>
Ponteiro para uma cadeia de caracteres que contém o caminho ou nome de arquivo.

*maior*<br/>
Ponteiro para os valores temporais armazenados.

## <a name="return-value"></a>Valor retornado

Cada uma dessas funções retornará 0 se a hora de modificação do arquivo for alterada. Um valor de retorno de-1 indica um erro. Se um parâmetro inválido for passado, o manipulador de parâmetro inválido será invocado, conforme descrito em [Validação de Parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução tiver permissão para continuar, essas funções retornam-1 e **errno** são definidas como um dos seguintes valores:

|Valor errno|Condição|
|-|-|
| **EACCES** | O caminho especifica o diretório ou o arquivo somente leitura |
| **EINVAL** | Argumento *Times* inválido |
| **EMFILE** | Há muitos arquivos abertos (o arquivo deve ser aberto para seu tempo de modificação ser alterado) |
| **ENOENT** | Caminho ou nome de arquivo não encontrado |

Consulte [_doserrno, errno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md) para obter mais informações sobre esses e outros códigos de retorno.

A data de um arquivo poderá ser alterada se tal alteração ocorrer após a meia-noite de 1º de janeiro de 1970 e antes que a data de término da função seja utilizada. **_utime** e **_wutime** usar um valor de tempo de 64 bits, então a data de término é 23:59:59, 31 de dezembro de 3000, UTC. Se **_USE_32BIT_TIME_T** for definido para forçar o comportamento antigo, a data de término será 23:59:59 18 de janeiro de 2038, UTC. **_utime32** ou **_wutime32** usar um tipo de hora de 32 bits, independentemente de o **_USE_32BIT_TIME_T** ser definido, e sempre ter a data de término anterior. **_utime64** ou **_wutime64** sempre usam o tipo de hora de 64 bits, portanto, essas funções sempre dão suporte à data de término posterior.

## <a name="remarks"></a>Comentários

A função **_utime** define a hora de modificação para o arquivo especificado por *filename*. O processo deve ter acesso de gravação ao arquivo para alterar a hora. No sistema operacional Windows, você pode alterar a hora de acesso e a hora de modificação na estrutura de **_utimbuf** . Se *Times* for um ponteiro **NULL** , a hora da modificação será definida como a hora local atual. Caso contrário, os *tempos* devem apontar para uma estrutura do tipo **_utimbuf**, definido em SYS\UTIME. T.

A estrutura de **_utimbuf** armazena os tempos de modificação e acesso a arquivos usados pelo **_utime** para alterar datas de modificação de arquivos. A estrutura tem os seguintes campos, que são do tipo **time_t**:

| Campo |   |
|-------|---|
| **actime** | Horário de acesso ao arquivo |
| **modtime** | Horário de modificação do arquivo |

Versões específicas da estrutura de **_utimbuf** (**_utimebuf32** e **__utimbuf64**) são definidas usando as versões de 32 bits e 64 bits do tipo de tempo. Elas são usadas nas versões específicas de 32 e 64 bits dessa função. o **_utimbuf** em si por padrão usa um tipo de hora de 64 bits, a menos que **_USE_32BIT_TIME_T** seja definido.

**_utime** é idêntico a **_futime** , exceto pelo fato de que o argumento *filename* de **_utime** é um filename ou um caminho para um arquivo, em vez de um descritor de arquivo de um arquivo aberto.

**_wutime** é uma versão de caractere largo do **_utime**; o argumento de *nome de arquivo* para **_wutime** é uma cadeia de caracteres largos. Caso contrário, essas funções se comportam de forma idêntica.

Por padrão, o estado global dessa função tem como escopo o aplicativo. Para alterar isso, consulte [estado global no CRT](../global-state.md).

### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico

|Rotina TCHAR.H|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|
|---------------------|------------------------------------|--------------------|-----------------------|
|**_tutime**|**_utime**|**_utime**|**_wutime**|
|**_tutime32**|**_utime32**|**_utime32**|**_wutime32**|
|**_tutime64**|**_utime64**|**_utime64**|**_wutime64**|

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalhos necessários|Cabeçalhos opcionais|
|-------------|----------------------|----------------------|
|**_utime**, **_utime32**, **_utime64**|\<sys/utime.h>|\<errno.h>|
|**_utime64**|\<sys/utime.h>|\<errno.h>|
|**_wutime**|\<utime.h> or \<wchar.h>|\<errno.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

Este programa usa **_utime** para definir a hora da modificação de arquivo para a hora atual.

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

### <a name="sample-output"></a>Saída de exemplo

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

[Gerenciamento de tempo](../../c-runtime-library/time-management.md)<br/>
[asctime, _wasctime](asctime-wasctime.md)<br/>
[ctime, _ctime32, _ctime64, _wctime, _wctime32, _wctime64](ctime-ctime32-ctime64-wctime-wctime32-wctime64.md)<br/>
[_fstat, _fstat32, _fstat64, _fstati64, _fstat32i64, _fstat64i32](fstat-fstat32-fstat64-fstati64-fstat32i64-fstat64i32.md)<br/>
[_ftime, _ftime32, _ftime64](ftime-ftime32-ftime64.md)<br/>
[_futime, _futime32, _futime64](futime-futime32-futime64.md)<br/>
[gmtime, _gmtime32, _gmtime64](gmtime-gmtime32-gmtime64.md)<br/>
[localtime, _localtime32, _localtime64](localtime-localtime32-localtime64.md)<br/>
[Funções _stat, _wstat](stat-functions.md)<br/>
[time, _time32, _time64](time-time32-time64.md)<br/>
