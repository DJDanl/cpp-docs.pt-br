---
title: C3290 de erro do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C3290
dev_langs:
- C++
helpviewer_keywords:
- C3290
ms.assetid: 0baf684b-1143-4953-ac99-a2fa267d8017
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: bf65a35469ca978b0464c6f7275a6ac0e331da5d
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
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