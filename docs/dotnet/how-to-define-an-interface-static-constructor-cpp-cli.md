---
title: 'Como: Definir um construtor estático de Interface (C + + / CLI)'
ms.date: 11/04/2016
helpviewer_keywords:
- constructors [C++]
- static constructors, interface
- interface static constructor
ms.assetid: 1f031cb2-e94f-43dc-819b-44cf2faaaa49
ms.openlocfilehash: dc1ef81bdefa5ed5d6418325bb250b7954d87268
ms.sourcegitcommit: dedd4c3cb28adec3793329018b9163ffddf890a4
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/11/2019
ms.locfileid: "57748600"
---
# <a name="how-to-define-an-interface-static-constructor-ccli"></a>Como: Definir um construtor estático de Interface (C + + / CLI)

Uma interface pode ter um construtor estático, que pode ser usado para inicializar membros de dados estáticos.  Um construtor estático será chamado no máximo uma vez e será chamado antes da primeira vez que um membro de interface estática é acessado.

## <a name="example"></a>Exemplo

```
// mcppv2_interface_class2.cpp
// compile with: /clr
using namespace System;

interface struct MyInterface {
   static int i;
   static void Test() {
      Console::WriteLine(i);
   }

   static MyInterface() {
      Console::WriteLine("in MyInterface static constructor");
      i = 99;
   }
};

ref class MyClass : public MyInterface {};

int main() {
   MyInterface::Test();
   MyClass::MyInterface::Test();

   MyInterface ^ mi = gcnew MyClass;
   mi->Test();
}
```

```Output
in MyInterface static constructor
99
99
99
```

## <a name="see-also"></a>Consulte também

[classe de interface](../windows/interface-class-cpp-component-extensions.md)
