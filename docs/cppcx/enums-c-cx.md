---
title: "Enumerações (C + + CX) | Microsoft Docs"
ms.custom: 
ms.date: 12/30/2016
ms.technology: cpp-windows
ms.reviewer: 
ms.suite: 
ms.tgt_pltfrm: 
ms.topic: language-reference
ms.assetid: 99fbbe28-c1cd-43af-9ead-60f90eba6e68
caps.latest.revision: 
author: ghogen
ms.author: ghogen
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: b3a95af557dd416d99368dbd1ab51495e0bd1d85
ms.sourcegitcommit: 6002df0ac79bde5d5cab7bbeb9d8e0ef9920da4a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/14/2018
---
# <a name="enums-ccx"></a>Enums (C++/CX)
C + + CX oferece suporte a `public enum class` palavra-chave, que é análoga a um C++ padrão `scoped  enum`. Quando você usa um enumerador que é declarado usando a palavra-chave `public enum class` , deve usar o identificador da enumeração para definir o escopo de cada valor de enumeração.  
  
### <a name="remarks"></a>Comentários  
 Uma `public enum class` que não tem um especificador de acesso, como `public`, é tratada como um [enum com escopo](../cpp/enumerations-cpp.md)C++ padrão.  
  
 Um `public enum class` ou `public enum struct` declaração pode ter um tipo subjacente de qualquer tipo integral Embora o tempo de execução do Windows em si requer que o tipo seja int32 ou uint32 para um enum de sinalizadores. A sintaxe a seguir descreve as partes de uma `public enum class` ou de `public enum struct`.  
  
 Este exemplo mostra como definir uma classe enum pública:  
  
 [!code-cpp[cx_enums#01](../cppcx/codesnippet/CPP/cpp/class1.h#01)]  
  
 Este exemplo a seguir mostra como consumi-la:  
  
 [!code-cpp[cx_enums#02](../cppcx/codesnippet/CPP/cpp/class1.h#02)]  
  
### <a name="examples"></a>Exemplos  
 Os exemplos a seguir mostram como declarar uma enum,  
  
 [!code-cpp[cx_enums#03](../cppcx/codesnippet/CPP/cpp/class1.h#03)]  
  
 O próximo exemplo mostra com converter em equivalentes numéricos e executar comparações. Observe que o uso do enumerador `One` tem seu escopo definido pelo identificador de enumeração `Enum1` e o enumerador `First` tem seu escopo definido por `Enum2`.  
  
 [!code-cpp[cx_enums#04](../cppcx/codesnippet/CPP/cpp/class1.h#04)]  
  
## <a name="see-also"></a>Consulte também  
 [Sistema de tipos](../cppcx/type-system-c-cx.md)   
 [Referência de linguagem do Visual C++](../cppcx/visual-c-language-reference-c-cx.md)   
 [Referência de namespaces](../cppcx/namespaces-reference-c-cx.md)