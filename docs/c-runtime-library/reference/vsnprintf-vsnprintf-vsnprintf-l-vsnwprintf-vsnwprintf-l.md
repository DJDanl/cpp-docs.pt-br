---
title: vsnprintf, _vsnprintf, _vsnprintf_l, _vsnwprintf, _vsnwprintf_l
description: Referência de API para vsnprintf, _vsnprintf, _vsnprintf_l, _vsnwprintf e _vsnwprintf_l; que grava a saída formatada usando um ponteiro para uma lista de argumentos.
ms.date: 06/24/2020
api_name:
- _vsnprintf
- _vsnprintf_l
- _vsnwprintf
- _vsnwprintf_l
- _vsnprintf
- _vsnprintf;
- vsnprintf; _vsnprintf
- _vsnwprintf;
- _vsnprintf_l;
- _vsnwprintf_l;
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
- ntoskrnl.exe
- ucrtbase.dll
api_type:
- DLLExport
topic_type:
- apiref
f1_keywords:
- _vsnprintf
- _vsnwprintf
- _vsntprintf
- vsnprintf
- stdio/vsnprintf
- stdio/_vsnprintf
- stdio/_vsnprintf_l
- stdio/_vsnwprintf
- stdio/_vsnwprintf_l
- _vsnprintf_l
- _vsnwprintf_l
helpviewer_keywords:
- vsntprintf function
- _vsnwprintf_l function
- vsnwprintf_l function
- vsntprintf_l function
- _vsntprintf function
- _vsnprintf_l function
- vsnprintf function
- _vsntprintf_l function
- vsnprintf_l function
- _vsnwprintf function
- _vsnprintf function
- formatted text [C++]
- vsnwprintf function
ms.assetid: a97f92df-c2f8-4ea0-9269-76920d2d566a
ms.openlocfilehash: e6ed3d146458f514691fe0b20a4c88ffebb5f877
ms.sourcegitcommit: 43cee7a0d41a062661229043c2f7cbc6ace17fa3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/13/2020
ms.locfileid: "92008696"
---
# <a name="vsnprintf-_vsnprintf-_vsnprintf_l-_vsnwprintf-_vsnwprintf_l"></a>vsnprintf, _vsnprintf, _vsnprintf_l, _vsnwprintf, _vsnwprintf_l

Grave saída formatada usando um ponteiro para uma lista de argumentos. Versões mais seguras dessas funções estão disponíveis; consulte [vsnprintf_s, _vsnprintf_s, _vsnprintf_s_l, _vsnwprintf_s, _vsnwprintf_s_l](vsnprintf-s-vsnprintf-s-vsnprintf-s-l-vsnwprintf-s-vsnwprintf-s-l.md).

## <a name="syntax"></a>Sintaxe

```C
int vsnprintf(
   char *buffer,
   size_t count,
   const char *format,
   va_list argptr
);
int _vsnprintf(
   char *buffer,
   size_t count,
   const char *format,
   va_list argptr
);
int _vsnprintf_l(
   char *buffer,
   size_t count,
   const char *format,
   locale_t locale,
   va_list argptr
);
int _vsnwprintf(
   wchar_t *buffer,
   size_t count,
   const wchar_t *format,
   va_list argptr
);
int _vsnwprintf_l(
   wchar_t *buffer,
   size_t count,
   const wchar_t *format,
   locale_t locale,
   va_list argptr
);
template <size_t size>
int vsnprintf(
   char (&buffer)[size],
   size_t count,
   const char *format,
   va_list argptr
); // C++ only
template <size_t size>
int _vsnprintf(
   char (&buffer)[size],
   size_t count,
   const char *format,
   va_list argptr
); // C++ only
template <size_t size>
int _vsnprintf_l(
   char (&buffer)[size],
   size_t count,
   const char *format,
   locale_t locale,
   va_list argptr
); // C++ only
template <size_t size>
int _vsnwprintf(
   wchar_t (&buffer)[size],
   size_t count,
   const wchar_t *format,
   va_list argptr
); // C++ only
template <size_t size>
int _vsnwprintf_l(
   wchar_t (&buffer)[size],
   size_t count,
   const wchar_t *format,
   locale_t locale,
   va_list argptr
); // C++ only
```

### <a name="parameters"></a>Parâmetros

*completo*<br/>
Local de armazenamento de saída.

