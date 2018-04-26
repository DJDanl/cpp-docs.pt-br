---
title: _strlwr_s, _strlwr_s_l, _mbslwr_s, _mbslwr_s_l, _wcslwr_s, _wcslwr_s_l | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.reviewer: ''
ms.suite: ''
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: ''
ms.topic: reference
apiname:
- _strlwr_s_l
- _mbslwr_s_l
- _mbslwr_s
- _wcslwr_s
- _strlwr_s
- _wcslwr_s_l
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
- _strlwr_s_l
- _strlwr_s
- mbslwr_s_l
- strlwr_s_l
- _wcslwr_s
- strlwr_s
- mbslwr_s
- _wcslwr_s_l
- wcslwr_s_l
- _tcslwr_s
- _tcslwr_s_l
- _mbslwr_s_l
- wcslwr_s
- _mbslwr_s
dev_langs:
- C++
helpviewer_keywords:
- _tcslwr_s function
- wcslwr_s function
- _mbslwr_s function
- _wcslwr_s function
- strlwr_s_l function
- mbslwr_s_l function
- _strlwr_s function
- string conversion [C++], case
- strlwr_s function
- wcslwr_s_l function
- _tcslwr_s_l function
- mbslwr_s function
- strings [C++], case
- _wcslwr_s_l function
- converting case, CRT functions
- _strlwr_s_l function
- _mbslwr_s_l function
- case, converting
- tcslwr_s function
- tcslwr_s_l function
- strings [C++], converting case
ms.assetid: 4883d31b-bdac-4049-83a1-91dfdeceee79
caps.latest.revision: 42
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 945616409565cca278ee71bf77c9fee26c821133
ms.sourcegitcommit: ef859ddf5afea903711e36bfd89a72389a12a8d6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/20/2018
---
# <a name="strlwrs-strlwrsl-mbslwrs-mbslwrsl-wcslwrs-wcslwrsl"></a>_strlwr_s, _strlwr_s_l, _mbslwr_s, _mbslwr_s_l, _wcslwr_s, _wcslwr_s_l

Converte uma cadeia de caracteres em minúsculas, usando a localidade atual ou um objeto de localidade que é passado. Essas versões de [_strlwr, _wcslwr, _mbslwr, _strlwr_l, _wcslwr_l, _mbslwr_l](strlwr-wcslwr-mbslwr-strlwr-l-wcslwr-l-mbslwr-l.md) têm aprimoramentos de segurança, conforme descrito em [Recursos de segurança no CRT](../../c-runtime-library/security-features-in-the-crt.md).

> [!IMPORTANT]
> **mbslwr_s** e **mbslwr_s_l** não pode ser usado em aplicativos que são executados o tempo de execução do Windows. Para obter mais informações, confira [Funções do CRT sem suporte em aplicativos da Plataforma Universal do Windows](../../cppcx/crt-functions-not-supported-in-universal-windows-platform-apps.md).

## <a name="syntax"></a>Sintaxe

```C
errno_t _strlwr_s(
   char *str,
   size_t numberOfElements
);
errno_t _strlwr_s_l(
   char *str,
   size_t numberOfElements,
   _locale_t locale
);
errno_t _mbslwr_s(
   unsigned char *str,
   size_t numberOfElements
);
errno_t _mbslwr_s_l(
   unsigned char *str,
   size_t numberOfElements,
   _locale_t locale
);
errno_t _wcslwr_s(
   wchar_t *str,
   size_t numberOfElements
);
errno_t _wcslwr_s_l(
   wchar_t *str,
   size_t numberOfElements,
   _locale_t locale
);
template <size_t size>
errno_t _strlwr_s(
   char (&str)[size]
); // C++ only
template <size_t size>
errno_t _strlwr_s_l(
   char (&str)[size],
   _locale_t locale
); // C++ only
template <size_t size>
errno_t _mbslwr_s(
   unsigned char (&str)[size]
); // C++ only
template <size_t size>
errno_t _mbslwr_s_l(
   unsigned char (&str)[size],
   _locale_t locale
); // C++ only
template <size_t size>
errno_t _wcslwr_s(
   wchar_t (&str)[size]
); // C++ only
template <size_t size>
errno_t _wcslwr_s_l(
   wchar_t (&str)[size],
   _locale_t locale
); // C++ only
```

