---
title: 'Como: melhorar o desempenho com genéricos (C + + / CLI)'
ms.date: 10/12/2018
ms.topic: reference
helpviewer_keywords:
- performance, C++
- C++, performance
- C++, generics
- generics [C++], performance
ms.assetid: f14a175b-301f-46cc-86e4-c82d35f9aa3e
ms.openlocfilehash: 61d858542505b0e37b03e13cca803df10ffbdddc
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50527953"
---
# <a name="how-to-improve-performance-with-generics-ccli"></a>Como: melhorar o desempenho com genéricos (C + + / CLI)

Com genéricos, você pode criar códigos reutilizáveis, com base em um parâmetro de tipo. O tipo real do parâmetro de tipo é adiado até que a chamada pelo código do cliente. Para obter mais informações sobre os genéricos, consulte [genéricos](../windows/generics-cpp-component-extensions.md).

Este artigo discutirá como genéricos podem ajudar a aumentar o desempenho de um aplicativo que usa coleções.

## <a name="example"></a>Exemplo

O .NET Framework vem com muitas classes de coleção no <xref:System.Collections?displayProperty=fullName> namespace. A maioria dessas coleções opera em objetos do tipo <xref:System.Object?displayProperty=fullName>. Isso permite que a coleções armazenar qualquer tipo, desde que todos os tipos no .NET Framework, até mesmo em tipos de valor derivam <xref:System.Object?displayProperty=fullName>. No entanto, há duas desvantagens nessa abordagem.

Primeiro, se a coleção está armazenando os tipos de valores como inteiros, o valor deve ser boxed antes de serem adicionados à coleção e unboxed quando o valor é recuperado da coleção. Essas são operações caras.

Em segundo lugar, não há nenhuma maneira de controlar quais tipos podem ser adicionados a uma coleção. É permitido adicionar um número inteiro e uma cadeia de caracteres na mesma coleção, mesmo que esse é provavelmente não é o pretendido. Portanto, para o seu código seja fortemente tipado que, é necessário que verificar se o tipo recuperado da coleção é realmente o que era esperado.

O exemplo de código a seguir mostra as duas principais desvantagens das coleções do .NET Framework anterior aos genéricos.

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

## <a name="example"></a>Exemplo

O novo <xref:System.Collections.Generic?displayProperty=fullName> namespace contém muitas das mesmas coleções encontradas no <xref:System.Collections?displayProperty=fullName> namespace, mas eles foram modificadas para aceitar parâmetros de tipo genérico. Isso elimina duas desvantagens de coleções não genéricas: a conversão boxing e unboxing de tipos de valor e a incapacidade de especificar os tipos a ser armazenado nas coleções. Operações em duas coleções são idênticas; elas diferem apenas em como eles são instanciados.

Compare o exemplo escrito acima com este exemplo que usa um genérico <xref:System.Collections.Generic.Stack%601> coleção. Em grandes coleções que são acessadas com frequência, o desempenho deste exemplo será significativamente maior do que o exemplo anterior.

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

## <a name="see-also"></a>Consulte também

[Genéricos](../windows/generics-cpp-component-extensions.md)