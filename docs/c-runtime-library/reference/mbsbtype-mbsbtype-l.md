---
title: _mbsbtype, _mbsbtype_l
ms.date: 4/2/2020
api_name:
- _mbsbtype_l
- _mbsbtype
- _o__mbsbtype
- _o__mbsbtype_l
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
- api-ms-win-crt-private-l1-1-0.dll
api_type:
- DLLExport
topic_type:
- apiref
f1_keywords:
- mbsbtype
- mbsbtype_l
- _mbsbtype_l
- _mbsbtype
helpviewer_keywords:
- _mbsbtype function
- mbsbtype function
- _mbsbtype_l function
- mbsbtype_l function
ms.assetid: 0d5dd91a-d32d-4f98-ac57-98dfc9e98eac
ms.openlocfilehash: c1431a2d0886ffd3d16b43abf82b7342c166273a
ms.sourcegitcommit: 5a069c7360f75b7c1cf9d4550446ec2fa2eb2293
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2020
ms.locfileid: "82909479"
---
# <a name="_mbsbtype-_mbsbtype_l"></a>_mbsbtype, _mbsbtype_l

Retorna o tipo de byte em uma cadeia de caracteres.

> [!IMPORTANT]
> Esta API não pode ser usada em aplicativos executados no Windows Runtime. Para obter mais informações, confira [Funções do CRT sem suporte em aplicativos da Plataforma Universal do Windows](../../cppcx/crt-functions-not-supported-in-universal-windows-platform-apps.md).

## <a name="syntax"></a>Sintaxe

```C
int _mbsbtype(
   const unsigned char *mbstr,
   size_t count
);
int _mbsbtype_l(
   const unsigned char *mbstr,
   size_t count,
   _locale_t locale
);
```

### <a name="parameters"></a>Parâmetros

*mbstr*<br/>
Endereço de uma sequência de caracteres multibyte.

*contagem*<br/>
Deslocamento do byte do início da cadeia de caracteres.

*locale*<br/>
Localidade a usar.

## <a name="return-value"></a>Valor retornado

**_mbsbtype** e **_mbsbtype_l** retorna um valor inteiro que indica o resultado do teste no byte especificado. As constantes de manifesto na tabela a seguir são definidas em Mbctype.h.

|Valor retornado|Tipo de byte|
|------------------|---------------|
|**_MBC_SINGLE** (0)|Caractere de um byte. Por exemplo, na página de código 932, **_mbsbtype** retornará 0 se o byte especificado estiver dentro do intervalo 0X20-0X7e ou 0XA1-0xDF.|
|**_MBC_LEAD** (1)|Byte inicial do caractere multibyte. Por exemplo, na página de código 932, **_mbsbtype** retornará 1 se o byte especificado estiver dentro do intervalo 0X81-0X9F ou 0XE0-0xFC.|
|**_MBC_TRAIL** (2)|Byte à direita do caractere multibyte. Por exemplo, na página de código 932, **_mbsbtype** retornará 2 se o byte especificado estiver dentro do intervalo 0X40-0x7E ou 0X80-0xFC.|
|**_MBC_ILLEGAL** (-1)|Cadeia de caracteres **nula** , caractere inválido ou byte nulo encontrado antes do byte na *contagem* de deslocamentos em *mbstr*.|

## <a name="remarks"></a>Comentários

A função **_mbsbtype** determina o tipo de um byte em uma cadeia de caracteres multibyte. A função examina apenas o byte na *contagem* de deslocamentos em *mbstr*, ignorando caracteres inválidos antes do byte especificado.

O valor de saída é afetado pela configuração da categoria **LC_CTYPE** da localidade. Consulte [setlocale](setlocale-wsetlocale.md) para obter mais informações. A versão dessa função sem o sufixo **_L** usa a localidade atual para esse comportamento dependente de localidade; a versão com o sufixo **_L** é idêntica, exceto pelo fato de que ele usa o parâmetro de localidade passado em vez disso. Para obter mais informações, consulte [Localidade](../../c-runtime-library/locale.md).

Se a cadeia de caracteres de entrada for **nula**, o manipulador de parâmetro inválido será invocado, conforme descrito em [validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução puder continuar, **errno** será definido como **EINVAL** e a função retornará **_MBC_ILLEGAL**.

Por padrão, o estado global dessa função tem como escopo o aplicativo. Para alterar isso, consulte [estado global no CRT](../global-state.md).

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|Cabeçalho opcional|
|-------------|---------------------|---------------------|
|**_mbsbtype**|\<mbstring.h>|\<mbctype.h>*|
|**_mbsbtype_l**|\<mbstring.h>|\<mbctype.h>*|

\* Para constantes de manifesto usadas como valores retornados.

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="see-also"></a>Consulte também

[Classificação de byte](../../c-runtime-library/byte-classification.md)<br/>
