---
title: strxfrm, wcsxfrm, _strxfrm_l, _wcsxfrm_l
ms.date: 11/04/2016
apiname:
- strxfrm
- _wcsxfrm_l
- _strxfrm_l
- wcsxfrm
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
- api-ms-win-crt-string-l1-1-0.dll
apitype: DLLExport
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
ms.openlocfilehash: e4dc94d76562daf10544e9b0d09d9608bd83e454
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69500779"
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

*strDest*<br/>
Cadeia de caracteres de destino.

*strSource*<br/>
Cadeia de caracteres de origem.

*count*<br/>
Número máximo de caracteres a serem colocados em *strDest*.

*locale*<br/>
A localidade a ser usada.

## <a name="return-value"></a>Valor de retorno

Retorna o tamanho da cadeia de caracteres transformada, sem contar o caractere nulo de terminação. Se o valor de retorno for maior ou igual à *contagem*, o conteúdo de *strDest* será imprevisível. Em um erro, cada função define **errno** e retorna **INT_MAX**. Para um caractere inválido, **errno** é definido como **EILSEQ**.

## <a name="remarks"></a>Comentários

A função **strxfrm** transforma a cadeia de caracteres apontada por *strSource* em um novo formulário agrupado armazenado em *strDest*. Não mais do que *contar* caracteres, incluindo o caractere nulo, são transformados e colocados na cadeia de caracteres resultante. A transformação é feita usando a configuração de categoria **LC_COLLATE** da localidade. Para obter mais informações sobre o **LC_COLLATE**, consulte [setlocaling](setlocale-wsetlocale.md). **strxfrm** usa a localidade atual para seu comportamento dependente de localidade; **_strxfrm_l** é idêntico, exceto pelo fato de que ele usa a localidade passada em vez da localidade atual. Para obter mais informações, consulte [Localidade](../../c-runtime-library/locale.md).

Após a transformação, uma chamada para **strcmp** com as duas cadeias de caracteres transformadas produz resultados idênticos aos de uma chamada para **strcoll** aplicada às duas cadeias de caracteres originais. Assim como com **strcoll** e **stricoll**, o **strxfrm** manipula automaticamente cadeias de caracteres multibyte conforme apropriado.

**wcsxfrm** é uma versão de caractere largo do **strxfrm**; os argumentos de cadeia de caracteres de **wcsxfrm** são ponteiros de caracteres largos. Para **wcsxfrm**, após a transformação da cadeia de caracteres, uma chamada para **wcscmp** com as duas cadeias de caracteres transformadas produz resultados idênticos aos de uma chamada para **wcscoll** aplicada às duas cadeias de caracteres originais. **wcsxfrm** e **strxfrm** se comportam de outra forma. **wcsxfrm** usa a localidade atual para seu comportamento dependente de localidade; **_wcsxfrm_l** usa a localidade passada em vez da localidade atual.

Essas funções validam seus parâmetros. Se *strSource* for um ponteiro nulo ou *strDest* for um ponteiro **nulo** (a menos que Count seja zero), ou se *Count* for maior que **INT_MAX**, o manipulador de parâmetro inválido será invocado, conforme descrito em validação de [parâmetro](../../c-runtime-library/parameter-validation.md) . Se a execução puder continuar, essas funções definirão **errno** como **EINVAL** e retornarão **INT_MAX**.

### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico

|Rotina TCHAR.H|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|
|---------------------|------------------------------------|--------------------|-----------------------|
|**_tcsxfrm**|**strxfrm**|**strxfrm**|**wcsxfrm**|
|**_tcsxfrm_l**|**_strxfrm_l**|**_strxfrm_l**|**_wcsxfrm_l**|

Na localidade “C”, a ordem dos caracteres no conjunto de caracteres (conjunto de caracteres ASCII) é a mesma que a ordem lexicográfica dos caracteres. No entanto, em outras localidades, a ordem de caracteres no conjunto de caracteres pode ser diferente da ordem lexicográfica de caracteres. Por exemplo, em algumas localidades europeias, o caractere “a” (valor 0x61) precede o caractere “&\#x00E4;” (valor 0xE4) no conjunto de caracteres, mas o caractere “ä” precede a caractere “a” lexicograficamente.

Em localidades para as quais o conjunto de caracteres e a ordem de caractere lexicográfica diferem, use **strxfrm** nas cadeias de caracteres originais e, em seguida, **strcmp** nas cadeias de caracteres resultantes para produzir uma comparação de cadeia de lexicográfica de acordo com a localidade atual Configuração de categoria **LC_COLLATE** . Portanto, para comparar duas cadeias de caracteres modo lexicográfico na localidade acima, use **strxfrm** nas cadeias de caracteres originais e, em seguida, **strcmp** nas cadeias de caracteres resultantes. Como alternativa, você pode usar **strcoll** em vez de **strcmp** nas cadeias de caracteres originais.

**strxfrm** é basicamente um wrapper em relação a [LCMapString](/windows/win32/api/winnls/nf-winnls-lcmapstringw) com **LCMAP_SORTKEY**.

O valor da expressão a seguir é o tamanho da matriz necessária para manter a transformação **strxfrm** da cadeia de caracteres de origem:

`1 + strxfrm( NULL, string, 0 )`

Somente na localidade "C", **strxfrm** é equivalente ao seguinte:

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

Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="see-also"></a>Consulte também

[Conversão de Dados](../../c-runtime-library/data-conversion.md)<br/>
[localeconv](localeconv.md)<br/>
[setlocale, _wsetlocale](setlocale-wsetlocale.md)<br/>
[Localidade](../../c-runtime-library/locale.md)<br/>
[Manipulação de cadeias de caracteres](../../c-runtime-library/string-manipulation-crt.md)<br/>
[Funções strcoll](../../c-runtime-library/strcoll-functions.md)<br/>
[strcmp, wcscmp, _mbscmp](strcmp-wcscmp-mbscmp.md)<br/>
[strncmp, wcsncmp, _mbsncmp, _mbsncmp_l](strncmp-wcsncmp-mbsncmp-mbsncmp-l.md)<br/>
