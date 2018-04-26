---
title: fputc, fputwc | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.reviewer: ''
ms.suite: ''
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: ''
ms.topic: reference
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
dev_langs:
- C++
helpviewer_keywords:
- streams, writing characters to
- fputtc function
- _fputtc function
- fputwc function
- fputc function
ms.assetid: 5a0a593d-43f4-4fa2-a401-ec4e23de4d2f
caps.latest.revision: 20
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 707c6d7fa2e45a4fb0c841015f59ef786e539168
ms.sourcegitcommit: ef859ddf5afea903711e36bfd89a72389a12a8d6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/20/2018
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

*Fluxo*<br/>
Ponteiro para a estrutura **FILE**.

## <a name="return-value"></a>Valor de retorno

Cada uma dessas funções retorna o caractere gravado. Para **fputc**, um valor de retorno **EOF** indica um erro. Para **fputwc**, um valor de retorno **WEOF** indica um erro. Se *fluxo* é **nulo**, essas funções invocam o manipulador de parâmetro inválido, conforme descrito em [validação do parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução é permitida para continuar, retorne **EOF** e defina **errno** para **EINVAL**.

Consulte [_doserrno, errno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md) para obter mais informações sobre esses e outros códigos de erro.

## <a name="remarks"></a>Comentários

Cada uma dessas funções grava o único caractere *c* em um arquivo na posição indicada pelo indicador de posição de arquivo associado (se definido) e avança o indicador conforme apropriado. No caso de **fputc** e **fputwc**, o arquivo está associado *fluxo*. Se o arquivo não puder dar suporte a solicitações de posicionamento ou tiver sido aberto no modo de acréscimo, o caractere será acrescentado ao final do fluxo.

As duas funções terão comportamento idêntico se o fluxo for aberto no modo ANSI. **fputc** não oferece suporte a saída em um fluxo UNICODE.

As versões com o sufixo **_nolock** são idênticas, exceto pelo fato de não serem protegidas contra interferência de outros threads. Para obter mais informações, consulte [_fputc_nolock, _fputwc_nolock](fputc-nolock-fputwc-nolock.md).

Veja comentários específicos sobre a rotina a seguir.

|Rotina|Comentários|
|-------------|-------------|
|**fputc**|Equivalente a **putc**, mas implementado apenas como uma função, em vez de como uma função e uma macro.|
|**fputwc**|Versão de caractere largo de **fputc**. Grava *c* como um caractere multibyte ou um caractere largo de acordo com se *fluxo* é aberto em modo de texto ou binário.|

### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico

|Rotina TCHAR.H|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|
|---------------------|------------------------------------|--------------------|-----------------------|
|**fputtc**|**fputc**|**fputc**|**fputwc**|

## <a name="requirements"></a>Requisitos

|Função|Cabeçalho necessário|
|--------------|---------------------|
|**fputc**|\<stdio.h>|
|**fputwc**|\<stdio.h> ou \<wchar.h>|

Não há suporte para o console em aplicativos do Windows UWP (plataforma Universal). Os identificadores de fluxo padrão que estão associados com o console —**stdin**, **stdout**, e **stderr**— deverá ser redirecionado para funções de tempo de execução C podem usá-los em aplicativos UWP . Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

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
