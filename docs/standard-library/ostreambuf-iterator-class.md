---
title: "Classe ostreambuf_iterator | Microsoft Docs"
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
  - "std.ostreambuf_iterator"
  - "streambuf/std::ostreambuf_iterator"
  - "ostreambuf_iterator"
  - "std::ostreambuf_iterator"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe ostreambuf_iterator"
ms.assetid: dad1e624-2f45-4e94-8887-a885e95f9071
caps.latest.revision: 16
caps.handback.revision: 10
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Classe ostreambuf_iterator
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

A classe de modelo ostreambuf\_iterator descreve um objeto de iterador de saída que grava elementos de caractere sucessivos no fluxo de saída com a extração **operator\>\>**.  As `ostreambuf_iterator`s são diferentes da [classe ostream\_iterator](../standard-library/ostream-iterator-class.md) por terem caracteres em vez de um tipo genérico no tipo de objeto que está sendo inserido no fluxo de saída.  
  
## Sintaxe  
  
```  
  
      template <   
   class CharType = char  
   class Traits = char_traits<CharType>  
>  
```  
  
#### Parâmetros  
 `CharType`  
 O tipo que representa o tipo de caractere para ostreambuf\_iterator.  Esse argumento é opcional e o valor padrão é `char`*.*  
  
 `Traits`  
 O tipo que representa o tipo de caractere para ostreambuf\_iterator.  Esse argumento é opcional e o valor padrão é `char_traits`\<*CharType\>.*  
  
## Comentários  
 A classe ostreambuf\_iterator deve atender aos requisitos de um iterador de saída.  Os algoritmos podem ser gravados diretamente nos fluxos de saída usando um `ostreambuf_iterator`.  A classe fornece um iterador de fluxo de nível baixo que permite acesso ao fluxo de E\/S bruto \(não formatado\) na forma de caracteres e a capacidade de ignorar o buffer e as conversões de caracteres associadas aos iteradores de fluxo de nível alto.  
  
### Construtores  
  
|||  
|-|-|  
|[ostreambuf\_iterator](../Topic/ostreambuf_iterator::ostreambuf_iterator.md)|Constrói uma `ostreambuf_iterator` que é inicializada para gravar caracteres no fluxo de saída.|  
  
### Typedefs  
  
|||  
|-|-|  
|[char\_type](../Topic/ostreambuf_iterator::char_type.md)|Um tipo que é fornecido para o tipo de caractere do `ostreambuf_iterator`.|  
|[ostream\_type](../Topic/ostreambuf_iterator::ostream_type.md)|Um tipo que é fornecido para o tipo de fluxo da `ostream_iterator`.|  
|[streambuf\_type](../Topic/ostreambuf_iterator::streambuf_type.md)|Um tipo que é fornecido para o tipo de fluxo da `ostreambuf_iterator`.|  
|[traits\_type](../Topic/ostreambuf_iterator::traits_type.md)|Um tipo que fornece o tipo de característica do caractere da `ostream_iterator`.|  
  
### Funções membro  
  
|||  
|-|-|  
|[failed](../Topic/ostreambuf_iterator::failed.md)|Testa a falha de uma inserção no buffer do fluxo de saída.|  
  
### Operadores  
  
|||  
|-|-|  
|[operator\*](../Topic/ostreambuf_iterator::operator*.md)|Operador de desreferenciamento usado para implementar a expressão do iterador de saída \*`i` \= `x`.|  
|[operator\+\+](../Topic/ostreambuf_iterator::operator++.md)|Um operador de incremento não funcional que retorna uma `ostreambuf_iterator` para o mesmo objeto que foi tratado antes de a operação ser chamada.|  
|[operator\=](../Topic/ostreambuf_iterator::operator=.md)|O operador insere um caractere no buffer do fluxo associado.|  
  
## Requisitos  
 **Cabeçalho:** \<iterator\>  
  
 **Namespace:** std  
  
## Consulte também  
 [\<iterator\>](../standard-library/iterator.md)   
 [Segurança de threads na Biblioteca Padrão C\+\+](../standard-library/thread-safety-in-the-cpp-standard-library.md)   
 [Biblioteca de Modelos Padrão](../misc/standard-template-library.md)