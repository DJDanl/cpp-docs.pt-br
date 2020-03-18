---
title: _mbsnbcoll, _mbsnbcoll_l, _mbsnbicoll, _mbsnbicoll_l
ms.date: 11/04/2016
api_name:
- _mbsnbicoll_l
- _mbsnbcoll_l
- _mbsnbcoll
- _mbsnbicoll
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
api_type:
- DLLExport
topic_type:
- apiref
f1_keywords:
- _mbsnbcoll
- _mbsnbcoll_l
- _mbsnbicoll
- mbsnbcoll_l
helpviewer_keywords:
- _mbsnbcoll_l function
- mbsnbcoll_l function
- _mbsnbcoll function
- _tcsnicoll function
- mbsnbcoll function
- mbsnbicoll_l function
- mbsnbicoll function
- _tcsncoll function
- _mbsnbicoll function
- _mbsnbicoll_l function
- _tcsncoll_l function
- _tcsnicoll_l function
ms.assetid: d139ed63-ccba-4458-baa2-61cbcef03e94
ms.openlocfilehash: d759bda0133a95406a586011d39d69074283bf97
ms.sourcegitcommit: 63784729604aaf526de21f6c6b62813882af930a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/17/2020
ms.locfileid: "79438212"
---
# <a name="_mbsnbcoll-_mbsnbcoll_l-_mbsnbicoll-_mbsnbicoll_l"></a>_mbsnbcoll, _mbsnbcoll_l, _mbsnbicoll, _mbsnbicoll_l

Compara *n* bytes de duas cadeias de caracteres multibyte usando informações de página de código multibyte.

> [!IMPORTANT]
> Esta API não pode ser usada em aplicativos executados no Windows Runtime. Para obter mais informações, confira [Funções do CRT sem suporte em aplicativos da Plataforma Universal do Windows](../../cppcx/crt-functions-not-supported-in-universal-windows-platform-apps.md).

## <a name="syntax"></a>Sintaxe

```C
int _mbsnbcoll(
   const unsigned char *string1,
   const unsigned char *string2,
   size_t count
);
int _mbsnbcoll_l(
   const unsigned char *string1,
   const unsigned char *string2,
   size_t count,
   _locale_t locale
);
int _mbsnbicoll(
   const unsigned char *string1,
   const unsigned char *string2,
   size_t count
);
int _mbsnbicoll_l(
   const unsigned char *string1,
   const unsigned char *string2,
   size_t count,
   _locale_t locale
);
```

### <a name="parameters"></a>Parâmetros

*seqüência1*, *seqüência2*<br/>
Cadeias de caracteres a serem comparadas.

*count*<br/>
Número de bytes a serem comparados.

*locale*<br/>
Localidade a usar.

## <a name="return-value"></a>Valor retornado

O valor de retorno indica a relação das subcadeias de caracteres de *seqüência1* e *seqüência2*.

|Valor retornado|Descrição|
|------------------|-----------------|
|< 0|Subcadeia de caracteres *Cadeia1* menor que a subcadeia de *seqüência2* .|
|0|Subcadeia de caracteres *seqüência1* idêntica à subcadeia de *seqüência2* .|
|> 0|Subcadeia de caracteres *seqüência1* maior que a subcadeia de *seqüência2* .|

