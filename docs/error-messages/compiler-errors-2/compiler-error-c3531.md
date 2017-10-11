---
title: C3531 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C3531
dev_langs:
- C++
helpviewer_keywords:
- C3531
ms.assetid: 2bdb9fdc-9ddf-403e-8b92-02763d434487
caps.latest.revision: 6
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: 7753e30e305b7b36adc3b4d2b535f755fa455bdd
ms.contentlocale: pt-br
ms.lasthandoff: 10/10/2017

---
# <a name="compiler-error-c3531"></a>C3531 de erro do compilador
'symbol': um símbolo cujo tipo contém 'auto' deve ter um inicializador  
  
 A variável especificada não tem uma expressão de inicializador.  
  
### <a name="to-correct-this-error"></a>Para corrigir este erro  
  
1.  Especifique uma expressão de inicializador, como uma atribuição simple que usa a sintaxe de sinal de igual, quando você declara a variável.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir produz C3531 porque variáveis `x1`, `y1, y2, y3`, e `z2` não foram inicializados.  
  
```  
// C3531.cpp  
// Compile with /Zc:auto  
int main()  
{  
   auto x1;                  // C3531  
   auto y1, y2, y3;          // C3531  
   auto z1 = 1, z2, z3 = -1; // C3531  
   return 0;  
}  
```  
  
## <a name="see-also"></a>Consulte também  
 [Palavra-chave auto](../../cpp/auto-keyword.md)
