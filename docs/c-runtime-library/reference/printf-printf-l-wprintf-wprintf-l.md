---
title: printf, _printf_l, wprintf, _wprintf_l
ms.date: 11/04/2016
api_name:
- _printf_l
- wprintf
- _wprintf_l
- printf
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
api_type:
- DLLExport
topic_type:
- apiref
f1_keywords:
- printf
- _tprintf
- wprintf
helpviewer_keywords:
- printf function
- printf_l function
- tprintf_l function
- tprintf function
- _printf_l function
- wprintf function
- writing to console
- wprintf_l function
- _tprintf_l function
- _wprintf_l function
- _tprintf function
- printf function, format specification fields
- printf function, using
- formatted text [C++]
ms.assetid: 77a854ae-5b48-4865-89f4-f2dc5cf80f52
ms.openlocfilehash: 3766ea24459423e730ab84ecae24d758d7f61e88
ms.sourcegitcommit: 8c8ed02a6f3bcb5ee008e3fe30ba7595d7c4c922
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/21/2020
ms.locfileid: "83759232"
---
# <a name="printf-_printf_l-wprintf-_wprintf_l"></a>printf, _printf_l, wprintf, _wprintf_l

Imprime saída formatada para o fluxo de saída padrão. Versões mais seguras dessas funções estão disponíveis; consulte [printf_s, _printf_s_l, wprintf_s, _wprintf_s_l](printf-s-printf-s-l-wprintf-s-wprintf-s-l.md).

## <a name="syntax"></a>Sintaxe

```C
int printf(
   const char *format [,
   argument]...
);
int _printf_l(
   const char *format,
   locale_t locale [,
   argument]...
);
int wprintf(
   const wchar_t *format [,
   argument]...
);
int _wprintf_l(
   const wchar_t *format,
   locale_t locale [,
   argument]...
);
```

### <a name="parameters"></a>Parâmetros

*format*<br/>
Formatar controle.

*argument*<br/>
Argumentos opcionais.

*locale*<br/>
A localidade a ser usada.

## <a name="return-value"></a>Valor Retornado

