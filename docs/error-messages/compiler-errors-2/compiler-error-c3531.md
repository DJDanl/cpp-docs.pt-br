---
title: C3531 de erro do compilador | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
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
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: 6ce52fda967f7296e7bb85b03f219cb8913398ad
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-error-c3531"></a>C3531 de erro do compilador
'symbol': um símbolo cujo tipo contém 'auto' deve ter um inicializador  
  
 A variável especificada não tem uma expressão de inicializador.  
  
### <a name="to-correct-this-error"></a>Para corrigir este erro  
  
1.  Especifique uma expressão de inicializador, como uma atribuição simple que usa a sintaxe de sinal de igual, quando você declara a variável.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir produz C3531 porque variáveis `x1`, `y1, y2, y3`, e `z2` não são inicializados.  
  
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
 [palavra-chave auto](../../cpp/auto-keyword.md)
