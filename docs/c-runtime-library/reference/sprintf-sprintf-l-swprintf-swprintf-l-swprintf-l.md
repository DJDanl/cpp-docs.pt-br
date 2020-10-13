---
title: sprintf, _sprintf_l, swprintf, _swprintf_l, __swprintf_l
ms.date: 06/23/2020
api_name:
- __swprintf_l
- sprintf
- _sprintf_l
- _swprintf_l
- swprintf
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
- ntdll.dll
- ucrtbase.dll
- ntoskrnl.exe
api_type:
- DLLExport
topic_type:
- apiref
f1_keywords:
- _stprintf_l
- __swprintf_l
- sprintf_l
- swprintf
- _sprintf_l
- sprintf
- _stprintf
- stprintf_l
helpviewer_keywords:
- _swprintf_l function
- _stprintf function
- __swprintf_l function
- stprintf function
- sprintf function
- _sprintf_l function
- _stprintf_l function
- swprintf function
- strings [C++], writing to
- _CRT_NON_CONFORMING_SWPRINTFS
- swprintf_l function
- stprintf_l function
- sprintf_l function
- formatted text [C++]
ms.assetid: f6efe66f-3563-4c74-9455-5411ed939b81
ms.openlocfilehash: da3c5b3660b481fd3a7140adbc236f44cd51f37e
ms.sourcegitcommit: 43cee7a0d41a062661229043c2f7cbc6ace17fa3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/13/2020
ms.locfileid: "92008822"
---
# <a name="sprintf-_sprintf_l-swprintf-_swprintf_l-__swprintf_l"></a>sprintf, _sprintf_l, swprintf, _swprintf_l, __swprintf_l

Grave os dados formatados em uma cadeia de caracteres. Versões mais seguras de algumas funções estão disponíveis; consulte [sprintf_s, _sprintf_s_l, swprintf_s, _swprintf_s_l](sprintf-s-sprintf-s-l-swprintf-s-swprintf-s-l.md). As versões seguras do **swprintf** e **_swprintf_l** têm o tamanho do buffer como um parâmetro.

## <a name="syntax"></a>Sintaxe

```C
int sprintf(
   char *buffer,
   const char *format [,
   argument] ...
);
int _sprintf_l(
   char *buffer,
   const char *format,
   locale_t locale [,
   argument] ...
);
int swprintf(
   wchar_t *buffer,
   size_t count,
   const wchar_t *format [,
   argument]...
);
int _swprintf_l(
   wchar_t *buffer,
   size_t count,
   const wchar_t *format,
   locale_t locale [,
   argument] ...
);
int __swprintf_l(
   wchar_t *buffer,
   const wchar_t *format,
   locale_t locale [,
   argument] ...
);
template <size_t size>
int sprintf(
   char (&buffer)[size],
   const char *format [,
   argument] ...
); // C++ only
template <size_t size>
int _sprintf_l(
   char (&buffer)[size],
   const char *format,
   locale_t locale [,
   argument] ...
); // C++ only
```

### <a name="parameters"></a>Parâmetros

*completo*<br/>
Local de armazenamento para a saída

*contagem*<br/>
Número máximo de caracteres a armazenar a versão Unicode dessa função.

*format*<br/>
Cadeia de caracteres de controle de formato

*argument*<br/>
Argumentos opcionais

*locale*<br/>
A localidade a ser usada.

Para obter mais informações, consulte [Especificações de formato](../../c-runtime-library/format-specification-syntax-printf-and-wprintf-functions.md).

## <a name="return-value"></a>Valor Retornado