*contagem*<br/>
O número máximo de caracteres a serem gravados.

*format*<br/>
Especificação de formato.

*argptr*<br/>
Ponteiro para a lista de argumentos.

*locale*<br/>
A localidade a ser usada.

Para obter mais informações, consulte [Especificações de formato](../../c-runtime-library/format-specification-syntax-printf-and-wprintf-functions.md).

## <a name="return-value"></a>Valor Retornado

A função **vsnprintf** retorna o número de caracteres que são gravados, não contando o caractere nulo de terminação. Se o tamanho do buffer especificado pela *contagem* não for suficientemente grande para conter a saída especificada por *Format* e *argptr*, o valor de retorno de **vsnprintf** será o número de caracteres que seriam gravados, não contando o caractere nulo, se *Count* fosse suficientemente grande. Se o valor de retorno for maior que *Count* -1, a saída será truncada. Um valor retornado -1 indica que ocorreu um erro de codificação.

As funções **_vsnprintf** e **_vsnwprintf** retornam o número de caracteres gravados se o número de caracteres a serem gravados for menor ou igual à *contagem*. Se o número de caracteres a serem gravados for maior que a *contagem*, essas funções retornarão-1 indicando que a saída foi truncada.

O valor retornado por todas essas funções não inclui o nulo de terminação, esteja ele gravado ou não.

