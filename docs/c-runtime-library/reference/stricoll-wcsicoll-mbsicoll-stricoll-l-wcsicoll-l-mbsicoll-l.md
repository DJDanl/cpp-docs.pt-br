---
title: _stricoll, _wcsicoll, _mbsicoll, _stricoll_l, _wcsicoll_l, _mbsicoll_l
ms.date: 4/2/2020
api_name:
- _mbsicoll_l
- _stricoll_l
- _mbsicoll
- _wcsicoll_l
- _wcsicoll
- _stricoll
- _o__mbsicoll
- _o__mbsicoll_l
- _o__stricoll
- _o__stricoll_l
- _o__wcsicoll
- _o__wcsicoll_l
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
- api-ms-win-crt-private-l1-1-0.dll
api_type:
- DLLExport
topic_type:
- apiref
f1_keywords:
- stricoll
- _stricoll
- _wcsicoll
- mbsicoll_l
- _mbsicoll
- _ftcsicoll
- wcsicoll_l
- _tcsicoll
- mbsicoll
- stricoll_l
helpviewer_keywords:
- code pages, using for string comparisons
- _ftcsicoll function
- _mbsicoll_l function
- _mbsicoll function
- mbsicoll function
- stricoll function
- tcsicoll function
- string comparison [C++], culture-specific
- _tcsicoll function
- _stricoll function
- _stricoll_l function
- _wcsicoll function
- mbsicoll_l function
- stricoll_l function
- strings [C++], comparing by code page
- ftcsicoll function
ms.assetid: 8ec93016-5a49-49d2-930f-721566661d82
ms.openlocfilehash: 9c023405043dea1c0a1d8e6d7f6fcc6505677583
ms.sourcegitcommit: 5a069c7360f75b7c1cf9d4550446ec2fa2eb2293
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2020
ms.locfileid: "82919999"
---
# <a name="_stricoll-_wcsicoll-_mbsicoll-_stricoll_l-_wcsicoll_l-_mbsicoll_l"></a>_stricoll, _wcsicoll, _mbsicoll, _stricoll_l, _wcsicoll_l, _mbsicoll_l

Compara cadeias de caracteres usando informações específicas de localidade.

> [!IMPORTANT]
> **_mbsicoll** e **_mbsicoll_l** não podem ser usados em aplicativos que são executados no Windows Runtime. Para obter mais informações, confira [Funções do CRT sem suporte em aplicativos da Plataforma Universal do Windows](../../cppcx/crt-functions-not-supported-in-universal-windows-platform-apps.md).

## <a name="syntax"></a>Sintaxe

```C
int _stricoll(
   const char *string1,
   const char *string2
);
int _wcsicoll(
   const wchar_t *string1,
   const wchar_t *string2
);
int _mbsicoll(
   const unsigned char *string1,
   const unsigned char *string2
);
int _stricoll_l(
   const char *string1,
   const char *string2,
   _locale_t locale
);
int _wcsicoll_l(
   const wchar_t *string1,
   const wchar_t *string2,
   _locale_t locale
);
int _mbsicoll_l(
   const unsigned char *string1,
   const unsigned char *string2,
   _locale_t locale
);
```

### <a name="parameters"></a>Parâmetros

*seqüência1*, *seqüência2*<br/>
Cadeias de caracteres com terminação nula.

*locale*<br/>
A localidade a ser usada.

## <a name="return-value"></a>Valor retornado

Cada uma dessas funções retorna um valor que indica a relação de *seqüência1* para *seqüência2*, como a seguir.

|Valor retornado|Relação da string1 com a string2|
|------------------|----------------------------------------|
|< 0|*seqüência1* menor que *seqüência2*|
|0|*seqüência1* idêntico a *seqüência2*|
|> 0|*seqüência1* maior que *seqüência2*|
|**_NLSCMPERROR**|Ocorreu um erro.|

