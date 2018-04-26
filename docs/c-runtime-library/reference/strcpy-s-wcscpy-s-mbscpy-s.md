---
title: strcpy_s, wcscpy_s, _mbscpy_s | Microsoft Docs
ms.custom: ''
ms.date: 03/22/2086
ms.technology:
- cpp-standard-libraries
ms.topic: reference
apiname:
- wcscpy_s
- _mbscpy_s
- strcpy_s
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
- api-ms-win-crt-multibyte-l1-1-0.dll
- api-ms-win-crt-string-l1-1-0.dll
apitype: DLLExport
f1_keywords:
- strcpy_s
- _mbscpy_s
- _tcscpy_s
- wcscpy_s
dev_langs:
- C++
helpviewer_keywords:
- strcpy_s function
- _tcscpy_s function
- _mbscpy_s function
- copying strings
- strings [C++], copying
- tcscpy_s function
- wcscpy_s function
ms.assetid: 611326f3-7929-4a5d-a465-a4683af3b053
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 16dfe0f560097ab7a5a423f7730c215c2d05530f
ms.sourcegitcommit: ef859ddf5afea903711e36bfd89a72389a12a8d6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/20/2018
---
# <a name="strcpys-wcscpys-mbscpys"></a>strcpy_s, wcscpy_s, _mbscpy_s

Copia uma cadeia de caracteres. Estas versões de [strcpy, wcscpy, _mbscpy](strcpy-wcscpy-mbscpy.md) têm aprimoramentos de segurança, conforme descrito em [Recursos de segurança no CRT](../../c-runtime-library/security-features-in-the-crt.md).

> [!IMPORTANT]
> **mbscpy_s** não pode ser usado em aplicativos que são executados o tempo de execução do Windows. Para obter mais informações, confira [Funções do CRT sem suporte em aplicativos da Plataforma Universal do Windows](../../cppcx/crt-functions-not-supported-in-universal-windows-platform-apps.md).

## <a name="syntax"></a>Sintaxe

```C
errno_t strcpy_s(
   char *dest,
   rsize_t dest_size,
   const char *src
);
errno_t wcscpy_s(
   wchar_t *dest,
   rsize_t dest_size,
   const wchar_t *src
);
errno_t _mbscpy_s(
   unsigned char *dest,
   rsize_t dest_size,
   const unsigned char *src
);
```

```cpp
// Template functions are C++ only:
template <size_t size>
errno_t strcpy_s(
   char (&dest)[size],
   const char *src
); // C++ only
template <size_t size>
errno_t wcscpy_s(
   wchar_t (&dest)[size],
   const wchar_t *src
); // C++ only
template <size_t size>
errno_t _mbscpy_s(
   unsigned char (&dest)[size],
   const unsigned char *src
); // C++ only
```

### <a name="parameters"></a>Parâmetros

*dest*<br/>
Local do buffer de cadeia de caracteres de destino.

*dest_size*<br/>
Tamanho do buffer de cadeia de caracteres de destino em **char** unidades para funções estreitas e de vários bytes, e **wchar_t** unidades para as funções amplas. Esse valor deve ser maior que zero e não é maior que **RSIZE_MAX**.

*src*<br/>
Buffer de cadeia de caracteres de origem com terminação nula.

## <a name="return-value"></a>Valor de retorno

Zero se for bem-sucedido; caso contrário, um código de erro.

### <a name="error-conditions"></a>Condições de Erro

|*dest*|*dest_size*|*src*|Valor retornado|Conteúdo de *dest*|
|----------------------|------------------------|-----------------|------------------|----------------------------------|
|**NULL**|qualquer|qualquer|**EINVAL**|não modificado|
|qualquer|qualquer|**NULL**|**EINVAL**|*dest*[0] definido como 0|
|qualquer|0 ou muito pequeno|qualquer|**ERANGE**|*dest*[0] definido como 0|

## <a name="remarks"></a>Comentários

O **strcpy_s** função copia o conteúdo no endereço de *src*, incluindo o caractere null de terminação, para o local que é especificado pelo *dest*. A cadeia de caracteres de destino deve ser grande o suficiente para conter a cadeia de caracteres de origem e o caractere nulo de terminação. O comportamento de **strcpy_s** será indefinido se sobreponham as cadeias de caracteres de origem e de destino.

**wcscpy_s** é a versão de caractere largo de **strcpy_s**, e **mbscpy_s** é a versão de caracteres multibyte. Os argumentos de **wcscpy_s** são caracteres largos cadeias de caracteres; desses **mbscpy_s** são cadeias de caracteres multibyte. Caso contrário, essas três funções se comportam de forma idêntica.

