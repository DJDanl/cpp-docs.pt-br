---
title: "Classe ostream_iterator | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "ostream_iterator"
  - "std.ostream_iterator"
  - "std::ostream_iterator"
  - "iterator/std::ostream_iterator"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe ostream_iterator"
ms.assetid: 24d842d3-9f45-4bf6-a697-62f5968f5a03
caps.latest.revision: 17
caps.handback.revision: 11
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Classe ostream_iterator
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

A classe de modelo ostream\_iterator descreve um objeto de iterador de saída que grava elementos sucessivos no fluxo de saída com a extração **operator \<\<**.  
  
## Sintaxe  
  
```  
  
      template <  
   class Type   
   class CharType = char  
   class Traits = char_traits<CharType>  
>  
class ostream_iterator  
```  
  
#### Parâmetros  
 *Type*  
 O tipo de objeto a ser inserido no fluxo de saída.  
  
 `CharType`  
 O tipo que representa o tipo de caractere para `ostream_iterator`.  Esse argumento é opcional e o valor padrão é `char`*.*  
  
 `Traits`  
 O tipo que representa o tipo de caractere para `ostream_iterator`.  Esse argumento é opcional e o valor padrão é `char_traits`\<*CharType\>.*  
  
 A classe ostream\_iterator deve atender aos requisitos de um iterador de saída.  Os algoritmos podem ser gravados diretamente nos fluxos de saída usando um `ostream_iterator`.  
  
### Construtores  
  
|||  
|-|-|  
|[ostream\_iterator](../Topic/ostream_iterator::ostream_iterator.md)|Constrói uma `ostream_iterator` que é inicializada e delimitada a gravar no fluxo de saída.|  
  
### Typedefs  
  
|||  
|-|-|  
|[char\_type](../Topic/ostream_iterator::char_type.md)|Um tipo que é fornecido para o tipo de caractere do `ostream_iterator`.|  
|[ostream\_type](../Topic/ostream_iterator::ostream_type.md)|Um tipo que é fornecido para o tipo de fluxo da `ostream_iterator`.|  
|[traits\_type](../Topic/ostream_iterator::traits_type.md)|Um tipo que fornece o tipo de característica do caractere da `ostream_iterator`.|  
  
### Operadores  
  
|||  
|-|-|  
|[operator\*](../Topic/ostream_iterator::operator*.md)|Operador de desreferenciamento usado para implementar a expressão do iterador de saída \*`i` \= `x`.|  
|[operator\+\+](../Topic/ostream_iterator::operator++.md)|Um operador de incremento não funcional que retorna uma `ostream_iterator` para o mesmo objeto que foi tratado antes de a operação ser chamada.|  
|[operator\=](../Topic/ostream_iterator::operator=.md)|O operador de atribuição usado para implementar a expressão do iterador de saída \*`i` \= `x` para gravação em um fluxo de saída.|  
  
## Requisitos  
 **Cabeçalho:** \<iterator\>  
  
 **Namespace:** std  
  
## Consulte também  
 [\<iterator\>](../standard-library/iterator.md)   
 [Segurança de threads na Biblioteca Padrão C\+\+](../standard-library/thread-safety-in-the-cpp-standard-library.md)   
 [Biblioteca de Modelos Padrão](../misc/standard-template-library.md)