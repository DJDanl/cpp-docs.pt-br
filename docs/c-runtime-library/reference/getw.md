---
title: _getw
ms.date: 4/2/2020
api_name:
- _getw
- _o__getw
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
- api-ms-win-crt-stdio-l1-1-0.dll
- api-ms-win-crt-private-l1-1-0
api_type:
- DLLExport
topic_type:
- apiref
f1_keywords:
- _getw
helpviewer_keywords:
- _getw function
- integers, getting from streams
- getw function
ms.assetid: ef75facc-b84e-470f-9f5f-8746c90822a0
ms.openlocfilehash: eddb68ae6108c8a66966472cebca60a9969b78d1
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81344159"
---
# <a name="_getw"></a>_getw

Obtém um inteiro de um fluxo.

## <a name="syntax"></a>Sintaxe

```C
int _getw(
   FILE *stream
);
```

### <a name="parameters"></a>Parâmetros

*fluxo*<br/>
Ponteiro para a estrutura **FILE**.

## <a name="return-value"></a>Valor retornado

**_getw** retorna o valor inteiro lido. Um valor de retorno do **EOF** indica um erro ou o fim do arquivo. No entanto, como o valor **EOF** também é um valor inteiro legítimo, use **feof** ou **ferror** para verificar uma condição de fim de arquivo ou erro. Se *o fluxo* for **NULO,** o manipulador de parâmetros inválidos é invocado, conforme descrito na [Validação de Parâmetros](../../c-runtime-library/parameter-validation.md). Se a execução continuar, **errno** será definido **como EINVAL** e a função retorna **EOF**.

## <a name="remarks"></a>Comentários

A função **_getw** lê o próximo valor binário do tipo **int** a partir do arquivo associado ao *fluxo* e incrementa o ponteiro de arquivo associado (se houver um) para apontar para o próximo caractere não lido. **_getw** não assume nenhum alinhamento especial de itens no fluxo. Problemas com a portação podem ocorrer com **_getw** porque o tamanho do tipo **int** e a ordem de bytes dentro do tipo **int** diferem entre os sistemas.

Por padrão, o estado global desta função é escopo para o aplicativo. Para mudar isso, consulte [Estado Global no CRT](../global-state.md).

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**_getw**|\<stdio.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

```C
// crt_getw.c
// This program uses _getw to read a word
// from a stream, then performs an error check.

#include <stdio.h>
#include <stdlib.h>

int main( void )
{
   FILE *stream;
   int i;

   if( fopen_s( &stream, "crt_getw.txt", "rb" ) )
      printf( "Couldn't open file\n" );
   else
   {
      // Read a word from the stream:
      i = _getw( stream );

      // If there is an error...
      if( ferror( stream ) )
      {
         printf( "_getw failed\n" );
         clearerr_s( stream );
      }
      else
         printf( "First data word in file: 0x%.4x\n", i );
      fclose( stream );
   }
}
```

### <a name="input-crt_getwtxt"></a>Entrada: crt_getw.txt

```Input
Line one.
Line two.
```

### <a name="output"></a>Saída

```Output
First data word in file: 0x656e694c
```

## <a name="see-also"></a>Confira também

[E/S de fluxo](../../c-runtime-library/stream-i-o.md)<br/>
[_putw](putw.md)<br/>
