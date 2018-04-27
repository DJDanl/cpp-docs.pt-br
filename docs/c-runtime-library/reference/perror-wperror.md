---
title: perror, _wperror | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.reviewer: ''
ms.suite: ''
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: ''
ms.topic: reference
apiname:
- _wperror
- perror
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
- api-ms-win-crt-runtime-l1-1-0.dll
apitype: DLLExport
f1_keywords:
- _wperror
- _tperror
- perror
dev_langs:
- C++
helpviewer_keywords:
- _tperror function
- tperror function
- wperror function
- error messages, printing
- printing error messages
- _wperror function
- perror function
ms.assetid: 34fce792-16fd-4673-9849-cd88b54b6cd5
caps.latest.revision: 14
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 3f6be77354f4efa1485f32ed178dc68b594b4f75
ms.sourcegitcommit: ef859ddf5afea903711e36bfd89a72389a12a8d6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/20/2018
---
# <a name="perror-wperror"></a>perror, _wperror

Imprima uma mensagem de erro.

## <a name="syntax"></a>Sintaxe

```C
void perror(
   const char *message
);
void _wperror(
   const wchar_t *message
);
```

### <a name="parameters"></a>Parâmetros

*mensagem* mensagem de cadeia de caracteres para imprimir.

## <a name="remarks"></a>Comentários

O **perror** função imprime uma mensagem de erro para **stderr**. **wperror** é uma versão de caractere largo de **_perror**; o *mensagem* argumento **wperror** é uma cadeia de caracteres largos. **wperror** e **_perror** se comportam de forma idêntica caso contrário.

### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico

|Rotina TCHAR.H|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|
|---------------------|------------------------------------|--------------------|-----------------------|
|**tperror**|**perror**|**perror**|**_wperror**|

*mensagem* é impresso primeiro, seguido por dois-pontos e pela mensagem de erro do sistema para a última chamada de biblioteca que gerou o erro e, finalmente, por um caractere de nova linha. Se *mensagem* é um ponteiro nulo ou um ponteiro para uma cadeia de caracteres nula, **perror** imprime somente a mensagem de erro do sistema.

O número do erro real é armazenado na variável [errno](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md) (definida em ERRNO.H). As mensagens de erro do sistema são acessadas por meio da variável [_sys_errlist](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md), que é uma matriz de mensagens ordenadas por número do erro. **perror** imprime a mensagem de erro apropriado usando a **errno** valor como um índice para **sys_errlist**. O valor da variável [sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md) é definido como o número máximo de elementos de **sys_errlist** matriz.

Para obter resultados precisos, chame **perror** imediatamente depois que retorna uma rotina de biblioteca com um erro. Caso contrário, as chamadas subsequentes podem substituir o **errno** valor.

Nas janelas do sistema operacional, alguns **errno** valores listados na ERRNO. H são utilizadas. Esses valores são reservados para uso pelo sistema operacional UNIX. Consulte [doserrno, errno, sys_errlist e sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md) para obter uma lista de **errno** valores usados pelo sistema operacional Windows. **perror** imprime uma cadeia de caracteres vazia para qualquer **errno** valor não usado por essas plataformas.

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**perror**|\<stdio.h> ou \<stdlib.h>|
|**_wperror**|\<stdio.h> ou \<wchar.h>|

Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="libraries"></a>Libraries

Todas as versões das [bibliotecas em tempo de execução C](../../c-runtime-library/crt-library-features.md).

## <a name="example"></a>Exemplo

```C
// crt_perror.c
// compile with: /W3
/* This program attempts to open a file named
* NOSUCHF.ILE. Because this file probably doesn't exist,
* an error message is displayed. The same message is
* created using perror, strerror, and _strerror.
*/

#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <io.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <share.h>

int main( void )
{
   int  fh;

   if( _sopen_s( &fh, "NOSUCHF.ILE", _O_RDONLY, _SH_DENYNO, 0 ) != 0 )
   {
      /* Three ways to create error message: */
      perror( "perror says open failed" );
      printf( "strerror says open failed: %s\n",
         strerror( errno ) ); // C4996
      printf( _strerror( "_strerror says open failed" ) ); // C4996
      // Note: strerror and _strerror are deprecated; consider
      // using strerror_s and _strerror_s instead.
   }
   else
   {
      printf( "open succeeded on input file\n" );
      _close( fh );
   }
}
```

```Output
perror says open failed: No such file or directory
strerror says open failed: No such file or directory
_strerror says open failed: No such file or directory
```

## <a name="see-also"></a>Consulte também

[Controle de processo e de ambiente](../../c-runtime-library/process-and-environment-control.md)<br/>
[clearerr](clearerr.md)<br/>
[ferror](ferror.md)<br/>
[strerror, _strerror, _wcserror, \__wcserror](strerror-strerror-wcserror-wcserror.md)<br/>
