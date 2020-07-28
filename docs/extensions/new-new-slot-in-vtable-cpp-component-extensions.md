---
title: novo (novo slot em vtable) (C++/CLI e C++/CX)
ms.date: 10/12/2018
ms.topic: reference
helpviewer_keywords:
- new keyword [C++]
ms.assetid: 1a9a5704-f02f-46ae-ad65-f0f2b6dbabc3
ms.openlocfilehash: 29e43fe4c462fa6ac6523f8627abf923f02247a8
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87214237"
---
# <a name="new-new-slot-in-vtable--ccli-and-ccx"></a>novo (novo slot em vtable) (C++/CLI e C++/CX)

A **`new`** palavra-chave indica que um membro virtual receberá um novo slot na vtable.

## <a name="all-runtimes"></a>Todos os Runtimes

(Não há comentários para esse recurso de linguagem que se apliquem a todos os runtimes.)

## <a name="windows-runtime"></a>Windows Runtime

Não é compatível com Windows Runtime.

## <a name="common-language-runtime"></a>Common Language Runtime

### <a name="remarks"></a>Comentários

Em uma `/clr` compilação, **`new`** indica que um membro virtual receberá um novo slot na vtable; que a função não substitui um método de classe base.

**`new`** faz com que o modificador NewSlot seja adicionado ao IL para a função.  Confira mais informações sobre newslot em:

- <xref:System.Reflection.MethodInfo.GetBaseDefinition?displayProperty=nameWithType>

- <xref:System.Reflection.MethodAttributes?displayProperty=nameWithType>

### <a name="requirements"></a>Requisitos

Opção do compilador: `/clr`

### <a name="examples"></a>Exemplos

O exemplo a seguir mostra o efeito de **`new`** .

```cpp
// newslot.cpp
// compile with: /clr
ref class C {
public:
   virtual void f() {
      System::Console::WriteLine("C::f() called");
   }

   virtual void g() {
      System::Console::WriteLine("C::g() called");
   }
};

ref class D : public C {
public:
   virtual void f() new {
      System::Console::WriteLine("D::f() called");
   }

   virtual void g() override {
      System::Console::WriteLine("D::g() called");
   }
};

ref class E : public D {
public:
   virtual void f() override {
      System::Console::WriteLine("E::f() called");
   }
};

int main() {
   D^ d = gcnew D;
   C^ c = gcnew D;

   c->f();   // calls C::f
   d->f();   // calls D::f

   c->g();   // calls D::g
   d->g();   // calls D::g

   D ^ e = gcnew E;
   e->f();   // calls E::f
}
```

```Output
C::f() called

D::f() called

D::g() called

D::g() called

E::f() called
```

## <a name="see-also"></a>Confira também

[Extensões de componente para .NET e UWP](component-extensions-for-runtime-platforms.md)<br/>
[Substituir especificadores](override-specifiers-cpp-component-extensions.md)
