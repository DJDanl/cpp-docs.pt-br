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
ms.openlocfilehash: d5060f1a0950b9b2ac2638b99ff157983944a3bb
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "65516161"
---
# <a name="abstract--ccli-and-ccx"></a>abstract (C++/CLI e C++/CX)

A palavra-chave **abstract** declara que:

- Um tipo pode ser usado como um tipo base, mas o tipo em si não pode ser instanciado.

- Uma função de membro de tipo pode ser definida apenas em um tipo derivado.

## <a name="all-platforms"></a>Todas as Plataformas

### <a name="syntax"></a>Sintaxe

*class-declaration* *class-identifier* **abstract {}**

**virtual** *return-type* *member-function-identifier* **() abstract ;**

### <a name="remarks"></a>Comentários

A primeira sintaxe de exemplo declara que uma classe é abstrata. O componente *class-declaration* pode ser uma declaração C++ nativa (**class** ou **struct**), ou uma declaração de extensão C++ (**ref class** ou **ref struct**) se a opção do compilador `/ZW` ou `/clr` está especificada.

A segunda sintaxe de exemplo declara que uma função de membro virtual é abstrata. Declarar uma função como abstrata é o mesmo que declarar que é uma função virtual pura. Declarar uma função de membro como abstrata também faz com que a classe delimitadora seja declarada como abstrata.

A palavra-chave **abstract** é compatível em código nativo e específico da plataforma; isto é, pode ser compilada com ou sem a opção do compilador `/ZW` ou `/clr`.

É possível detectar se um tipo é abstrato com o tipo `__is_abstract(type)` no tempo de compilação. Saiba mais em [Suporte para compilador de traços de tipo](compiler-support-for-type-traits-cpp-component-extensions.md).

A palavra-chave **abstract** é um especificador de substituição contextual. Saiba mais sobre palavras-chave contextuais em [Palavras-chave contextuais](context-sensitive-keywords-cpp-component-extensions.md). Saiba mais sobre especificadores de substituição em [Como declarar especificadores de substituição em compilações nativas](../dotnet/how-to-declare-override-specifiers-in-native-compilations-cpp-cli.md).

## <a name="windows-runtime"></a>Tempo de Execução do Windows

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

## <a name="see-also"></a>Consulte também

[Extensões de componentes para .NET e UWP](component-extensions-for-runtime-platforms.md)
