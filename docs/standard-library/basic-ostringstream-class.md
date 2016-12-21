---
title: "Classe basic_ostringstream | Microsoft Docs"
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
  - "basic_ostringstream"
  - "std.basic_ostringstream"
  - "sstream/std::basic_ostringstream"
  - "std::basic_ostringstream"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe basic_ostringstream"
ms.assetid: aea699f7-350f-432a-acca-adbae7b483fb
caps.latest.revision: 19
caps.handback.revision: 12
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Classe basic_ostringstream
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Descreve um objeto que controla a inserção de elementos e objetos codificados em um buffer de fluxo da classe[basic\_stringbuf](../Topic/basic_stringbuf%20Class.md)\<**ElemTr**`Alloc`\>.  
  
## Sintaxe  
  
```  
  
        template <  
   class Elem,   
   class Tr = char_traits<Elem>,   
   class Alloc = allocator<Elem>   
>  
   class basic_ostringstream : public basic_ostream<Elem, Tr>  
```  
  
#### Parâmetros  
 `Alloc`  
 A classe do alocador.  
  
 `Elem`  
 O tipo do elemento básico da cadeia de caracteres.  
  
 *TR*  
 As características de caractere especializado no elemento básico da cadeia de caracteres.  
  
## Comentários  
 A classe descreve um objeto que controla a inserção de elementos e objetos codificados em um buffer de fluxo com elementos do tipo**Elem**cujas características de caractere são determinadas pela classe**Tr**e cujos elementos são alocados por um alocador de classe`Alloc`.  O objeto armazena um objeto de classe basic\_stringbuf \<**ElemTr**`Alloc`\>.  
  
### Construtores  
  
|||  
|-|-|  
|[basic\_ostringstream](../Topic/basic_ostringstream::basic_ostringstream.md)|Constrói um objeto do tipo`basic_ostringstream`.|  
  
### DefsTipo  
  
|||  
|-|-|  
|[allocator\_type](../Topic/basic_ostringstream::allocator_type.md)|O tipo é um sinônimo para o parâmetro de modelo`Alloc`.|  
  
### Funções membro  
  
|||  
|-|-|  
|[rdbuf](../Topic/basic_ostringstream::rdbuf.md)|Retorna o endereço do buffer de fluxo armazenado do tipo`pointer`para[basic\_stringbuf](../Topic/basic_stringbuf%20Class.md)\<`Elem``Tr``Alloc`\>.|  
|[STR](../Topic/basic_ostringstream::str.md)|Define ou obtém o texto em um buffer de cadeia de caracteres sem alterar a posição de gravação.|  
  
## Requisitos  
 **Cabeçalho:**\< sstream \>  
  
 **Namespace:** std  
  
## Consulte também  
 [Segurança de threads na Biblioteca Padrão C\+\+](../standard-library/thread-safety-in-the-cpp-standard-library.md)   
 [Programação iostream](../Topic/iostream%20Programming.md)   
 [Convenções iostreams](../standard-library/iostreams-conventions.md)