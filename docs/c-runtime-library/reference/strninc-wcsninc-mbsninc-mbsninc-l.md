---
title: _strninc, _wcsninc, _mbsninc, _mbsninc_l | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-standard-libraries
ms.topic: reference
apiname:
- _mbsninc
- _mbsninc_l
- _wcsninc
- _strninc
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
apitype: DLLExport
f1_keywords:
- strninc
- wcsninc
- mbsninc_l
- _strninc
- _tcsninc
- mbsninc
- _mbsninc_l
- _ftcsninc
- _wcsninc
- _mbsninc
dev_langs:
- C++
helpviewer_keywords:
- _mbsninc_l function
- mbsninc function
- _strninc function
- tcsninc function
- wcsninc function
- _mbsninc function
- strninc function
- _wcsninc function
- mbsninc_l function
- _tcsninc function
ms.assetid: 6caace64-f9e4-48c0-afa8-ea51824ad723
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 21218c411ad8bab9e3e4bd73eea266d0889f6c7d
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
---
# <a name="strninc-wcsninc-mbsninc-mbsnincl"></a>_strninc, _wcsninc, _mbsninc, _mbsninc_l

Avança um ponteiro de cadeia de caracteres por **n** caracteres.

> [!IMPORTANT]
> **mbsninc** e **mbsninc_l** não pode ser usado em aplicativos que são executados o tempo de execução do Windows. Para obter mais informações, confira [Funções do CRT sem suporte em aplicativos da Plataforma Universal do Windows](../../cppcx/crt-functions-not-supported-in-universal-windows-platform-apps.md).

## <a name="syntax"></a>Sintaxe

```C
char *_strninc(
   const char *str,
   size_t count
);
wchar_t *_wcsninc(
   const wchar_t *str,
   size_t count
);
unsigned char *_mbsninc(
   const unsigned char *str,
   size_t count
);
unsigned char *_mbsninc(
   const unsigned char *str,
   size_t count,
   _locale_t locale
);
```

### <a name="parameters"></a>Parâmetros

*str*<br/>
Cadeia de caracteres de origem.

*count*<br/>
Número de caracteres para incrementar um ponteiro de cadeia de caracteres.

*locale*<br/>
Localidade a usar.

## <a name="return-value"></a>Valor de retorno

Cada uma dessas rotinas retorna um ponteiro para *str* depois *str* foi incrementada *contagem* caracteres ou **nulo** se fornecido ponteiro é **nulo**. Se *contagem* é maior que ou igual ao número de caracteres em *str*, o resultado é indefinido.

## <a name="remarks"></a>Comentários

O **mbsninc** função incrementos *str* por *contagem* caracteres multibyte. **mbsninc** reconhece sequências de caracteres multibyte de acordo com o [página de código multibyte](../../c-runtime-library/code-pages.md) atualmente em uso.

### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico

|Rotina Tchar.h|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|
|---------------------|--------------------------------------|--------------------|-----------------------|
|**_tcsninc**|**_strninc**|**_mbsninc**|**_wcsninc**|

**strninc** e **wcsninc** são cadeia de caracteres de byte único e versões de cadeia de caracteres largos do **mbsninc**. **wcsninc** e **strninc** são fornecidos apenas para esse mapeamento e não deve ser usado caso contrário. Para obter mais informações, consulte [Usando mapeamentos de texto genérico](../../c-runtime-library/using-generic-text-mappings.md) e [Mapeamentos de Texto Genérico](../../c-runtime-library/generic-text-mappings.md).

**mbsninc_l** é idêntico, exceto que ele usa o parâmetro de localidade passado em vez disso. Para obter mais informações, consulte [Localidade](../../c-runtime-library/locale.md).

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**_mbsninc**|\<mbstring.h>|
|**_mbsninc_l**|\<mbstring.h>|
|**_strninc**|\<tchar.h>|
|**_wcsninc**|\<tchar.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="see-also"></a>Consulte também

[Manipulação de cadeias de caracteres](../../c-runtime-library/string-manipulation-crt.md)<br/>
[Localidade](../../c-runtime-library/locale.md)<br/>
[Interpretação de sequências de caracteres multibyte](../../c-runtime-library/interpretation-of-multibyte-character-sequences.md)<br/>
[_strdec, _wcsdec, _mbsdec, _mbsdec_l](strdec-wcsdec-mbsdec-mbsdec-l.md)<br/>
[_strinc, _wcsinc, _mbsinc, _mbsinc_l](strinc-wcsinc-mbsinc-mbsinc-l.md)<br/>
[_strnextc, _wcsnextc, _mbsnextc, _mbsnextc_l](strnextc-wcsnextc-mbsnextc-mbsnextc-l.md)<br/>
