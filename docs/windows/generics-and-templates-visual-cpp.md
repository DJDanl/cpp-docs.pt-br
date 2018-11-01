---
title: Genéricos e modelos (C + + / CLI)
ms.date: 10/12/2018
ms.topic: reference
helpviewer_keywords:
- generics [C++], vs. templates
- templates, C++
ms.assetid: 63adec79-b1dc-4a1a-a21d-b8a72a8fce31
ms.openlocfilehash: 81b2812faa2fcb7acfdc272474d22039afa24655
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50660038"
---
# <a name="generics-and-templates-ccli"></a>Genéricos e modelos (C + + / CLI)

Genéricos e modelos são recursos de linguagem que oferecem suporte para tipos parametrizados. No entanto, eles são diferentes e têm diferentes usos. Este tópico fornece uma visão geral das muitas diferenças.

Para obter mais informações, consulte [tempo de execução do Windows e modelos gerenciados](../windows/windows-runtime-and-managed-templates-cpp-component-extensions.md).

## <a name="comparing-templates-and-generics"></a>Comparando modelos e genéricos

Principais diferenças entre modelos C++ e genéricos:

- Genéricos são genéricos, até que os tipos são substituídos para eles em tempo de execução. Os modelos são especializados em tempo de compilação para que não sejam ainda com parâmetros de tipos em tempo de execução

- O common language runtime especificamente dá suporte a genéricos no MSIL. Como o tempo de execução sabe sobre os genéricos, tipos específicos podem ser substituídos por tipos genéricos, ao referenciar um assembly que contém um tipo genérico. Modelos, por outro lado, resolvem em tipos comuns em tempo de compilação e os tipos resultantes não podem ser especializados em outros assemblies.

- Genéricos especializada em dois assemblies diferentes com o mesmo tipo de argumentos são do mesmo tipo. Os modelos são especializados em dois assemblies diferentes com o mesmo tipo que os argumentos são considerados pelo tempo de execução para tipos diferentes.

- Genéricos são gerados como uma única parte do código executável que é usado para todos os argumentos de tipo de referência (isso não é verdadeiro para tipos de valor, que têm uma implementação exclusiva por tipo de valor). O compilador JIT sabe sobre os genéricos e é capaz de otimizar o código para os tipos de valor ou referência que são usados como argumentos de tipo. Modelos de geram código de tempo de execução separado para cada especialização.

- Os genéricos não permitem que parâmetros de modelo sem tipo, como `template <int i> C {}`. Os modelos permitem a eles.

- Genéricos não permitem que a especialização explícita (ou seja, uma implementação personalizada de um modelo para um tipo específico). Modelos de fazem.

- Genéricos não permitem que a especialização parcial (uma implementação personalizada para um subconjunto dos argumentos de tipo). Modelos de fazem.

- Os genéricos não permitem que o parâmetro de tipo a ser usado como a classe base para o tipo genérico. Modelos de fazem.

- Modelos oferecem suporte a parâmetros de modelo de modelo (por exemplo, `template<template<class T> class X> class MyClass`), mas não genéricos.

## <a name="combining-templates-and-generics"></a>Genéricos e modelos de combinação

A diferença básica em genéricos tem implicações para a criação de aplicativos que combinam modelos e genéricos. Por exemplo, suponha que você tenha uma classe de modelo que você deseja criar um invólucro genérico para expor esse modelo para outros idiomas como um elemento genérico. Você não pode ter das genérica leva um parâmetro de tipo que ele, em seguida, passa para o modelo, uma vez que o modelo precisa ter esse parâmetro de tipo em tempo de compilação, mas genérica não resolver o parâmetro de tipo até que o tempo de execução. Aninhamento de um modelo dentro de um genérico também não funcionará porque não há nenhuma maneira de expandir os modelos em tempo de compilação para tipos genéricos arbitrários que pode ser instanciada em tempo de execução.

## <a name="example"></a>Exemplo

### <a name="description"></a>Descrição

O exemplo a seguir mostra um exemplo simples de usar modelos e genéricos juntos. Neste exemplo, a classe de modelo passa seu parâmetro por meio de para o tipo genérico. O inverso não é possível.

Essa linguagem pode ser usada quando você deseja criar em uma API genérica existente com o código de modelo que seja local para C + c++ /CLI assembly da CLI, ou quando você precisa adicionar uma camada extra de parametrização para um tipo genérico tirar proveito de determinados recursos de modelos não há suporte para b genéricos de y.

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

## <a name="see-also"></a>Consulte também

[Genéricos](../windows/generics-cpp-component-extensions.md)