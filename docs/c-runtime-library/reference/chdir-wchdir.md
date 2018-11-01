---
title: _chdir, _wchdir
ms.date: 11/04/2016
apiname:
- _wchdir
- _chdir
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
- api-ms-win-crt-filesystem-l1-1-0.dll
apitype: DLLExport
f1_keywords:
- tchdir
- _chdir
- _wchdir
- _tchdir
- wchdir
helpviewer_keywords:
- _tchdir function
- _chdir function
- _wchdir function
- tchdir function
- wchdir function
- chdir function
- directories [C++], changing
ms.assetid: 85e9393b-62ac-45d5-ab2a-fa2217f6152e
ms.openlocfilehash: e4cf7a44864df0b5ecca531aab3db4546c25bb2c
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50556332"
---
# <a name="chdir-wchdir"></a>_chdir, _wchdir

Altera o diretório de trabalho atual.

## <a name="syntax"></a>Sintaxe

```C
int _chdir(
   const char *dirname
);
int _wchdir(
   const wchar_t *dirname
);
```

### <a name="parameters"></a>Parâmetros

*dirname*<br/>
Caminho do novo diretório de trabalho.

## <a name="return-value"></a>Valor de retorno

Essas funções retornarão um valor de 0 se forem bem-sucedidas. Um valor de retorno de -1 indica falha. Se o caminho especificado não pôde ser encontrado, **errno** é definido como **ENOENT**. Se *dirname* é **nulo**, o manipulador de parâmetro inválido será invocado, conforme descrito na [validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução puder continuar, **errno** é definido como **EINVAL** e a função retornará -1.

## <a name="remarks"></a>Comentários

O **chdir** função altera o diretório de trabalho atual para o diretório especificado por *dirname*. O *dirname* parâmetro deve se referir a um diretório existente. Essa função pode mudar o diretório de trabalho atual em qualquer unidade. Se uma nova letra da unidade for especificada na *dirname*, a letra da unidade padrão mudará também. Por exemplo, se A for a letra da unidade padrão e \BIN for o diretório de trabalho atual, a chamada a seguir alterará o diretório de trabalho atual para a unidade C e estabelecerá C como a nova unidade padrão:

```C
_chdir("c:\temp");
```

Quando você usa o caractere de barra invertida opcional (**&#92;**) em caminhos, você deve colocar duas barras invertidas (**&#92;&#92;**) em uma cadeia de caracteres do C literal a representar uma única barra invertida ( **&#92;**).

**wchdir** é uma versão de caractere largo de **chdir**; o *dirname* argumento **wchdir** é uma cadeia de caracteres largos. **wchdir** e **chdir** se comportam de forma idêntica caso contrário.

### <a name="generic-text-routine-mapping"></a>Mapeamento da Rotina de Texto Genérico:

|Rotina Tchar.h|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|
|---------------------|--------------------------------------|--------------------|-----------------------|
|**tchdir**|**_chdir**|**_chdir**|**_wchdir**|

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|Cabeçalho opcional|
|-------------|---------------------|---------------------|
|**_chdir**|\<direct.h>|\<errno.h>|
|**_wchdir**|\<direct.h> ou \<wchar.h>|\<errno.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

```C
// crt_chdir.c
// arguments: C:\WINDOWS

/* This program uses the _chdir function to verify
   that a given directory exists. */

#include <direct.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main( int argc, char *argv[] )
{

   if(_chdir( argv[1] ) )
   {
      switch (errno)
      {
      case ENOENT:
         printf( "Unable to locate the directory: %s\n", argv[1] );
         break;
      case EINVAL:
         printf( "Invalid buffer.\n");
         break;
      default:
         printf( "Unknown error.\n");
      }
   }
   else
      system( "dir *.exe");
}
```

```Output
Volume in drive C has no label.
Volume Serial Number is 2018-08A1

Directory of c:\windows

08/29/2002  04:00 AM         1,004,032 explorer.exe
12/17/2002  04:43 PM            10,752 hh.exe
03/03/2003  09:24 AM            33,792 ieuninst.exe
10/29/1998  04:45 PM           306,688 IsUninst.exe
08/29/2002  04:00 AM            66,048 NOTEPAD.EXE
03/03/2003  09:24 AM            33,792 Q330994.exe
08/29/2002  04:00 AM           134,144 regedit.exe
02/28/2003  06:26 PM            46,352 setdebug.exe
08/29/2002  04:00 AM            15,360 TASKMAN.EXE
08/29/2002  04:00 AM            49,680 twunk_16.exe
08/29/2002  04:00 AM            25,600 twunk_32.exe
08/29/2002  04:00 AM           256,192 winhelp.exe
08/29/2002  04:00 AM           266,752 winhlp32.exe
              13 File(s)      2,249,184 bytes
               0 Dir(s)  67,326,029,824 bytes free
```

## <a name="see-also"></a>Consulte também

[Controle de diretório](../../c-runtime-library/directory-control.md)<br/>
[_mkdir, _wmkdir](mkdir-wmkdir.md)<br/>
[_rmdir, _wrmdir](rmdir-wrmdir.md)<br/>
[system, _wsystem](system-wsystem.md)<br/>
