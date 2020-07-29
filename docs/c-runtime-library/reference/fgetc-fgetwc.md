---
title: fgetc, fgetwc
ms.date: 4/2/2020
api_name:
- fgetwc
- fgetc
- _o_fgetc
- _o_fgetwc
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
- _fgettc
- fgetwc
- fgetc
helpviewer_keywords:
- fgettc function
- characters, reading
- _fgettc function
- fgetc function
- streams, reading characters from
- reading characters from streams
- fgetwc function
ms.assetid: 13348b7b-dc86-421c-9d6c-611ca79c8338
ms.openlocfilehash: 5f8d4b1fcdc2d4d4de712ee79742025db74b6452
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87189279"
---
# <a name="fgetc-fgetwc"></a>fgetc, fgetwc

Lê um caractere de um fluxo.

## <a name="syntax"></a>Sintaxe

```C
int fgetc(
   FILE *stream
);
wint_t fgetwc(
   FILE *stream
);
```

### <a name="parameters"></a>parâmetros

*fluxo*<br/>
Ponteiro para a estrutura **FILE**.

## <a name="return-value"></a>Valor retornado

**fgetc** retorna o caractere lido como um **`int`** ou retorna **EOF** para indicar um erro ou fim de arquivo. **fgetwc** retorna, como um [wint_t](../../c-runtime-library/standard-types.md), o caractere largo que corresponde ao caractere lido ou retorna **WEOF** para indicar um erro ou fim de arquivo. Para ambas as funções, use **feof** ou **referenciador** para distinguir entre um erro e uma condição de fim de arquivo. Se ocorrer um erro de leitura, o indicador de erro para o fluxo será definido. Se *Stream* for **NULL**, **fgetc** e **fgetwc** invocarão o manipulador de parâmetro inválido, conforme descrito em [validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução tiver permissão para continuar, essas funções definem **errno** como **EINVAL** e retornam **EOF**.

## <a name="remarks"></a>Comentários

Cada uma dessas funções lê um único caractere da posição atual do arquivo associado ao *fluxo*. A função, em seguida, incrementa o ponteiro de arquivo associado (se definido) para apontar para o próximo caractere. Se o fluxo estiver no fim do arquivo, o indicador de fim de arquivo para o fluxo será definido.

**fgetc** é equivalente a **getc**, mas é implementado somente como uma função, em vez de como uma função e uma macro.

**fgetwc** é a versão de caractere largo do **fgetc**; Ele lê **c** como um caractere multibyte ou um caractere largo de acordo com se o *fluxo* é aberto no modo de texto ou no modo binário.

As versões com o sufixo **_nolock** são idênticas, exceto pelo fato de não serem protegidas contra interferência de outros threads.

Para obter mais informações sobre como processar caracteres largos e caracteres multibyte em modos de texto e binários, consulte [E/S de fluxo de Unicode em modos de texto e binário](../../c-runtime-library/unicode-stream-i-o-in-text-and-binary-modes.md).

Por padrão, o estado global dessa função tem como escopo o aplicativo. Para alterar isso, consulte [estado global no CRT](../global-state.md).

### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico

|Rotina TCHAR.H|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|
|---------------------|------------------------------------|--------------------|-----------------------|
|**_fgettc**|**fgetc**|**fgetc**|**fgetwc**|

## <a name="requirements"></a>Requisitos

|Função|Cabeçalho necessário|
|--------------|---------------------|
|**fgetc**|\<stdio.h>|
|**fgetwc**|\<stdio.h> ou \<wchar.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

```C
// crt_fgetc.c
// This program uses getc to read the first
// 80 input characters (or until the end of input)
// and place them into a string named buffer.

#include <stdio.h>
#include <stdlib.h>

int main( void )
{
   FILE *stream;
   char buffer[81];
   int  i, ch;

   // Open file to read line from:
   fopen_s( &stream, "crt_fgetc.txt", "r" );
   if( stream == NULL )
      exit( 0 );

   // Read in first 80 characters and place them in "buffer":
   ch = fgetc( stream );
   for( i=0; (i < 80 ) && ( feof( stream ) == 0 ); i++ )
   {
      buffer[i] = (char)ch;
      ch = fgetc( stream );
   }

   // Add null to end string
   buffer[i] = '\0';
   printf( "%s\n", buffer );
   fclose( stream );
}
```

## <a name="input-crt_fgetctxt"></a>Entrada: crt_fgetc.txt

```Input
Line one.
Line two.
```

### <a name="output"></a>Saída

```Output
Line one.
Line two.
```

## <a name="see-also"></a>Confira também

[E/S de fluxo](../../c-runtime-library/stream-i-o.md)<br/>
[fputc, fputwc](fputc-fputwc.md)<br/>
[getc, getwc](getc-getwc.md)<br/>
