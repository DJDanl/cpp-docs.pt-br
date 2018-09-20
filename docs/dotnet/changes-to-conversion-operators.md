---
title: Altera para operadores de conversão | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-cli
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- conversion operators
- operators [C++], explicit type conversion
- type conversion, explicit conversions
- conversions, explicit
- explicit keyword [C++]
ms.assetid: 9b83925c-71b7-4bd3-ac2e-843dd7c7f184
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- dotnet
ms.openlocfilehash: 03b17c5abc559289a9f85a10b9c5914b49498922
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46381096"
---
# <a name="changes-to-conversion-operators"></a>Alterações feitas em operadores da conversão

A sintaxe para os operadores de conversão foi alterado de extensões gerenciadas para C++ no Visual C++.

Um exemplo é escrever `op_Implicit` para especificar uma conversão. Aqui está uma definição de `MyDouble` obtido da especificação de linguagem:

```
__gc struct MyDouble {
   static MyDouble* op_Implicit( int i );
   static int op_Explicit( MyDouble* val );
   static String* op_Explicit( MyDouble* val );
};
```

Isso significa que, considerando um número inteiro, o algoritmo para converter esse inteiro em um `MyDouble` é fornecido pelo `op_Implicit` operador. Além disso, essa conversão será executada implicitamente pelo compilador. Da mesma forma, dado um `MyDouble` objeto, os dois `op_Explicit` operadores fornecem os respectivos algoritmos para converter esse objeto em um inteiro ou um gerenciado `String` entidade. No entanto, o compilador não realizará a conversão, a menos que explicitamente solicitado pelo usuário.

No c#, isso será semelhante ao seguinte:

```
class MyDouble {
   public static implicit operator MyDouble( int i );
   public static explicit operator int( MyDouble val );
   public static explicit operator string( MyDouble val );
};
```

O código c# se parece mais com C++ de extensões gerenciadas para C++. Esse não for o caso na nova sintaxe.

O Comitê de ISO-c introduziu uma palavra-chave `explicit`, para minimizar as consequências não intencionais - por exemplo, um `Array` classe que usa um único argumento inteiro como uma dimensão converterá implicitamente qualquer inteiro em um `Array` do objeto que não é o que você quer. Uma maneira de evitar isso é uma linguagem de design de um segundo argumento fictícia para um construtor

Por outro lado, você deve fornecer um par de conversão durante a criação de um tipo de classe dentro do C++. O melhor exemplo para o que é a classe de cadeia de caracteres padrão. A conversão implícita é o construtor de argumento único que usa uma cadeia de caracteres de estilo C. No entanto, ele não fornece o operador de conversão implícita correspondente - que de converter uma cadeia de caracteres do objeto para uma cadeia de caracteres de estilo C, mas em vez disso, requer que o usuário invocar explicitamente uma função nomeada - nesse caso, `c_str()`.

Portanto, associar um comportamento implícitas/explícitas em um operador de conversão (e como encapsulando o conjunto de conversões em um único formulário de declaração) parece ser uma melhoria no suporte de C++ original para operadores de conversão, que, eventualmente, levou para o `explicit` palavra-chave. O suporte de linguagem do Visual C++ para os operadores de conversão será semelhante ao seguinte, que é um pouco menos detalhado que c# devido ao comportamento padrão do operador que dão suporte a um aplicativo implícito do algoritmo de conversão:

```
ref struct MyDouble {
public:
   static operator MyDouble^ ( int i );
   static explicit operator int ( MyDouble^ val );
   static explicit operator String^ ( MyDouble^ val );
};
```

Outra mudança é que um construtor de argumento único é tratado como se ela é declarada como `explicit`. Isso significa que, para disparar seus invocações, uma conversão explícita é necessária. No entanto, observe que, se um operador de conversão explícita é definido, ele e não o construtor de argumento único, é invocado.

## <a name="see-also"></a>Consulte também

[Declarações de membro em uma classe ou interface (C++/CLI)](../dotnet/member-declarations-within-a-class-or-interface-cpp-cli.md)