---
title: "How to: Improve Performance with Generics (Visual C++) | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "language-reference"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "performance, C++"
  - "Visual C++, performance"
  - "Visual C++, generics"
  - "generics [C++], performance"
ms.assetid: f14a175b-301f-46cc-86e4-c82d35f9aa3e
caps.latest.revision: 7
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# How to: Improve Performance with Generics (Visual C++)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Com produtos genéricos, você pode criar o código reutilizável base em um parâmetro de tipo.  O tipo real do parâmetro de tipo é adiada até chamado pelo código de cliente.  Para obter mais informações sobre os produtos genéricos, consulte [Generics](../windows/generics-cpp-component-extensions.md).  
  
 Este artigo descreverá como os produtos genéricas podem ajudar a melhorar o desempenho de um aplicativo que use coleções.  
  
## Exemplo  
 O .NET Framework vem com muitas classes de coleção no namespace de <xref:System.Collections?displayProperty=fullName> .  A maioria dessas coleções funcionam em objetos do tipo <xref:System.Object?displayProperty=fullName>.  Isso permite que as coleções armazenam qualquer tipo, desde que tudo no.NET Framework, mesmo tipos de valor, é derivado de <xref:System.Object?displayProperty=fullName>.  No entanto, há dois desvantagens desse método.  
  
 Primeiro, se a coleção está armazenando tipos de valor como inteiros, o valor deve ser encaixotado antes de ser adicionado à coleção e ser unboxed quando o valor é da coleção.  Sido essas operações caras.  
  
 Segundo, não há nenhuma maneira de controlar quais digita pode ser adicionada a uma coleção.  É perfeitamente legais adicionar um inteiro e uma cadeia de caracteres a mesma coleção, mesmo que isso não é provavelmente o que foi planejado.  Em virtude disso, para que seu código é do tipo seguro, você tem que verificar se o tipo recuperado da coleção é de fato o esperado.  
  
 O exemplo de código a seguir mostra os dois desvantagens principais das coleções do .NET Framework antes do produto genéricas.  
  
```  
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
    while (s->Count > 0)  
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
  
  **Apareceu uma cadeia de caracteres: Sete**  
**Apareceu um int: 7**   
## Exemplo  
 O novo namespace de <xref:System.Collections.Generic?displayProperty=fullName> contém muitas das coleções localizadas no namespace de <xref:System.Collections?displayProperty=fullName> , mas foram modificadas para aceitar parâmetros de tipo genéricas.  Isso elimina os dois desvantagens de coleções não genéricas: o com unboxing e os tipos de valor e a incapacidade especificar os tipos a ser armazenados nas coleções.  As operações nas duas coleções são idênticas; diferem apenas no modo como são instanciados.  
  
 Compare o exemplo acima gravado com este exemplo que usa uma coleção genérica de <xref:System.Collections.Generic.Stack%601> .  Nas coleções grandes que são acessadas frequentemente, o desempenho deste exemplo será significativamente maior do que o exemplo anterior.  
  
```  
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
  
  **14**   
## Consulte também  
 [Generics](../windows/generics-cpp-component-extensions.md)