Se *string1* ou *string2* for **NULL** ou *Count* for maior que **INT_MAX**, o manipulador de parâmetro inválido será invocado, conforme descrito em [validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução puder continuar, essas funções retornarão **_NLSCMPERROR** e definirá **errno** como **EINVAL**. Para usar o **_NLSCMPERROR**, inclua String. h ou mbstring. h.

## <a name="remarks"></a>Comentários

Cada uma dessas funções agrupa, no máximo, os primeiros bytes de *contagem* em *seqüência1* e *seqüência2* e retorna um valor que indica a relação entre as subcadeias de caracteres resultante de *seqüência1* e *seqüência2*. Se o byte final na Subcadeia de caracteres *seqüência1* ou *seqüência2* for um byte de Lead, ele não será incluído na comparação; essas funções comparam apenas caracteres completos nas subcadeias. **_mbsnbicoll** é uma versão de **_mbsnbcoll**que não diferencia maiúsculas de minúsculas. Como [_mbsnbcmp](mbsnbcmp-mbsnbcmp-l.md) e [_mbsnbicmp](mbsnbicmp-mbsnbicmp-l.md), **_mbsnbcoll** e **_mbsnbicoll** agrupam as duas cadeias de caracteres multibyte de acordo com a ordem de lexicográfica especificada pela [página de código](../../c-runtime-library/code-pages.md) multibyte em uso no momento.

Para algumas páginas de código e conjuntos de caracteres correspondente, a ordem dos caracteres no conjunto de caracteres pode diferir da ordem de caracteres lexicográfica. Na localidade “C”, esse não é o caso: a ordem dos caracteres no conjunto de caracteres ASCII é a mesma que a ordem lexicográfica dos caracteres. No entanto, em algumas páginas de código europeias, por exemplo, o caractere “a” (valor 0x61) precede o caractere “ä” (valor 0xE4) no conjunto de caracteres, mas o caractere “ä” precede a caractere “a” lexicograficamente. Para executar uma comparação lexicográfica de cadeias de caracteres por bytes em uma instância desse tipo, use **_mbsnbcoll** em vez de **_mbsnbcmp**; para verificar apenas a igualdade da cadeia de caracteres, use **_mbsnbcmp**.

Como as funções **Coll** agrupam cadeias de caracteres modo lexicográfico para comparação, enquanto as funções **CMP** simplesmente testam a igualdade da cadeia de caracteres, as funções **Coll** são muito mais lentas do que as versões **CMP** correspondentes. Portanto, as funções **Coll** devem ser usadas somente quando há uma diferença entre a ordem de conjunto de caracteres e a ordem de caracteres lexicográfica na página de código atual e essa diferença é de interesse para a comparação.

O valor de saída é afetado pela configuração da categoria **LC_CTYPE** da localidade. Consulte [setlocale](setlocale-wsetlocale.md) para obter mais informações. As versões dessas funções sem o sufixo **_l** usam a localidade atual desse comportamento dependente da localidade. As versões com o sufixo **_l** são idênticas, exceto por usarem o parâmetro de localidade passado em seu lugar. Para obter mais informações, consulte [Localidade](../../c-runtime-library/locale.md).

### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico

|Rotina Tchar.h|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|
|---------------------|--------------------------------------|--------------------|-----------------------|
|**_tcsncoll**|[_strncoll](strncoll-wcsncoll-mbsncoll-strncoll-l-wcsncoll-l-mbsncoll-l.md)|**_mbsnbcoll**|[_wcsncoll](strncoll-wcsncoll-mbsncoll-strncoll-l-wcsncoll-l-mbsncoll-l.md)|
|**_tcsncoll_l**|[_strncoll, _wcsncoll, _mbsncoll, _strncoll_l, _wcsncoll_l, _mbsncoll_l](strncoll-wcsncoll-mbsncoll-strncoll-l-wcsncoll-l-mbsncoll-l.md)|**_mbsnbcoll_l**|[_wcsncoll_l](strncoll-wcsncoll-mbsncoll-strncoll-l-wcsncoll-l-mbsncoll-l.md)|
|**_tcsnicoll**|[_strnicoll](strnicoll-wcsnicoll-mbsnicoll-strnicoll-l-wcsnicoll-l-mbsnicoll-l.md)|**_mbsnbicoll**|[_wcsnicoll](strnicoll-wcsnicoll-mbsnicoll-strnicoll-l-wcsnicoll-l-mbsnicoll-l.md)|
|**_tcsnicoll_l**|[_strnicoll_l](strnicoll-wcsnicoll-mbsnicoll-strnicoll-l-wcsnicoll-l-mbsnicoll-l.md)|**_mbsnbicoll_l**|[_wcsnicoll_l](strnicoll-wcsnicoll-mbsnicoll-strnicoll-l-wcsnicoll-l-mbsnicoll-l.md)|

## <a name="requirements"></a>{1&gt;{2&gt;Requisitos&lt;2}&lt;1}

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**_mbsnbcoll**|\<mbstring.h>|
|**_mbsnbcoll_l**|\<mbstring.h>|
|**_mbsnbicoll**|\<mbstring.h>|
|**_mbsnbicoll_l**|\<mbstring.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="see-also"></a>Consulte também

[Manipulação de cadeias de caracteres](../../c-runtime-library/string-manipulation-crt.md)<br/>
[_mbsnbcat, _mbsnbcat_l](mbsnbcat-mbsnbcat-l.md)<br/>
[_mbsnbcmp, _mbsnbcmp_l](mbsnbcmp-mbsnbcmp-l.md)<br/>
[_mbsnbicmp, _mbsnbicmp_l](mbsnbicmp-mbsnbicmp-l.md)<br/>
[Funções strcoll](../../c-runtime-library/strcoll-functions.md)<br/>
[strncmp, wcsncmp, _mbsncmp, _mbsncmp_l](strncmp-wcsncmp-mbsncmp-mbsncmp-l.md)<br/>
[_strnicmp, _wcsnicmp, _mbsnicmp, _strnicmp_l, _wcsnicmp_l, _mbsnicmp_l](strnicmp-wcsnicmp-mbsnicmp-strnicmp-l-wcsnicmp-l-mbsnicmp-l.md)<br/>
