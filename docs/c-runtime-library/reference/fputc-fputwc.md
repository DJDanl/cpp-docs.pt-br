---
title: fputc, fputwc
ms.date: 4/2/2020
api_name:
- fputc
- fputwc
- _o_fputc
- _o_fputwc
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
- fputc
- fputwc
- _fputtc
helpviewer_keywords:
- streams, writing characters to
- fputtc function
- _fputtc function
- fputwc function
- fputc function
ms.assetid: 5a0a593d-43f4-4fa2-a401-ec4e23de4d2f
ms.openlocfilehash: 289e1114a936bdaa41fc59a0526db006536461f7
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81346265"
---
# <a name="fputc-fputwc"></a>fputc, fputwc

Grava um caractere em um fluxo.

## <a name="syntax"></a>Sintaxe

```C
int fputc(
   int c,
   FILE *stream
);
wint_t fputwc(
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

Cada uma dessas funções retorna o caractere gravado. Para **fputc,** um valor de retorno do **EOF** indica um erro. Para **fputwc,** um valor de retorno do **WEOF** indica um erro. Se *o fluxo* for **NULO,** essas funções invocam o manipulador de parâmetros inválidos, conforme descrito na [Validação de Parâmetros](../../c-runtime-library/parameter-validation.md). Se a execução for permitida, eles retornam **eOF** e definem **errno** ao **EINVAL**.

Consulte [_doserrno, errno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md) para obter mais informações sobre esses e outros códigos de erro.

## <a name="remarks"></a>Comentários

Cada uma dessas funções grava o caractere *único c* para um arquivo na posição indicada pelo indicador de posição do arquivo associado (se definido) e avança o indicador conforme apropriado. No caso de **fputc** e **fputwc,** o arquivo está associado ao *fluxo*. Se o arquivo não puder dar suporte a solicitações de posicionamento ou tiver sido aberto no modo de acréscimo, o caractere será acrescentado ao final do fluxo.

As duas funções terão comportamento idêntico se o fluxo for aberto no modo ANSI. **Fputc** não suporta atualmente a saída em um fluxo UNICODE.

As versões com o sufixo **_nolock** são idênticas, exceto pelo fato de não serem protegidas contra interferência de outros threads. Para obter mais informações, consulte [_fputc_nolock, _fputwc_nolock](fputc-nolock-fputwc-nolock.md).

Veja comentários específicos sobre a rotina a seguir.

|Rotina|Comentários|
|-------------|-------------|
|**fputc**|Equivalente a **putc,** mas implementado apenas como uma função, e não como uma função e uma macro.|
|**fputwc**|Versão de amplo caráter de **fputc**. Escreve *c* como um caractere multibyte ou um caractere amplo de acordo com se *o fluxo* é aberto no modo texto ou no modo binário.|

Por padrão, o estado global desta função é escopo para o aplicativo. Para mudar isso, consulte [Estado Global no CRT](../global-state.md).

### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico

|Rotina TCHAR.H|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|
|---------------------|------------------------------------|--------------------|-----------------------|
|**_fputtc**|**fputc**|**fputc**|**fputwc**|

## <a name="requirements"></a>Requisitos

|Função|Cabeçalho necessário|
|--------------|---------------------|
|**fputc**|\<stdio.h>|
|**fputwc**|\<stdio.h> ou \<wchar.h>|

O console não é suportado em aplicativos Universal Windows Platform (UWP). As alças de fluxo padrão associadas ao console,**stdin,** **stdout**e **stderr,** devem ser redirecionadas antes que as funções de tempo de execução C possam usá-las em aplicativos UWP. Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

```C
// crt_fputc.c
// This program uses fputc
// to send a character array to stdout.

#include <stdio.h>

int main( void )
{
   char strptr1[] = "This is a test of fputc!!\n";
   char *p;

   // Print line to stream using fputc.
   p = strptr1;
   while( (*p != '\0') && fputc( *(p++), stdout ) != EOF ) ;

}
```

```Output
This is a test of fputc!!
```

## <a name="see-also"></a>Confira também

[E/S de fluxo](../../c-runtime-library/stream-i-o.md)<br/>
[fgetc, fgetwc](fgetc-fgetwc.md)<br/>
[putc, putwc](putc-putwc.md)<br/>
