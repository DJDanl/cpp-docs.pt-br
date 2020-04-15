---
title: _chdir, _wchdir
ms.date: 4/2/2020
api_name:
- _wchdir
- _chdir
- _o__chdir
- _o__wchdir
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
- api-ms-win-crt-filesystem-l1-1-0.dll
- api-ms-win-crt-private-l1-1-0
api_type:
- DLLExport
topic_type:
- apiref
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
ms.openlocfilehash: a3f224e68e4b5a43274616892012ceba737d6d17
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81333385"
---
# <a name="_chdir-_wchdir"></a>_chdir, _wchdir

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

*Dirname*<br/>
Caminho do novo diretório de trabalho.

## <a name="return-value"></a>Valor retornado

Essas funções retornarão um valor de 0 se forem bem-sucedidas. Um valor de retorno de -1 indica falha. Se o caminho especificado não for encontrado, **errno** será definido **como ENOENT**. Se *dirname* for **NULL**, o manipulador de parâmetros inválidos é invocado, conforme descrito na [Validação de Parâmetros](../../c-runtime-library/parameter-validation.md). Se a execução continuar, **errno** será definido **como EINVAL** e a função retorna -1.

## <a name="remarks"></a>Comentários

A função **_chdir** altera o diretório de trabalho atual para o diretório especificado por *dirname*. O *parâmetro dirname* deve se referir a um diretório existente. Essa função pode mudar o diretório de trabalho atual em qualquer unidade. Se uma nova letra de unidade for especificada em *dirname,* a letra de unidade padrão também será alterada. Por exemplo, se A for a letra da unidade padrão e \BIN for o diretório de trabalho atual, a chamada a seguir alterará o diretório de trabalho atual para a unidade C e estabelecerá C como a nova unidade padrão:

```C
_chdir("c:\temp");
```

Quando você usa o caractere de barra invertida opcional** (&#92;) **em caminhos, você deve colocar duas barras traseiras** (&#92;&#92;) **em uma seqüência de caracteres C literal para representar uma única barra invertida** (&#92;). **

**_wchdir** é uma versão ampla de **_chdir;** o argumento *dirname* para **_wchdir** é uma seqüência de caracteres amplo. **_wchdir** e **_chdir** se comportam de forma idêntica.

Por padrão, o estado global desta função é escopo para o aplicativo. Para mudar isso, consulte [Estado Global no CRT](../global-state.md).

### <a name="generic-text-routine-mapping"></a>Mapeamento da Rotina de Texto Genérico:

|Rotina Tchar.h|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|
|---------------------|--------------------------------------|--------------------|-----------------------|
|**_tchdir**|**_chdir**|**_chdir**|**_wchdir**|

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

## <a name="see-also"></a>Confira também

[Controle de diretório](../../c-runtime-library/directory-control.md)<br/>
[_mkdir, _wmkdir](mkdir-wmkdir.md)<br/>
[_rmdir, _wrmdir](rmdir-wrmdir.md)<br/>
[system, _wsystem](system-wsystem.md)<br/>
