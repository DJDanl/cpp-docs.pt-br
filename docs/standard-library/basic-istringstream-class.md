---
title: "Classe basic_istringstream | Microsoft Docs"
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
  - "std::basic_istringstream"
  - "sstream/std::basic_istringstream"
  - "basic_istringstream"
  - "std.basic_istringstream"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe basic_istringstream"
ms.assetid: 1d5bb4b5-793d-4833-98e5-14676c451915
caps.latest.revision: 19
caps.handback.revision: 12
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Classe basic_istringstream
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Descreve um objeto que controla a extração de elementos e objetos codificados de um buffer de fluxo da classe[basic\_stringbuf](../Topic/basic_stringbuf%20Class.md)\<**ElemTr**`Alloc`\>.  
  
## Sintaxe  
  
```  
  
        template <  
   class Elem,   
   class Tr = char_traits<Elem>,   
   class Alloc = allocator<Elem>   
>  
   class basic_istringstream : public basic_istream<Elem, Tr>  
```  
  
#### Parâmetros  
 `Alloc`  
 A classe do alocador.  
  
 `Elem`  
 O tipo do elemento básico da cadeia de caracteres.  
  
 *TR*  
 As características de caractere especializado no elemento básico da cadeia de caracteres.  
  
## Comentários  
 A classe de modelo descreve um objeto que controla a extração de elementos e objetos codificados de um buffer de fluxo da classe[basic\_stringbuf](../Topic/basic_stringbuf%20Class.md)\<**ElemTr**`Alloc`\>, com elementos do tipo**Elem**cujas características de caractere são determinadas pela classe**Tr**e cujos elementos são alocados por um alocador de classe`Alloc`.  O objeto armazena um objeto de classe basic\_stringbuf \<**ElemTr**`Alloc`\>.  
  
### Construtores  
  
|||  
|-|-|  
|[basic\_istringstream](../Topic/basic_istringstream::basic_istringstream.md)|Constrói um objeto do tipo`basic_istringstream`.|  
  
### DefsTipo  
  
|||  
|-|-|  
|[allocator\_type](../Topic/basic_istringstream::allocator_type.md)|O tipo é um sinônimo para o parâmetro de modelo`Alloc`.|  
  
### Funções membro  
  
|||  
|-|-|  
|[rdbuf](../Topic/basic_istringstream::rdbuf.md)|Retorna o endereço do buffer de fluxo armazenado do tipo`pointer`para[basic\_stringbuf](../Topic/basic_stringbuf%20Class.md)\<`Elem``Tr``Alloc`\>.|  
|[STR](../Topic/basic_istringstream::str.md)|Define ou obtém o texto em um buffer de cadeia de caracteres sem alterar a posição de gravação.|  
|[swap](../Topic/basic_istringstream::swap.md)|Troca os valores nessa`basic_istringstream`objeto para aqueles do objeto fornecido.|  
  
### Operadores  
  
|||  
|-|-|  
|[operator\=](../Topic/basic_istringstream::operator=.md)|Atribui os valores a esta`basic_istringstream`objeto do parâmetro de objeto.|  
  
## Requisitos  
 **Cabeçalho:**\< sstream \>  
  
 **Namespace:** std  
  
## Consulte também  
 [Segurança de threads na Biblioteca Padrão C\+\+](../standard-library/thread-safety-in-the-cpp-standard-library.md)   
 [Programação iostream](../Topic/iostream%20Programming.md)   
 [Convenções iostreams](../standard-library/iostreams-conventions.md)