Retorna o número de caracteres impressos ou um valor negativo se ocorrer um erro. Se o *formato* for **nulo**, o manipulador de parâmetro inválido será invocado, conforme descrito em [validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução tiver permissão para continuar, a função retornará-1 e definirá **errno** como **EINVAL**. Se **EOF** (0xFFFF) for encontrado no *argumento*, a função retornará-1.

Para obter informações sobre códigos de erro e **errno** , consulte [_doserrno, errno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md).

## <a name="remarks"></a>Comentários

A função **printf** formata e imprime uma série de caracteres e valores para o fluxo de saída padrão, **stdout**. Se os argumentos seguirem a cadeia de caracteres de *formato* , a cadeia de caracteres de *formato* deverá conter especificações que determinam o formato de saída para os argumentos. **printf** e [fprintf](fprintf-fprintf-l-fwprintf-fwprintf-l.md) se comportam de forma idêntica, exceto que **printf** grava a saída em **stdout** em vez de um destino do tipo **File**.

**wprintf** é uma versão de caractere largo de **printf**; *Format* é uma cadeia de caracteres largos. **wprintf** e **printf** se comportam de forma idêntica se o fluxo é aberto no modo ANSI. no momento, **printf** não dá suporte à saída em um fluxo Unicode.

As versões dessas funções com o sufixo **_L** são idênticas, exceto pelo fato de que usam o parâmetro Locale passado em vez da localidade do thread atual.

### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico

|Rotina TCHAR.H|_UNICODE e _MBCS não definidos|_MBCS definido|_unicode definido|
|---------------------|------------------------------------|--------------------|-----------------------|
|**_tprintf**|**printf**|**printf**|**wprintf**|

O argumento *Format* consiste em caracteres comuns, sequências de escape e (se os argumentos seguirem o *formato*) especificações de formato. Os caracteres e as sequências de escape comuns são copiados para **stdout** na ordem de sua aparência. Por exemplo, a linha:

```C
printf("Line one\n\t\tLine two\n");
```

produz a saída:

```Output
Line one
        Line two
```

As [especificações de formato](../../c-runtime-library/format-specification-syntax-printf-and-wprintf-functions.md) sempre começam com um sinal de porcentagem ( **%** ) e são lidas da esquerda para a direita. Quando **printf** encontra a primeira especificação de formato (se houver), converte o valor do primeiro argumento após o *formato* e o gera de acordo. A segunda especificação de formato faz com que o segundo argumento seja convertido e a saída gerada e assim por diante. Se houver mais argumentos do que especificações de formato, os argumentos extras serão ignorados. Os resultados serão indefinidos se não houver argumentos suficientes para as especificações de formato.

> [!IMPORTANT]
> Verifique se *format* não é uma cadeia de caracteres definida pelo usuário.

### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico

|Rotina Tchar.h|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|
|---------------------|--------------------------------------|--------------------|-----------------------|
|**_tprintf**|**printf**|**printf**|**wprintf**|
|**_tprintf_l**|**_printf_l**|**_printf_l**|**_wprintf_l**|

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**printf**, **_printf_l**|\<stdio.h>|
|**wprintf**, **_wprintf_l**|\<stdio.h> ou \<wchar.h>|

Não há suporte para o console em aplicativos Plataforma Universal do Windows (UWP). Os identificadores de fluxo padrão associados ao console, **stdin**, **stdout**e **stderr**devem ser redirecionados antes que as funções de tempo de execução do C possam usá-los em aplicativos UWP. Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

```C
// crt_printf.c
// This program uses the printf and wprintf functions
// to produce formatted output.

#include <stdio.h>

int main( void )
{
   char     ch = 'h',
            *string = "computer";
   wchar_t  wch = L'w',
            *wstring = L"Unicode";
   int      count = -9234;
   double   fp = 251.7366;

   // Display integers
   printf( "Integer formats:\n"
           "   Decimal: %d  Justified: %.6d  "
           "Unsigned: %u\n",
           count, count, count, count );

   // Display decimals
   printf( "Decimal %d as:\n   Hex: %Xh  "
           "C hex: 0x%x  Octal: %o\n",
            count, count, count, count );

   // Display in different radixes
   printf( "Digits 10 equal:\n   Hex: %i  "
           "Octal: %i  Decimal: %i\n",
            0x10, 010, 10 );

   // Display characters
   printf("Characters in field (1):\n"
          "%10c%5hc%5C%5lc\n",
          ch, ch, wch, wch);
   wprintf(L"Characters in field (2):\n"
           L"%10C%5hc%5c%5lc\n",
           ch, ch, wch, wch);

   // Display strings
   printf("Strings in field (1):\n%25s\n"
          "%25.4hs\n   %S%25.3ls\n",
          string, string, wstring, wstring);
   wprintf(L"Strings in field (2):\n%25S\n"
           L"%25.4hs\n   %s%25.3ls\n",
           string, string, wstring, wstring);

   // Display real numbers
   printf("Real numbers:\n   %f %.2f %e %E\n",
          fp, fp, fp, fp );

   // Display pointer
   printf( "\nAddress as:   %p\n", &count);
}
```

### <a name="sample-output"></a>Saída de exemplo

```Output
Integer formats:
   Decimal: -9234  Justified: -009234  Unsigned: 4294958062
Decimal -9234 as:
   Hex: FFFFDBEEh  C hex: 0xffffdbee  Octal: 37777755756
Digits 10 equal:
   Hex: 16  Octal: 8  Decimal: 10
Characters in field (1):
         h    h    w    w
Characters in field (2):
         h    h    w    w
Strings in field (1):
                 computer
                     comp
   Unicode                      Uni
Strings in field (2):
                 computer
                     comp
   Unicode                      Uni
Real numbers:
   251.736600 251.74 2.517366e+002 2.517366E+002

Address as:   0012FF3C
```

## <a name="see-also"></a>Veja também

[Sintaxe de especificação de formato: funções printf e wprintf](../format-specification-syntax-printf-and-wprintf-functions.md)<br/>
[Suporte de ponto flutuante](../../c-runtime-library/floating-point-support.md)<br/>
[E/S de fluxo](../../c-runtime-library/stream-i-o.md)<br/>
[Locale](../../c-runtime-library/locale.md)<br/>
[fopen, _wfopen](fopen-wfopen.md)<br/>
[_fprintf_p, _fprintf_p_l, _fwprintf_p, _fwprintf_p_l](fprintf-p-fprintf-p-l-fwprintf-p-fwprintf-p-l.md)<br/>
[scanf, _scanf_l, wscanf, _wscanf_l](scanf-scanf-l-wscanf-wscanf-l.md)<br/>
[sprintf, _sprintf_l, swprintf, _swprintf_l, \_ _swprintf_l](sprintf-sprintf-l-swprintf-swprintf-l-swprintf-l.md)<br/>
[Funções vprintf](../../c-runtime-library/vprintf-functions.md)<br/>
[_set_output_format](../../c-runtime-library/set-output-format.md)<br/>
