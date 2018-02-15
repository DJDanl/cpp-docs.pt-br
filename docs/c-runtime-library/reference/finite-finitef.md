---
title: _finite, _finitef | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: 
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
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: eb904e04e8a99bff242d520f6c0ca3d404a74e89
ms.sourcegitcommit: 6002df0ac79bde5d5cab7bbeb9d8e0ef9920da4a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/14/2018
---
# <a name="finite-finitef"></a>_finite, _finitef
Determina se um valor de ponto flutuante é finito.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
int _finite(   
   double x   
);  
  
int _finitef(   
   float x   
); /* x64 and ARM/ARM64 only */  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `x`  
 O valor de ponto flutuante a ser testado.  
  
## <a name="return-value"></a>Valor de retorno  
 Ambos `_finite` e `_finitef` retornar um valor diferente de zero se o argumento *x* é finita; o que é, se -INF < `x` < + INF. Ele retorna 0 se o argumento for infinito ou um NAN.  
  
## <a name="remarks"></a>Comentários  
 As funções `_finite` e `_finitef` são específicas da Microsoft. A função `_finitef` só está disponível quando compilada para plataformas x86, ARM ou ARM64.  
  
## <a name="requirements"></a>Requisitos  
  
|Função|Cabeçalho necessário (C)|Cabeçalho necessário (C++)|  
|--------------|---------------------------|-------------------------------|  
|`_finite`|\<float.h> ou \<math.h>|\<float.h>, \<math.h>, \<cfloat> ou \<cmath>|  
|`_finitef`|\<math.h>|\<math.h> ou \<cmath>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
## <a name="see-also"></a>Consulte também  
 [Suporte de ponto flutuante](../../c-runtime-library/floating-point-support.md)   
 [isnan, _isnan, _isnanf](../../c-runtime-library/reference/isnan-isnan-isnanf.md)   
 [_fpclass, _fpclassf](../../c-runtime-library/reference/fpclass-fpclassf.md)