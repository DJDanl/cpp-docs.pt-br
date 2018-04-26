---
title: _finite, _finitef | Microsoft Docs
ms.custom: ''
ms.date: 04/05/2018
ms.reviewer: ''
ms.suite: ''
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: ''
ms.topic: reference
apiname:
- _finite
- _finitef
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
- finite
- _finite
- _finitef
- math/_finite
- math/_finitef
- float/_finite
dev_langs:
- C++
helpviewer_keywords:
- finite function
- _finite function
- _finitef function
ms.assetid: 5a7d7ca7-befb-4e1f-831d-28713c6eb805
caps.latest.revision: 15
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 31b34568def8969fea3602e749502beceb989b39
ms.sourcegitcommit: ef859ddf5afea903711e36bfd89a72389a12a8d6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/20/2018
---
# <a name="finite-finitef"></a>_finite, _finitef

Determina se um valor de ponto flutuante é finito.

## <a name="syntax"></a>Sintaxe

```C
int _finite(
   double x
);

int _finitef(
   float x
); /* x64 and ARM/ARM64 only */
```

### <a name="parameters"></a>Parâmetros

*x*<br/>
O valor de ponto flutuante a ser testado.

## <a name="return-value"></a>Valor de retorno

Ambos **Finitas** e **_finitef** retornar um valor diferente de zero se o argumento *x* é finita; o que é, se -INF < *x* < + INF. Ele retorna 0 se o argumento for infinito ou um NAN.

## <a name="remarks"></a>Comentários

O **Finitas** e **_finitef** funções são específicas da Microsoft. O **_finitef** função só está disponível quando compilado para x86, ARM e ARM64 plataformas.

## <a name="requirements"></a>Requisitos

|Função|Cabeçalho necessário (C)|Cabeçalho necessário (C++)|
|--------------|---------------------------|-------------------------------|
|**_finite**|\<float.h> ou \<math.h>|\<float.h>, \<math.h>, \<cfloat> ou \<cmath>|
|**_finitef**|\<math.h>|\<math.h> ou \<cmath>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="see-also"></a>Consulte também

[Suporte a ponto flutuante](../../c-runtime-library/floating-point-support.md)<br/>
[isnan, _isnan, _isnanf](isnan-isnan-isnanf.md)<br/>
[_fpclass, _fpclassf](fpclass-fpclassf.md)<br/>
