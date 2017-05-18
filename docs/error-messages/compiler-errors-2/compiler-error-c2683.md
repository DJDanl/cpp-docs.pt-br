---
title: C2683 de erro do compilador | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C2683
dev_langs:
- C++
helpviewer_keywords:
- C2683
ms.assetid: db605e4f-601b-4d05-92a1-c43ca24de08d
caps.latest.revision: 10
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
ms.translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: 0d1a78f1dbc6b72fd43f555601e0f9e711a65fab
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-error-c2683"></a>C2683 de erro do compilador
'cast': 'type' não é um tipo polimórfico  
  
 Não é possível usar [dynamic_cast](../../cpp/dynamic-cast-operator.md) para converter de uma classe não é polimórfico (uma classe sem funções virtuais).  
  
 Você pode usar [static_cast](../../cpp/static-cast-operator.md) para realizar conversões de tipos não polimórficos. No entanto, `static_cast` não executa uma verificação de tempo de execução.  
  
 O exemplo a seguir gera C2683:  
  
```  
// C2683.cpp  
// compile with: /c  
class B { };  
class D : public B { };  
  
void f(B* pb) {  
   D* pd1 = dynamic_cast<D*>(pb);  // C2683  
   D* pd1 = static_cast<D*>(pb);   // OK  
}  
```