Cada uma dessas funções retorna **_NLSCMPERROR**. Para usar **_NLSCMPERROR**, inclua a \<cadeia de caracteres. h \<> ou mbstring. h>. **_wcsicoll** poderá falhar se *seqüência1* ou *seqüência2* contiver códigos de caracteres largos fora do domínio da sequência de agrupamento. Quando ocorre um erro, **_wcsicoll** pode definir **errno** como **EINVAL**. Para verificar se há um erro em uma chamada para **_wcsicoll**, defina **errno** como 0 e, em seguida, marque **errno** depois de chamar **_wcsicoll**.

## <a name="remarks"></a>Comentários

Cada uma dessas funções executa uma comparação que não diferencia maiúsculas de minúsculas de *seqüência1* e *seqüência2* de acordo com a página de código em uso no momento. Essas funções devem ser usadas somente quando há uma diferença entre a ordem de conjunto de caracteres e a ordem lexicográfica de caracteres na página de código atual e essa diferença é de interesse para a comparação de cadeia de caracteres.

**_stricmp** difere de **_stricoll** no que a comparação de **_stricmp** é afetada pelo **LC_CTYPE**, enquanto a comparação de **_stricoll** é de acordo com as categorias **LC_CTYPE** **e LC_COLLATE da** localidade. Para obter mais informações sobre **LC_COLLATE** a categoria de LC_COLLATE [, consulte categorias de local e](setlocale-wsetlocale.md) de [localidade](../../c-runtime-library/locale-categories.md). As versões dessas funções sem o sufixo **_L** usam a localidade atual; as versões com o sufixo **_L** são idênticas, exceto que usam a localidade passada em vez disso. Para obter mais informações, consulte [Localidade](../../c-runtime-library/locale.md).

Todas essas funções validam seus parâmetros. Se *seqüência1* ou *seqüência2* forem ponteiros **nulos** , o manipulador de parâmetro inválido será invocado, conforme descrito em [validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução puder continuar, essas funções retornarão **_NLSCMPERROR** e definirá **errno** como **EINVAL**.

Por padrão, o estado global dessa função tem como escopo o aplicativo. Para alterar isso, consulte [estado global no CRT](../global-state.md).

### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico

|Rotina TCHAR.H|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|
|---------------------|------------------------------------|--------------------|-----------------------|
|**_tcsicoll**|**_stricoll**|**_mbsicoll**|**_wcsicoll**|

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**_stricoll**, **_stricoll_l**|\<string.h>|
|**_wcsicoll**, **_wcsicoll_l**|\<wchar.h>, \<string.h>|
|**_mbsicoll**, **_mbsicoll_l**|\<mbstring.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="see-also"></a>Consulte também

[Locale](../../c-runtime-library/locale.md)<br/>
[Manipulação de cadeia de caracteres](../../c-runtime-library/string-manipulation-crt.md)<br/>
[Funções strcoll](../../c-runtime-library/strcoll-functions.md)<br/>
[localeconv](localeconv.md)<br/>
[_mbsnbcoll, _mbsnbcoll_l, _mbsnbicoll, _mbsnbicoll_l](mbsnbcoll-mbsnbcoll-l-mbsnbicoll-mbsnbicoll-l.md)<br/>
[setlocale, _wsetlocale](setlocale-wsetlocale.md)<br/>
[strcmp, wcscmp, _mbscmp](strcmp-wcscmp-mbscmp.md)<br/>
[_stricmp, _wcsicmp, _mbsicmp, _stricmp_l, _wcsicmp_l, _mbsicmp_l](stricmp-wcsicmp-mbsicmp-stricmp-l-wcsicmp-l-mbsicmp-l.md)<br/>
[strncmp, wcsncmp, _mbsncmp, _mbsncmp_l](strncmp-wcsncmp-mbsncmp-mbsncmp-l.md)<br/>
[_strnicmp, _wcsnicmp, _mbsnicmp, _strnicmp_l, _wcsnicmp_l, _mbsnicmp_l](strnicmp-wcsnicmp-mbsnicmp-strnicmp-l-wcsnicmp-l-mbsnicmp-l.md)<br/>
[strxfrm, wcsxfrm, _strxfrm_l, _wcsxfrm_l](strxfrm-wcsxfrm-strxfrm-l-wcsxfrm-l.md)<br/>
