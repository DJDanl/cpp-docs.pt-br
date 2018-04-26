---
title: _strncoll, _wcsncoll, _mbsncoll, _strncoll_l, _wcsncoll_l, _mbsncoll_l | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.reviewer: ''
ms.suite: ''
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: ''
ms.topic: reference
apiname:
- _strncoll
- _mbsncoll_l
- _wcsncoll
- _wcsncoll_l
- _mbsncoll
- _strncoll_l
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
- mbsncoll_l
- strncoll
- _wcsncoll
- _tcsnccoll
- _ftcsnccoll
- wcsncoll
- _mbsncoll
- wcsncoll_l
- strncoll_l
- _ftcsncoll
- _strncoll
- _tcsncoll
- mbsncoll
dev_langs:
- C++
helpviewer_keywords:
- _strncoll_l function
- code pages, using for string comparisons
- _strncoll function
- _mbsncoll function
- ftcsncoll function
- strncoll function
- _ftcsncoll function
- strncoll_l function
- wcsncoll function
- mbsncoll function
- _tcsncoll function
- _tcsnccoll function
- wcsncoll_l function
- tcsnccoll function
- mbsncoll_l function
- _mbsncoll_l function
- tcsncoll function
- _wcsncoll function
- strings [C++], comparing by code page
- _ftcsnccoll function
- ftcsnccoll function
- _wcsncoll_l function
ms.assetid: e659a5a4-8afe-4033-8e72-17ffd4bdd8e9
caps.latest.revision: 21
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: ab49ecde97cd7cf4bfba68ac886e12e411206f83
ms.sourcegitcommit: ef859ddf5afea903711e36bfd89a72389a12a8d6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/20/2018
---
# <a name="strncoll-wcsncoll-mbsncoll-strncolll-wcsncolll-mbsncolll"></a>_strncoll, _wcsncoll, _mbsncoll, _strncoll_l, _wcsncoll_l, _mbsncoll_l

Compara cadeias de caracteres usando informações específicas de localidade.

> [!IMPORTANT]
> **mbsncoll** e **mbsncoll_l** não pode ser usado em aplicativos que são executados o tempo de execução do Windows. Para obter mais informações, confira [Funções do CRT sem suporte em aplicativos da Plataforma Universal do Windows](../../cppcx/crt-functions-not-supported-in-universal-windows-platform-apps.md).

## <a name="syntax"></a>Sintaxe

```C
int _strncoll(
   const char *string1,
   const char *string2,
   size_t count
);
int _wcsncoll(
   const wchar_t *string1,
   const wchar_t *string2,
   size_t count
);
int _mbsncoll(
   const unsigned char *string1,
   const unsigned char *string2,
   size_t count
);
int _strncoll_l(
   const char *string1,
   const char *string2,
   size_t count,
   _locale_t locale
);
int _wcsncoll_l(
   const wchar_t *string1,
   const wchar_t *string2,
   size_t count,
   _locale_t locale
);
int _mbsncoll_l(
   const unsigned char *string1,
   const unsigned char *string2,
   size_t count,
   _locale_t locale
);
```

### <a name="parameters"></a>Parâmetros

*string1*, *string2*<br/>
Cadeias de caracteres com terminação nula.

*count*<br/>
O número de caracteres a ser comparado.

*locale*<br/>
A localidade a ser usada.

## <a name="return-value"></a>Valor de retorno

Cada uma dessas funções retorna um valor que indica a relação de subcadeias de caracteres de *string1* e *string2*, da seguinte maneira.

|Valor retornado|Relação da string1 com a string2|
|------------------|----------------------------------------|
|< 0|*string1* é menor que *string2*.|
|0|*string1* é idêntico ao *string2*.|
|> 0|*string1* é maior do que *string2*.|

Cada uma dessas funções retorna **_NLSCMPERROR**. Para usar **_NLSCMPERROR**, incluir STRING.h ou MBSTRING.h. **wcsncoll** pode falhar se *string1* ou *string2* contém códigos de caractere largo que estão fora do domínio da sequência de agrupamento. Quando ocorre um erro, **wcsncoll** podem definir **errno** para **EINVAL**. Para verificar se há um erro em uma chamada para **wcsncoll**, defina **errno** como 0 e, em seguida, verifique **errno** depois de chamar **wcsncoll**.

## <a name="remarks"></a>Comentários

Cada uma dessas funções executa uma comparação diferencia maiusculas e minúsculas do primeiro *contagem* caracteres de *string1* e *string2*, de acordo com a página de código que está no momento Use. Use essas funções somente quando há uma diferença entre a ordem do conjunto de caracteres e a ordem lexicográfica dos caracteres na página de código atual e essa diferença é de interesse para a comparação de cadeia de caracteres. A ordem do conjunto de caracteres é dependente de localidade. As versões dessas funções que não têm o **_l** uso de sufixo a localidade atual, mas as versões que têm o **_l** sufixo usam a localidade que é transmitida. Para obter mais informações, consulte [Localidade](../../c-runtime-library/locale.md).

Todas essas funções validam seus parâmetros. Se qualquer um dos *string1* ou *string2* é um ponteiro nulo, ou *contagem* é maior do que **INT_MAX**, o manipulador de parâmetro inválido é invocado, conforme descrito em [validação do parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução é permitida para continuar, essas funções retornam **_NLSCMPERROR** e defina **errno** para **EINVAL**.

### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico

|Rotina TCHAR.H|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|
|---------------------|------------------------------------|--------------------|-----------------------|
|**tcsnccoll**|**_strncoll**|**_mbsncoll**|**_wcsncoll**|
|**tcsncoll**|**_strncoll**|[_mbsnbcoll](mbsnbcoll-mbsnbcoll-l-mbsnbicoll-mbsnbicoll-l.md)|**_wcsncoll**|

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**strncoll**, **strncoll_l**|\<string.h>|
|**wcsncoll**, **wcsncoll_l**|\<wchar.h> or \<string.h>|
|**mbsncoll**, **mbsncoll_l**|\<mbstring.h>|

Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="see-also"></a>Consulte também

[Localidade](../../c-runtime-library/locale.md)<br/>
[Manipulação de cadeias de caracteres](../../c-runtime-library/string-manipulation-crt.md)<br/>
[Funções strcoll](../../c-runtime-library/strcoll-functions.md)<br/>
[localeconv](localeconv.md)<br/>
[_mbsnbcoll, _mbsnbcoll_l, _mbsnbicoll, _mbsnbicoll_l](mbsnbcoll-mbsnbcoll-l-mbsnbicoll-mbsnbicoll-l.md)<br/>
[setlocale, _wsetlocale](setlocale-wsetlocale.md)<br/>
[strcmp, wcscmp, _mbscmp](strcmp-wcscmp-mbscmp.md)<br/>
[_stricmp, _wcsicmp, _mbsicmp, _stricmp_l, _wcsicmp_l, _mbsicmp_l](stricmp-wcsicmp-mbsicmp-stricmp-l-wcsicmp-l-mbsicmp-l.md)<br/>
[strncmp, wcsncmp, _mbsncmp, _mbsncmp_l](strncmp-wcsncmp-mbsncmp-mbsncmp-l.md)<br/>
[_strnicmp, _wcsnicmp, _mbsnicmp, _strnicmp_l, _wcsnicmp_l, _mbsnicmp_l](strnicmp-wcsnicmp-mbsnicmp-strnicmp-l-wcsnicmp-l-mbsnicmp-l.md)<br/>
[strxfrm, wcsxfrm, _strxfrm_l, _wcsxfrm_l](strxfrm-wcsxfrm-strxfrm-l-wcsxfrm-l.md)<br/>
