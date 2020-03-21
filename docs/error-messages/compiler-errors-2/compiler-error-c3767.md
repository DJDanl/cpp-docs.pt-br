---
title: Erro do compilador C3767
ms.date: 11/04/2016
f1_keywords:
- C3767
helpviewer_keywords:
- C3767
ms.assetid: 5247cdcd-639c-4527-bd37-37e74c4e8fab
ms.openlocfilehash: d4a69d7dffb4a01a91b14c3858cb0a5d553d1cf8
ms.sourcegitcommit: 8e285a766523e653aeeb34d412dc6f615ef7b17b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/21/2020
ms.locfileid: "80075163"
---
# <a name="compiler-error-c3767"></a>Erro do compilador C3767

funções de candidato de ' função ' não acessíveis

Uma função Friend definida em uma classe não deve ser tratada como se fosse definida e declarada no escopo do namespace global. No entanto, ele pode ser encontrado pela pesquisa dependente de argumento.

C3767 também pode ser causado por uma alteração significativa: os tipos nativos agora são privados por padrão em uma compilação **/CLR** ; consulte [visibilidade de tipo](../../dotnet/how-to-define-and-consume-classes-and-structs-cpp-cli.md#BKMK_Type_visibility) para obter mais informações.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C3767:

```cpp
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

```cpp
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
