---
title: _putc_nolock, _putwc_nolock
ms.date: 4/2/2020
api_name:
- _putc_nolock
- _putwc_nolock
- _o__putc_nolock
- _o__putwc_nolock
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
- _puttc_nolock
- puttc_nolock
- putwc_nolock
- _putwc_nolock
- _putc_nolock
- putc_nolock
helpviewer_keywords:
- puttc_nolock function
- putc_nolock function
- _putc_nolock function
- streams, writing characters to
- characters, writing
- putwc_nolock function
- _puttc_nolock function
- _putwc_nolock function
ms.assetid: 3cfc7f21-c9e8-4b7f-b0fb-af0d4d85e7e1
ms.openlocfilehash: 21ab002dee736a099bae5ce12f5c78248e682d58
ms.sourcegitcommit: 5a069c7360f75b7c1cf9d4550446ec2fa2eb2293
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2020
ms.locfileid: "82913316"
---
# <a name="_putc_nolock-_putwc_nolock"></a>_putc_nolock, _putwc_nolock

Grava um caractere em um fluxo sem bloquear o thread.

## <a name="syntax"></a>Sintaxe

```C
int _putc_nolock(
   int c,
   FILE *stream
);
wint_t _putwc_nolock(
   wchar_t c,
   FILE *stream
);
```

### <a name="parameters"></a>Parâmetros

*&*<br/>
O caractere a ser gravado.

*fluxo*<br/>
Ponteiro para a estrutura **FILE**.

## <a name="return-value"></a>Valor retornado

Consulte **putc, putwc**.

## <a name="remarks"></a>Comentários

**_putc_nolock** e **_putwc_nolock** são idênticas às versões sem o sufixo **_nolock** , exceto que não estão protegidas contra interferência por outros threads. Elas podem ser mais rápidas, porque não incorrem na sobrecarga de bloquear outros threads. Use estas funções apenas em contextos thread-safe, como aplicativos de thread único ou em que o escopo de chamada já trata do isolamento de threads.

**_putwc_nolock** é a versão de caractere largo do **_putc_nolock**; as duas funções se comportam de forma idêntica se o fluxo é aberto no modo ANSI. no momento, o **_putc_nolock** não dá suporte à saída em um fluxo Unicode.

Por padrão, o estado global dessa função tem como escopo o aplicativo. Para alterar isso, consulte [estado global no CRT](../global-state.md).

### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico

|Rotina Tchar.h|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|
|---------------------|--------------------------------------|--------------------|-----------------------|
|**_puttc_nolock**|**_putc_nolock**|**_putc_nolock**|**_putwc_nolock**|

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**_putc_nolock**|\<stdio.h>|
|**_putwc_nolock**|\<stdio.h> ou \<wchar.h>|

Não há suporte para o console em aplicativos Plataforma Universal do Windows (UWP). Os identificadores de fluxo padrão associados ao console, **stdin**, **stdout**e **stderr**devem ser redirecionados antes que as funções de tempo de execução do C possam usá-los em aplicativos UWP. Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="libraries"></a>Bibliotecas

Todas as versões das [bibliotecas em tempo de execução C](../../c-runtime-library/crt-library-features.md).

## <a name="example"></a>Exemplo

```C
// crt_putc_nolock.c
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
      ch = _putc_nolock( *p, stream );
}
```

### <a name="output"></a>Saída

```Output
This is the line of output
```

## <a name="see-also"></a>Consulte também

[E/S de fluxo](../../c-runtime-library/stream-i-o.md)<br/>
[fputc, fputwc](fputc-fputwc.md)<br/>
[getc, getwc](getc-getwc.md)<br/>
