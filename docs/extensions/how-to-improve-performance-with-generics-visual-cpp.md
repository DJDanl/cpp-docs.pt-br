---
title: Como melhorar o desempenho com genéricos (C++/CLI)
ms.date: 10/12/2018
ms.topic: reference
helpviewer_keywords:
- performance, C++
- C++, performance
- C++, generics
- generics [C++], performance
ms.assetid: f14a175b-301f-46cc-86e4-c82d35f9aa3e
ms.openlocfilehash: 039c5b069351249e51d961d9d1757ed6b09ef99c
ms.sourcegitcommit: 94893973211d0b254c8bcdcf0779997dcc136b0c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/28/2020
ms.locfileid: "91414159"
---
# <a name="how-to-improve-performance-with-generics-ccli"></a>Como melhorar o desempenho com genéricos (C++/CLI)

Com genéricos, você pode criar um código reutilizável com base em um parâmetro de tipo. O tipo real do parâmetro de tipo é adiado até ser chamado pelo código do cliente. Confira mais informações sobre genéricos em [Genéricos](generics-cpp-component-extensions.md).

Este artigo discutirá como os genéricos podem ajudar a aumentar o desempenho de um aplicativo que usa coleções.

## <a name="example-two-main-drawbacks-of-net-framework-collections"></a>Exemplo: duas desvantagens principais das coleções de .NET Framework

O .NET Framework acompanha várias classes de coleções no namespace <xref:System.Collections?displayProperty=fullName>. A maioria dessas coleções opera em objetos do tipo <xref:System.Object?displayProperty=fullName>. Isso permite que as coleções armazenem qualquer tipo, já que todos os tipos no .NET Framework, até mesmo os tipos de valores, são derivados de <xref:System.Object?displayProperty=fullName>. No entanto, existem duas desvantagens nessa abordagem.

A primeira é que, se a coleção estiver armazenando tipos de valores, como inteiros, o valor deverá receber conversão boxing antes de ser adicionado à coleção e receber com conversão unboxing quando o valor for recuperado da coleção. Essas operações são caras.

A segunda é que não há como controlar quais tipos podem ser adicionados a uma coleção. É perfeitamente aceitável adicionar um inteiro e uma cadeia à mesma coleção, mesmo que esta provavelmente não seja a ação pretendida. Portanto, para que seu código seja do tipo seguro, é necessário verificar se o tipo recuperado da coleção é realmente o esperado.

O exemplo de código a seguir mostra as duas principais desvantagens das coleções do .NET Framework antes dos genéricos.

```cpp
// perf_pre_generics.cpp
// compile with: /clr

using namespace System;
using namespace System::Collections;

int main()
{
    // This Stack can contain any type.
    Stack ^s = gcnew Stack();

    // Push an integer to the Stack.
    // A boxing operation is performed here.
    s->Push(7);

    // Push a String to the same Stack.
    // The Stack now contains two different data types.
    s->Push("Seven");

    // Pop the items off the Stack.
    // The item is returned as an Object, so a cast is
    // necessary to convert it to its proper type.
    while (s->Count> 0)
    {
        Object ^o = s->Pop();
        if (o->GetType() == Type::GetType("System.String"))
        {
            Console::WriteLine("Popped a String: {0}", (String ^)o);
        }
        else if (o->GetType() == Type::GetType("System.Int32"))
        {
            Console::WriteLine("Popped an int: {0}", (int)o);
        }
        else
        {
            Console::WriteLine("Popped an unknown type!");
        }
    }
}
```

```Output
Popped a String: Seven
Popped an int: 7
```

## <a name="example-benefit-of-using-generic-collection"></a>Exemplo: benefício de usar a coleção genérica

O novo namespace <xref:System.Collections.Generic?displayProperty=fullName> contém muitas das mesmas coleções encontradas no namespace <xref:System.Collections?displayProperty=fullName>, mas estas foram modificadas para aceitar parâmetros de tipo genérico. Isso elimina as duas desvantagens das coleções não genéricas: a conversão boxing e a conversão unboxing dos tipos de valores, bem como a incapacidade de especificar os tipos a serem armazenados nas coleções. As operações nas duas coleções são idênticas, diferindo apenas na maneira como são instanciadas.

Compare o exemplo escrito acima com este exemplo que usa uma coleção <xref:System.Collections.Generic.Stack%601> genérica. Em coleções grandes que são acessadas com frequência, o desempenho desse exemplo será significativamente maior que o do exemplo anterior.

```cpp
// perf_post_generics.cpp
// compile with: /clr

#using <System.dll>

using namespace System;
using namespace System::Collections::Generic;

int main()
{
    // This Stack can only contain integers.
    Stack<int> ^s = gcnew Stack<int>();

    // Push an integer to the Stack.
    // A boxing operation is performed here.
    s->Push(7);
    s->Push(14);

    // You can no longer push a String to the same Stack.
    // This will result in compile time error C2664.
    //s->Push("Seven");

    // Pop an item off the Stack.
    // The item is returned as the type of the collection, so no
    // casting is necessary and no unboxing is performed for
    // value types.
    int i = s->Pop();
    Console::WriteLine(i);

    // You can no longer retrieve a String from the Stack.
    // This will result in compile time error C2440.
    //String ^str = s->Pop();
}
```

```Output
14
```

## <a name="see-also"></a>Confira também

[Genéricos](generics-cpp-component-extensions.md)
