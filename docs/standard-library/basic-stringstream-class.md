---
title: "Classe basic_stringstream | Microsoft Docs"
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
  - "std.basic_stringstream"
  - "basic_stringstream"
  - "std::basic_stringstream"
  - "sstream/std::basic_stringstream"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe basic_stringstream"
ms.assetid: 49629814-ca37-45c5-931b-4ff894e6ebd2
caps.latest.revision: 19
caps.handback.revision: 12
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Classe basic_stringstream
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Descreve um objeto que controla a inserção e extração de elementos e objetos codificados usando um buffer de fluxo da classe[basic\_stringbuf](../Topic/basic_stringbuf%20Class.md)\<**ElemTr**`Alloc`\>.  
  
## Sintaxe  
  
```  
  
        template <  
   class Elem,   
   class Tr = char_traits<Elem>,   
   class Alloc = allocator<Elem>   
>  
   class basic_stringstream : public basic_iostream<Elem, Tr>  
```  
  
#### Parâmetros  
 `Alloc`  
 A classe do alocador.  
  
 `Elem`  
 O tipo do elemento básico da cadeia de caracteres.  
  
 *TR*  
 As características de caractere especializado no elemento básico da cadeia de caracteres.  
  
## Comentários  
 A classe de modelo descreve um objeto que controla a inserção e extração de elementos e objetos codificados usando um buffer de fluxo da classe[basic\_stringbuf](../Topic/basic_stringbuf%20Class.md)\<**ElemTr**`Alloc`\>, com elementos do tipo**Elem**cujas características de caractere são determinadas pela classe**Tr**e cujos elementos são alocados por um alocador de classe`Alloc`.  O objeto armazena um objeto de classe basic\_stringbuf \<**ElemTr**`Alloc`\>.  
  
### Construtores  
  
|||  
|-|-|  
|[basic\_stringstream](../Topic/basic_stringstream::basic_stringstream.md)|Constrói um objeto do tipo`basic_stringstream`.|  
  
### DefsTipo  
  
|||  
|-|-|  
|[allocator\_type](../Topic/basic_stringstream::allocator_type.md)|O tipo é um sinônimo para o parâmetro de modelo`Alloc`.|  
  
### Funções membro  
  
|||  
|-|-|  
|[rdbuf](../Topic/basic_stringstream::rdbuf.md)|Retorna o endereço do buffer de fluxo armazenado do tipo`pointer`para[basic\_stringbuf](../Topic/basic_stringbuf%20Class.md)\<`Elem``Tr``Alloc`\>.|  
|[STR](../Topic/basic_stringstream::str.md)|Define ou obtém o texto em um buffer de cadeia de caracteres sem alterar a posição de gravação.|  
  
## Requisitos  
 **Cabeçalho:**\< sstream \>  
  
 **Namespace:** std  
  
## Consulte também  
 [Segurança de threads na Biblioteca Padrão C\+\+](../standard-library/thread-safety-in-the-cpp-standard-library.md)   
 [Programação iostream](../Topic/iostream%20Programming.md)   
 [Convenções iostreams](../standard-library/iostreams-conventions.md)