### <a name="parameters"></a>Parâmetros

*str*<br/>
Sequência de terminação nula para converter em minúsculas.

*numberOfElements*<br/>
O tamanho do buffer.

*locale*<br/>
A localidade a ser usada.

## <a name="return-value"></a>Valor de retorno

Zero se tiver êxito; um código de erro diferente de zero em caso de falha.

Essas funções validam seus parâmetros. Se *str* não é uma cadeia válida de terminação nula, o manipulador de parâmetro inválido é invocado, conforme descrito em [validação do parâmetro](../../c-runtime-library/parameter-validation.md) . Se a execução é permitida para continuar, as funções retornam **EINVAL** e defina **errno** para **EINVAL**. Se *numberOfElements* é menor que o comprimento da cadeia de caracteres, as funções também retornam **EINVAL** e defina **errno** para **EINVAL**.

## <a name="remarks"></a>Comentários

O **strlwr_s** converte de função, no lugar, qualquer letras maiusculas no *str* em minúsculas. **mbslwr_s** é uma versão de caracteres multibyte do **strlwr_s**. **wcslwr_s** é uma versão de caractere largo de **strlwr_s**.

O valor de saída é afetado pela configuração do **LC_CTYPE** configuração de categoria da localidade, consulte [setlocale](setlocale-wsetlocale.md) para obter mais informações. As versões dessas funções sem o sufixo **_l** usam a localidade atual desse comportamento dependente da localidade. As versões com o sufixo **_l** são idênticas, exceto por usarem o parâmetro de localidade passado em seu lugar. Para obter mais informações, consulte [Localidade](../../c-runtime-library/locale.md).

Em C++, o uso dessas funções é simplificado pelas sobrecargas de modelo; as sobrecargas podem inferir o tamanho do buffer automaticamente (eliminando a necessidade de especificar um argumento de tamanho) e podem substituir automaticamente funções mais antigas e não seguras por suas equivalentes mais recentes e seguras. Para obter mais informações, consulte [Sobrecargas de modelo seguro](../../c-runtime-library/secure-template-overloads.md).

As versões de depuração dessas funções preenchem primeiro o buffer com 0xFD. Para desabilitar esse comportamento, use [_CrtSetDebugFillThreshold](crtsetdebugfillthreshold.md).

### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico

|Rotina TCHAR.H|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|
|---------------------|------------------------------------|--------------------|-----------------------|
|**tcslwr_s**|**_strlwr_s**|**_mbslwr_s**|**_wcslwr_s**|
|**tcslwr_s_l**|**_strlwr_s_l**|**_mbslwr_s_l**|**_wcslwr_s_l**|

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**strlwr_s**, **strlwr_s_l**|\<string.h>|
|**mbslwr_s**, **mbslwr_s_l**|\<mbstring.h>|
|**wcslwr_s**, **wcslwr_s_l**|\<string.h> ou \<wchar.h>|

Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

```cpp
// crt_strlwr_s.cpp
// This program uses _strlwr_s and _strupr_s to create
// uppercase and lowercase copies of a mixed-case string.
//

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
   char str[] = "The String to End All Strings!";
   char *copy1, *copy2;
   errno_t err;

   err = _strlwr_s( copy1 = _strdup(str), strlen(str) + 1);
   err = _strupr_s( copy2 = _strdup(str), strlen(str) + 1);

   printf( "Mixed: %s\n", str );
   printf( "Lower: %s\n", copy1 );
   printf( "Upper: %s\n", copy2 );

   free( copy1 );
   free( copy2 );

   return 0;
}
```

```Output
Mixed: The String to End All Strings!
Lower: the string to end all strings!
Upper: THE STRING TO END ALL STRINGS!
```

## <a name="see-also"></a>Consulte também

[Manipulação de cadeias de caracteres](../../c-runtime-library/string-manipulation-crt.md)<br/>
[Localidade](../../c-runtime-library/locale.md)<br/>
[Interpretação de sequências de caracteres multibyte](../../c-runtime-library/interpretation-of-multibyte-character-sequences.md)<br/>
[_strupr_s, _strupr_s_l, _mbsupr_s, _mbsupr_s_l, _wcsupr_s, _wcsupr_s_l](strupr-s-strupr-s-l-mbsupr-s-mbsupr-s-l-wcsupr-s-wcsupr-s-l.md)<br/>
