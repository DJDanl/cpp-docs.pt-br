---
title: Declaração de um tipo de classe gerenciada | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-cli
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- __gc types
- classes [C++], managed
- class keyword [C++], CLR
- __value keyword
- value types, declaring
- value keyword [C++]
- managed classes
- interface class keyword
- ref keyword [C++]
ms.assetid: 16de9c94-91d7-492f-8ac7-f0729cc627e9
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- dotnet
ms.openlocfilehash: 0f9ceb0867fbdfbbdb46075662fca802d1ee0bba
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46393666"
---
# <a name="declaration-of-a-managed-class-type"></a>Declaração de um tipo de classe gerenciado

A maneira de declarar um tipo de classe de referência alterado de extensões gerenciadas para C++ para Visual C++.

Nas extensões gerenciadas, um tipo de classe de referência seja prefixado com o `__gc` palavra-chave. Na nova sintaxe, o `__gc` palavra-chave é substituída por uma das duas palavras-chave espaçadas: `ref class` ou `ref struct`. A escolha da `struct` ou `class` indica o público (para `struct`) ou privada (para `class`) o nível de acesso padrão de seus membros declarados em uma seção sem rótulo inicial do corpo do tipo.

Da mesma forma, nas extensões gerenciadas, um tipo de classe de valor seja prefixado com o `__value` palavra-chave. Na nova sintaxe, o `__value` palavra-chave é substituída por uma das duas palavras-chave espaçadas: `value class` ou `value struct`.

Um tipo de interface, nas extensões gerenciadas, foi indicado com a palavra-chave `__interface`. Na nova sintaxe, ele é substituído por `interface class`.

Por exemplo, as seguintes declarações de classe nas extensões gerenciadas:

```
public __gc class Block {};     // reference class
public __value class Vector {}; // value class
public __interface IFooBar {};  // interface class
```

Sob a nova sintaxe esses são equivalentemente declarados da seguinte maneira:

```
public ref class Block {};         // reference class
public value class Vector {};      // value class
public interface class IFooBar {}; // interface class
```

## <a name="specifying-the-class-as-abstract"></a>Especificando a classe como abstrata

Em extensões gerenciadas, você coloca a palavra-chave `__abstract` antes do `class` palavra-chave (antes ou depois de `__gc`) para indicar que a classe está incompleta e que os objetos da classe não podem ser criados dentro do programa:

```
public __gc __abstract class Shape {};
public __gc __abstract class Shape2D: public Shape {};
```

Sob a nova sintaxe, você deve especificar o `abstract` palavra-chave contextual, seguindo a classe e o nome antes do corpo da classe, lista de derivação de classe base ou ponto e vírgula.

```
public ref class Shape abstract {};
public ref class Shape2D abstract : public Shape{};
```

É claro, o significado semântico permanece inalterado.

## <a name="specifying-the-class-as-sealed"></a>Especificando a classe como selado

Em extensões gerenciadas, você coloca a palavra-chave `__sealed` antes do `class` palavra-chave (antes ou depois `__gc`) para indicar que os objetos da classe não podem ser herdados de:

```
public __gc __sealed class String {};
```

Sob a nova sintaxe, você deve especificar o `sealed` palavra-chave contextual, seguindo a classe e o nome antes do corpo da classe, lista de derivação de classe base ou ponto e vírgula.

Você pode derivar uma classe e lacrá-lo. Por exemplo, o `String` classe é derivada implicitamente de `Object`. O benefício de lacrar uma classe é que ele oferece suporte a resolução estática (ou seja, em tempo de compilação) de todas as chamadas de função virtual por meio do objeto de classe de referência lacrado. Isso ocorre porque o `sealed` especificador garante que o `String` alça de controle não pode se referir a uma classe derivada, subsequentemente, que pode fornecer uma instância de substituição do método virtual que está sendo invocado. Aqui está um exemplo de uma classe selada na nova sintaxe:

```
public ref class String sealed {};
```

Um também pode especificar uma classe como ambos os abstrato e selado - esta é uma condição de especial que indica uma classe estática. Isso é descrito na documentação do CLR da seguinte maneira:

"Um tipo que é ambas `abstract` e `sealed` deve ter apenas membros estáticos e serve como o que algumas linguagens chamar um namespace."

Por exemplo, aqui está uma declaração de uma classe sealed abstract usando a sintaxe de Managed Extensions:

```
public __gc __sealed __abstract class State {
public:
   static State() {}
   static bool inParamList();

private:
   static bool ms_inParam;
};
```

e aqui está essa declaração traduzida para a nova sintaxe:

```
public ref class State abstract sealed {
public:
   static State();
   static bool inParamList();

private:
   static bool ms_inParam;
};
```

## <a name="clr-inheritance-specifying-the-base-class"></a>Herança de CLR: Especifica a classe Base

No modelo de objeto CLR, há suporte para somente a herança única pública. No entanto, as extensões gerenciadas mantido a interpretação do padrão ISO C++ de uma classe base sem uma palavra-chave de acesso que especificar uma derivação particular. Isso significa que cada declaração de herança do CLR tinha que fornecer o `public` palavra-chave para substituir a interpretação padrão.

```
// Managed Extensions: error: defaults to private derivation
__gc class Derived : Base {};
```

Na nova definição de sintaxe, a ausência de uma palavra-chave de acesso indica uma derivação pública em uma definição de herança do CLR. Portanto, o `public` palavra-chave de acesso agora é opcional. Embora isso não exige nenhuma modificação das extensões gerenciadas para código C++, para listar essa alteração para fins de integridade.

```
// New syntax: ok: defaults to public derivation
ref class Derived : Base{};
```

## <a name="see-also"></a>Consulte também

[Tipos gerenciados (C++ /CLI CL)](../dotnet/managed-types-cpp-cl.md)<br/>
[Classes e Structs](../windows/classes-and-structs-cpp-component-extensions.md)<br/>
[abstract](../windows/abstract-cpp-component-extensions.md)<br/>
[sealed](../windows/sealed-cpp-component-extensions.md)