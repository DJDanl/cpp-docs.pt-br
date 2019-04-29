---
title: fputc, fputwc
ms.date: 11/04/2016
apiname:
- fputc
- fputwc
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
ms.openlocfilehash: fc06c9f2060baae63071339768cef11fc5f34023
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62288013"
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

*c*<br/>
O caractere a ser gravado.

*stream*<br/>
Ponteiro para a estrutura **FILE**.

## <a name="return-value"></a>Valor de retorno

Cada uma dessas funções retorna o caractere gravado. Para **fputc**, um valor de retorno **EOF** indica um erro. Para **fputwc**, um valor de retorno **WEOF** indica um erro. Se *stream* é **nulo**, essas funções invocarão o manipulador de parâmetro inválido, conforme descrito na [validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução puder continuar, eles retornam **EOF** e defina **errno** para **EINVAL**.

Consulte [_doserrno, errno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md) para obter mais informações sobre esses e outros códigos de erro.

## <a name="remarks"></a>Comentários

Cada uma dessas funções grava o único caractere *c* em um arquivo na posição indicada pelo indicador de posição de arquivo associado (se definido) e avança o indicador conforme apropriado. No caso de **fputc** e **fputwc**, o arquivo está associado *fluxo*. Se o arquivo não puder dar suporte a solicitações de posicionamento ou tiver sido aberto no modo de acréscimo, o caractere será acrescentado ao final do fluxo.

As duas funções terão comportamento idêntico se o fluxo for aberto no modo ANSI. **fputc** não oferece suporte a saída em um fluxo UNICODE.

As versões com o sufixo **_nolock** são idênticas, exceto pelo fato de não serem protegidas contra interferência de outros threads. Para obter mais informações, consulte [_fputc_nolock, _fputwc_nolock](fputc-nolock-fputwc-nolock.md).

Veja comentários específicos sobre a rotina a seguir.

|Rotina|Comentários|
|-------------|-------------|
|**fputc**|Equivalente a **putc**, mas implementado somente como uma função, em vez de uma função e uma macro.|
|**fputwc**|Versão de caractere largo de **fputc**. Grava *c* como um caractere multibyte ou um caractere largo se *fluxo* é aberto no modo de texto ou binário.|

### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico

|Rotina TCHAR.H|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|
|---------------------|------------------------------------|--------------------|-----------------------|
|**_fputtc**|**fputc**|**fputc**|**fputwc**|

## <a name="requirements"></a>Requisitos

|Função|Cabeçalho necessário|
|--------------|---------------------|
|**fputc**|\<stdio.h>|
|**fputwc**|\<stdio.h> ou \<wchar.h>|

Não há suporte para o console em aplicativos da plataforma Universal do Windows (UWP). Os identificadores de fluxo padrão que estão associados com o console —**stdin**, **stdout**, e **stderr**— deverá ser redirecionado para funções de tempo de execução C possam ser usados em aplicativos UWP . Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

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

## <a name="see-also"></a>Consulte também

[E/S de fluxo](../../c-runtime-library/stream-i-o.md)<br/>
[fgetc, fgetwc](fgetc-fgetwc.md)<br/>
[putc, putwc](putc-putwc.md)<br/>
