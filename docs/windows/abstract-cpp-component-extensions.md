---
title: abstrata (C + + c++ /CLI e c++ /CLI CX)
ms.date: 10/12/2018
ms.topic: reference
f1_keywords:
- abstract
- abstract_cpp
helpviewer_keywords:
- abstract keyword [C++]
ms.assetid: cbae3408-0378-4ac8-b70d-c016b381a6d5
ms.openlocfilehash: d2cb8e6d1d60d4469e325a4380701beda49a4355
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50645673"
---
# <a name="abstract--ccli-and-ccx"></a>abstrata (C + + c++ /CLI e c++ /CLI CX)

O **abstrata** palavra-chave declara que qualquer um:

- Um tipo pode ser usado como um tipo base, mas o próprio tipo não pode ser instanciado.

- Uma função de membro de tipo pode ser definida apenas em um tipo derivado.

## <a name="all-platforms"></a>Todas as Plataformas

### <a name="syntax"></a>Sintaxe

*declaração de classe* *identificador de classe* **abstrato {}**

**virtual** *tipo de retorno* *identificador de função de membro* **abstract ();**

### <a name="remarks"></a>Comentários

A primeira sintaxe de exemplo declara uma classe para ser abstrato. O *declaração de classe* componente pode ser uma declaração C++ nativa (**classe** ou **struct**), ou uma declaração de extensão do C++ (**classe ref** ou **ref struct**) se o `/ZW` ou `/clr` for especificada a opção de compilador.

A segunda sintaxe de exemplo declara uma função membro virtual para ser abstrato. Declarando um resumo da função é o mesmo que declarar uma função virtual pura. Declarando um resumo da função de membro também faz com que a classe delimitadora ser declarada como abstrata.

O **abstrata** palavra-chave é suportado no código nativo e específicos da plataforma; ou seja, ele pode ser compilado com ou sem o `/ZW` ou `/clr` opção de compilador.

Você pode detectar no tempo de compilação se um tipo for abstrato com o `__is_abstract(type)` característica de tipo. Para obter mais informações, consulte [suporte do compilador para características de tipo](../windows/compiler-support-for-type-traits-cpp-component-extensions.md).

O **abstrata** palavra-chave é um especificador de substituição sensível ao contexto. Para obter mais informações sobre palavras-chave contextuais, consulte [contextual as palavras-chave](../windows/context-sensitive-keywords-cpp-component-extensions.md). Para obter mais informações sobre especificadores de substituição, consulte [como: declarar especificadores de substituição em compilações nativas](../dotnet/how-to-declare-override-specifiers-in-native-compilations-cpp-cli.md).

## <a name="windows-runtime"></a>Tempo de Execução do Windows

Para obter mais informações, consulte [classes e estruturas Ref](../cppcx/ref-classes-and-structs-c-cx.md).

### <a name="requirements"></a>Requisitos

Opção do compilador: `/ZW`

## <a name="common-language-runtime"></a>Common Language Runtime

### <a name="requirements"></a>Requisitos

Opção do compilador: `/clr`

### <a name="examples"></a>Exemplos

O exemplo de código a seguir gera um erro porque classe `X` está marcada **abstrata**.

```cpp
// abstract_keyword.cpp
// compile with: /clr
ref class X abstract {
public:
   virtual void f() {}
};

int main() {
   X ^ MyX = gcnew X;   // C3622
}
```

O exemplo de código a seguir gera um erro porque ele instancia uma classe nativa que é marcada **abstrata**. Este erro ocorrerá com ou sem o `/clr` opção de compilador.

```cpp
// abstract_keyword_2.cpp
class X abstract {
public:
   virtual void f() {}
};

int main() {
   X * MyX = new X; // C3622: 'X': a class declared as 'abstract'
                    // cannot be instantiated. See declaration of 'X'}
```

O exemplo de código a seguir gera um erro porque função `f` inclui uma definição, mas está marcada **abstrata**. A instrução final no exemplo mostra que a declarar uma função virtual abstract é equivalente ao declarar uma função virtual pura.

```cpp
// abstract_keyword_3.cpp
// compile with: /clr
ref class X {
public:
   virtual void f() abstract {}   // C3634
   virtual void g() = 0 {}   // C3634
};
```

## <a name="see-also"></a>Consulte também

[Extensões de componentes para .NET e UWP](../windows/component-extensions-for-runtime-platforms.md)
