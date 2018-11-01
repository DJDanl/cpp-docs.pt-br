---
title: clearerr
ms.date: 11/04/2016
apiname:
- clearerr
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
- api-ms-win-crt-stdio-l1-1-0.dll
apitype: DLLExport
f1_keywords:
- clearerr
helpviewer_keywords:
- error indicator for streams
- resetting stream error indicator
- clearerr function
ms.assetid: a9711cd4-3335-43d4-a018-87bbac5b3bac
ms.openlocfilehash: 2e2bf43946f8f306ce120cb48998b84c5ae09bf1
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50646323"
---
# <a name="clearerr"></a>clearerr

Redefine o indicador de erro para um fluxo. Uma versão mais segura dessa função está disponível. Consulte [clearerr_s](clearerr-s.md).

## <a name="syntax"></a>Sintaxe

```C
void clearerr(
   FILE *stream
);
```

### <a name="parameters"></a>Parâmetros

*fluxo*<br/>
Ponteiro para a estrutura **FILE**.

## <a name="remarks"></a>Comentários

O **clearerr** função redefine o indicador de erro e o indicador de fim-de-arquivo para *fluxo*. Indicadores de erro não são removidos automaticamente; Depois que o indicador de erro para um fluxo especificado é definido, as operações naquele fluxo continuam a retornar um valor de erro até **clearerr**, [fseek](fseek-fseeki64.md), **fsetpos**, ou [rewind](rewind.md) é chamado.

Se *stream* é **nulo**, o manipulador de parâmetro inválido será invocado, conforme descrito na [validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução puder continuar, essa função definirá **errno** à **EINVAL** e retorna. Para obter mais informações sobre **errno** e códigos de erro, consulte [constantes errno](../../c-runtime-library/errno-constants.md).

Uma versão mais segura dessa função está disponível. Consulte [clearerr_s](clearerr-s.md).

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**clearerr**|\<stdio.h>|

Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

```C
// crt_clearerr.c
// This program creates an error
// on the standard input stream, then clears
// it so that future reads won't fail.

#include <stdio.h>

int main( void )
{
   int c;
   // Create an error by writing to standard input.
   putc( 'c', stdin );
   if( ferror( stdin ) )
   {
      perror( "Write error" );
      clearerr( stdin );
   }

   // See if read causes an error.
   printf( "Will input cause an error? " );
   c = getc( stdin );
   if( ferror( stdin ) )
   {
      perror( "Read error" );
      clearerr( stdin );
   }
   else
      printf( "No read error\n" );
}
```

```Output

n

```

```Output

      nWrite error: No error
Will input cause an error? n
No read error
```

## <a name="see-also"></a>Consulte também

[Tratamento de erro](../../c-runtime-library/error-handling-crt.md)<br/>
[E/S de fluxo](../../c-runtime-library/stream-i-o.md)<br/>
[_eof](eof.md)<br/>
[feof](feof.md)<br/>
[ferror](ferror.md)<br/>
[perror, _wperror](perror-wperror.md)<br/>
