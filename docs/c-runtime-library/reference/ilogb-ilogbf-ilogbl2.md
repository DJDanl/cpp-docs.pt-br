---
title: ilogb, ilogbf, ilogbl2 | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
apiname:
- ilogb
- ilogbf
- ilogbl
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
- ilogb
- ilogbf
- ilogbl
- math/ilogb
- math/ilogbf
- math/ilogbl
helpviewer_keywords:
- ilogb function
- ilogbf function
- ilogbl function
ms.assetid: 9ef19d57-1caa-41d5-8233-2faad3562fcb
caps.latest.revision: "4"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 3ecf7f9bb38cdd844514001126a98bced67617e7
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="ilogb-ilogbf-ilogbl"></a>ilogb, ilogbf, ilogbl
Recupera um inteiro que representa o expoente de base 2 neutro do valor especificado.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
int ilogb(  
   double x  
);  
  
int ilogb(  
   float x  
); //C++ only  
  
int ilogb(  
   long double x  
); //C++ only  
  
int ilogbf(  
   float x  
);  
  
int ilogbl(  
   long double x  
);  
  
```  
  
#### <a name="parameters"></a>Parâmetros  
 [in] `x`  
 O valor especificado.  
  
## <a name="return-value"></a>Valor de retorno  
 Se for bem-sucedido, retorna o expoente de base 2 de `x` como um `int` valor com sinal.  
  
 Caso contrário, retorna um dos valores a seguir, definidos em É um dos valores a seguir, definidos em \<math.h>:  
  
|Entrada|Resultado|  
|-----------|------------|  
|±0|FP_ILOGB0|  
|±inf, ±nan, indefinido|FP_ILOGBNAN|  
  
 Os erros são relatados conforme especificado em [_matherr](../../c-runtime-library/reference/matherr.md).  
  
## <a name="remarks"></a>Comentários  
 Uma vez que C++ permite sobrecargas, é possível chamar sobrecargas de `ilogb` que utilizam e retornam tipos duplos flutuantes e longos. Em um programa C, `ilogb` sempre usa e retorna um duplo.  
  
 Chamar essa função é semelhante a chamar a função `logb` equivalente, convertendo, em seguida, o valor retornado para `int`.  
  
## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalho C|Cabeçalho C++|  
|-------------|--------------|------------------|  
|`ilogb`,                `ilogbf`,  `ilogbl`|\<math.h>|\<cmath>|  
  
 Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
## <a name="see-also"></a>Consulte também  
 [Alphabetical Function Reference](../../c-runtime-library/reference/crt-alphabetical-function-reference.md)  (Referência da função alfabética)  
 [frexp](../../c-runtime-library/reference/frexp.md)   
 [logb, logbf, logbl, _logb, _logbf](../../c-runtime-library/reference/logb-logbf-logbl-logb-logbf.md)