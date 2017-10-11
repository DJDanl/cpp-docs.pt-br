---
title: C3290 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- C3290
dev_langs:
- C++
helpviewer_keywords:
- C3290
ms.assetid: 0baf684b-1143-4953-ac99-a2fa267d8017
caps.latest.revision: 8
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: c3dceac5102936bbb86f5c103fb0c9240f5ee2d2
ms.contentlocale: pt-br
ms.lasthandoff: 10/10/2017

---
# <a name="compiler-error-c3290"></a>C3290 de erro do compilador
'type': uma propriedade trivial não pode ter o tipo de referência  
  
 Uma propriedade foi declarada incorretamente. Quando você declara uma propriedade trivial, o compilador cria uma variável que atualizará a propriedade e não é possível ter uma referência de rastreamento variável em uma classe.  
  
 Consulte [propriedade](../../windows/property-cpp-component-extensions.md) e [operador de referência de rastreamento](../../windows/tracking-reference-operator-cpp-component-extensions.md) para obter mais informações.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir gera C3290.  
  
```  
// C3290.cpp  
// compile with: /clr /c  
ref struct R {};  
  
ref struct X {  
   R^ mr;  
  
   property R % y;   // C3290  
   property R ^ x;   // OK  
  
   // OK  
   property R% prop {  
      R% get() {   
         return *mr;   
      }  
  
      void set(R%) {}  
   }  
};  
  
int main() {  
   X x;  
   R% xp = x.prop;  
}  
```
