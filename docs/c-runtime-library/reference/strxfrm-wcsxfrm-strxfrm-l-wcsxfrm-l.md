---
title: strxfrm, wcsxfrm, _strxfrm_l, _wcsxfrm_l
ms.date: 4/2/2020
api_name:
- strxfrm
- _wcsxfrm_l
- _strxfrm_l
- wcsxfrm
- _o__strxfrm_l
- _o__wcsxfrm_l
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
- api-ms-win-crt-string-l1-1-0.dll
- api-ms-win-crt-private-l1-1-0
api_type:
- DLLExport
topic_type:
- apiref
f1_keywords:
- strxfrm
- _tcsxfrm
- wcsxfrm
helpviewer_keywords:
- strxfrm_l function
- _tcsxfrm function
- _strxfrm_l function
- strxfrm function
- wcsxfrm_l function
- wcsxfrm function
- string comparison [C++], transforming strings
- tcsxfrm function
- strings [C++], comparing locale
- _wcsxfrm_l function
ms.assetid: 6ba8e1f6-4484-49aa-83b8-bc2373187d9e
ms.openlocfilehash: aabe7e7c2e44f558b936e0fd4c6fa4a85dc582f5
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81362966"
---
# <a name="strxfrm-wcsxfrm-_strxfrm_l-_wcsxfrm_l"></a>strxfrm, wcsxfrm, _strxfrm_l, _wcsxfrm_l

Transforme uma cadeia de caracteres com base nas informações específicas à localidade.

## <a name="syntax"></a>Sintaxe

```C
size_t strxfrm(
   char *strDest,
   const char *strSource,
   size_t count
);
size_t wcsxfrm(
   wchar_t *strDest,
   const wchar_t *strSource,
   size_t count
);
size_t _strxfrm_l(
   char *strDest,
   const char *strSource,
   size_t count,
   _locale_t locale
);
size_t wcsxfrm_l(
   wchar_t *strDest,
   const wchar_t *strSource,
   size_t count,
   _locale_t locale
);
```

### <a name="parameters"></a>Parâmetros

*Strdest*<br/>
Cadeia de caracteres de destino.

*Strsource*<br/>
Cadeia de caracteres de origem.

*contagem*<br/>
Número máximo de caracteres a serem colocados em *strDest*.

*Localidade*<br/>
A localidade a ser usada.

## <a name="return-value"></a>Valor retornado

Retorna o tamanho da cadeia de caracteres transformada, sem contar o caractere nulo de terminação. Se o valor de retorno for maior ou igual a *contar,* o conteúdo do *strDest* é imprevisível. Em um erro, cada função define **errno** e retorna **INT_MAX**. Para um caractere inválido, **errno** é definido **como EILSEQ**.

## <a name="remarks"></a>Comentários

A função **strxfrm** transforma a seqüência apontada por *strSource* em uma nova forma coletizada que é armazenada em *strDest*. Não mais do que *contar* caracteres, incluindo o caractere nulo, são transformados e colocados na seqüência resultante. A transformação é feita usando a configuração de categoria **LC_COLLATE** do local. Para obter mais informações sobre **LC_COLLATE,** consulte [setlocale](setlocale-wsetlocale.md). **strxfrm** usa o local atual para seu comportamento dependente de localidades; **_strxfrm_l** é idêntica, exceto que usa o local passado em vez do local atual. Para obter mais informações, consulte [Localidade](../../c-runtime-library/locale.md).

Após a transformação, uma chamada para **estrangular** com as duas cordas transformadas produz resultados idênticos aos de uma chamada para **strcoll** aplicada às duas cordas originais. Como acontece com **strcoll** e **stricoll,** **strxfrm** lida automaticamente com cordas de caracteres multibytes conforme apropriado.

