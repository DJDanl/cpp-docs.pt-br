---
title: C4485 de aviso do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C4485
dev_langs:
- C++
helpviewer_keywords:
- C4485
ms.assetid: a6f2b437-ca93-4dcd-b9cb-df415e10df86
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 1289ee1ce2a5f756d7a21f966424007eee704ac1
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="compiler-warning-c4485"></a>C4485 de aviso do compilador
'override_function': corresponde ao método de classe ref base 'base_class_function', mas não está marcado como 'new' ou 'override'; 'new' (e 'virtual') são assumidos  
  
 Substitui um acessador, com ou sem o `virtual` palavra-chave, uma função de acessador de classe base, mas o `override` ou `new` especificador não fazia parte da assinatura de função de substituição. Adicionar o `new` ou `override` especificador para resolver este aviso.  
  
 Consulte [substituir](../../windows/override-cpp-component-extensions.md) e [novo (novo slot em vtable)](../../windows/new-new-slot-in-vtable-cpp-component-extensions.md) para obter mais informações.  
  
 C4485 sempre é emitido como um erro. Use o [aviso](../../preprocessor/warning.md) pragma para suprimir C4485.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir gera C4485  
  
```  
// C4485.cpp  
// compile with: /clr  
delegate void Del();  
  
ref struct A {  
   virtual event Del ^E;  
};  
  
ref struct B : A {  
   virtual event Del ^E;   // C4485  
};  
  
ref struct C : B {  
   virtual event Del ^E {  
      void raise() override {}  
      void add(Del ^) override {}  
      void remove(Del^) override {}  
   }  
};  
```