---
title: Genéricos e modelos (C++/CLI)
ms.date: 10/12/2018
ms.topic: reference
helpviewer_keywords:
- generics [C++], vs. templates
- templates, C++
ms.assetid: 63adec79-b1dc-4a1a-a21d-b8a72a8fce31
ms.openlocfilehash: 567286ee24e9df968b2d352489fe12f2735854eb
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80172341"
---
# <a name="generics-and-templates-ccli"></a>Genéricos e modelos (C++/CLI)

Os modelos e genéricos são recursos de linguagem que são compatíveis com tipos parametrizados. No entanto, eles são diferentes e têm usos diversificados. Este tópico fornece uma visão geral das muitas diferenças.

Saiba mais em [Windows Runtime e modelos gerenciados](windows-runtime-and-managed-templates-cpp-component-extensions.md).

## <a name="comparing-templates-and-generics"></a>Comparação de modelos e genéricos

Principais diferenças entre genéricos e modelos do C++:

- Os genéricos são genéricos até serem substituídos por tipos no runtime. Os modelos são especializados no tempo de compilação para que não sejam tipos parametrizados no runtime

- O Common Language Runtime é compatível especificamente com genéricos no MSIL. Como o runtime reconhece os genéricos, tipos específicos podem ser substituídos por tipos genéricos ao fazer referência a um assembly que contém um tipo genérico. Modelos, por outro lado, são resolvidos em tipos comuns no tempo de compilação, e os tipos resultantes não podem ser especializados em outros assemblies.

- Genéricos especializados em dois assemblies diferentes com os mesmos argumentos de tipo são o mesmo tipo. Modelos especializados em dois assemblies diferentes com os mesmos argumentos de tipo são considerados pelo runtime como tipos diferentes.

- Genéricos são gerados como uma única parte do código executável que é usado para todos os argumentos de tipo de referência (isso não se aplica a tipos de valor, que têm uma implementação exclusiva por tipo de valor). O compilador JIT tem conhecimento dos genéricos e é capaz de otimizar o código para os tipos de valor ou referência que são usados como argumentos de tipo. Os modelos geram um código de runtime separado para cada especialização.

- Os genéricos não permitem parâmetros de modelo sem tipo, como `template <int i> C {}`. Os modelos permitem.

- Os genéricos não são compatíveis com especialização explícita (ou seja, uma implementação personalizada de um modelo para um tipo específico). Os modelos permitem.

- Os genéricos não permitem especialização parcial (uma implementação personalizada para um subconjunto dos argumentos de tipo). Os modelos permitem.

- Os genéricos não permitem que o parâmetro de tipo seja usado como a classe base para o tipo genérico. Os modelos permitem.

- Os modelos são compatíveis com parâmetros de modelo-modelo (por exemplo, `template<template<class T> class X> class MyClass`), enquanto os genéricos não.

## <a name="combining-templates-and-generics"></a>Combinação de modelos e genéricos

A diferença básica nos genéricos tem implicações na criação de aplicativos que combinam modelos e genéricos. Por exemplo, suponha que você queira criar um wrapper genérico para uma classe de modelo para expor esse modelo a outras linguagens como genérico. Não é possível fazer o genérico pegar um parâmetro de tipo e passar para o modelo, já que o modelo precisa ter esse parâmetro de tipo no tempo de compilação, mas o genérico não resolve o parâmetro de tipo até o runtime. Aninhar um modelo dentro de um genérico também não funciona porque não há nenhuma maneira de expandir os modelos no tempo de compilação para tipos genéricos arbitrários que possa ser instanciada no runtime.

## <a name="example"></a>Exemplo

### <a name="description"></a>DESCRIÇÃO

O exemplo a seguir mostra uma maneira simples de usar modelos e genéricos juntos. Neste exemplo, a classe de modelo passa o próprio parâmetro para o tipo genérico. O inverso não é possível.

Essa linguagem pode ser usada ao criar em uma API genérica existente com um código de modelo local para um assembly de C++/CLI ou quando você precisar adicionar uma camada extra de parametrização a um tipo genérico, para aproveitar determinados recursos de modelos não compatíveis com genéricos.

### <a name="code"></a>Código

```cpp
// templates_and_generics.cpp
// compile with: /clr
using namespace System;

generic <class ItemType>
ref class MyGeneric {
   ItemType m_item;

public:
   MyGeneric(ItemType item) : m_item(item) {}
   void F() {
      Console::WriteLine("F");
   }
};

template <class T>
public ref class MyRef {
MyGeneric<T>^ ig;

public:
   MyRef(T t) {
      ig = gcnew MyGeneric<T>(t);
      ig->F();
    }
};

int main() {
   // instantiate the template
   MyRef<int>^ mref = gcnew MyRef<int>(11);
}
```

```Output
F
```

## <a name="see-also"></a>Confira também

[Genéricos](generics-cpp-component-extensions.md)
