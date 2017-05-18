---
title: C4485 de aviso do compilador | Documentos do Microsoft
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
caps.latest.revision: 7
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
ms.openlocfilehash: 7a3578b78f3ae8d33a602fe4d52b76c10930e42b
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-warning-c4485"></a>C4485 de aviso do compilador
'override_function': corresponde ao método da classe base ref 'base_class_function', mas não está marcado como 'new' ou 'Substituir'; 'new' (e 'virtual') serão assumidos  
  
 Substitui um acessador, com ou sem o `virtual` palavra-chave, uma função de acessador de classe base, mas o `override` ou `new` especificador não fazia parte da assinatura de função de substituição. Adicionar o `new` ou `override` especificador para resolver esse aviso.  
  
 Consulte [substituir](../../windows/override-cpp-component-extensions.md) e [novo (novo slot em vtable)](../../windows/new-new-slot-in-vtable-cpp-component-extensions.md) para obter mais informações.  
  
 C4485 sempre é emitida como um erro. Use o [aviso](../../preprocessor/warning.md) pragma para suprimir C4485.  
  
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
