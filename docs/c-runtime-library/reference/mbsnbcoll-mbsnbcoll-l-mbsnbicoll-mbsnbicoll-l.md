---
title: _mbsnbcoll, _mbsnbcoll_l, _mbsnbicoll, _mbsnbicoll_l | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.reviewer: ''
ms.suite: ''
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: ''
ms.topic: reference
apiname:
- _mbsnbicoll_l
- _mbsnbcoll_l
- _mbsnbcoll
- _mbsnbicoll
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
- mbsnbicoll
- mbsnbcoll
- mbsnbicoll_l
- _mbsnbcoll
- _mbsnbicoll
- _ftcsnicoll
- _ftcsncoll
- mbsnbcoll_l
dev_langs:
- C++
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
- tcsncoll function
- tcsnicoll function
ms.assetid: d139ed63-ccba-4458-baa2-61cbcef03e94
caps.latest.revision: 21
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 5be9c6cb3421b5ba1b191977f70a35d7ffc38625
ms.sourcegitcommit: ef859ddf5afea903711e36bfd89a72389a12a8d6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/20/2018
---
# <a name="mbsnbcoll-mbsnbcolll-mbsnbicoll-mbsnbicolll"></a>_mbsnbcoll, _mbsnbcoll_l, _mbsnbicoll, _mbsnbicoll_l

Compara *n* bytes de duas cadeias de caracteres multibyte usando as informações da página de código multibyte.

> [!IMPORTANT]
> Esta API não pode ser usada em aplicativos executados no Tempo de Execução do Windows. Para obter mais informações, confira [Funções do CRT sem suporte em aplicativos da Plataforma Universal do Windows](../../cppcx/crt-functions-not-supported-in-universal-windows-platform-apps.md).

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

*string1*, *string2*<br/>
Cadeias de caracteres a serem comparadas.

*count*<br/>
Número de bytes a serem comparados.

*locale*<br/>
Localidade a usar.

## <a name="return-value"></a>Valor de retorno

O valor de retorno indica a relação de subcadeias de caracteres de *string1* e *string2*.

|Valor retornado|Descrição|
|------------------|-----------------|
|< 0|*string1* subcadeia de caracteres menor *string2* subcadeia de caracteres.|
|0|*string1* subcadeia de caracteres idêntica à *string2* subcadeia de caracteres.|
|> 0|*string1* subcadeia de caracteres maior que *string2* subcadeia de caracteres.|

Se *string1* ou *string2* é **nulo** ou *contagem* é maior do que **INT_MAX**, inválido manipulador de parâmetro é chamado, conforme descrito em [validação do parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução é permitida para continuar, essas funções retornam **_NLSCMPERROR** e defina **errno** para **EINVAL**. Para usar **_NLSCMPERROR**, incluir String.h ou Mbstring.h.

## <a name="remarks"></a>Comentários

Cada uma dessas funções é agrupado, no máximo, o primeiro *contagem* bytes em *string1* e *string2* e retorna um valor que indica a relação entre resultante subcadeias de *string1* e *string2*. Se o byte final na subcadeia de caracteres de *string1* ou *string2* é um byte inicial, ele não está incluído na comparação; essas funções comparam apenas completas caracteres em subcadeias de caracteres. **mbsnbicoll** é uma versão de maiusculas e minúsculas do **mbsnbcoll**. Como [mbsnbcmp](mbsnbcmp-mbsnbcmp-l.md) e [mbsnbicmp](mbsnbicmp-mbsnbicmp-l.md), **mbsnbcoll** e **mbsnbicoll** agrupar as duas cadeias de caracteres de caracteres multibyte acordo com o ordem lexicográfica especificado pelo multibyte [página de código](../../c-runtime-library/code-pages.md) atualmente em uso.

Para algumas páginas de código e conjuntos de caracteres correspondente, a ordem dos caracteres no conjunto de caracteres pode diferir da ordem de caracteres lexicográfica. Na localidade “C”, esse não é o caso: a ordem dos caracteres no conjunto de caracteres ASCII é a mesma que a ordem lexicográfica dos caracteres. No entanto, em algumas páginas de código europeias, por exemplo, o caractere “a” (valor 0x61) precede o caractere “ä” (valor 0xE4) no conjunto de caracteres, mas o caractere “ä” precede a caractere “a” lexicograficamente. Para executar uma comparação lexicográfica de cadeias de caracteres em bytes em uma instância, use **mbsnbcoll** em vez de **mbsnbcmp**; para verificar somente para fins de igualdade de cadeia de caracteres, use **mbsnbcmp**.

Porque o **coll** funções collate cadeias de caracteres lexicograficamente para comparação, enquanto o **cmp** funções simplesmente testam a igualdade de cadeia de caracteres, o **coll** são funções muito mais lento do que o correspondente **cmp** versões. Portanto, o **coll** funções devem ser usadas somente quando há uma diferença entre a ordem do conjunto de caracteres e a ordem lexicográfica de caractere na página de código atual, e essa diferença é de interesse para a comparação.

O valor de saída é afetado pela configuração do **LC_CTYPE** configuração de categoria da localidade, consulte [setlocale](setlocale-wsetlocale.md) para obter mais informações. As versões dessas funções sem o sufixo **_l** usam a localidade atual desse comportamento dependente da localidade. As versões com o sufixo **_l** são idênticas, exceto por usarem o parâmetro de localidade passado em seu lugar. Para obter mais informações, consulte [Localidade](../../c-runtime-library/locale.md).

### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico

|Rotina Tchar.h|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|
|---------------------|--------------------------------------|--------------------|-----------------------|
|**tcsncoll**|[_strncoll](strncoll-wcsncoll-mbsncoll-strncoll-l-wcsncoll-l-mbsncoll-l.md)|**_mbsnbcoll**|[_wcsncoll](strncoll-wcsncoll-mbsncoll-strncoll-l-wcsncoll-l-mbsncoll-l.md)|
|**_tcsncoll_l**|[_strncoll, _wcsncoll, _mbsncoll, _strncoll_l, _wcsncoll_l, _mbsncoll_l](strncoll-wcsncoll-mbsncoll-strncoll-l-wcsncoll-l-mbsncoll-l.md)|**_mbsnbcoll_l**|[_wcsncoll_l](strncoll-wcsncoll-mbsncoll-strncoll-l-wcsncoll-l-mbsncoll-l.md)|
|**tcsnicoll**|[_strnicoll](strnicoll-wcsnicoll-mbsnicoll-strnicoll-l-wcsnicoll-l-mbsnicoll-l.md)|**_mbsnbicoll**|[_wcsnicoll](strnicoll-wcsnicoll-mbsnicoll-strnicoll-l-wcsnicoll-l-mbsnicoll-l.md)|
|**_tcsnicoll_l**|[_strnicoll_l](strnicoll-wcsnicoll-mbsnicoll-strnicoll-l-wcsnicoll-l-mbsnicoll-l.md)|**_mbsnbicoll_l**|[_wcsnicoll_l](strnicoll-wcsnicoll-mbsnicoll-strnicoll-l-wcsnicoll-l-mbsnicoll-l.md)|

## <a name="requirements"></a>Requisitos

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
