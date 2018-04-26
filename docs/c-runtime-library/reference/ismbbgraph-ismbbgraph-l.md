---
title: _ismbbgraph, _ismbbgraph_l | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.reviewer: ''
ms.suite: ''
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: ''
ms.topic: reference
apiname:
- _ismbbgraph_l
- _ismbbgraph
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
- _ismbbgraph
- _ismbbgraph_l
- ismbbgraph
- ismbbgraph_l
dev_langs:
- C++
helpviewer_keywords:
- _ismbbgraph_l function
- ismbbgraph_l function
- _ismbbgraph function
- ismbbgraph function
ms.assetid: b60db718-134f-4796-acc1-592d0b9efbb7
caps.latest.revision: 20
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: ba7016160890bbbbf04a73847341acddb0d2c2f9
ms.sourcegitcommit: ef859ddf5afea903711e36bfd89a72389a12a8d6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/20/2018
---
# <a name="ismbbgraph-ismbbgraphl"></a>_ismbbgraph, _ismbbgraph_l

Determina se um dado caractere multibyte é um caractere gráfico.

## <a name="syntax"></a>Sintaxe

```C
int _ismbbgraph (
   unsigned int c
);
int _ismbbgraph_l (
   unsigned int c,
   _locale_t locale
);
```

### <a name="parameters"></a>Parâmetros

*c*<br/>
Inteiro a ser testado.

*locale*<br/>
Localidade a usar.

## <a name="return-value"></a>Valor de retorno

Retorna um valor diferente de zero se a expressão:

`isctype(c, ( _PUNCT | _UPPER | _LOWER | _DIGIT )) || _ismbbkprint(c)`

é diferente de zero para *c*, ou 0 se não for. **ismbbgraph** usa a localidade atual para qualquer comportamento dependente de localidade. **ismbbgraph_l** é idêntico, exceto que ele usa a localidade passada em vez disso. Para obter mais informações, consulte [Localidade](../../c-runtime-library/locale.md).

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**_ismbbgraph**|\<mbctype.h>|
|**_ismbbgraph_l**|\<mbctype.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="libraries"></a>Libraries

Todas as versões das [bibliotecas em tempo de execução C](../../c-runtime-library/crt-library-features.md).

## <a name="see-also"></a>Consulte também

[Classificação de byte](../../c-runtime-library/byte-classification.md)<br/>
[Rotinas _ismbb](../../c-runtime-library/ismbb-routines.md)<br/>
