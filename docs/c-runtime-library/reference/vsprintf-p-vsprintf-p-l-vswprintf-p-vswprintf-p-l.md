---
title: _vsprintf_p, _vsprintf_p_l, _vswprintf_p, _vswprintf_p_l | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.reviewer: ''
ms.suite: ''
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: ''
ms.topic: reference
apiname:
- _vsprintf_p
- _vswprintf_p
- _vsprintf_p_l
- _vswprintf_p_l
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
apitype: DLLExport
f1_keywords:
- vsprintf_p
- _vswprintf_p
- _vstprintf_p
- vswprintf_p
- _vsprintf_p
- vstprintf_p
dev_langs:
- C++
helpviewer_keywords:
- vstprintf_p_l function
- _vsprintf_p_l function
- _vstprintf_p function
- vsprintf_p_l function
- _vswprintf_p function
- vswprintf_p function
- vsprintf_p function
- vswprintf_p_l function
- _vswprintf_p_l function
- vstprintf_p function
- formatted text [C++]
- _vsprintf_p function
- _vstprintf_p_l function
ms.assetid: 00821c0d-9fee-4d8a-836c-0669cfb11317
caps.latest.revision: 20
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: dcd4416154e150b1b052d22ca24ce8589c59716f
ms.sourcegitcommit: ef859ddf5afea903711e36bfd89a72389a12a8d6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/20/2018
---
# <a name="vsprintfp-vsprintfpl-vswprintfp-vswprintfpl"></a>_vsprintf_p, _vsprintf_p_l, _vswprintf_p, _vswprintf_p_l

Grave saída formatada usando um ponteiro para uma lista de argumentos, com a capacidade de especificar a ordem em que os argumentos são usados.

## <a name="syntax"></a>Sintaxe

```C
int _vsprintf_p(
   char *buffer,
   size_t sizeInBytes,
   const char *format,
   va_list argptr
);
int _vsprintf_p_l(
   char *buffer,
   size_t sizeInBytes,
   const char *format,
   locale_t locale,
   va_list argptr
);
int _vswprintf_p(
   wchar_t *buffer,
   size_t count,
   const wchar_t *format,
   va_list argptr
);
int _vswprintf_p_l(
   wchar_t *buffer,
   size_t count,
   const wchar_t *format,
   locale_t locale,
   va_list argptr
);
```

### <a name="parameters"></a>Parâmetros

*buffer*<br/>
Local de armazenamento de saída.

*sizeInBytes*<br/>
Tamanho de *buffer* em caracteres.

*count*<br/>
Número máximo de caracteres a armazenar a versão UNICODE dessa função.

*format*<br/>
Especificação de formato.

*argptr*<br/>
Ponteiro para a lista de argumentos.

*locale*<br/>
A localidade a ser usada.

## <a name="return-value"></a>Valor de retorno

**vsprintf_p** e **vswprintf_p** retornar o número de caracteres gravados, não incluindo o caractere null de terminação ou um valor negativo se ocorrer um erro de saída.

## <a name="remarks"></a>Comentários

Cada uma dessas funções usa um ponteiro para uma lista de argumentos e, em seguida, formata e escreve os dados fornecidos para a memória apontada pelo *buffer*.

Essas funções diferem do **vsprintf_s** e **vswprintf_s** apenas se eles oferecem suporte a parâmetros posicionais. Para obter mais informações, consulte [Parâmetros posicionais printf_p](../../c-runtime-library/printf-p-positional-parameters.md).

As versões dessas funções com o **_l** sufixo são idênticas, exceto que eles usam o parâmetro de localidade passado em vez da localidade do thread atual.

Se o *buffer* ou *formato* parâmetros são ponteiros NULL, se a contagem for zero, ou se a cadeia de caracteres de formato contém caracteres inválidos de formatação, o manipulador de parâmetro inválido é invocado, conforme descrito em [ Validação do parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução é permitida para continuar, retornam -1, as funções e defina **errno** para **EINVAL**.

### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico

|Rotina TCHAR.H|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|
|---------------------|------------------------------------|--------------------|-----------------------|
|**vstprintf_p**|**_vsprintf_p**|**_vsprintf_p**|**_vswprintf_p**|
|**vstprintf_p_l**|**_vsprintf_p_l**|**_vsprintf_p_l**|**_vswprintf_p_l**|

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|Cabeçalhos opcionais|
|-------------|---------------------|----------------------|
|**vsprintf_p**, **vsprintf_p_l**|\<stdio.h> e \<stdarg.h>|\<varargs.h>*|
|**vswprintf_p**, **vswprintf_p_l**|\<stdio.h> ou \<wchar.h> e \<stdarg.h>|\<varargs.h>*|

\* Necessário para compatibilidade com UNIX V.

Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

```C
// crt__vsprintf_p.c
// This program uses vsprintf_p to write to a buffer.
// The size of the buffer is determined by _vscprintf_p.

#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>

void example( char * format, ... )
{
    va_list  args;
    int      len;
    char     *buffer = NULL;

    va_start( args, format );

    // _vscprintf doesn't count the
    // null terminating string so we add 1.
    len = _vscprintf_p( format, args ) + 1;

    // Allocate memory for our buffer
    buffer = (char*)malloc( len * sizeof(char) );
    if (buffer)
    {
        _vsprintf_p( buffer, len, format, args );
        puts( buffer );
        free( buffer );
    }
    va_end( args );
}

int main( void )
{
    // First example
    example( "%2$d %1$c %3$d", '<', 123, 456 );

    // Second example
    example( "%s", "This is a string" );
}
```

```Output
123 < 456
This is a string
```

## <a name="see-also"></a>Consulte também

[E/S de fluxo](../../c-runtime-library/stream-i-o.md)<br/>
[Funções vprintf](../../c-runtime-library/vprintf-functions.md)<br/>
[Sintaxe de especificação de formato: funções printf e wprintf](../../c-runtime-library/format-specification-syntax-printf-and-wprintf-functions.md)<br/>
[fprintf, _fprintf_l, fwprintf, _fwprintf_l](fprintf-fprintf-l-fwprintf-fwprintf-l.md)<br/>
[printf, _printf_l, wprintf, _wprintf_l](printf-printf-l-wprintf-wprintf-l.md)<br/>
[sprintf, _sprintf_l, swprintf, _swprintf_l, \__swprintf_l](sprintf-sprintf-l-swprintf-swprintf-l-swprintf-l.md)<br/>
[va_arg, va_copy, va_end, va_start](va-arg-va-copy-va-end-va-start.md)<br/>
