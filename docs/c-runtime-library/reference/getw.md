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
- api-ms-win-crt-private-l1-1-0.dll
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
ms.openlocfilehash: 786246afbb8ce4f733f733af75af3a70ce33006d
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87226210"
---
# <a name="_getw"></a>_getw

Obtém um inteiro de um fluxo.

## <a name="syntax"></a>Sintaxe

```C
int _getw(
   FILE *stream
);
```

### <a name="parameters"></a>parâmetros

*fluxo*<br/>
Ponteiro para a estrutura **FILE**.

## <a name="return-value"></a>Valor retornado

**_getw** retorna o valor inteiro lido. Um valor de retorno de **EOF** indica um erro ou um fim de arquivo. No entanto, como o valor de **EOF** também é um valor inteiro legítimo, use **feof** ou **referenciador** para verificar uma condição de fim de arquivo ou de erro. Se o *fluxo* for **nulo**, o manipulador de parâmetro inválido será invocado, conforme descrito em [validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução puder continuar, **errno** será definido como **EINVAL** e a função retornará **EOF**.

## <a name="remarks"></a>Comentários

A função **_getw** lê o próximo valor binário do tipo **`int`** a partir do arquivo associado ao *fluxo* e incrementa o ponteiro de arquivo associado (se houver) para apontar para o próximo caractere não lido. **_getw** não assume nenhum alinhamento especial de itens no fluxo. Problemas com portabilidade podem ocorrer com **_getw** porque o tamanho do **`int`** tipo e a ordenação de bytes dentro do **`int`** tipo diferem entre sistemas.

Por padrão, o estado global dessa função tem como escopo o aplicativo. Para alterar isso, consulte [estado global no CRT](../global-state.md).

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
