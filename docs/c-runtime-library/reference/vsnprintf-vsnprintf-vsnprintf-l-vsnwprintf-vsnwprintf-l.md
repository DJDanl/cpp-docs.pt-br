---
title: vsnprintf, _vsnprintf, _vsnprintf_l, _vsnwprintf, _vsnwprintf_l | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.reviewer: ''
ms.suite: ''
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: ''
ms.topic: reference
apiname:
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
- ntoskrnl.exe
- ucrtbase.dll
apitype: DLLExport
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
dev_langs:
- C++
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
caps.latest.revision: 35
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: ba1574d29679ea0f8363270061d2ced9ab16100e
ms.sourcegitcommit: ef859ddf5afea903711e36bfd89a72389a12a8d6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/20/2018
---
# <a name="vsnprintf-vsnprintf-vsnprintfl-vsnwprintf-vsnwprintfl"></a>vsnprintf, _vsnprintf, _vsnprintf_l, _vsnwprintf, _vsnwprintf_l

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

*buffer*<br/>
Local de armazenamento de saída.

*count*<br/>
O número máximo de caracteres a serem gravados.

*format*<br/>
Especificação de formato.

*argptr*<br/>
Ponteiro para a lista de argumentos.

*locale*<br/>
A localidade a ser usada.

Para obter mais informações, consulte [Especificações de formato](../../c-runtime-library/format-specification-syntax-printf-and-wprintf-functions.md).

## <a name="return-value"></a>Valor de retorno

O **vsnprintf** função retorna o número de caracteres gravados, sem contar o caractere null de terminação. Se o tamanho do buffer especificado por *contagem* não é grande o suficiente para conter a saída especificada pelo *formato* e *argptr*, o valor de retorno  **vsnprintf** é o número de caracteres que deve ser gravado, sem contar o caractere nulo, se *contagem* foram grande o suficiente. Se o valor de retorno for maior que *contagem* - 1, a saída foi truncada. Um valor retornado -1 indica que ocorreu um erro de codificação.

Ambos **vsnprintf** e **vsnwprintf** funções retornam o número de caracteres gravados se o número de caracteres para escrever é menor ou igual a *contagem*; se o número de caracteres a gravação é maior que *contagem*, essas funções de retorno -1 que indica que a saída foi truncada.

O valor retornado por todas essas funções não inclui o nulo de terminação, quer seja gravado um ou não. Quando *contagem* for zero, o valor retornado é o número de caracteres, as funções escreve, não incluindo nenhum null de terminação. Você pode usar esse resultado para alocar espaço suficiente no buffer para a cadeia de caracteres e seu nulo de terminação e, em seguida, chamar a função novamente para preencher o buffer.

Se *formato* é **nulo**, ou se *buffer* é NULL e *contagem* não é igual a zero, essas funções invocar o manipulador de parâmetro inválido conforme descrito em [validação do parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução é permitida para continuar, essas funções retornam -1 e defina **errno** para **EINVAL**.

## <a name="remarks"></a>Comentários

Cada uma dessas funções usa um ponteiro para uma lista de argumentos, em seguida, formata os dados e grava até *contagem* caracteres para a memória apontado pela *buffer*. O **vsnprintf** função sempre grava um terminador nulo, mesmo se ele trunca a saída. Ao usar **vsnprintf** e **vsnwprintf**, o buffer será seja terminada em nulo somente se houver espaço no final (ou seja, se o número de caracteres para escrever é menor que *contagem*).

> [!IMPORTANT]
> Para impedir que certos tipos de riscos de segurança, certifique-se de que *formato* não é uma cadeia de caracteres definida pelo usuário. Para obter mais informações, consulte [Avoiding Buffer Overruns](http://msdn.microsoft.com/library/windows/desktop/ms717795) (Evitando estouros de buffer).

> [!NOTE]
> Para garantir que haja espaço para a terminação nula ao chamar **vsnprintf**, **vsnprintf_l**, **vsnwprintf** e **vsnwprintf_l**, certifique-se de que *contagem* é estritamente menor do que o comprimento do buffer e inicializar o buffer nulo antes de chamar a função.
>
> Porque **vsnprintf** sempre grava o terminação null, o *contagem* parâmetro pode ser igual ao tamanho do buffer.

Começando com a UCRT no Visual Studio 2015 e Windows 10, **vsnprintf** não é idêntico ao **vsnprintf**. O **vsnprintf** função está em conformidade com o padrão de C99; **_vnsprintf** é mantido para compatibilidade com versões anteriores com o código anterior do Visual Studio.

As versões dessas funções com o **_l** sufixo são idênticas, exceto que eles usam o parâmetro de localidade passado em vez da localidade do thread atual.

No C++, essas funções têm sobrecargas de modelo que invocam os equivalentes mais novos e seguros dessas funções. Para obter mais informações, consulte [Sobrecargas de modelo seguro](../../c-runtime-library/secure-template-overloads.md).

### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico

|Rotina TCHAR.H|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|
|---------------------|------------------------------------|--------------------|-----------------------|
|**vsntprintf**|**_vsnprintf**|**_vsnprintf**|**_vsnwprintf**|
|**vsntprintf_l**|**_vsnprintf_l**|**_vsnprintf_l**|**_vsnwprintf_l**|

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário (C)|Cabeçalho necessário (C++)|
|-------------|---------------------------|-------------------------------|
|**vsnprintf**, **vsnprintf**, **vsnprintf_l**|\<stdio.h>|\<stdio.h> ou \<cstdio>|
|**vsnwprintf**, **vsnwprintf_l**|\<stdio.h> ou \<wchar.h>|\<stdio.h>, \<wchar.h>, \<cstdio> ou \<cwchar>|

O **vsnprintf**, **vsnprintf_l**, **vsnwprintf** e **vsnwprintf_l** funções são específicas da Microsoft. Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

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

O comportamento será alterado se você usar vsnprintf em vez disso, juntamente com parâmetros de cadeia estreita. O *contagem* parâmetro pode ser o tamanho inteiro do buffer e o valor de retorno é o número de caracteres que será gravada se *contagem* era grande o suficiente:

## <a name="example"></a>Exemplo

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

## <a name="see-also"></a>Consulte também

[E/S de fluxo](../../c-runtime-library/stream-i-o.md)<br/>
[Funções vprintf](../../c-runtime-library/vprintf-functions.md)<br/>
[Sintaxe de especificação de formato: funções printf e wprintf](../../c-runtime-library/format-specification-syntax-printf-and-wprintf-functions.md)<br/>
[fprintf, _fprintf_l, fwprintf, _fwprintf_l](fprintf-fprintf-l-fwprintf-fwprintf-l.md)<br/>
[printf, _printf_l, wprintf, _wprintf_l](printf-printf-l-wprintf-wprintf-l.md)<br/>
[sprintf, _sprintf_l, swprintf, _swprintf_l, \__swprintf_l](sprintf-sprintf-l-swprintf-swprintf-l-swprintf-l.md)<br/>
[va_arg, va_copy, va_end, va_start](va-arg-va-copy-va-end-va-start.md)<br/>
