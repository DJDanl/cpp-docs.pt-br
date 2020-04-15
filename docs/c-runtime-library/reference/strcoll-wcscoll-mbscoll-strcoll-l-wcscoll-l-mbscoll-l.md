---
title: strcoll, wcscoll, _mbscoll, _strcoll_l, _wcscoll_l, _mbscoll_l
ms.date: 4/2/2020
api_name:
- wcscoll
- _mbscoll
- _mbscoll_l
- strcoll
- _strcoll_l
- _wcscoll_l
- _o__mbscoll
- _o__mbscoll_l
- _o__strcoll_l
- _o__wcscoll_l
- _o_strcoll
- _o_wcscoll
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
- api-ms-win-crt-multibyte-l1-1-0.dll
- api-ms-win-crt-string-l1-1-0.dll
- api-ms-win-crt-private-l1-1-0
api_type:
- DLLExport
topic_type:
- apiref
f1_keywords:
- wcscoll
- _mbscoll
- _tcscoll
- _ftcscoll
helpviewer_keywords:
- code pages, using for string comparisons
- mbscoll function
- wcscoll_l function
- ftcscoll function
- wcscoll function
- _strcoll_l function
- tcscoll function
- _ftcscoll function
- _tcscoll function
- _wcscoll_l function
- _mbscoll function
- strcoll_l function
- strcoll functions
- strings [C++], comparing by code page
ms.assetid: 900a7540-c7ec-4c2f-b292-7a85f63e3fe8
ms.openlocfilehash: 9cbf24fafa78ac6a53a99abf0d1bb1ab3a0625c3
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81358125"
---
# <a name="strcoll-wcscoll-_mbscoll-_strcoll_l-_wcscoll_l-_mbscoll_l"></a>strcoll, wcscoll, _mbscoll, _strcoll_l, _wcscoll_l, _mbscoll_l

Compara cadeias de caracteres usando a localidade atual ou uma categoria de estado de conversão LC_COLLATE especificada.

> [!IMPORTANT]
> **_mbscoll** e **_mbscoll_l** não podem ser usados em aplicativos executados no Tempo de Execução do Windows. Para obter mais informações, confira [Funções do CRT sem suporte em aplicativos da Plataforma Universal do Windows](../../cppcx/crt-functions-not-supported-in-universal-windows-platform-apps.md).

## <a name="syntax"></a>Sintaxe

```C
int strcoll(
   const char *string1,
   const char *string2
);
int wcscoll(
   const wchar_t *string1,
   const wchar_t *string2
);
int _mbscoll(
   const unsigned char *string1,
   const unsigned char *string2
);
int _strcoll_l(
   const char *string1,
   const char *string2,
   _locale_t locale
);
int wcscoll_l(
   const wchar_t *string1,
   const wchar_t *string2,
   _locale_t locale
);
int _mbscoll_l(
   const unsigned char *string1,
   const unsigned char *string2,
   _locale_t locale
);
```

### <a name="parameters"></a>Parâmetros

*string1,* *string2*<br/>
Cadeias de caracteres com terminação nula.

*Localidade*<br/>
Localidade a usar.

## <a name="return-value"></a>Valor retornado

Cada uma dessas funções retorna um valor indicando a relação de *string1* com *string2*, da seguinte forma.

|Valor retornado|Relação da string1 com a string2|
|------------------|----------------------------------------|
|< 0|*string1* menos que *string2*|
|0|*string1* idêntico à *string2*|
|> 0|*string1* maior que *string2*|

Cada uma dessas funções retorna **_NLSCMPERROR** em um erro. Para **usá_NLSCMPERROR,** inclua STRING. H ou MBSTRING. H. **wcscoll** pode falhar se *string1* ou *string2* **forNULL** ou contiver códigos de caracteres amplos fora do domínio da seqüência de colisão. Quando ocorre um erro, **o wcscoll** pode definir **errno** para **EINVAL**. Para verificar se há um erro em uma chamada para **wcscoll**, definir **errno** para 0 e, em seguida, verificar **errno** depois de chamar **wcscoll**.

## <a name="remarks"></a>Comentários

Cada uma dessas funções realiza uma comparação sensível a maiúsculas e minúsculas de *string1* e *string2* de acordo com a página de código atualmente em uso. Essas funções devem ser usadas somente quando há uma diferença entre a ordem de conjunto de caracteres e a ordem lexicográfica de caracteres na página de código atual e essa diferença é de interesse para a comparação de cadeia de caracteres.

Todas essas funções validam seus parâmetros. Se *string1* ou *string2* for um ponteiro nulo ou se *a contagem* for maior que **INT_MAX,** o manipulador de parâmetros inválidos é invocado, conforme descrito na [Validação de Parâmetros](../../c-runtime-library/parameter-validation.md) . Se a execução continuar, essas funções retornam **_NLSCMPERROR** e definem **errno** para **EINVAL**.

A comparação de duas cadeias de caracteres é uma operação dependente de localidade, já que cada localidade tem regras diferentes para classificar caracteres. As versões dessas funções sem o **sufixo _l** usam a localidade do segmento atual para este comportamento dependente da localidade; as versões com o **sufixo _l** são idênticas à função correspondente sem o sufixo, exceto que eles usam a localidade passada como parâmetro em vez da localização atual. Para obter mais informações, consulte [Localidade](../../c-runtime-library/locale.md).

Por padrão, o estado global desta função é escopo para o aplicativo. Para mudar isso, consulte [Estado Global no CRT](../global-state.md).

### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico

|Rotina TCHAR.H|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|
|---------------------|------------------------------------|--------------------|-----------------------|
|**_tcscoll**|**strcoll**|**_mbscoll**|**wcscoll**|

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**strcoll**|\<string.h>|
|**wcscoll**|\<wchar.h>, \<string.h>|
|**_mbscoll** **_mbscoll_l.**|\<mbstring.h>|
|**_strcoll_l**|\<string.h>|
|**_wcscoll_l**|\<wchar.h>, \<string.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="see-also"></a>Confira também

[Localidade](../../c-runtime-library/locale.md)<br/>
[Manipulação de cordas](../../c-runtime-library/string-manipulation-crt.md)<br/>
[Funções strcoll](../../c-runtime-library/strcoll-functions.md)<br/>
[localeconv](localeconv.md)<br/>
[_mbsnbcoll, _mbsnbcoll_l, _mbsnbicoll, _mbsnbicoll_l](mbsnbcoll-mbsnbcoll-l-mbsnbicoll-mbsnbicoll-l.md)<br/>
[setlocale, _wsetlocale](setlocale-wsetlocale.md)<br/>
[strcmp, wcscmp, _mbscmp](strcmp-wcscmp-mbscmp.md)<br/>
[_stricmp, _wcsicmp, _mbsicmp, _stricmp_l, _wcsicmp_l, _mbsicmp_l](stricmp-wcsicmp-mbsicmp-stricmp-l-wcsicmp-l-mbsicmp-l.md)<br/>
[strncmp, wcsncmp, _mbsncmp, _mbsncmp_l](strncmp-wcsncmp-mbsncmp-mbsncmp-l.md)<br/>
[_strnicmp, _wcsnicmp, _mbsnicmp, _strnicmp_l, _wcsnicmp_l, _mbsnicmp_l](strnicmp-wcsnicmp-mbsnicmp-strnicmp-l-wcsnicmp-l-mbsnicmp-l.md)<br/>
[strxfrm, wcsxfrm, _strxfrm_l, _wcsxfrm_l](strxfrm-wcsxfrm-strxfrm-l-wcsxfrm-l.md)<br/>
