---
title: ceil, ceilf, ceill | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
apiname:
- ceilf
- ceil
- ceill
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
- ntdll.dll
- api-ms-win-crt-math-l1-1-0.dll
apitype: DLLExport
f1_keywords:
- ceil
- ceilf
- ceill
dev_langs: C++
helpviewer_keywords:
- calculating value ceilings
- ceill function
- ceil function
- ceilf function
ms.assetid: f4e5acab-5c8f-4b10-9ae2-9561e6453718
caps.latest.revision: "13"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 4831b9f6f046dbc1a5d337f22e6be3dc3f4a5662
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="ceil-ceilf-ceill"></a>ceil, ceilf, ceill
Calcula o limite máximo de um valor.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
double ceil(   
   double x   
);  
float ceil(  
   float x  
);  // C++ only  
long double ceil(  
   long double x  
);  // C++ only  
float ceilf(  
   float x  
);  
long double ceill(  
   long double x  
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `x`  
 Valor de ponto flutuante.  
  
## <a name="return-value"></a>Valor de retorno  
 As funções `ceil` retornam um valor de ponto flutuante que representa o menor inteiro que é maior ou igual a `x`. Nenhum erro é retornado.  
  
|Entrada|Exceção SEH|Exceção Matherr|  
|-----------|-------------------|-----------------------|  
|± `QNAN`,`IND`|nenhum|`_DOMAIN`|  
  
 `ceil` tem uma implementação que usa SSE2 (Extensões SIMD de Streaming 2). Para obter informações e restrições relativas ao uso da implementação de SSE2, consulte [_set_SSE2_enable](../../c-runtime-library/reference/set-sse2-enable.md).  
  
## <a name="remarks"></a>Comentários  
 Uma vez que C++ permite sobrecargas, é possível chamar sobrecargas de `ceil`. Em um programa C, `ceil` sempre usa e retorna um duplo.  
  
## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalho necessário|  
|-------------|---------------------|  
|`ceil`, `ceilf`, `ceill`|\<math.h>|  
  
 Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
## <a name="example"></a>Exemplo  
 Veja o exemplo de [floor](../../c-runtime-library/reference/floor-floorf-floorl.md).  
  
## <a name="see-also"></a>Consulte também  
 [Suporte a ponto flutuante](../../c-runtime-library/floating-point-support.md)   
 [floor, floorf, floorl](../../c-runtime-library/reference/floor-floorf-floorl.md)   
 [fmod, fmodf](../../c-runtime-library/reference/fmod-fmodf.md)   
 [round, roundf, roundl](../../c-runtime-library/reference/round-roundf-roundl.md)