O número de caracteres gravados ou-1 se ocorreu um erro. Se o *buffer* ou o *formato* for um ponteiro NULL, o manipulador de parâmetro inválido será invocado, conforme descrito em [validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução tiver permissão para continuar, essas funções retornam-1 e definem **errno** como **EINVAL**.

**sprintf** retorna o número de bytes armazenados no *buffer*, não contando o caractere nulo de terminação. **swprintf** retorna o número de caracteres largos armazenados no *buffer*, sem contar a terminação de caractere nulo de finalização.

## <a name="remarks"></a>Comentários

A função **sprintf** formata e armazena uma série de caracteres e valores no *buffer*. Cada *argumento* (se houver) é convertido e apresentado de acordo com a especificação de formato correspondente no *formato*. O formato consiste em caracteres comuns e tem a mesma forma e função que o argumento de *formato* para [printf](printf-printf-l-wprintf-wprintf-l.md). Um caractere nulo é acrescentado após o último caractere escrito. Se ocorrer cópia entre cadeias de caracteres que se sobrepõem, o comportamento será indefinido.

> [!IMPORTANT]
> Usando o **sprintf**, não há nenhuma maneira de limitar o número de caracteres gravados, o que significa que o código que usa **sprintf** é suscetível a estouros de buffer. Considere usar a função relacionada [_snprintf](snprintf-snprintf-snprintf-l-snwprintf-snwprintf-l.md), que especifica um número máximo de caracteres a serem gravados no *buffer*ou use [_scprintf](scprintf-scprintf-l-scwprintf-scwprintf-l.md) para determinar o tamanho de um buffer é necessário. Além disso, verifique se o *formato* não é uma cadeia de caracteres definida pelo usuário.

**swprintf** é uma versão de caractere largo do **sprintf**; os argumentos de ponteiro para **swprintf** são cadeias de caracteres largos. A detecção de erros de codificação em **swprintf** pode ser diferente de **sprintf**. **swprintf** e **fwprintf** se comportam de forma idêntica, exceto que **swprintf** grava a saída em uma cadeia de caracteres em vez de um destino do tipo **File**, e **swprintf** requer que o parâmetro *Count* especifique o número máximo de caracteres a serem gravados. As versões dessas funções com o sufixo **_L** são idênticas, exceto que usam o parâmetro Locale passado em vez da localidade do thread atual.

o **swprintf** está em conformidade com o padrão ISO C, que requer o segundo parâmetro, *Count*, do tipo **size_t**. Para forçar o comportamento não padrão antigo, defina **_CRT_NON_CONFORMING_SWPRINTFS**. Em uma versão futura, o comportamento antigo pode ser removido, então o código deve ser alterado para usar o novo comportamento compatível.

No C++, essas funções têm sobrecargas de modelo que invocam os equivalentes mais novos e seguros dessas funções. Para obter mais informações, consulte [Sobrecargas de modelo seguro](../../c-runtime-library/secure-template-overloads.md).

### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico

|Rotina TCHAR.H|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|
|---------------------|------------------------------------|--------------------|-----------------------|
|**_stprintf**|**sprintf**|**sprintf**|**_swprintf**|
|**_stprintf_l**|**_sprintf_l**|**_sprintf_l**|**__swprintf_l**|

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**sprintf**, **_sprintf_l**|\<stdio.h>|
|**swprintf**, **_swprintf_l**|\<stdio.h> ou \<wchar.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example-use-sprintf-to-format-data"></a>Exemplo: usar sprintf para formatar dados

```C
// crt_sprintf.c
// compile with: /W3
// This program uses sprintf to format various
// data and place them in the string named buffer.

#include <stdio.h>

int main( void )
{
   char  buffer[200], s[] = "computer", c = 'l';
   int   i = 35, j;
   float fp = 1.7320534f;

   // Format and print various data:
   j  = sprintf( buffer,     "   String:    %s\n", s ); // C4996
   j += sprintf( buffer + j, "   Character: %c\n", c ); // C4996
   j += sprintf( buffer + j, "   Integer:   %d\n", i ); // C4996
   j += sprintf( buffer + j, "   Real:      %f\n", fp );// C4996
   // Note: sprintf is deprecated; consider using sprintf_s instead

   printf( "Output:\n%s\ncharacter count = %d\n", buffer, j );
}
```

```Output
Output:
   String:    computer
   Character: l
   Integer:   35
   Real:      1.732053

character count = 79
```

## <a name="example-error-code-handling"></a>Exemplo: tratamento de código de erro

```C
// crt_swprintf.c
// wide character example
// also demonstrates swprintf returning error code
#include <stdio.h>

int main( void )
{
   wchar_t buf[100];
   int len = swprintf( buf, 100, L"%s", L"Hello world" );
   printf( "wrote %d characters\n", len );
   len = swprintf( buf, 100, L"%s", L"Hello\xffff world" );
   // swprintf fails because string contains WEOF (\xffff)
   printf( "wrote %d characters\n", len );
}
```

```Output
wrote 11 characters
wrote -1 characters
```

## <a name="see-also"></a>Veja também

[E/S de fluxo](../../c-runtime-library/stream-i-o.md)<br/>
[fprintf, _fprintf_l, fwprintf, _fwprintf_l](fprintf-fprintf-l-fwprintf-fwprintf-l.md)<br/>
[printf, _printf_l, wprintf, _wprintf_l](printf-printf-l-wprintf-wprintf-l.md)<br/>
[scanf, _scanf_l, wscanf, _wscanf_l](scanf-scanf-l-wscanf-wscanf-l.md)<br/>
[sscanf, _sscanf_l, swscanf, _swscanf_l](sscanf-sscanf-l-swscanf-swscanf-l.md)<br/>
[Funções vprintf](../../c-runtime-library/vprintf-functions.md)<br/>
