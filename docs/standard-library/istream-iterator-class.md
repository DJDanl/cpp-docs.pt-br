---
title: "Classe istream_iterator | Microsoft Docs"
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
  - "iterator/std::istream_iterator"
  - "std.istream_iterator"
  - "std::istream_iterator"
  - "istream_iterator"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe istream_iterator"
ms.assetid: fb52a8cd-7f71-48d1-b73e-4b064e2a8d16
caps.latest.revision: 18
caps.handback.revision: 12
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Classe istream_iterator
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Descreve um objeto de iterador de entrada.  Extrai objetos da classe `Type` de um fluxo de entrada, que acessa por meio de um objeto que armazena, do tipo `pointer` para `basic_istream`\<`CharType`, `Traits`\>.  
  
## Sintaxe  
  
```  
template<class Type,  
    class CharType = char,  
    class Traits = char_traits<CharType>,  
    class Distance = ptrdiff_t,  
> class istream_iterator  
 : public iterator<  
        input_iterator_tag,  
        Type,   
        Distance,   
        const Type *,  
        const Type&  
    >;  
```  
  
#### Parâmetros  
 `Type`  
 O tipo de objeto a ser extraído do fluxo de entrada.  
  
 `CharType`  
 O tipo que representa o tipo de caractere para `istream_iterator`.  Esse argumento é opcional e o valor padrão é `char`.  
  
 `Traits`  
 O tipo que representa o tipo de caractere para `istream_iterator`.  Esse argumento é opcional e o valor padrão é `char_traits`\<`CharType`\>.  
  
 `Distance`  
 Um tipo integral com sinal que representa o tipo de diferença para `istream_iterator`.  Esse argumento é opcional e o valor padrão é `ptrdiff_t`.  
  
 Depois de construir ou incrementar um objeto da classe istream\_iterator com um ponteiro armazenado não nulo, o objeto tenta extrair e armazenar um objeto do tipo `Type` do fluxo de entrada associado.  Se a extração falhar, o objeto substitui eficientemente o ponteiro armazenado por um ponteiro nulo, criando um indicador de fim de sequência.  
  
### Construtores  
  
|||  
|-|-|  
|[istream\_iterator](../Topic/istream_iterator::istream_iterator.md)|Constrói um iterador de fim de fluxo como o `istream_iterator` padrão ou um `istream_iterator` inicializado para o tipo de fluxo do iterador do qual ele lê.|  
  
### Typedefs  
  
|||  
|-|-|  
|[char\_type](../Topic/istream_iterator::char_type.md)|Um tipo que é fornecido para o tipo de caractere do `istream_iterator`.|  
|[istream\_type](../Topic/istream_iterator::istream_type.md)|Um tipo que é fornecido para o tipo de fluxo da `istream_iterator`.|  
|[traits\_type](../Topic/istream_iterator::traits_type.md)|Um tipo que fornece o tipo de característica do caractere da `istream_iterator`.|  
  
### Operadores  
  
|||  
|-|-|  
|[operator\*](../Topic/istream_iterator::operator*.md)|O operador de desreferenciamento retorna o objeto armazenado do tipo `Type` tratado por `istream_iterator`.|  
|[operator\-\>](../Topic/istream_iterator::operator-%3E.md)|Retorna o valor de um membro, se houver.|  
|[operator\+\+](../Topic/istream_iterator::operator++.md)|Ou extrai um objeto incrementado do fluxo de entrada, ou copia o objeto antes de incrementá\-lo e retorna a cópia.|  
  
## Requisitos  
 **Cabeçalho:** \<iterator\>  
  
 **Namespace:** std  
  
## Consulte também  
 [Struct input\_iterator\_tag](../standard-library/input-iterator-tag-struct.md)   
 [Struct iterator](../Topic/iterator%20Struct.md)   
 [\<iterator\>](../standard-library/iterator.md)   
 [Segurança de threads na Biblioteca Padrão C\+\+](../standard-library/thread-safety-in-the-cpp-standard-library.md)   
 [Biblioteca de Modelos Padrão](../misc/standard-template-library.md)