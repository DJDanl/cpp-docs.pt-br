---
title: nearbyint, nearbyintf, nearbyintl | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
apiname:
- nearbyint
- nearbyintf
- nerabyintl
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
- nearbyint
- nearbyintf
- nearbyintl
- math/nearbyint
- math/narbyintf
- math/narbyintl
dev_langs:
- C++
helpviewer_keywords:
- nearbyint function
- nearbyintf function
- nearbyintl function
ms.assetid: dd39cb68-96b0-434b-820f-6ff2ea65584f
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: f6c4cce9fb5d95da5e65a064d622da22e4d0f0a8
ms.sourcegitcommit: 6002df0ac79bde5d5cab7bbeb9d8e0ef9920da4a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/14/2018
---
# <a name="nearbyint-nearbyintf-nearbyintl"></a>nearbyint, nearbyintf, nearbyintl
Arredonda o valor especificado de ponto flutuante para um inteiro e retorna esse valor em um formato de ponto flutuante.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
double nearbyint(  
   double x  
);  
  
float nearbyint(  
   float x  
); //C++ only  
  
long double nearbyint(  
   long double x  
); //C++ only  
  
float nearbyintf(  
   float x  
);  
  
long double nearbyintl(  
   long double x  
);  
  
```  
  
#### <a name="parameters"></a>Parâmetros  
 [in] `x`  
 O valor a ser arredondado.  
  
## <a name="return-value"></a>Valor de retorno  
 Se for bem-sucedido, retornará `x`, arredondado para o inteiro mais próximo, usando o formato de arredondamento atual conforme definido por fegetround. Caso contrário, a função pode retornar um dos seguintes valores:  
  
|Problema|Valor de|  
|-----------|------------|  
|`x` = ±INFINITY|±INFINITY, sem modificações|  
|`x` = ±0|±0, sem modificações|  
|`x` = NaN|NaN|  
  
 Erros não são reportados por [matherr](../../c-runtime-library/reference/matherr.md); especificamente, essa função não relata todas as exceções FE_INEXACT.  
  
## <a name="remarks"></a>Comentários  
 A principal diferença entre essa função e `rint` é que essa função não gera a exceção de ponto flutuante inexata.  
  
 Como os valores máximos de ponto flutuante são inteiros exatos, essa função nunca estourará sozinha. Em vez disso, a saída pode estourar o valor retornado, dependendo da versão da função que você usar.  
  
## <a name="requirements"></a>Requisitos  
  
|Função|Cabeçalho C|Cabeçalho C++|  
|--------------|--------------|------------------|  
|`nearbyint`,                `nearbyintf`,  `nearbyintl`|\<math.h>|\<cmath>|  
  
 Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
## <a name="see-also"></a>Consulte também  
 [Referência da Função Alfabética](../../c-runtime-library/reference/crt-alphabetical-function-reference.md)