**wcsxfrm** é uma versão de amplo caráter de **strxfrm;** os argumentos de seqüência de **wcsxfrm** são ponteiros de caracteres largos. Para **wcsxfrm,** após a transformação das cordas, uma chamada para **wcscmp** com as duas cordas transformadas produz resultados idênticos aos de uma chamada para **wcscoll** aplicada às duas cordas originais. **wcsxfrm** e **strxfrm** se comportam de forma idêntica de outra forma. **o wcsxfrm** utiliza o local atual para seu comportamento dependente de localidades; **_wcsxfrm_l** usa o local passado em vez do local atual.

Essas funções validam seus parâmetros. Se *strSource* for um ponteiro nulo ou *strDest* é um ponteiro **NULL** (a menos que a contagem seja zero), ou se *a contagem* for maior que **INT_MAX,** o manipulador de parâmetros inválido sao invocado, conforme descrito na [Validação de Parâmetros](../../c-runtime-library/parameter-validation.md) . Se a execução for permitida, essas funções definem **errno** para **EINVAL** e retornam **INT_MAX**.

Por padrão, o estado global desta função é escopo para o aplicativo. Para mudar isso, consulte [Estado Global no CRT](../global-state.md).

### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico

|Rotina TCHAR.H|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|
|---------------------|------------------------------------|--------------------|-----------------------|
|**_tcsxfrm**|**strxfrm**|**strxfrm**|**wcsxfrm**|
|**_tcsxfrm_l**|**_strxfrm_l**|**_strxfrm_l**|**_wcsxfrm_l**|

Na localidade “C”, a ordem dos caracteres no conjunto de caracteres (conjunto de caracteres ASCII) é a mesma que a ordem lexicográfica dos caracteres. No entanto, em outras localidades, a ordem de caracteres no conjunto de caracteres pode ser diferente da ordem lexicográfica de caracteres. Por exemplo, em algumas localidades europeias, o caractere “a” (valor 0x61) precede o caractere “&\#x00E4;” (valor 0xE4) no conjunto de caracteres, mas o caractere “ä” precede a caractere “a” lexicograficamente.

Em locais para os quais o conjunto de caracteres e a ordem de caracteres lexicográficos diferem, use **strxfrm** nas cordas originais e, em seguida, **tride** sobre as cordas resultantes para produzir uma comparação de cordas lexicográficade de acordo com a configuração da categoria **de LC_COLLATE** do local atual. Assim, para comparar duas cordas lexicograficamente no local acima, use **strxfrm** nas cordas originais e, em seguida, **trieça** as cordas resultantes. Alternativamente, você pode usar **strcoll** em vez **de strcmp** nas strings originais.

**strxfrm** é basicamente um invólucro em torno [de LCMapString](/windows/win32/api/winnls/nf-winnls-lcmapstringw) com **LCMAP_SORTKEY**.

O valor da seguinte expressão é o tamanho da matriz necessária para segurar a transformação **strxfrm** da seqüência de origem:

`1 + strxfrm( NULL, string, 0 )`

Apenas no local "C", **strxfrm** é equivalente ao seguinte:

```C
strncpy( _string1, _string2, _count );
return( strlen( _string1 ) );
```

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**strxfrm**|\<string.h>|
|**wcsxfrm**|\<string.h> ou \<wchar.h>|
|**_strxfrm_l**|\<string.h>|
|**_wcsxfrm_l**|\<string.h> ou \<wchar.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="see-also"></a>Confira também

[Conversão de Dados](../../c-runtime-library/data-conversion.md)<br/>
[localeconv](localeconv.md)<br/>
[setlocale, _wsetlocale](setlocale-wsetlocale.md)<br/>
[Localidade](../../c-runtime-library/locale.md)<br/>
[Manipulação de cordas](../../c-runtime-library/string-manipulation-crt.md)<br/>
[Funções strcoll](../../c-runtime-library/strcoll-functions.md)<br/>
[strcmp, wcscmp, _mbscmp](strcmp-wcscmp-mbscmp.md)<br/>
[strncmp, wcsncmp, _mbsncmp, _mbsncmp_l](strncmp-wcsncmp-mbsncmp-mbsncmp-l.md)<br/>
