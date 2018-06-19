---
title: C3531 de erro do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C3531
dev_langs:
- C++
helpviewer_keywords:
- C3531
ms.assetid: 2bdb9fdc-9ddf-403e-8b92-02763d434487
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 69fcacacafba752f77aacd55d5cd57b2c42b5ba9
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33252678"
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