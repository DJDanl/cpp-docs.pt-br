---
title: novo (novo slot em vtable) (C++/CLI e C++/CX)
ms.date: 10/12/2018
ms.topic: reference
helpviewer_keywords:
- new keyword [C++]
ms.assetid: 1a9a5704-f02f-46ae-ad65-f0f2b6dbabc3
ms.openlocfilehash: c5446e5e84491ff7d736ce3b3af49dacd471c010
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "65515641"
---
# <a name="new-new-slot-in-vtable--ccli-and-ccx"></a>novo (novo slot em vtable) (C++/CLI e C++/CX)

A palavra-chave **new** indica que um membro virtual terá um novo slot em vtable.

## <a name="all-runtimes"></a>Todos os Tempos de Execução

(Não há comentários para esse recurso de linguagem que se apliquem a todos os tempos de execução.)

## <a name="windows-runtime"></a>Tempo de Execução do Windows

Não é compatível com Windows Runtime.

## <a name="common-language-runtime"></a>Common Language Runtime

### <a name="remarks"></a>Comentários

Em uma compilação `/clr`, **new** indica que um membro virtual obterá um novo slot em vtable e que a função não substitui um método de classe base.

**new** faz com que o modificador newslot seja adicionado ao IL da função.  Confira mais informações sobre newslot em:

- <xref:System.Reflection.MethodInfo.GetBaseDefinition?displayProperty=nameWithType>

- <xref:System.Reflection.MethodAttributes?displayProperty=nameWithType>

### <a name="requirements"></a>Requisitos

Opção do compilador: `/clr`

### <a name="examples"></a>Exemplos

O exemplo a seguir mostra o efeito de **new**.

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

## <a name="see-also"></a>Consulte também

[Extensões de componentes para .NET e UWP](component-extensions-for-runtime-platforms.md)<br/>

[Especificadores de substituição](override-specifiers-cpp-component-extensions.md)