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
ms.openlocfilehash: 6d3be5a46eab68a7f02bb97c477c1ec0b7fcd54d
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33108257"
---
# <a name="a-tracking-handle-to-a-boxed-value"></a>Uma manipulação de acompanhamento de um valor demarcado
O uso de um identificador de rastreamento para um tipo de valor de referência foi alterado de extensões gerenciadas para C++ para Visual C++.  
  
 Conversão boxing é uma particularidade do sistema de tipo CLR unificado. Tipos de valor contêm diretamente seu estado, enquanto tipos de referência são um par de implícita: a entidade nomeada é um identificador para um objeto sem nome alocado no heap gerenciado. Qualquer inicialização ou atribuição de um valor de tipo para um `Object`, por exemplo, requer que o tipo de valor seja colocado no heap CLR - isso é onde a imagem de conversão boxing ele surge - primeiro alocando a memória associada e, em seguida, copiando o estado do tipo de valor e, em seguida, retornar o endereço desse anônimo híbrida entre o valor de referência. Portanto, quando um grava em c#  
  
```  
object o = 1024; // C# implicit boxing  
```  
  
 Há muito mais em andamento que fica aparente pela simplicidade do código. O design do c# oculta a complexidade, não apenas as operações que estão ocorrendo nos bastidores, mas também da abstração de conversão boxing em si. Managed Extensions para C++, por outro lado, a questão que isso poderia levar a uma falsa sensação de eficiência, coloca na face do usuário, exigindo uma instrução explícita:  
  
```  
Object *o = __box( 1024 ); // Managed Extensions explicit boxing  
```  
  
 Conversão boxing é implícita no Visual C++:  
  
```  
Object ^o = 1024; // new syntax implicit boxing  
```  
  
 O `__box` palavra-chave serve um serviço vital dentro das extensões gerenciadas, que está ausente por design de linguagens como c# e Visual Basic: fornece um vocabulário e o controle de identificador para a manipulação direta de uma instância demarcada no heap gerenciado. Por exemplo, considere o seguinte programa pequeno:  
  
```  
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
  
 O código subjacente gerado para as três invocações de `WriteLine` mostrar os vários custos de acessar o valor de um valor demarcado digite (graças Yves Dolce para destacar essas diferenças), onde as linhas indicadas mostram a sobrecarga associada a cada invocação.  
  
```  
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
  
 Passando o tipo de valor demarcado diretamente para `Console::WriteLine` elimina a conversão boxing e a necessidade de chamar `ToString()`. (É claro, há a conversão boxing anterior ao inicializar `br`, portanto, não obtemos nada, a menos que realmente colocamos `br` para trabalhar.  
  
 Na nova sintaxe, o suporte para tipos de valor boxed é consideravelmente mais elegante e integrado no sistema de tipo, mantendo sua capacidade. Por exemplo, aqui está a tradução do programa anterior pequeno:  
  
```  
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
 [Tipos de valor e seus comportamentos (C + + CLI)](../dotnet/value-types-and-their-behaviors-cpp-cli.md)   
 [Como solicitar uma conversão boxing explicitamente](../dotnet/how-to-explicitly-request-boxing.md)