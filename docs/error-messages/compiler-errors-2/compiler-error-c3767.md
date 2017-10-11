---
title: C3767 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C3767
dev_langs:
- C++
helpviewer_keywords:
- C3767
ms.assetid: 5247cdcd-639c-4527-bd37-37e74c4e8fab
caps.latest.revision: 12
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: 6ebbcbe30a0c9359116d259c36d702a968b333c9
ms.contentlocale: pt-br
ms.lasthandoff: 10/10/2017

---
# <a name="compiler-error-c3767"></a>C3767 de erro do compilador
funções de candidato 'function' não está acessíveis  
  
 Uma função friend definida em uma classe não deve ser tratado como se fosse definido e declarada no escopo de namespace global. Ele pode, no entanto, ser encontrados pela pesquisa dependente de argumento.  
  
 C3767 também pode ser causado por uma alteração significativa: tipos nativos agora são private por padrão em um **/clr** compilação; consulte [visibilidade de tipo](../../dotnet/how-to-define-and-consume-classes-and-structs-cpp-cli.md#BKMK_Type_visibility) para obter mais informações.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir gera C3767:  
  
```  
// C3767a.cpp  
// compile with: /clr  
using namespace System;  
public delegate void TestDel();  
  
public ref class MyClass {  
public:  
   static event TestDel^ MyClass_Event;  
};  
  
public ref class MyClass2 : public MyClass {  
public:  
   void Test() {  
      MyClass^ patient = gcnew MyClass;  
      patient->MyClass_Event();  
    }  
};  
  
int main() {  
   MyClass^ x = gcnew MyClass;  
   x->MyClass_Event();   // C3767  
  
   // OK  
   MyClass2^ y = gcnew MyClass2();  
   y->Test();  
};  
```  
  
 O exemplo a seguir gera C3767:  
  
```  
// C3767c.cpp  
// compile with: /clr /c  
  
ref class Base  {  
protected:  
   void Method() {  
      System::Console::WriteLine("protected");  
   }  
};  
  
ref class Der : public Base {  
   void Method() {  
      ((Base^)this)->Method();   // C3767  
      // try the following line instead  
      // Base::Method();  
   }  
};  
```  
  
 No Visual C++ .NET 2002, o compilador mudou a forma de pesquisado de símbolos. Em alguns casos, ele automaticamente seria para símbolos em um namespace especificado. Agora, ele usa a pesquisa dependente de argumento.  
  
 O exemplo a seguir gera C3767:  
  
```  
// C3767e.cpp  
namespace N {  
   class C {  
      friend void FriendFunc() {}  
      friend void AnotherFriendFunc(C* c) {}  
   };  
}  
  
int main() {  
   using namespace N;  
   FriendFunc();   // C3767 error  
   C* pC = new C();  
   AnotherFriendFunc(pC);   // found via argument-dependent lookup  
}  
```  
  
 Para o código que é válido no Visual C++ .NET 2003 e o Visual C++ .NET 2002, declare um amigo no escopo de classe e defini-lo no escopo de namespace:  
  
```  
// C3767f.cpp  
class MyClass {  
   int m_private;  
   friend void func();  
};  
  
void func() {  
   MyClass s;  
   s.m_private = 0;  
}  
  
int main() {  
   func();  
}  
```
