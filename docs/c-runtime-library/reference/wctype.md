---
title: wctype
ms.date: 11/04/2016
api_name:
- wctype
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
api_type:
- DLLExport
topic_type:
- apiref
f1_keywords:
- wctype
helpviewer_keywords:
- wctype function
- wide characters
ms.assetid: 14aded12-4087-4123-bc48-db4e10999223
ms.openlocfilehash: f77082bbcc5f3cd9d82fb40993c3ac678e7e7ba2
ms.sourcegitcommit: f19474151276d47da77cdfd20df53128fdcc3ea7
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/12/2019
ms.locfileid: "70957796"
---
# <a name="wctype"></a>wctype

Determina uma regra de classificação para códigos de caracteres largos.

## <a name="syntax"></a>Sintaxe

```C
wctype_t wctype(
   const char * property
);
```

### <a name="parameters"></a>Parâmetros

*propriedade*<br/>
Cadeia de caracteres de propriedade.

## <a name="return-value"></a>Valor de retorno

Se a categoria **LC_CTYPE** da localidade atual não definir uma regra de classificação cujo nome corresponda à *Propriedade*de cadeia de caracteres de propriedade, a função retornará zero. Caso contrário, retornará um valor diferente de zero adequado para uso como o segundo argumento para uma chamada subsequente a [towctrans](towctrans.md).

## <a name="remarks"></a>Comentários

A função determina uma regra de classificação para códigos de caracteres largos. Os seguintes pares de chamadas têm o mesmo comportamento em todas as localidades (mas uma implementação pode definir regras de classificação adicionais até mesmo na localidade "C"):

|Função|Mesmo que|
|--------------|-------------|
|iswalnum (c)|iswctype (c, wctype ("alnum"))|
|iswalpha (c)|iswctype (c, wctype ("Alpha"))|
|iswcntrl (c)|iswctype(c, wctype( "cntrl" ) )|
|iswdigit (c)|iswctype(c, wctype( "digit" ) )|
|iswgraph (c)|iswctype (c, wctype ("grafo"))|
|iswlower (c)|iswctype (c, wctype ("Lower"))|
|iswprint (c)|iswctype(c, wctype( "print" ) )|
|iswpunct (c)|iswctype(c, wctype( "punct" ) )|
|iswspace (c)|iswctype(c, wctype( "space" ) )|
|iswupper (c)|iswctype(c, wctype( "upper" ) )|
|iswxdigit (c)|iswctype(c, wctype( "xdigit" ) )|

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**wctype**|\<wctype.h>|

Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="see-also"></a>Consulte também

[Conversão de Dados](../../c-runtime-library/data-conversion.md)<br/>
[setlocale, _wsetlocale](setlocale-wsetlocale.md)<br/>
