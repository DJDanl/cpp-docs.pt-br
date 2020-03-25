---
title: sealed (C++/CLI e C++/CX)
ms.date: 10/12/2018
ms.topic: reference
f1_keywords:
- sealed_cpp
- sealed
helpviewer_keywords:
- sealed keyword [C++]
ms.assetid: 3d0d688a-41aa-45f5-a25a-65c44206521e
ms.openlocfilehash: ab5d5b32ceb87a3b1ccf08d170889dd4825f6c17
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80181792"
---
# <a name="sealed--ccli-and-ccx"></a>sealed (C++/CLI e C++/CX)

**sealed** é uma palavra-chave contextual para classes de referência que indica que um membro virtual não pode ser substituído, ou que um tipo não pode ser usado como um tipo base.

> [!NOTE]
> A linguagem padrão ISO 11 do C++introduziu a palavra-chave [final](../cpp/final-specifier.md). Use **final** em classes padrão e **sealed** em classes ref.

## <a name="all-runtimes"></a>Todos os Runtimes

## <a name="syntax"></a>Sintaxe

```cpp
ref class identifier sealed {...};
virtual return-type identifier() sealed {...};
```

### <a name="parameters"></a>parâmetros

*identifier*<br/>
O nome da função ou classe.

*return-type*<br/>
O tipo retornado por uma função.

## <a name="remarks"></a>Comentários

No primeiro exemplo de sintaxe, uma classe é “sealed”. No segundo exemplo, uma função virtual é “sealed”.

Use a palavra-chave **sealed** para as classes ref e suas funções de membro virtual. Saiba mais em [Especificadores de substituição e compilações nativas](../dotnet/how-to-declare-override-specifiers-in-native-compilations-cpp-cli.md).

Você pode detectar se um tipo é “sealed” usando o traço de tipo `__is_sealed(type)` no tempo de compilação. Saiba mais em [Suporte para compilador de traços de tipo](compiler-support-for-type-traits-cpp-component-extensions.md).

**sealed** é uma palavra-chave contextual.  Saiba mais em [Palavras-chave contextuais](context-sensitive-keywords-cpp-component-extensions.md).

## <a name="windows-runtime"></a>Tempo de Execução do Windows

Confira [Classes e structs ref](../cppcx/ref-classes-and-structs-c-cx.md).

### <a name="requirements"></a>Requisitos

Opção do compilador: `/ZW`

## <a name="common-language-runtime"></a>Common Language Runtime

(Não há comentários para esse recurso de linguagem que se apliquem apenas ao Common Language Runtime.)

### <a name="requirements"></a>Requisitos

Opção do compilador: `/clr`

### <a name="examples"></a>Exemplos

O exemplo de código a seguir mostra o efeito de **sealed** em um membro virtual.

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

O próximo exemplo de código mostra como marcar uma classe como “sealed”.

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

## <a name="see-also"></a>Confira também

[Extensões de componentes para .NET e UWP](component-extensions-for-runtime-platforms.md)
