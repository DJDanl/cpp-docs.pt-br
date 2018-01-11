---
title: "Como: melhorar o desempenho com genéricos (Visual C++) | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: language-reference
dev_langs: C++
helpviewer_keywords:
- performance, C++
- Visual C++, performance
- Visual C++, generics
- generics [C++], performance
ms.assetid: f14a175b-301f-46cc-86e4-c82d35f9aa3e
caps.latest.revision: "7"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 8d8aad77236e5c1b2cdc8fe5958d87d8c53b8f05
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="how-to-improve-performance-with-generics-visual-c"></a>Como melhorar o desempenho com genéricos (Visual C++)
Com genéricos, você pode criar com base em um parâmetro de tipo de código reutilizável. O tipo real do parâmetro de tipo é adiado até que a chamada pelo código do cliente. Para obter mais informações sobre genéricos, consulte [genéricos](../windows/generics-cpp-component-extensions.md).  
  
 Este artigo discutirá como genéricos podem ajudar a aumentar o desempenho de um aplicativo que usa coleções.  
  
## <a name="example"></a>Exemplo  
 O .NET Framework vem com muitas classes de coleção no <xref:System.Collections?displayProperty=fullName> namespace. A maioria dessas coleções operar em objetos do tipo <xref:System.Object?displayProperty=fullName>. Isso permite que a coleções armazenar qualquer tipo, desde que todos os tipos do .NET Framework, mesmo em tipos de valor derivam <xref:System.Object?displayProperty=fullName>. No entanto, há duas desvantagens dessa abordagem.  
  
 Primeiro, se a coleção está armazenando os tipos de valor como inteiros, o valor deve ser boxed antes de serem adicionados à coleção e desencaixotado quando o valor é recuperado da coleção. Essas são operações caras.  
  
 Segundo, não há nenhuma maneira de controlar quais tipos podem ser adicionados a uma coleção. É permitido adicionar um número inteiro e uma cadeia de caracteres para a mesma coleção, mesmo que esse é provavelmente não o pretendido. Portanto, em ordem para que seu código seja de tipo seguro, é necessário que verificar se o tipo recuperado da coleção é realmente o que era esperado.  
  
 O exemplo de código a seguir mostra as duas principais desvantagens das coleções do .NET Framework antes de genéricos.  
  
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
  
```Output  
Popped a String: Seven  
Popped an int: 7  
```  
  
## <a name="example"></a>Exemplo  
 O novo <xref:System.Collections.Generic?displayProperty=fullName> namespace contém muitas das coleções mesmo encontradas no <xref:System.Collections?displayProperty=fullName> namespace, mas eles foram modificadas para aceitar parâmetros de tipo genérico. Isso elimina as duas desvantagens coleções não genéricas: a conversão boxing e unboxing de tipos de valor e a incapacidade de especificar os tipos a ser armazenado nas coleções. Operações em duas coleções são idênticas; elas diferem apenas em como eles são instanciados.  
  
 Compare o exemplo descrito acima com este exemplo que usa um genérico <xref:System.Collections.Generic.Stack%601> coleção. Em grandes coleções que são acessadas com frequência, o desempenho deste exemplo pode ser significativamente maior do que o exemplo anterior.  
  
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
  
```Output  
14  
```  
  
## <a name="see-also"></a>Consulte também  
 [Genéricos](../windows/generics-cpp-component-extensions.md)