---
title: novo (novo slot em vtable) (C + + c++ /CLI e c++ /CLI CX)
ms.date: 10/12/2018
ms.topic: reference
helpviewer_keywords:
- new keyword [C++]
ms.assetid: 1a9a5704-f02f-46ae-ad65-f0f2b6dbabc3
ms.openlocfilehash: b143b2ead1165382d0959f4e4c90f1d2e7ea936a
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50487159"
---
# <a name="new-new-slot-in-vtable--ccli-and-ccx"></a>novo (novo slot em vtable) (C + + c++ /CLI e c++ /CLI CX)

O **novo** palavra-chave indica que um membro virtual obterá um novo slot em vtable.

## <a name="all-runtimes"></a>Todos os Tempos de Execução

(Não há nenhum comentário sobre este recurso de linguagem que se aplicam a todos os tempos de execução.)

## <a name="windows-runtime"></a>Tempo de Execução do Windows

Não tem suporte em tempo de execução do Windows.

## <a name="common-language-runtime"></a>Common Language Runtime

### <a name="remarks"></a>Comentários

Em um `/clr` compilação, **nova** indica que um membro virtual obterá um novo slot em vtable; que a função não substitui um método de classe base.

**novo** faz com que o modificador newslot a ser adicionado ao IL para a função.  Para obter mais informações sobre novo slot, consulte:

- [Método MethodInfo. Getbasedefinition](https://msdn.microsoft.com/library/system.reflection.methodinfo.getbasedefinition.aspx)

- [Enumeração de MethodAttributes](https://msdn.microsoft.com/library/system.reflection.methodattributes.aspx)

### <a name="requirements"></a>Requisitos

Opção do compilador: `/clr`

### <a name="examples"></a>Exemplos

O exemplo a seguir mostra o efeito **novo**.

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

[Extensões de componentes para .NET e UWP](../windows/component-extensions-for-runtime-platforms.md)<br/>

[Especificadores de substituição](../windows/override-specifiers-cpp-component-extensions.md)