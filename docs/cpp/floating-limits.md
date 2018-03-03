---
title: Limites flutuantes | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-language
ms.tgt_pltfrm: 
ms.topic: language-reference
dev_langs:
- C++
helpviewer_keywords:
- ranges, floating-point constants
- floating-point constants, limits
- float.h header file
- limits, floating-point constants
- floating-point numbers [C++]
- floating limits
ms.assetid: fc718652-1f4c-4ed8-af60-0e769637459c
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 6406d3d2d81fa3025a024606da68d61b5dcefdb7
ms.sourcegitcommit: 9a0a287d6940591523af959ebdac5affa36220da
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 01/25/2018
---
# <a name="floating-limits"></a>Limites flutuantes
**Seção específica da Microsoft**  
  
 A tabela a seguir lista os limites nos valores de constantes de ponto flutuante. Esses limites também são definidos no arquivo de cabeçalho padrão \<float. h >.  
  
### <a name="limits-on-floating-point-constants"></a>Limites em constantes de ponto flutuante  
  
|Constante|Significado|Valor|  
|--------------|-------------|-----------|  
|FLT_DIG DBL_DIG LDBL_DIG|Número de dígitos, q, de modo que um número de ponto flutuante com dígitos decimais de q possam ser arredondados em uma representação de ponto flutuante e de volta sem perda de precisão.|6 15 15|  
|FLT_EPSILON DBL_EPSILON LDBL_EPSILON|O menor número positivo x, de modo que x + 1,0 não é igual a 1,0.|1.192092896e-07F 2.2204460492503131e-016 2.2204460492503131e-016|  
|FLT_GUARD||0|  
|FLT_MANT_DIG DBL_MANT_DIG LDBL_MANT_DIG|Número de dígitos na raiz especificada por FLT_RADIX em significando de ponto flutuante. A base é 2; Portanto, esses valores especificam bits.|24 53 53|  
|FLT_MAX DBL_MAX LDBL_MAX|Número máximo de ponto flutuante representável.|3.402823466e+38F 1.7976931348623158e+308 1.7976931348623158e+308|  
|FLT_MAX_10_EXP DBL_MAX_10_EXP LDBL_MAX_10_EXP|Inteiro máximo, de modo que 10 gerado para esse número é um número de ponto flutuante representável.|38 308 308|  
|FLT_MAX_EXP DBL_MAX_EXP LDBL_MAX_EXP|Inteiro máximo de modo que FLT_RADIX gerado para esse número seja um número de ponto flutuante representável.|128 1024 1024|  
|FLT_MIN DBL_MIN LDBL_MIN|Valor positivo mínimo.|1.175494351e-38F 2.2250738585072014e-308 2.2250738585072014e-308|  
|FLT_MIN_10_EXP DBL_MIN_10_EXP LDBL_MIN_10_EXP|Mínimo inteiro negativo, de modo que 10 gerado para esse número é um número de ponto flutuante representável.|-37<br /><br /> -307<br /><br /> -307|  
|FLT_MIN_EXP DBL_MIN_EXP LDBL_MIN_EXP|Inteiro negativo mínimo de modo que FLT_RADIX gerado para esse número seja um número de ponto flutuante representável.|-125<br /><br /> -1021<br /><br /> -1021|  
|FLT_NORMALIZE||0|  
|FLT_RADIX _DBL_RADIX _LDBL_RADIX|Raiz de representação do expoente.|2 2 2|  
|FLT_ROUNDS _DBL_ROUNDS _LDBL_ROUNDS|Modo de arredondamento para adição de ponto flutuante.|1 (aproximado) 1 (aproximado) 1 (aproximado)|  
  
> [!NOTE]
>  As informações da tabela podem ser diferente em versões futuras do produto.  
  
**Fim da seção específica da Microsoft**  
  
## <a name="see-also"></a>Consulte também  
 [Limites de inteiros](../cpp/integer-limits.md)