- Se *Count* for zero e *buffer* for **NULL**, o valor retornado será o número de caracteres que as funções gravarão. O valor não leva em conta um **nulo**de terminação. Você pode usar esse resultado para alocar espaço suficiente no buffer para a cadeia de caracteres e seu nulo de terminação e, em seguida, chamar a função novamente para preencher o buffer.
- Se *Count* for zero, mas *buffer* não for **NULL**, nada será gravado e a função retornará `-1` .
- Se o *formato* for **nulo**ou se *o buffer* for **nulo** e a *contagem* não for igual a zero, essas funções invocarão o manipulador de parâmetro inválido, conforme descrito em [validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução tiver permissão para continuar, essas funções retornam-1 e definem **errno** como **EINVAL**.

## <a name="remarks"></a>Comentários

Cada uma dessas funções usa um ponteiro para uma lista de argumentos e, em seguida, formata os dados e grava até a *contagem* de caracteres para a memória apontada por *buffer*. A função **vsnprintf** sempre grava um terminador nulo, mesmo se ele truncar a saída. Ao usar **_vsnprintf** e **_vsnwprintf**, o buffer será encerrado em nulo somente se houver espaço no final (ou seja, se o número de caracteres a serem gravados for menor que a *contagem*).

> [!IMPORTANT]
> Para evitar certos tipos de riscos de segurança, verifique se o *formato* não é uma cadeia de caracteres definida pelo usuário. Para obter mais informações, consulte [Avoiding Buffer Overruns](/windows/win32/SecBP/avoiding-buffer-overruns) (Evitando estouros de buffer).

> [!NOTE]
> Para garantir que haja espaço para o nulo de terminação ao chamar **_vsnprintf**, **_vsnprintf_l**, **_vsnwprintf** e **_vsnwprintf_l**, certifique-se de que *Count* seja estritamente menor que o comprimento do buffer e inicialize o buffer para NULL antes de chamar a função.
>
> Como **vsnprintf** sempre grava o nulo de terminação, o parâmetro de *contagem* pode ser igual ao tamanho do buffer.

A partir do UCRT no Visual Studio 2015 e no Windows 10, o **vsnprintf** não é mais idêntico ao **_vsnprintf**. A função **vsnprintf** está em conformidade com o C99 Standard; **_vnsprintf** é mantido para compatibilidade com versões anteriores com o Visual Studio Code mais antigo.

As versões dessas funções com o sufixo **_L** são idênticas, exceto pelo fato de que usam o parâmetro Locale passado em vez da localidade do thread atual.

No C++, essas funções têm sobrecargas de modelo que invocam os equivalentes mais novos e seguros dessas funções. Para obter mais informações, consulte [Sobrecargas de modelo seguro](../../c-runtime-library/secure-template-overloads.md).

### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico

|Rotina TCHAR.H|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|
|---------------------|------------------------------------|--------------------|-----------------------|
|**_vsntprintf**|**_vsnprintf**|**_vsnprintf**|**_vsnwprintf**|
|**_vsntprintf_l**|**_vsnprintf_l**|**_vsnprintf_l**|**_vsnwprintf_l**|

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário (C)|Cabeçalho necessário (C++)|
|-------------|---------------------------|-------------------------------|
|**vsnprintf**, **_vsnprintf**, **_vsnprintf_l**|\<stdio.h>|\<stdio.h> ou \<cstdio>|
|**_vsnwprintf**, **_vsnwprintf_l**|\<stdio.h> ou \<wchar.h>|\<stdio.h>, \<wchar.h>, \<cstdio> ou \<cwchar>|

As funções **_vsnprintf**, **_vsnprintf_l**, **_vsnwprintf** e **_vsnwprintf_l** são específicas da Microsoft. Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example-use-wide-characters-with-_vsnwprintf"></a>Exemplo: usar caracteres largos com `_vsnwprintf()`

```C
// crt_vsnwprintf.c
// compile by using: cl /W3 crt_vsnwprintf.c

// To turn off error C4996, define this symbol:
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <wtypes.h>

#define BUFFCOUNT (10)

void FormatOutput(LPCWSTR formatstring, ...)
{
    int nSize = 0;
    wchar_t buff[BUFFCOUNT];
    memset(buff, 0, sizeof(buff));
    va_list args;
    va_start(args, formatstring);
    // Note: _vsnwprintf is deprecated; consider vsnwprintf_s instead
    nSize = _vsnwprintf(buff, BUFFCOUNT - 1, formatstring, args); // C4996
    wprintf(L"nSize: %d, buff: %ls\n", nSize, buff);
    va_end(args);
}

int main() {
    FormatOutput(L"%ls %ls", L"Hi", L"there");
    FormatOutput(L"%ls %ls", L"Hi", L"there!");
    FormatOutput(L"%ls %ls", L"Hi", L"there!!");
}
```

```Output
nSize: 8, buff: Hi there
nSize: 9, buff: Hi there!
nSize: -1, buff: Hi there!
```

O comportamento será alterado se você usar vsnprintf em vez disso, juntamente com parâmetros de cadeia estreita. O parâmetro *Count* pode ser o tamanho inteiro do buffer, e o valor de retorno é o número de caracteres que teriam sido gravados se *Count* fosse grande o suficiente:

## <a name="example-use-vsnprintf-with-narrow-strings"></a>Exemplo: use `vsnprintf()` com cadeias de caracteres estreitas

```C
// crt_vsnprintf.c
// compile by using: cl /W4 crt_vsnprintf.c
#include <stdio.h>
#include <stdarg.h> // for va_list, va_start
#include <string.h> // for memset

#define BUFFCOUNT (10)

void FormatOutput(char* formatstring, ...)
{
    int nSize = 0;
    char buff[BUFFCOUNT];
    memset(buff, 0, sizeof(buff));
    va_list args;
    va_start(args, formatstring);
    nSize = vsnprintf(buff, sizeof(buff), formatstring, args);
    printf("nSize: %d, buff: %s\n", nSize, buff);
    va_end(args);
}

int main() {
    FormatOutput("%s %s", "Hi", "there");   //  8 chars + null
    FormatOutput("%s %s", "Hi", "there!");  //  9 chars + null
    FormatOutput("%s %s", "Hi", "there!!"); // 10 chars + null
}
```

```Output
nSize: 8, buff: Hi there
nSize: 9, buff: Hi there!
nSize: 10, buff: Hi there!
```

## <a name="see-also"></a>Veja também

[E/S de fluxo](../../c-runtime-library/stream-i-o.md)<br/>
[Funções vprintf](../../c-runtime-library/vprintf-functions.md)<br/>
[Sintaxe de especificação de formato: funções printf e wprintf](../../c-runtime-library/format-specification-syntax-printf-and-wprintf-functions.md)<br/>
[fprintf, _fprintf_l, fwprintf, _fwprintf_l](fprintf-fprintf-l-fwprintf-fwprintf-l.md)<br/>
[printf, _printf_l, wprintf, _wprintf_l](printf-printf-l-wprintf-wprintf-l.md)<br/>
[sprintf, _sprintf_l, swprintf, _swprintf_l, \_ _swprintf_l](sprintf-sprintf-l-swprintf-swprintf-l-swprintf-l.md)<br/>
[va_arg, va_copy, va_end, va_start](va-arg-va-copy-va-end-va-start.md)<br/>
