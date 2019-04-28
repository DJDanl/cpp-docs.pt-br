---
title: printf, _printf_l, wprintf, _wprintf_l
ms.date: 11/04/2016
apiname:
- _printf_l
- wprintf
- _wprintf_l
- printf
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
ms.openlocfilehash: 1f3d439c12fa803bfe1af31a9a45d777b2e1caa2
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62232487"
---
# <a name="printf-printfl-wprintf-wprintfl"></a>printf, _printf_l, wprintf, _wprintf_l

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

## <a name="return-value"></a>Valor de retorno

Retorna o número de caracteres impressos ou um valor negativo se ocorrer um erro. Se *formato* é **nulo**, o manipulador de parâmetro inválido será invocado, conforme descrito na [validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução puder continuar, a função retornará -1 e definirá **errno** à **EINVAL**. Se **EOF** (0xFFFF) é encontrado no *argumento*, a função retornará -1.

Para obter informações sobre **errno** e códigos de erro, consulte [doserrno, errno, sys_errlist e sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md).

## <a name="remarks"></a>Comentários

O **printf** função formata e imprime uma série de caracteres e valores para o fluxo de saída padrão **stdout**. Se os argumentos seguirem o *formato* cadeia de caracteres, o *formato* cadeia de caracteres deve conter especificações que determinam o formato de saída para os argumentos. **printf** e [fprintf](fprintf-fprintf-l-fwprintf-fwprintf-l.md) se comportam de forma idêntica exceto que **printf** grava a saída **stdout** em vez de um destino do tipo **arquivo** .

**wprintf** é uma versão de caractere largo de **printf**; *formato* é uma cadeia de caracteres largos. **wprintf** e **printf** terão comportamento idêntico se o fluxo for aberto no modo ANSI. **printf** não oferece suporte a saída em um fluxo UNICODE.

As versões dessas funções com o **l** sufixo são idênticas, exceto que eles usam o parâmetro de localidade passado em vez da localidade do thread atual.

### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico

|Rotina TCHAR.H|_UNICODE e _MBCS não definidos|_MBCS definido|_unicode definido|
|---------------------|------------------------------------|--------------------|-----------------------|
|**_tprintf**|**printf**|**printf**|**wprintf**|

O *formato* argumento consiste em caracteres comuns, sequências de escape, e (se os argumentos seguirem *formato*) especificações de formato. Os caracteres comuns e as sequências de escape são copiadas para **stdout** na ordem de sua aparência. Por exemplo, a linha:

```C
printf("Line one\n\t\tLine two\n");
```

produz a saída:

```Output
Line one
        Line two
```

[Especificações de formato](../../c-runtime-library/format-specification-syntax-printf-and-wprintf-functions.md) sempre começam com um sinal de porcentagem (**%**) e são lidos da esquerda para a direita. Quando **printf** encontra a primeira especificação de formato (se houver), ele converte o valor do primeiro argumento após *formato* e produz saídas de acordo. A segunda especificação de formato faz com que o segundo argumento seja convertido e a saída gerada e assim por diante. Se houver mais argumentos do que especificações de formato, os argumentos extras serão ignorados. Os resultados serão indefinidos se não houver argumentos suficientes para as especificações de formato.

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

Não há suporte para o console em aplicativos da plataforma Universal do Windows (UWP). Os identificadores de fluxo padrão que estão associados com o console **stdin**, **stdout**, e **stderr**, deverá ser redirecionado para funções de tempo de execução C possam ser usados em aplicativos UWP . Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

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

### <a name="sample-output"></a>Saída de Exemplo

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

## <a name="see-also"></a>Consulte também

[Suporte a ponto flutuante](../../c-runtime-library/floating-point-support.md)<br/>
[E/S de fluxo](../../c-runtime-library/stream-i-o.md)<br/>
[Localidade](../../c-runtime-library/locale.md)<br/>
[fopen, _wfopen](fopen-wfopen.md)<br/>
[_fprintf_p, _fprintf_p_l, _fwprintf_p, _fwprintf_p_l](fprintf-p-fprintf-p-l-fwprintf-p-fwprintf-p-l.md)<br/>
[scanf, _scanf_l, wscanf, _wscanf_l](scanf-scanf-l-wscanf-wscanf-l.md)<br/>
[sprintf, _sprintf_l, swprintf, _swprintf_l, \__swprintf_l](sprintf-sprintf-l-swprintf-swprintf-l-swprintf-l.md)<br/>
[Funções vprintf](../../c-runtime-library/vprintf-functions.md)<br/>
[_set_output_format](../../c-runtime-library/set-output-format.md)<br/>
