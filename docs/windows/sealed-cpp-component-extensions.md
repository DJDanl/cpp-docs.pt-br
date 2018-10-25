---
title: sealed (C + + c++ /CLI e c++ /CLI CX) | Microsoft Docs
ms.custom: ''
ms.date: 10/12/2018
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- sealed_cpp
- sealed
dev_langs:
- C++
helpviewer_keywords:
- sealed keyword [C++]
ms.assetid: 3d0d688a-41aa-45f5-a25a-65c44206521e
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: ee0ea65267320a4730c543cec978c2675ef1cc57
ms.sourcegitcommit: a9dcbcc85b4c28eed280d8e451c494a00d8c4c25
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/25/2018
ms.locfileid: "50071947"
---
# <a name="sealed--ccli-and-ccx"></a>sealed (C + + c++ /CLI e c++ /CLI CX)

**lacrado** é uma palavra-chave contextual para classes ref que indica que um membro virtual não pode ser substituído ou que um tipo não pode ser usado como um tipo base.

> [!NOTE]
> O C + + 11 linguagem padrão ISO introduziu o [final](../cpp/final-specifier.md) palavra-chave. Use **final** em classes padrão, e **lacrado** em classes ref.

## <a name="all-runtimes"></a>Todos os Tempos de Execução

## <a name="syntax"></a>Sintaxe

```cpp
ref class identifier sealed {...};
virtual return-type identifier() sealed {...};
```

### <a name="parameters"></a>Parâmetros

*identifier*<br/>
O nome da função ou classe.

*tipo de retorno*<br/>
O tipo que é retornado por uma função.

## <a name="remarks"></a>Comentários

No primeiro exemplo de sintaxe, uma classe é selada. No segundo exemplo, uma função virtual está lacrada.

Use o **lacrado** palavra-chave para classes e suas funções de membro virtual. Para obter mais informações, consulte [especificadores de substituição e compilações nativas](../dotnet/how-to-declare-override-specifiers-in-native-compilations-cpp-cli.md).

Você pode detectar no tempo de compilação se um tipo está lacrado usando o `__is_sealed(type)` característica de tipo. Para obter mais informações, consulte [suporte do compilador para características de tipo](../windows/compiler-support-for-type-traits-cpp-component-extensions.md).

**lacrado** é uma palavra-chave contextual.  Para obter mais informações, consulte [contextual as palavras-chave](../windows/context-sensitive-keywords-cpp-component-extensions.md).

## <a name="windows-runtime"></a>Tempo de Execução do Windows

Ver [classes e estruturas Ref](../cppcx/ref-classes-and-structs-c-cx.md).

### <a name="requirements"></a>Requisitos

Opção do compilador: `/ZW`

## <a name="common-language-runtime"></a>Common Language Runtime

(Não há nenhum comentário sobre este recurso de linguagem que se aplicam a apenas o common language runtime.)

### <a name="requirements"></a>Requisitos

Opção do compilador: `/clr`

### <a name="examples"></a>Exemplos

Este exemplo de código a seguir mostra o efeito de **lacrado** em um membro virtual.

```cpp
// sealed_keyword.cpp
// compile with: /clr
interface struct I1 {
   virtual void f();
   virtual void g();
};

ref class X : I1 {
public:
   virtual void f() {
      System::Console::WriteLine("X::f override of I1::f");
   }

   virtual void g() sealed {
      System::Console::WriteLine("X::f override of I1::g");
   }
};

ref class Y : public X {
public:
   virtual void f() override {
      System::Console::WriteLine("Y::f override of I1::f");
   }

   /*
   // the following override generates a compiler error
   virtual void g() override {
      System::Console::WriteLine("Y::g override of I1::g");
   }
   */
};

int main() {
   I1 ^ MyI = gcnew X;
   MyI -> f();
   MyI -> g();

   I1 ^ MyI2 = gcnew Y;
   MyI2 -> f();
}
```

```Output
X::f override of I1::f
X::f override of I1::g
Y::f override of I1::f
```

O exemplo de código a seguir mostra como marcar uma classe como sealed.

```cpp
// sealed_keyword_2.cpp
// compile with: /clr
interface struct I1 {
   virtual void f();
};

ref class X sealed : I1 {
public:
   virtual void f() override {}
};

ref class Y : public X {   // C3246 base class X is sealed
public:
   virtual void f() override {}
};
```

## <a name="see-also"></a>Consulte também

[Extensões de componentes para .NET e UWP](../windows/component-extensions-for-runtime-platforms.md)