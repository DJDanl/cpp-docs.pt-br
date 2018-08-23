---
title: abstract (extensões de componentes C++) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- abstract
- abstract_cpp
dev_langs:
- C++
helpviewer_keywords:
- abstract keyword [C++]
ms.assetid: cbae3408-0378-4ac8-b70d-c016b381a6d5
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 463848ea5f01bf232850d548c9f4255c07409254
ms.sourcegitcommit: 6f8dd98de57bb80bf4c9852abafef1c35a7600f1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/22/2018
ms.locfileid: "42610993"
---
# <a name="abstract--c-component-extensions"></a>abstrata (Extensões de Componentes C++)

O **abstrata** palavra-chave declara que qualquer um:

- Um tipo pode ser usado como um tipo base, mas o próprio tipo não pode ser instanciado.

- Uma função de membro de tipo pode ser definida apenas em um tipo derivado.

## <a name="all-platforms"></a>Todas as Plataformas

### <a name="syntax"></a>Sintaxe

```cpp
      class-declaration
      class-identifier
      abstract {}
virtualreturn-typemember-function-identifier() abstract ;
```

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

[Extensões de componentes para plataformas de tempo de execução](../windows/component-extensions-for-runtime-platforms.md)