---
title: "Compilador aviso (nível 1) C4803 | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C4803
dev_langs:
- C++
helpviewer_keywords:
- C4803
ms.assetid: 2552f3a6-c418-49f4-98a2-a929857be658
caps.latest.revision: 9
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
ms.sourcegitcommit: c243063a9770542f137d5950e8a269f771960f74
ms.openlocfilehash: 2581d4240306e88d75fe5fcc0249371005853b7e
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-warning-level-1-c4803"></a>Compilador C4803 de aviso (nível 1)
'method': o método para disparar tem uma classe de armazenamento diferente do evento, 'event'  
  
Métodos de evento devem ter a mesma classe de armazenamento que a declaração de evento. O compilador ajusta os métodos do evento para que as classes de armazenamento são os mesmos.  
  
Esse aviso pode ocorrer se você tiver uma classe que implementa um evento de uma interface. O compilador não gera implicitamente um método para disparar um evento em uma interface. Quando você implementa essa interface em uma classe, o compilador gerar implicitamente um método para disparar e esse método não será virtual, portanto, o aviso. Para obter mais informações sobre eventos, consulte [evento](../../windows/event-cpp-component-extensions.md).  
  
Consulte [aviso](../../preprocessor/warning.md) pragma para obter informações sobre como desativar um aviso.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir gera C4803.  
  
```  
// C4803.cpp  
// compile with: /clr /W1  
using namespace System;  
  
public delegate void Del();  
  
ref struct E {  
   Del ^ _pd1;  
   event Del ^ E1 {  
      void add (Del ^ pd1) {  
         _pd1 = dynamic_cast<Del ^>(Delegate::Combine(_pd1, pd1));  
      }  
  
      void remove(Del^ pd1) {  
         _pd1 = dynamic_cast<Del^> (Delegate::Remove(_pd1, pd1));  
      }  
  
      virtual void raise() {   // C4803 warning (remove virtual)  
         if (_pd1)  
            _pd1();  
      }  
   }  
  
   void func() {  
      Console::WriteLine("In E::func()");  
   }  
};  
  
int main() {  
   E ^ ep = gcnew E;  
   ep->E1 += gcnew Del(ep, &E::func);  
   ep->E1();  
   ep->E1 -= gcnew Del(ep, &E::func);  
   ep->E1();  
}  
```  

