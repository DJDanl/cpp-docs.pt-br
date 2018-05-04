---
title: wctype | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-standard-libraries
ms.topic: reference
apiname:
- wctype
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
apitype: DLLExport
f1_keywords:
- wctype
dev_langs:
- C++
helpviewer_keywords:
- wctype function
- wide characters
ms.assetid: 14aded12-4087-4123-bc48-db4e10999223
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 0bb5003db02ed27c2906ebc3619313489e40e5fb
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
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

Se o **LC_CTYPE** categoria da localidade atual não define uma regra de classificação cujo nome corresponda a cadeia de caracteres de propriedade *propriedade*, a função retornará zero. Caso contrário, retornará um valor diferente de zero adequado para uso como o segundo argumento para uma chamada subsequente a [towctrans](towctrans.md).

## <a name="remarks"></a>Comentários

A função determina uma regra de classificação para códigos de caracteres largos. Os seguintes pares de chamadas têm o mesmo comportamento em todas as localidades (mas uma implementação pode definir regras de classificação adicionais até mesmo na localidade "C"):

|Função|Mesmo que|
|--------------|-------------|
|iswalnum(c)|iswctype (c, wctype ("alnum"))|
|iswalpha(c)|iswctype (c, wctype ("alpha"))|
|iswcntrl(c)|iswctype (c, wctype ("cntrl"))|
|iswdigit(c)|iswctype (c, wctype ("dígito"))|
|iswgraph(c)|iswctype (c, wctype ("gráfico"))|
|iswlower(c)|iswctype (c, wctype ("inferior"))|
|iswprint(c)|iswctype (c, wctype ("print"))|
|iswpunct(c)|iswctype (c, wctype ("pontuação"))|
|iswspace(c)|iswctype (c, wctype ("espaço"))|
|iswupper(c)|iswctype (c, wctype ("superior"))|
|iswxdigit(c)|iswctype (c, wctype ("xdigit"))|

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**wctype**|\<wctype.h>|

Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="see-also"></a>Consulte também

[Conversão de Dados](../../c-runtime-library/data-conversion.md)<br/>
[setlocale, _wsetlocale](setlocale-wsetlocale.md)<br/>
