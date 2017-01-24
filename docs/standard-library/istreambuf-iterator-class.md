---
title: "Classe istreambuf_iterator | Microsoft Docs"
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
  - "istreambuf_iterator"
  - "std.istreambuf_iterator"
  - "std::istreambuf_iterator"
  - "streambuf/std::istreambuf_iterator"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe istreambuf_iterator"
ms.assetid: 39002da2-61a6-48a5-9d0c-5df8271f6038
caps.latest.revision: 19
caps.handback.revision: 13
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Classe istreambuf_iterator
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

A classe de modelo istreambuf\_iterator descreve um objeto de iterador de entrada que extrai elementos de caractere de um buffer de fluxo de entrada, que acessa por meio de um objeto que armazena, do tipo ponteiro para `basic_streambuf`\<**CharType**, **Traits**\>.  
  
## Sintaxe  
  
```  
  
      template <   
   class CharType  
   class Traits = char_traits<CharType>  
>  
class istreambuf_iterator  
: public iterator<input_iterator_tag, CharType, typename Traits::off_type, CharType *, CharType&>  
```  
  
#### Parâmetros  
 `CharType`  
 O tipo que representa o tipo de caractere para istreambuf\_iterator.  
  
 `Traits`  
 O tipo que representa o tipo de caractere para istreambuf\_iterator.  Esse argumento é opcional e o valor padrão é `char_traits`\<*CharType\>.*  
  
## Comentários  
 A classe istreambuf\_iterator deve atender aos requisitos de um iterador de entrada.  
  
 Depois de construir ou incrementar um objeto da classe istreambuf\_iterator com um ponteiro armazenado não nulo, o objeto tenta eficientemente extrair e armazenar um objeto do tipo **CharType** do fluxo de entrada associado.  A extração pode ser atrasada, no entanto, até que o objeto seja de fato desreferenciado ou copiado.  Se a extração falhar, o objeto substitui eficientemente o ponteiro armazenado por um ponteiro nulo, criando um indicador de fim de sequência.  
  
### Construtores  
  
|||  
|-|-|  
|[istreambuf\_iterator](../Topic/istreambuf_iterator::istreambuf_iterator.md)|Constrói uma `istreambuf_iterator` que é inicializada para ler caracteres do fluxo de entrada.|  
  
### Typedefs  
  
|||  
|-|-|  
|[char\_type](../Topic/istreambuf_iterator::char_type.md)|Um tipo que é fornecido para o tipo de caractere do `ostreambuf_iterator`.|  
|[int\_type](../Topic/istreambuf_iterator::int_type.md)|Um tipo que fornece um tipo de inteiro para uma `istreambuf_iterator`.|  
|[istream\_type](../Topic/istreambuf_iterator::istream_type.md)|Um tipo que é fornecido para o tipo de fluxo da `istream_iterator`.|  
|[streambuf\_type](../Topic/istreambuf_iterator::streambuf_type.md)|Um tipo que é fornecido para o tipo de fluxo da `istreambuf_iterator`.|  
|[traits\_type](../Topic/istream_iterator::traits_type.md)|Um tipo que fornece o tipo de característica do caractere da `istream_iterator`.|  
  
### Funções membro  
  
|||  
|-|-|  
|[equal](../Topic/istreambuf_iterator::equal.md)|Testa a igualdade entre dois iteradores do buffer de fluxo de entrada.|  
  
### Operadores  
  
|||  
|-|-|  
|[operator\*](../Topic/istreambuf_iterator::operator*.md)|O operador de desreferenciamento retorna o próximo caractere no fluxo.|  
|[operator\+\+](../Topic/istreambuf_iterator::operator++.md)|Ou retorna o próximo caracteres do fluxo de entrada, ou copia o objeto antes de incrementá\-lo e retorna a cópia.|  
|[operator\-\>](../Topic/istreambuf_iterator::operator-%3E.md)|Retorna o valor de um membro, se houver.|  
  
## Requisitos  
 **Cabeçalho:** \<iterator\>  
  
 **Namespace:** std  
  
## Consulte também  
 [Struct iterator](../Topic/iterator%20Struct.md)   
 [\<iterator\>](../standard-library/iterator.md)   
 [Segurança de threads na Biblioteca Padrão C\+\+](../standard-library/thread-safety-in-the-cpp-standard-library.md)   
 [Biblioteca de Modelos Padrão](../misc/standard-template-library.md)