---
title: putc, putwc
ms.date: 4/2/2020
api_name:
- putwc
- putc
- _o_putc
- _o_putwc
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
- _puttc
- putwc
- putc
helpviewer_keywords:
- streams, writing characters to
- characters, writing
- putwc function
- putc function
- _puttc function
- puttc function
ms.assetid: a37b2e82-9d88-4565-8190-ff8d04c0ddb9
ms.openlocfilehash: 8809595c90c48976d9f28ffa659714f5b9d919c9
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81338454"
---
# <a name="putc-putwc"></a>putc, putwc

Grava um caractere em um fluxo.

## <a name="syntax"></a>Sintaxe

```C
int putc(
   int c,
   FILE *stream
);
wint_t putwc(
   wchar_t c,
   FILE *stream
);
```

### <a name="parameters"></a>Parâmetros

*C*<br/>
O caractere a ser gravado.

*fluxo*<br/>
Ponteiro para a estrutura **FILE**.

## <a name="return-value"></a>Valor retornado

Retorna o caractere gravado. Para indicar uma condição de erro ou fim do arquivo, **putc** e **putchar** retornam **EOF**; **putwc** e **putwchar** retorno **WEOF**. Para todas as quatro rotinas, use [ferror](ferror.md) ou [feof](feof.md) para verificar se há um erro ou o fim do arquivo. Se passar um ponteiro nulo para *fluxo,* o manipulador de parâmetros inválidos é invocado, conforme descrito na [Validação de Parâmetros](../../c-runtime-library/parameter-validation.md). Se a execução for permitida, essas funções retornam **EOF** ou **WEOF** e definem **errno** para **EINVAL**.

Consulte [_doserrno, errno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md) para obter mais informações sobre esses e outros códigos de erro.

## <a name="remarks"></a>Comentários

A rotina **putc** escreve o caractere *único c* para o *fluxo* de saída na posição atual. Qualquer inteiro pode ser passado para **putc,** mas apenas os 8 bits inferiores são escritos. A rotina **de putchar** é idêntica a `putc( c, stdout )`. Para cada rotina, se ocorrer um erro de leitura, o indicador de erro para o fluxo será definido. **putc** e **putchar** são semelhantes aos **fputc** e **_fputchar,** respectivamente, mas são implementados tanto como funções quanto como macros (ver [Escolhendo Entre Funções e Macros](../../c-runtime-library/recommendations-for-choosing-between-functions-and-macros.md)). **putwc** e **putwchar** são versões de grande caráter de **putc** e **putchar,** respectivamente. **putwc** e **putc** se comportam de forma idêntica se o fluxo for aberto no modo ANSI. **putc** não suporta atualmente a saída em um fluxo UNICODE.

As versões com o sufixo **_nolock** são idênticas, exceto pelo fato de não serem protegidas contra interferência de outros threads. Para obter mais informações, consulte **_putc_nolock, _putwc_nolock**.

Por padrão, o estado global desta função é escopo para o aplicativo. Para mudar isso, consulte [Estado Global no CRT](../global-state.md).

### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico

|Rotina TCHAR.H|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|
|---------------------|------------------------------------|--------------------|-----------------------|
|**_puttc**|**putc**|**putc**|**putwc**|

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**putc**|\<stdio.h>|
|**putwc**|\<stdio.h> ou \<wchar.h>|

O console não é suportado em aplicativos Universal Windows Platform (UWP). As alças de fluxo padrão associadas ao console, **stdin**, **stdout**e **stderr,** devem ser redirecionadas antes que as funções de tempo de execução C possam usá-las em aplicativos UWP. Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="libraries"></a>Bibliotecas

Todas as versões das [bibliotecas em tempo de execução C](../../c-runtime-library/crt-library-features.md).

## <a name="example"></a>Exemplo

```C
// crt_putc.c
/* This program uses putc to write buffer
* to a stream. If an error occurs, the program
* stops before writing the entire buffer.
*/

#include <stdio.h>

int main( void )
{
   FILE *stream;
   char *p, buffer[] = "This is the line of output\n";
   int  ch;

   ch = 0;
   /* Make standard out the stream and write to it. */
   stream = stdout;
   for( p = buffer; (ch != EOF) && (*p != '\0'); p++ )
      ch = putc( *p, stream );
}
```

### <a name="output"></a>Saída

```Output
This is the line of output
```

## <a name="see-also"></a>Confira também

[E/S de fluxo](../../c-runtime-library/stream-i-o.md)<br/>
[fputc, fputwc](fputc-fputwc.md)<br/>
[getc, getwc](getc-getwc.md)<br/>