Se *dest* ou *src* é um ponteiro nulo, ou se o tamanho da cadeia de caracteres de destino *dest_size* é muito pequeno, o manipulador de parâmetro inválido é invocado, conforme descrito em [Validação do parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução é permitida para continuar, essas funções retornam **EINVAL** e defina **errno** para **EINVAL** quando *dest* ou  *src* é um ponteiro nulo, e elas retornam **ERANGE** e defina **errno** para **ERANGE** quando a cadeia de caracteres de destino é muito pequena.

No caso de execução bem-sucedida, a cadeia de caracteres de destino é sempre terminada em nulo.

Em C++, o uso dessas funções é simplificado por sobrecargas de modelo que podem inferir o tamanho do buffer automaticamente, eliminando a necessidade de especificar um argumento de tamanho e podem substituir automaticamente funções mais antigas e menos seguras por equivalentes mais novas e mais seguras. Para obter mais informações, consulte [Sobrecargas de modelo seguro](../../c-runtime-library/secure-template-overloads.md).

As versões da biblioteca de depuração dessas funções primeiro preenchem o buffer com 0xFE. Para desabilitar esse comportamento, use [_CrtSetDebugFillThreshold](crtsetdebugfillthreshold.md).

### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico

|Rotina TCHAR.H|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|
|---------------------|------------------------------------|--------------------|-----------------------|
|**tcscpy_s**|**strcpy_s**|**_mbscpy_s**|**wcscpy_s**|

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**strcpy_s**|\<string.h>|
|**wcscpy_s**|\<string.h> ou \<wchar.h>|
|**_mbscpy_s**|\<mbstring.h>|

Essas funções são específicas da Microsoft. Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

Diferente do código de qualidade de produção, este exemplo chama as funções de cadeia de caracteres segura sem a verificação de erros:

```C
// crt_strcpy_s.c
// Compile by using: cl /W4 crt_strcpy_s.c
// This program uses strcpy_s and strcat_s
// to build a phrase.

#include <string.h>     // for strcpy_s, strcat_s
#include <stdlib.h>     // for _countof
#include <stdio.h>      // for printf
#include <errno.h>      // for return values

int main(void)
{
    char string[80];

    strcpy_s(string, _countof(string), "Hello world from ");
    strcat_s(string, _countof(string), "strcpy_s ");
    strcat_s(string, _countof(string), "and ");
    strcat_s(string, _countof(string), "strcat_s!");

    printf("String = %s\n", string);
}
```

```Output
String = Hello world from strcpy_s and strcat_s!
```

Ao compilar o código C++, as versões do modelo podem ser mais fácil de usar.

```cpp
// crt_wcscpy_s.cpp
// Compile by using: cl /EHsc /W4 crt_wcscpy_s.cpp
// This program uses wcscpy_s and wcscat_s
// to build a phrase.

#include <cstring>  // for wcscpy_s, wcscat_s
#include <cstdlib>  // for _countof
#include <iostream> // for cout, includes <cstdlib>, <cstring>
#include <errno.h>  // for return values

int main(void)
{
    wchar_t string[80];
    // using template versions of wcscpy_s and wcscat_s:
    wcscpy_s(string, L"Hello world from ");
    wcscat_s(string, L"wcscpy_s ");
    wcscat_s(string, L"and ");
    // of course we can supply the size explicitly if we want to:
    wcscat_s(string, _countof(string), L"wcscat_s!");

    std::wcout << L"String = " << string << std::endl;
}
```

```Output
String = Hello world from wcscpy_s and wcscat_s!
```

## <a name="see-also"></a>Consulte também

[Manipulação de cadeias de caracteres](../../c-runtime-library/string-manipulation-crt.md) <br/>
[strcat, wcscat, _mbscat](strcat-wcscat-mbscat.md) <br/>
[strcmp, wcscmp, _mbscmp](strcmp-wcscmp-mbscmp.md) <br/>
[strncat_s, _strncat_s_l, wcsncat_s, _wcsncat_s_l, _mbsncat_s, _mbsncat_s_l](strncat-s-strncat-s-l-wcsncat-s-wcsncat-s-l-mbsncat-s-mbsncat-s-l.md) <br/>
[strncmp, wcsncmp, _mbsncmp, _mbsncmp_l](strncmp-wcsncmp-mbsncmp-mbsncmp-l.md) <br/>
[strncpy_s, _strncpy_s_l, wcsncpy_s, _wcsncpy_s_l, _mbsncpy_s, _mbsncpy_s_l](strncpy-s-strncpy-s-l-wcsncpy-s-wcsncpy-s-l-mbsncpy-s-mbsncpy-s-l.md) <br/>
[_strnicmp, _wcsnicmp, _mbsnicmp, _strnicmp_l, _wcsnicmp_l, _mbsnicmp_l](strnicmp-wcsnicmp-mbsnicmp-strnicmp-l-wcsnicmp-l-mbsnicmp-l.md) <br/>
[strrchr, wcsrchr, _mbsrchr, _mbsrchr_l](strrchr-wcsrchr-mbsrchr-mbsrchr-l.md) <br/>
[strspn, wcsspn, _mbsspn, _mbsspn_l](strspn-wcsspn-mbsspn-mbsspn-l.md)<br/>
