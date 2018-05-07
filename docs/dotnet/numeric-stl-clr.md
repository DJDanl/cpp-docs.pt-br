---
title: numérico (STL/CLR) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-cli
ms.topic: reference
f1_keywords:
- <cliext/numeric>
dev_langs:
- C++
helpviewer_keywords:
- numeric functions [STL/CLR]
- <cliext/numeric> header [STL/CLR]
- <numeric> header [STL/CLR]
ms.assetid: 1dc4d9a3-e734-459c-9678-5d9be0ef4c79
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- dotnet
ms.openlocfilehash: 8d02423b2f8a2573fb4a90fd6f348a8e012dc91b
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="numeric-stlclr"></a>numérico (STL/CLR)
Define as funções de modelo de contêiner que executam algoritmos fornecidos para processamento numérico.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
#include <cliext/numeric>  
```  
  
## <a name="functions"></a>Funções  
  
|Função|Descrição|  
|--------------|-----------------|  
|[accumulate (STL/CLR)](../dotnet/accumulate-stl-clr.md)|Calcula a soma de todos os elementos em um intervalo especificado, incluindo qualquer valor inicial ao calcular somas parciais sucessivas ou calcula o resultado de resultados parciais sucessivos obtidos usando uma operação binária especificada diferente da soma.|  
|[adjacent_difference (STL/CLR)](../dotnet/adjacent-difference-stl-clr.md)|Calcula as diferenças sucessivas entre cada elemento e seu predecessor em um intervalo de entrada e gera os resultados em um intervalo de destino ou calcula o resultado de um procedimento generalizado, em que a operação de diferença é substituída por outra operação binária especificada.|  
|[inner_product (STL/CLR)](../dotnet/inner-product-stl-clr.md)|Calcula a soma do produto em relação ao elemento de dois intervalos e a adiciona a um valor inicial especificado ou calcula o resultado de um procedimento generalizado, em que as operações binárias de produto e a soma são substituídas por outras operações binárias especificadas.|  
|[partial_sum (STL/CLR)](../dotnet/partial-sum-stl-clr.md)|Calcula uma série de somas em um intervalo de entrada do primeiro elemento por meio de `i`elemento th e armazena o resultado de cada essa soma em `i`elemento th de um intervalo de destino ou calcula o resultado de um procedimento generalizado onde a operação de soma é substituída por outra operação binário especificada.|  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** \<cliext/numeric >  
  
 **Namespace:** cliext  
  
## <a name="see-also"></a>Consulte também  
 [Referência de biblioteca STL/CLR](../dotnet/stl-clr-library-reference.md)