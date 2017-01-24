---
title: "Altera&#231;&#245;es feitas em operadores da convers&#227;o | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
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
  - "operadores de conversão"
  - "conversões, explicit"
  - "Palavra-chave explicit [C++]"
  - "operadores [C++], conversão implícita de tipo"
  - "conversão de tipo, conversões explícitas"
ms.assetid: 9b83925c-71b7-4bd3-ac2e-843dd7c7f184
caps.latest.revision: 9
caps.handback.revision: 9
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Altera&#231;&#245;es feitas em operadores da convers&#227;o
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

A sintaxe para operadores de conversão foi alterada de extensões gerenciadas para C\+\+ a [!INCLUDE[cpp_current_long](../Token/cpp_current_long_md.md)].  
  
 Um exemplo é gravar `op_Implicit` para especificar uma conversão.  Eis uma definição de `MyDouble` tomada da especificação de linguagem:  
  
```  
__gc struct MyDouble {  
   static MyDouble* op_Implicit( int i );   
   static int op_Explicit( MyDouble* val );  
   static String* op_Explicit( MyDouble* val );   
};  
```  
  
 Isso indica que, dado um inteiro, o algoritmo para converter esse valor inteiro em `MyDouble` é fornecido pelo operador de `op_Implicit` .  Além disso, essa conversão será executada implicitamente pelo compilador.  De maneira semelhante, dado um objeto de `MyDouble` , os dois operadores de `op_Explicit` fornecem os algoritmos respectivos para converter esse objeto em um inteiro ou em uma entidade gerenciada de `String` .  No entanto, o compilador não executará a conversão a menos que sejam explicitamente solicitados pelo usuário.  
  
 No C\#, isso é semelhante a seguinte maneira:  
  
```  
class MyDouble {  
   public static implicit operator MyDouble( int i );   
   public static explicit operator int( MyDouble val );  
   public static explicit operator string( MyDouble val );   
};  
```  
  
 O código de exemplo c como C\+\+ mais do que as extensões gerenciadas para C\+\+ oferecem.  Isso não é os casos na nova sintaxe.  
  
 O comitê de ISO\-C\+\+ o introduziu uma palavra\-chave, `explicit`, para reduzir consequências não intencionais – por exemplo, uma classe de `Array` que usa um único argumento inteiro como uma dimensão converterá implicitamente qualquer inteiro em um objeto de `Array` que não é o que você deseja.  Uma maneira de evitar isso é uma linguagem de design de um segundo argumento fictícia a um construtor  
  
 Por outro lado, você não deve fornecer um par de conversão ao criar um tipo de classe do C\+\+.  O melhor exemplo para que é a classe padrão de cadeia de caracteres.  A conversão implícita é o construtor de um único argumento que usa a c o estilo da cadeia de caracteres.  Porém, o não fornece um operador de conversão implícita de correspondência – da conversão de um objeto de cadeia de caracteres para c o estilo da cadeia de caracteres, mas requer um pouco o usuário invocar explicitamente uma função nomeada – nesse caso, `c_str()`.  
  
 Assim, associar comportamento implícita e explícita em um operador de conversão \(e como encapsular o conjunto de conversões a um único formulário de declaração\) parece ser uma melhoria no suporte ao original C\+\+ para os operadores de conversão, que resultaram se houver a `explicit` a palavra\-chave.  O suporte a idioma de [!INCLUDE[cpp_current_long](../Token/cpp_current_long_md.md)] para operadores de conversão é semelhante a seguir, que é um pouco menos detalhado que o C\# devido ao comportamento padrão do operador que oferece suporte a um aplicativo implícito do algoritmo de conversão:  
  
```  
ref struct MyDouble {  
public:  
   static operator MyDouble^ ( int i );  
   static explicit operator int ( MyDouble^ val );  
   static explicit operator String^ ( MyDouble^ val );  
};  
```  
  
 Outra alteração é que um único construtor de argumento será tratado como se for declarado como `explicit`.  Isso significa que para disparar as invocações, uma conversão explícita é necessária.  Observe, entretanto, que se um operador de conversão explícita é definido, ele e não o construtor de um único argumento, é invocada.  
  
## Consulte também  
 [Declarações de membro em uma classe ou uma interface \(C\+\+\/CLI\)](../dotnet/member-declarations-within-a-class-or-interface-cpp-cli.md)