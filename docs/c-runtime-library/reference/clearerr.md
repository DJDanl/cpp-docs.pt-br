---
title: clearerr | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.reviewer: ''
ms.suite: ''
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: ''
ms.topic: reference
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
dev_langs:
- C++
helpviewer_keywords:
- error indicator for streams
- resetting stream error indicator
- clearerr function
ms.assetid: a9711cd4-3335-43d4-a018-87bbac5b3bac
caps.latest.revision: 21
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 8fbca4b6e6083cb22bc559b7bad7e75b00b8885c
ms.sourcegitcommit: ef859ddf5afea903711e36bfd89a72389a12a8d6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/20/2018
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

*fluxo* ponteiro para **arquivo** estrutura.

## <a name="remarks"></a>Comentários

O **clearerr** função redefine o indicador de erro e o indicador de fim de arquivo para *fluxo*. Indicadores de erro não são limpos automaticamente; Quando o indicador de erro para um fluxo especificado estiver definido, as operações no fluxo continuar retornar um valor de erro até **clearerr**, [fseek](fseek-fseeki64.md), **fsetpos**, ou [retroceder](rewind.md) é chamado.

Se *fluxo* é **nulo**, o manipulador de parâmetro inválido é invocado, conforme descrito em [validação do parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução é permitida para continuar, esta função define **errno** para **EINVAL** e retorna. Para obter mais informações sobre **errno** e códigos de erro, consulte [constantes errno](../../c-runtime-library/errno-constants.md).

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
