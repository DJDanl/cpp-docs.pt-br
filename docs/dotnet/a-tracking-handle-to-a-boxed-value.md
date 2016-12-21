---
title: "Uma manipula&#231;&#227;o de acompanhamento de um valor demarcado | Microsoft Docs"
ms.custom: ""
ms.date: "12/15/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "tipos de valor demarcado, manipulador de acompanhamento para"
ms.assetid: 16c92048-5b74-47d5-8eca-dfea3d38879a
caps.latest.revision: 11
caps.handback.revision: 11
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Uma manipula&#231;&#227;o de acompanhamento de um valor demarcado
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

O uso de um identificador de rastreamento para fazer referência a um tipo de valor foi alterada de extensões gerenciadas para C\+\+ a [!INCLUDE[cpp_current_long](../Token/cpp_current_long_md.md)].  
  
 O boxing é uma peculiaridade do sistema de tipo unificado CLR.  Os tipos de valores diretamente contêm seu estado, quando os tipos de referência é um par implícitos: a entidade nomeada é um identificador para um objeto sem nome atribuído no heap gerenciado.  Qualquer inicialização ou atribuição de um tipo de valor a `Object`, por exemplo, requerem que o tipo de valor seja colocado no heap de CLR – este é onde a imagem do com ele ocorre – primeiro atribuindo a memória associado, então copiar o estado do tipo de valor, e depois retornando o endereço desse híbrido anônima do valor\/referência.  Assim, quando escrever em C\#  
  
```  
object o = 1024; // C# implicit boxing  
```  
  
 há muitos vai no que é feito aparente pela simplicidade de código.  O design C\# ocultar a complexidade não apenas de operações que estão ocorrendo na capa, mas também a abstração de boxing própria.  As extensões gerenciadas para C\+\+, por outro lado, referiram\-se que essa resultaria em um sentido false de eficiência, o coloca na aparência do usuário exigindo uma instrução explícita:  
  
```  
Object *o = __box( 1024 ); // Managed Extensions explicit boxing  
```  
  
 O boxing está implícito em [!INCLUDE[cpp_current_long](../Token/cpp_current_long_md.md)]:  
  
```  
Object ^o = 1024; // new syntax implicit boxing  
```  
  
 A palavra\-chave de `__box` serve um serviço vital nas extensões gerenciadas, um que está ausente por design dos idiomas como C\# e [!INCLUDE[vbprvb](../Token/vbprvb_md.md)]: fornece um vocabulário e o identificador de rastreamento para manipular diretamente uma instância encaixotada no heap gerenciado.  Por exemplo, considere o seguinte programa pequeno:  
  
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
  
 O código subjacente gerado para as três invocações de apresentação de `WriteLine` vários custo de acessar o valor de um tipo de valor encaixotado \(graças a Yves Dolce para indicar essas diferenças\), onde as linhas apontadas mostram a sobrecarga associada a cada invocação.  
  
```  
// Console::WriteLine( S"result :: {0}", result.ToString() ) ;  
ldstr      "result :: {0}"  
ldloca.s   result  // ToString overhead  
call       instance string  [mscorlib]System.Double::ToString()  // ToString overhead  
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
  
 Passe o tipo de valor encaixotado diretamente a `Console::WriteLine` elimina o e com a necessidade invocar `ToString()`. \(Logicamente, há o com anterior para inicializar `br`, o que nós não ganhamos qualquer coisa a menos que nós colocarmos realmente `br` para trabalhar.  
  
 Na nova sintaxe, o suporte para tipos de valor boxed é consideravelmente mais elegante e integrado no sistema de tipos para manter sua capacidade.  Por exemplo, aqui está a tradução de programa pequeno anterior:  
  
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
  
## Consulte também  
 [Tipos de valor e seus comportamentos \(C\+\+\/CLI\)](../dotnet/value-types-and-their-behaviors-cpp-cli.md)   
 [Como fazer uma conversão boxing de solicitação explícita](../Topic/How%20to:%20Explicitly%20Request%20Boxing.md)