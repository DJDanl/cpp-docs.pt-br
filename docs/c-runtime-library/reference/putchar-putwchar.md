---
title: putchar, putwchar | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-standard-libraries
ms.topic: reference
apiname:
- putchar
- putwchar
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
- putchar
- putwchar
- _puttchar
dev_langs:
- C++
helpviewer_keywords:
- putchar function
- _puttchar function
- characters, writing
- standard output, writing to
- putwchar function
ms.assetid: 93657c7f-cca1-4032-8e3a-cd6ab6193748
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 7602ca44d6f8ec8197d1ebc61b4ef1d0847133f6
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32404617"
---
# <a name="putchar-putwchar"></a>putchar, putwchar

Grava um caractere em **stdout**.

## <a name="syntax"></a>Sintaxe

```C
int putchar(
   int c
);
wint_t putwchar(
   wchar_t c
);
```

### <a name="parameters"></a>Parâmetros

*c*<br/>
O caractere a ser gravado.

## <a name="return-value"></a>Valor de retorno

Retorna o caractere gravado. Para indicar um erro ou condição de fim de arquivo, **putc** e **putchar** retornar * * EOF`; **putwc` e **putwchar** retornar **WEOF**. Para todas as quatro rotinas, use [ferror](ferror.md) ou [feof](feof.md) para verificar se há um erro ou o fim do arquivo. Se passado um ponteiro nulo para *fluxo*, essas funções para gerar uma exceção de parâmetro inválido, conforme descrito em [validação do parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução é permitida para continuar, retorne **EOF** ou **WEOF** e defina **errno** para **EINVAL**.

Consulte [_doserrno, errno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md) para obter mais informações sobre esses e outros códigos de erro.

## <a name="remarks"></a>Comentários

O **putc** rotina grava o único caractere *c* para a saída *fluxo* na posição atual. Qualquer inteiro pode ser passado para **putc**, mas somente os 8 bits inferiores são gravados. O **putchar** rotina é idêntica ao **putc (** * c ***, stdout)**. Para cada rotina, se ocorrer um erro de leitura, o indicador de erro para o fluxo será definido. **putc** e **putchar** são semelhantes às **fputc** e **fputchar**, respectivamente, mas são implementados como funções e macros (consulte [ Escolher entre funções e Macros](../../c-runtime-library/recommendations-for-choosing-between-functions-and-macros.md)). **putwc** e **putwchar** são versões de caractere largo de **putc** e **putchar**, respectivamente.

As versões com o sufixo **_nolock** são idênticas, exceto pelo fato de não serem protegidas contra interferência de outros threads. Elas pode ser mais rápidas, pois não incorrem na sobrecarga de bloquear outros threads. Use estas funções apenas em contextos thread-safe, como aplicativos de thread único ou em que o escopo de chamada já trata do isolamento de threads.

### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico

|Rotina TCHAR.H|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|
|---------------------|------------------------------------|--------------------|-----------------------|
|**puttchar**|**putchar**|**putchar**|**putwchar**|

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**putchar**|\<stdio.h>|
|**putwchar**|\<stdio.h> ou \<wchar.h>|

Não há suporte para o console em aplicativos do Windows UWP (plataforma Universal). Os identificadores de fluxo padrão que estão associados com o console, **stdin**, **stdout**, e **stderr**, deverá ser redirecionado para funções de tempo de execução C podem usá-los em aplicativos UWP . Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="libraries"></a>Libraries

Todas as versões das [bibliotecas em tempo de execução C](../../c-runtime-library/crt-library-features.md).

## <a name="example"></a>Exemplo

```C
// crt_putchar.c
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

   for( p = buffer; (ch != EOF) && (*p != '\0'); p++ )
      ch = putchar( *p );
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
