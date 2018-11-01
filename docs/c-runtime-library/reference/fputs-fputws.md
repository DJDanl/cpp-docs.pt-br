---
title: fputs, fputws
ms.date: 11/04/2016
apiname:
- fputs
- fputws
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
ms.openlocfilehash: 3f7c7cff3300ae28717062a41aebd9e19c0cb5e0
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50574844"
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

*str*<br/>
Cadeia de caracteres de saída.

*fluxo*<br/>
Ponteiro para a estrutura **FILE**.

## <a name="return-value"></a>Valor de retorno

Cada uma dessas funções retornará um valor não negativo se for bem-sucedida. Em um erro **fputs** e **fputws** retornar **EOF**. Se *str* ou *fluxo* é um ponteiro nulo, essas funções invocarão o manipulador de parâmetro inválido, conforme descrito na [validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução puder continuar, essas funções definirão **errno** à **EINVAL** e, em seguida, **fputs** retorna **EOF**, e  **fputws** retorna **WEOF**.

Consulte [_doserrno, errno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md) para obter mais informações sobre esses e outros códigos de erro.

## <a name="remarks"></a>Comentários

Cada uma dessas funções cópias *str* à saída *fluxo* na posição atual. **fputws** copia o argumento de caractere largo *str* à *fluxo* como uma cadeia de caracteres multibyte ou uma cadeia de caracteres largos dependendo *fluxo*é aberto no modo de texto ou binário, respectivamente. Nenhuma função copia o caractere nulo de terminação.

As duas funções terão comportamento idêntico se o fluxo for aberto no modo ANSI. **fputs** não oferece suporte a saída em um fluxo UNICODE.

### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico

|Rotina TCHAR.H|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|
|---------------------|------------------------------------|--------------------|-----------------------|
|**fputts**|**fputs**|**fputs**|**fputws**|

## <a name="requirements"></a>Requisitos

|Função|Cabeçalho necessário|
|--------------|---------------------|
|**fputs**|\<stdio.h>|
|**fputws**|\<stdio.h> ou \<wchar.h>|

Não há suporte para o console em aplicativos da plataforma Universal do Windows (UWP). Os identificadores de fluxo padrão que estão associados com o console —**stdin**, **stdout**, e **stderr**— deverá ser redirecionado para funções de tempo de execução C possam ser usados em aplicativos UWP . Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

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

## <a name="see-also"></a>Consulte também

[E/S de fluxo](../../c-runtime-library/stream-i-o.md)<br/>
[fgets, fgetws](fgets-fgetws.md)<br/>
[gets, _getws](../../c-runtime-library/gets-getws.md)<br/>
[puts, _putws](puts-putws.md)<br/>
