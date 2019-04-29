---
title: _mbsbtype, _mbsbtype_l
ms.date: 11/04/2016
apiname:
- _mbsbtype_l
- _mbsbtype
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
ms.openlocfilehash: 5c2927b4e4b68b1284341fe7e767ec50feb21a44
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62331500"
---
# <a name="mbsbtype-mbsbtypel"></a>_mbsbtype, _mbsbtype_l

Retorna o tipo de byte em uma cadeia de caracteres.

> [!IMPORTANT]
> Esta API não pode ser usada em aplicativos executados no Tempo de Execução do Windows. Para obter mais informações, confira [Funções do CRT sem suporte em aplicativos da Plataforma Universal do Windows](../../cppcx/crt-functions-not-supported-in-universal-windows-platform-apps.md).

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

*count*<br/>
Deslocamento do byte do início da cadeia de caracteres.

*locale*<br/>
Localidade a usar.

## <a name="return-value"></a>Valor de retorno

**mbsbtype** e **mbsbtype_l** retorna um valor inteiro que indica o resultado do teste no byte especificado. As constantes de manifesto na tabela a seguir são definidas em Mbctype.h.

|Valor retornado|Tipo de byte|
|------------------|---------------|
|**_MBC_SINGLE** (0)|Caractere de um byte. Por exemplo, na página de código 932, **mbsbtype** retornará 0 se o byte especificado estiver dentro do intervalo 0x20 – 0x7E ou 0xA1 – 0xDF.|
|**_MBC_LEAD** (1)|Byte inicial do caractere multibyte. Por exemplo, na página de código 932, **mbsbtype** retornará 1 se o byte especificado estiver dentro do intervalo 0x81 – 0x9F ou 0xE0 – 0xFC.|
|**_MBC_TRAIL** (2)|Byte à direita do caractere multibyte. Por exemplo, na página de código 932, **mbsbtype** retorna 2 se o byte especificado estiver dentro do intervalo 0x40 – 0x7E ou 0x80 – 0xFC.|
|**_MBC_ILLEGAL** (-1)|**NULO** cadeia de caracteres, caractere inválido ou byte nulo encontrado antes do byte no deslocamento *contagem* na *mbstr*.|

## <a name="remarks"></a>Comentários

O **mbsbtype** função determina o tipo de um byte em uma cadeia de caracteres multibyte. A função examina somente os bytes no deslocamento *contagem* na *mbstr*, ignorando os caracteres inválidos antes do byte especificado.

O valor de saída é afetado pela configuração da categoria **LC_CTYPE** da localidade. Consulte [setlocale](setlocale-wsetlocale.md) para obter mais informações. A versão dessa função sem o **l** sufixo usa a localidade atual desse comportamento dependente da localidade; a versão com o **l** sufixo é idêntico, exceto que ele use o parâmetro de localidade passado em vez disso. Para obter mais informações, consulte [Localidade](../../c-runtime-library/locale.md).

Se a cadeia de caracteres de entrada estiver **nulo**, o manipulador de parâmetro inválido será invocado, conforme descrito em [validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução puder continuar, **errno** é definido como **EINVAL** e a função retornará **_MBC_ILLEGAL**.

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|Cabeçalho opcional|
|-------------|---------------------|---------------------|
|**_mbsbtype**|\<mbstring.h>|\<mbctype.h>*|
|**_mbsbtype_l**|\<mbstring.h>|\<mbctype.h>*|

\* Para constantes de manifesto usadas como valores retornados.

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="see-also"></a>Consulte também

[Classificação de byte](../../c-runtime-library/byte-classification.md)<br/>
