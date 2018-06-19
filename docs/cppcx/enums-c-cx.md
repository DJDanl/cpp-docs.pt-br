---
title: Enumerações (C + + CX) | Microsoft Docs
ms.custom: ''
ms.date: 12/30/2016
ms.technology: cpp-windows
ms.topic: language-reference
ms.assetid: 99fbbe28-c1cd-43af-9ead-60f90eba6e68
author: ghogen
ms.author: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: c96fa4e7194e262eec0be4cf5f7467c163530bd2
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33087375"
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