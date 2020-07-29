---
title: abstract (C++/CLI e C++/CX)
ms.date: 10/12/2018
ms.topic: reference
f1_keywords:
- abstract
- abstract_cpp
helpviewer_keywords:
- abstract keyword [C++]
ms.assetid: cbae3408-0378-4ac8-b70d-c016b381a6d5
ms.openlocfilehash: 1e729589f78c56111717a87a27f9c7370dca7b90
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87214289"
---
# <a name="abstract--ccli-and-ccx"></a>abstract (C++/CLI e C++/CX)

A palavra-chave **abstract** declara que:

- Um tipo pode ser usado como um tipo base, mas o tipo em si não pode ser instanciado.

- Uma função de membro de tipo pode ser definida apenas em um tipo derivado.

## <a name="all-platforms"></a>Todas as plataformas

### <a name="syntax"></a>Sintaxe

*class-declaration* *class-identifier* **abstract {}**

**`virtual`***tipo de retorno* de *membro-função-identificador* **() abstrato;**

### <a name="remarks"></a>Comentários

A primeira sintaxe de exemplo declara que uma classe é abstrata. O componente *de declaração de classe* pode ser uma declaração c++ nativa (** `class` * * * * ou **`struct`** ), ou uma declaração de extensão de c++ (** ref class * * ou **ref struct**) se a `/ZW` opção de compilador ou `/clr` for especificada.

A segunda sintaxe de exemplo declara que uma função de membro virtual é abstrata. Declarar uma função como abstrata é o mesmo que declarar que é uma função virtual pura. Declarar uma função de membro como abstrata também faz com que a classe delimitadora seja declarada como abstrata.

A palavra-chave **abstract** é compatível em código nativo e específico da plataforma; isto é, pode ser compilada com ou sem a opção do compilador `/ZW` ou `/clr`.

É possível detectar se um tipo é abstrato com o tipo `__is_abstract(type)` no tempo de compilação. Saiba mais em [Suporte para compilador de traços de tipo](compiler-support-for-type-traits-cpp-component-extensions.md).

A palavra-chave **abstract** é um especificador de substituição contextual. Saiba mais sobre palavras-chave contextuais em [Palavras-chave contextuais](context-sensitive-keywords-cpp-component-extensions.md). Para obter mais informações sobre especificadores de substituição, consulte [como: declarar especificadores de substituição em compilações nativas](../dotnet/how-to-declare-override-specifiers-in-native-compilations-cpp-cli.md).

## <a name="windows-runtime"></a>Windows Runtime

Saiba mais em [Classes e structs ref](../cppcx/ref-classes-and-structs-c-cx.md).

### <a name="requirements"></a>Requisitos

Opção do compilador: `/ZW`

## <a name="common-language-runtime"></a>Common Language Runtime

### <a name="requirements"></a>Requisitos

Opção do compilador: `/clr`

### <a name="examples"></a>Exemplos

O exemplo de código a seguir gera um erro porque a classe `X` está marcada como **abstract**.

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

O exemplo de código a seguir gera um erro porque cria uma instância de uma classe nativa marcada como **abstract**. Este erro ocorrerá com ou sem a opção do compilador `/clr`.

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

O exemplo de código a seguir gera um erro porque a função `f` inclui uma definição, mas está marcada como **abstract**. A instrução final no exemplo mostra que declarar uma função virtual como abstrata é equivalente a declarar uma função como virtual pura.

```cpp
// abstract_keyword_3.cpp
// compile with: /clr
ref class X {
public:
   virtual void f() abstract {}   // C3634
   virtual void g() = 0 {}   // C3634
};
```

## <a name="see-also"></a>Confira também

[Extensões de componente para .NET e UWP](component-extensions-for-runtime-platforms.md)
