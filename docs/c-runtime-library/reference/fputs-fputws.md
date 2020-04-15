---
title: fputs, fputws
ms.date: 4/2/2020
api_name:
- fputs
- fputws
- _o_fputs
- _o_fputws
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
- fputs
- fputws
- _fputts
helpviewer_keywords:
- streams, writing strings to
- fputws function
- _fputts function
- fputs function
- fputts function
ms.assetid: d48c82b8-aa17-4830-8c7d-30442ddbb326
ms.openlocfilehash: 0a6ac7770e88975a60e1e4aef522dddf901206fb
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81346213"
---
# <a name="fputs-fputws"></a>fputs, fputws

Grava uma cadeia de caracteres em um fluxo.

## <a name="syntax"></a>Sintaxe

```C
int fputs(
   const char *str,
   FILE *stream
);
int fputws(
   const wchar_t *str,
   FILE *stream
);
```

### <a name="parameters"></a>Parâmetros

*Str*<br/>
Cadeia de caracteres de saída.

*fluxo*<br/>
Ponteiro para a estrutura **FILE**.

## <a name="return-value"></a>Valor retornado

Cada uma dessas funções retornará um valor não negativo se for bem-sucedida. Em um erro, **fputs** e **fputws** retornam **EOF**. Se *str* ou *fluxo* for um ponteiro nulo, essas funções invocam o manipulador de parâmetros inválidos, conforme descrito na Validação [de Parâmetros](../../c-runtime-library/parameter-validation.md). Se a execução for permitida, essas funções definem **errno** para **EINVAL** e, em seguida, **fputs** retorna **EOF**, e **fputws** retorna **WEOF**.

Consulte [_doserrno, errno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md) para obter mais informações sobre esses e outros códigos de erro.

## <a name="remarks"></a>Comentários

Cada uma dessas funções copia *str* para o *fluxo* de saída na posição atual. **fputws** copia o *str* de argumento de caractere amplo para *transmitir* como uma seqüência de caracteres de vários bytes ou uma seqüência de caracteres amplos de acordo com se *o fluxo* é aberto no modo texto ou no modo binário, respectivamente. Nenhuma função copia o caractere nulo de terminação.

As duas funções terão comportamento idêntico se o fluxo for aberto no modo ANSI. **Os fputs** não suportam atualmente a saída em um fluxo UNICODE.

Por padrão, o estado global desta função é escopo para o aplicativo. Para mudar isso, consulte [Estado Global no CRT](../global-state.md).

### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico

|Rotina TCHAR.H|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|
|---------------------|------------------------------------|--------------------|-----------------------|
|**_fputts**|**fputs**|**fputs**|**fputws**|

## <a name="requirements"></a>Requisitos

|Função|Cabeçalho necessário|
|--------------|---------------------|
|**fputs**|\<stdio.h>|
|**fputws**|\<stdio.h> ou \<wchar.h>|

O console não é suportado em aplicativos Universal Windows Platform (UWP). As alças de fluxo padrão associadas ao console,**stdin,** **stdout**e **stderr,** devem ser redirecionadas antes que as funções de tempo de execução C possam usá-las em aplicativos UWP. Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

```C
// crt_fputs.c
// This program uses fputs to write
// a single line to the stdout stream.

#include <stdio.h>

int main( void )
{
   fputs( "Hello world from fputs.\n", stdout );
}
```

```Output
Hello world from fputs.
```

## <a name="see-also"></a>Confira também

[E/S de fluxo](../../c-runtime-library/stream-i-o.md)<br/>
[fgets, fgetws](fgets-fgetws.md)<br/>
[fica, _getws](../../c-runtime-library/gets-getws.md)<br/>
[puts, _putws](puts-putws.md)<br/>
