---
title: Um identificador de rastreamento para um valor demarcado | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-cli
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- boxed value types, tracking handle to
ms.assetid: 16c92048-5b74-47d5-8eca-dfea3d38879a
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- dotnet
ms.openlocfilehash: c7e26efae93b509700c3bb0c992d9f397559e99f
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46380719"
---
# <a name="a-tracking-handle-to-a-boxed-value"></a>Uma manipulação de acompanhamento de um valor demarcado

O uso de um identificador de acompanhamento de referência de um tipo de valor foi alterado de extensões gerenciadas para C++ para Visual C++.

Conversão boxing é uma peculiaridade do sistema de tipos CLR unificada. Tipos de valor contêm diretamente seus estados, enquanto os tipos de referência são um par de implícito: a entidade nomeada é um identificador para um objeto sem nome alocado no heap gerenciado. Qualquer inicialização ou atribuição de um valor de tipo para um `Object`, por exemplo, requer que o tipo de valor seja colocado no heap CLR - isso é onde a imagem da conversão boxing ele surge - primeiro alocando a memória associada e, em seguida, copiando o estado do tipo de valor e, em seguida, retornando o endereço desse anônimo híbrida entre o valor de referência. Assim, quando um grava em c#

```cpp
object o = 1024; // C# implicit boxing
```

Há muito mais acontecendo que fica aparente com a simplicidade do código. O design da linguagem c# oculta a complexidade não apenas as operações que estão ocorrendo nos bastidores, mas também da abstração de conversão boxing em si. Managed Extensions para C++, por outro lado, preocupado que isso poderia levar a uma falsa sensação de eficiência, coloca na face do usuário, exigindo uma instrução explícita:

```cpp
Object *o = __box( 1024 ); // Managed Extensions explicit boxing
```

Conversão boxing é implícita no Visual C++:

```cpp
Object ^o = 1024; // new syntax implicit boxing
```

O `__box` palavra-chave serve um serviço vital em extensões gerenciadas, o que estiver ausente por design de linguagens como c# e Visual Basic: ele fornece um vocabulário e o acompanhamento de tratar para manipular diretamente uma instância demarcada no heap gerenciado. Por exemplo, considere o seguinte programa pequeno:

```cpp
int main() {
   double result = 3.14159;
   __box double * br = __box( result );

   result = 2.7;
   *br = 2.17;
   Object * o = br;

   Console::WriteLine( S"result :: {0}", result.ToString() ) ;
   Console::WriteLine( S"result :: {0}", __box(result) ) ;
   Console::WriteLine( S"result :: {0}", br );
}
```

O código subjacente gerado para as três invocações de `WriteLine` mostrar vários custos de acessar o valor de um valor demarcado de tipo (graças a Yves Dolce para destacar a essas diferenças), onde as linhas indicadas mostram a sobrecarga associada a cada invocação.

```cpp
// Console::WriteLine( S"result :: {0}", result.ToString() ) ;
ldstr      "result :: {0}"
ldloca.s   result  // ToString overhead
call       instance string  [mscorlib]System.Double::ToString()  // ToString overhead
call       void [mscorlib]System.Console::WriteLine(string, object)

// Console::WriteLine( S"result :: {0}", __box(result) ) ;
Ldstr    " result :: {0}"
ldloc.0
box    [mscorlib]System.Double // box overhead
call    void [mscorlib]System.Console::WriteLine(string, object)

// Console::WriteLine( S"result :: {0}", br );
ldstr    "result :: {0}"
ldloc.0
call     void [mscorlib]System.Console::WriteLine(string, object)
```

Passando o tipo de valor demarcado diretamente para `Console::WriteLine` elimina a conversão boxing e a necessidade de chamar `ToString()`. (É claro, há a conversão boxing anterior para inicializar `br`, portanto, não obtemos nada, a menos que realmente colocamos `br` funcione.

Na nova sintaxe, o suporte para tipos de valor demarcado é consideravelmente mais elegante e integrado dentro do sistema de tipo, mantendo sua capacidade. Por exemplo, aqui está a tradução do programa pequeno anterior:

```cpp
int main()
{
   double result = 3.14159;
   double^ br = result;
   result = 2.7;
   *br = 2.17;
   Object^ o = br;
   Console::WriteLine( "result :: {0}", result.ToString() );
   Console::WriteLine( "result :: {0}", result );
   Console::WriteLine( "result :: {0}", br );
}
```

## <a name="see-also"></a>Consulte também

[Tipos de valor e seus comportamentos (C++/CLI)](../dotnet/value-types-and-their-behaviors-cpp-cli.md)<br/>
[Como solicitar uma conversão boxing explicitamente](../dotnet/how-to-explicitly-request-boxing.md)