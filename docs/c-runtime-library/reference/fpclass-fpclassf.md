---
title: _fpclass, _fpclassf | Microsoft Docs
ms.custom: ''
ms.date: 04/05/2018
ms.reviewer: ''
ms.suite: ''
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: ''
ms.topic: reference
apiname:
- _fpclass
- _fpclassf
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
- api-ms-win-crt-math-l1-1-0.dll
apitype: DLLExport
f1_keywords:
- fpclass
- _fpclass
- _fpclassf
- math/_fpclass
- float/_fpclass
- math/_fpclassf
dev_langs:
- C++
helpviewer_keywords:
- fpclass function
- floating-point numbers, IEEE representation
- _fpclass function
- _fpclassf function
ms.assetid: 2774872d-3543-446f-bc72-db85f8b95a6b
caps.latest.revision: 13
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 3ee483334c7456c1cf2be480d7f925d8f3a839e9
ms.sourcegitcommit: ef859ddf5afea903711e36bfd89a72389a12a8d6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/20/2018
---
# <a name="fpclass-fpclassf"></a>_fpclass, _fpclassf

Retorna um valor que indica a classificação de ponto flutuante do argumento.

## <a name="syntax"></a>Sintaxe

```C
int _fpclass(
   double x
);

int _fpclassf(
   float x
); /* x64 only */
```

### <a name="parameters"></a>Parâmetros

*x*<br/>
O valor de ponto flutuante a ser testado.

## <a name="return-value"></a>Valor de retorno

O **fpclass** e **_fpclassf** funções retornam um valor inteiro que indica a classificação de ponto flutuante do argumento *x*. A classificação pode ter um dos valores a seguir, definidos em \<float.>.

|Valor|Descrição|
|-----------|-----------------|
|**_FPCLASS_SNAN**|Sinalização de NaN|
|**_FPCLASS_QNAN**|NaN silencioso|
|**_FPCLASS_NINF**|Infinito negativo (-INF)|
|**_FPCLASS_NN**|Negativo normalizado diferente de zero|
|**_FPCLASS_ND**|Negativo desnormalizado|
|**_FPCLASS_NZ**|Zero negativo (- 0)|
|**_FPCLASS_PZ**|0 positivo (+0)|
|**_FPCLASS_PD**|Positivo desnormalizado|
|**_FPCLASS_PN**|Positivo normalizado diferente de zero|
|**_FPCLASS_PINF**|Infinito positivo (+INF)|

## <a name="remarks"></a>Comentários

O **fpclass** e **_fpclassf** funções são específicas da Microsoft. Elas são semelhantes a [fpclassify](fpclassify.md), mas retornam informações mais detalhadas sobre o argumento. O **_fpclassf** função só está disponível quando compilado para o x64 plataforma.

## <a name="requirements"></a>Requisitos

|Função|Cabeçalho necessário|
|--------------|---------------------|
|**fpclass**, **_fpclassf**|\<float.h>|

Para obter mais informações sobre compatibilidade e conformidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="see-also"></a>Consulte também

[Suporte a ponto flutuante](../../c-runtime-library/floating-point-support.md)<br/>
[isnan, _isnan, _isnanf](isnan-isnan-isnanf.md)<br/>
[fpclassify](fpclassify.md)<br/>