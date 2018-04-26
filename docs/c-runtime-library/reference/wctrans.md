---
title: wctrans | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.reviewer: ''
ms.suite: ''
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: ''
ms.topic: reference
apiname:
- wctrans
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
- api-ms-win-crt-convert-l1-1-0.dll
apitype: DLLExport
f1_keywords:
- wctrans
dev_langs:
- C++
helpviewer_keywords:
- character codes, wctrans
- characters, codes
- characters, converting
- wctrans function
ms.assetid: 215404bf-6d60-489c-9ae9-880e6b586162
caps.latest.revision: 13
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: dab0f5a55f9ee1df30b0a5f040e7944292b5cf25
ms.sourcegitcommit: ef859ddf5afea903711e36bfd89a72389a12a8d6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/20/2018
---
# <a name="wctrans"></a>wctrans

Determina um mapeamento de um conjunto de códigos de caracteres para outro.

## <a name="syntax"></a>Sintaxe

```C
wctrans_t wctrans(
   const char *property
);
```

### <a name="parameters"></a>Parâmetros

*propriedade*<br/>
Uma cadeia de caracteres que especifica uma das transformações válidas.

## <a name="return-value"></a>Valor de retorno

Se o **LC_CTYPE** categoria da localidade atual não define um mapeamento cujo nome corresponda a cadeia de caracteres de propriedade *propriedade*, a função retornará zero. Caso contrário, retornará um valor diferente de zero adequado para uso como o segundo argumento para uma chamada subsequente a [towctrans](towctrans.md).

## <a name="remarks"></a>Comentários

Esta função determina um mapeamento de um conjunto de códigos de caracteres para outro.

Os seguintes pares de chamadas têm o mesmo comportamento em todas as localidades, mas é possível definir mapeamentos adicionais até mesmo na localidade "C":

|Função|Mesmo que|
|--------------|-------------|
|ToLower(c)|towctrans (c, wctrans("towlower"))|
|towupper(c)|towctrans (c, wctrans("toupper"))|

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**wctrans**|\<wctype.h>|

Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

```C
// crt_wctrans.cpp
// compile with: /EHsc
// This example determines a mapping from one set of character
// codes to another.

#include <wchar.h>
#include <wctype.h>
#include <stdio.h>
#include <iostream>

int main()
{
    wint_t c = 'a';
    printf_s("%d\n",c);

    wctrans_t i = wctrans("toupper");
    printf_s("%d\n",i);

    wctrans_t ii = wctrans("towlower");
    printf_s("%d\n",ii);

    wchar_t wc = towctrans(c, i);
    printf_s("%d\n",wc);
}
```

```Output
97
1
0
65
```

## <a name="see-also"></a>Consulte também

[Conversão de Dados](../../c-runtime-library/data-conversion.md)<br/>
[setlocale, _wsetlocale](setlocale-wsetlocale.md)<br/>
