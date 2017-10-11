---
title: C3154 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C3154
dev_langs:
- C++
helpviewer_keywords:
- C3154
ms.assetid: 78005c74-eaaf-4ac2-88ae-6c25d01a302a
caps.latest.revision: 7
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: de38898f775d621edfec464de8a51d20c3bdb4f0
ms.contentlocale: pt-br
ms.lasthandoff: 10/10/2017

---
# <a name="compiler-error-c3154"></a>C3154 de erro do compilador
Esperado ',' antes de reticências. Vírgula não separados não tem suportada em funções de matriz de parâmetro de reticências.  
  
 Uma função de argumento variável não foi declarada corretamente.  
  
 Para obter mais informações, consulte [listas de argumentos variáveis (...) (C + + CLI) ](../../windows/variable-argument-lists-dot-dot-dot-cpp-cli.md).  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir gera C3154.  
  
```  
// C3154.cpp  
// compile with: /clr  
ref struct R {  
   void Func(int ... array<int> ^);   // C3154  
   void Func2(int i, ... array<int> ^){}   // OK  
   void Func3(array<int> ^){}   // OK  
   void Func4(... array<int> ^){}   // OK  
};  
  
int main() {  
   R ^ r = gcnew R;  
   r->Func4(1,2,3);  
}  
```
