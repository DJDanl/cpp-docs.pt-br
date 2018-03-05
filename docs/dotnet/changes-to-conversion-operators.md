---
title: "Altera para os operadores de conversão | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
helpviewer_keywords:
- conversion operators
- operators [C++], explicit type conversion
- type conversion, explicit conversions
- conversions, explicit
- explicit keyword [C++]
ms.assetid: 9b83925c-71b7-4bd3-ac2e-843dd7c7f184
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- dotnet
ms.openlocfilehash: 8f89c49035e2e48dde8d502b1d61fa33d198f69a
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="changes-to-conversion-operators"></a>Alterações feitas em operadores da conversão
A sintaxe de operadores de conversão foi alterado de extensões gerenciadas para C++ para Visual C++.  
  
 Um exemplo é escrever `op_Implicit` para especificar uma conversão. Aqui está uma definição de `MyDouble` obtido da especificação de linguagem:  
  
```  
__gc struct MyDouble {  
   static MyDouble* op_Implicit( int i );   
   static int op_Explicit( MyDouble* val );  
   static String* op_Explicit( MyDouble* val );   
};  
```  
  
 Isso significa que, considerando um número inteiro, o algoritmo para converter esse inteiro em uma `MyDouble` é fornecido pelo `op_Implicit` operador. Além disso, essa conversão será executada implicitamente pelo compilador. Da mesma forma, dado um `MyDouble` objeto, os dois `op_Explicit` operadores fornecem os respectivos algoritmos para converter o objeto em um número inteiro ou um gerenciado `String` entidade. No entanto, o compilador não executará a conversão, a menos que explicitamente solicitada pelo usuário.  
  
 Em c#, isso será semelhante ao seguinte:  
  
```  
class MyDouble {  
   public static implicit operator MyDouble( int i );   
   public static explicit operator int( MyDouble val );  
   public static explicit operator string( MyDouble val );   
};  
```  
  
 O código c# parece mais com C++ que das extensões gerenciadas para C++. Esse não for o caso em que a nova sintaxe.  
  
 O Comitê de ISO C++ introduziu uma palavra-chave `explicit`, para minimizar as consequências não intencionais - por exemplo, um `Array` classe que usa um único argumento inteiro como uma dimensão converterá implicitamente qualquer inteiro em um `Array` do objeto que é não o que você deseja. Uma maneira de evitar que isso é um idioma de design de um segundo argumento fictício para um construtor  
  
 Por outro lado, você deve fornecer um par de conversão durante a criação de um tipo de classe do C++. O melhor exemplo para o que é a classe de cadeia de caracteres padrão. A conversão implícita é o construtor com um único argumento colocar uma cadeia de caracteres de estilo C. No entanto, ele não fornece o operador de conversão implícita correspondente - que de converter uma cadeia de caracteres do objeto para uma cadeia de caracteres de estilo C, mas exige que o usuário explicitamente invocar uma função nomeada - nesse caso, em vez disso `c_str()`.  
  
 Portanto, associar um comportamento implícita/explícita em um operador de conversão (e como o conjunto de conversões em uma única forma de declaração de encapsulamento) parece ser um aprimoramento de suporte do C++ original para os operadores de conversão, que eventualmente levou para o `explicit` palavra-chave. O suporte de linguagem Visual C++ para os operadores de conversão será semelhante ao seguinte, que é um pouco menos detalhada do que o de C# por causa o comportamento padrão do operador dão suporte a um aplicativo implícita do algoritmo de conversão:  
  
```  
ref struct MyDouble {  
public:  
   static operator MyDouble^ ( int i );  
   static explicit operator int ( MyDouble^ val );  
   static explicit operator String^ ( MyDouble^ val );  
};  
```  
  
 Outra alteração é que um construtor único argumento é tratado como se ele está declarado como `explicit`. Isso significa que, para acionar os invocações, uma conversão explícita é necessária. No entanto, observe que, se um operador de conversão explícita é definido, ele e não o construtor com um único argumento, é invocado.  
  
## <a name="see-also"></a>Consulte também  
 [Declarações de membro em uma classe ou interface (C++/CLI)](../dotnet/member-declarations-within-a-class-or-interface-cpp-cli.md)