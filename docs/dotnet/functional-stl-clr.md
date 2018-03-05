---
title: funcional (STL/CLR) | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- <cliext/functional>
dev_langs:
- C++
helpviewer_keywords:
- <functional> header [STL/CLR]
- <cliext/functional> header [STL/CLR]
- functional functions [STL/CLR]
ms.assetid: 88738b8c-5d37-4375-970e-a4442bf5efde
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- dotnet
ms.openlocfilehash: 8e731767401964045307635a428d7606d628aca8
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="functional-stlclr"></a>functional (STL/CLR)
Incluir o cabeçalho STL/CLR `<cliext/functional>` para definir a um número de classes de modelo e delegados de modelo relacionados e funções.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
#include <functional>  
```  
  
## <a name="declarations"></a>Declarações  
  
|delegado|Descrição|  
|--------------|-----------------|  
|[binary_delegate (STL/CLR)](../dotnet/binary-delegate-stl-clr.md)|Delegado de dois argumentos.|  
|[binary_delegate_noreturn (STL/CLR)](../dotnet/binary-delegate-noreturn-stl-clr.md)|Delegado de dois argumentos retornando `void`.|  
|[unary_delegate (STL/CLR)](../dotnet/unary-delegate-stl-clr.md)|Um argumento de delegate.|  
|[unary_delegate_noreturn (STL/CLR)](../dotnet/unary-delegate-noreturn-stl-clr.md)|Um argumento delegado retornando `void`.|  
  
|Classe|Descrição|  
|-----------|-----------------|  
|[binary_negate (STL/CLR)](../dotnet/binary-negate-stl-clr.md)|Functor para negar uma functor de dois argumentos.|  
|[binder1st (STL/CLR)](../dotnet/binder1st-stl-clr.md)|Functor para associar o primeiro argumento para um functor de dois argumentos.|  
|[binder2nd (STL/CLR)](../dotnet/binder2nd-stl-clr.md)|Functor para associar o segundo argumento para um functor de dois argumentos.|  
|[divides (STL/CLR)](../dotnet/divides-stl-clr.md)|Divida functor.|  
|[equal_to (STL/CLR)](../dotnet/equal-to-stl-clr.md)|Functor de comparação igual.|  
|[greater (STL/CLR)](../dotnet/greater-stl-clr.md)|Maior functor de comparação.|  
|[greater_equal (STL/CLR)](../dotnet/greater-equal-stl-clr.md)|Functor de comparação igual ou maior.|  
|[less (STL/CLR)](../dotnet/less-stl-clr.md)|Menos functor de comparação.|  
|[less_equal (STL/CLR)](../dotnet/less-equal-stl-clr.md)|Functor de comparação menor ou igual.|  
|[logical_and (STL/CLR)](../dotnet/logical-and-stl-clr.md)|Functor AND lógico.|  
|[logical_not (STL/CLR)](../dotnet/logical-not-stl-clr.md)|Lógica não functor.|  
|[logical_or (STL/CLR)](../dotnet/logical-or-stl-clr.md)|Functor de OR lógico.|  
|[minus (STL/CLR)](../dotnet/minus-stl-clr.md)|Subtrai functor.|  
|[modulus (STL/CLR)](../dotnet/modulus-stl-clr.md)|Functor do módulo.|  
|[multiplies (STL/CLR)](../dotnet/multiplies-stl-clr.md)|Multiplique functor.|  
|[negate (STL/CLR)](../dotnet/negate-stl-clr.md)|Functor para retornar o argumento negado.|  
|[not_equal_to (STL/CLR)](../dotnet/not-equal-to-stl-clr.md)|Functor de comparação não é igual.|  
|[plus (STL/CLR)](../dotnet/plus-stl-clr.md)|Adicione functor.|  
|[unary_negate (STL/CLR)](../dotnet/unary-negate-stl-clr.md)|Functor para negar um functor um argumento.|  
  
|Função|Descrição|  
|--------------|-----------------|  
|[bind1st (STL/CLR)](../dotnet/bind1st-stl-clr.md)|Gera um binder1st para um argumento e functor.|  
|[bind2nd (STL/CLR)](../dotnet/bind2nd-stl-clr.md)|Gera um binder2nd para um argumento e functor.|  
|[not1 (STL/CLR)](../dotnet/not1-stl-clr.md)|Gera um unary_negate para um functor.|  
|[not1 (STL/CLR)](../dotnet/not1-stl-clr.md)|Gera um binary_negate para um functor.|  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** \<cliext/funcional >  
  
 **Namespace:** cliext  
  
## <a name="see-also"></a>Consulte também  
 [Referência de biblioteca STL/CLR](../dotnet/stl-clr-library-reference.md)