---
title: "&lt;sstream&gt; | Microsoft Docs"
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
  - "std.<sstream>"
  - "std::<sstream>"
  - "<sstream>"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Cabeçalho sstream"
ms.assetid: 56f55bc5-549d-4e7f-aaad-99e0ffa49c9e
caps.latest.revision: 20
caps.handback.revision: 11
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# &lt;sstream&gt;
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Define várias classes de modelo que oferecem suporte a operações de iostreams em sequências armazenadas em um objeto atribuído da matriz.  Essas sequências são convertidas facilmente a e de objetos da classe [basic\_string](../standard-library/basic-string-class.md)do modelo.  
  
## Sintaxe  
  
```  
namespace std {  
template<class CharType,  
    class Traits = char_traits<CharType>,  
    class Allocator = allocator<CharType> >  
    class basic_stringbuf;  
typedef basic_stringbuf<char> stringbuf;  
typedef basic_stringbuf<wchar_t> wstringbuf;  
  
template<class CharType,  
    class Traits = char_traits<CharType>,  
    class Allocator = allocator<CharType> >  
    class basic_istringstream;  
typedef basic_istringstream<char> istringstream;  
typedef basic_istringstream<wchar_t> wistringstream;  
  
template<class CharType,  
    class Traits = char_traits<CharType>,  
    class Allocator = allocator<CharType> >  
    class basic_ostringstream;  
typedef basic_ostringstream<char> ostringstream;  
typedef basic_ostringstream<wchar_t> wostringstream;  
  
template<class CharType,  
    class Traits = char_traits<CharType>,  
    class Allocator = allocator<CharType> >  
    class basic_stringstream;  
typedef basic_stringstream<char> stringstream;  
typedef basic_stringstream<wchar_t> wstringstream;  
  
        // TEMPLATE FUNCTIONS  
template<class CharType, class Traits, class Allocator>  
    void swap(  
        basic_stringbuf<CharType, Traits, Allocator>& _Left,  
        basic_stringbuf<CharType, Traits, Allocator>& _Right  
    );   
template<class CharType, class Traits, class Allocator>  
    void swap(  
        basic_istringstream<CharType, Traits, Allocator>& _Left,  
        basic_istringstream<CharType, Traits, Allocator>& _Right  
    );  
template<class CharType, class Traits, class Allocator>  
    void swap(  
        basic_ostringstream<CharType, Traits, Allocator>& _Left,  
        basic_ostringstream<CharType, Traits, Allocator>& _Right  
    );  
template<class CharType, class Traits, class Allocator>  
    void swap (  
        basic_stringstream<CharType, Traits, Allocator>& _Left,  
        basic_stringstream<CharType, Traits, Allocator>& _Right  
    );  
}  // namespace std  
  
```  
  
#### Parâmetros  
  
|Parâmetro|Descrição|  
|---------------|---------------|  
|`_Left`|Referência a um objeto de `sstream` .|  
|`_Right`|Referência a um objeto de `sstream` .|  
  
## Comentários  
 Os objetos do tipo `char *` podem usar a funcionalidade em [\<strstream\>](../standard-library/strstream.md) para transmitir.  No entanto, `<strstream>` é preterida e o uso de `<sstream>` é incentivado.  
  
### Typedefs  
  
|||  
|-|-|  
|[istringstream](../Topic/istringstream.md)|Cria um tipo `basic_istringstream` especializado em um parâmetro do modelo de `char` .|  
|[ostringstream](../Topic/ostringstream.md)|Cria um tipo `basic_ostringstream` especializado em um parâmetro do modelo de `char` .|  
|[stringbuf](../Topic/stringbuf.md)|Cria um tipo `basic_stringbuf` especializado em um parâmetro do modelo de `char` .|  
|[stringstream](../Topic/stringstream.md)|Cria um tipo `basic_stringstream` especializado em um parâmetro do modelo de `char` .|  
|[wistringstream](../Topic/wistringstream.md)|Cria um tipo `basic_istringstream` especializado em um parâmetro do modelo de `wchar_t` .|  
|[wostringstream](../Topic/wostringstream.md)|Cria um tipo `basic_ostringstream` especializado em um parâmetro do modelo de `wchar_t` .|  
|[wstringbuf](../Topic/wstringbuf.md)|Cria um tipo `basic_stringbuf` especializado em um parâmetro do modelo de `wchar_t` .|  
|[wstringstream](../Topic/wstringstream.md)|Cria um tipo `basic_stringstream` especializado em um parâmetro do modelo de `wchar_t` .|  
  
### Manipuladores  
  
|||  
|-|-|  
|[troca](../Topic/%3Csstream%3E%20swap.md)|Troca os valores entre dois objetos de `sstream` .|  
  
### Classes  
  
|||  
|-|-|  
|[basic\_stringbuf](../Topic/basic_stringbuf%20Class.md)|Descreve um buffer de fluxo que controla a transmissão de elementos de tipo **Elem**, cujos características de caractere são determinados pela classe **Tr**, para uma sequência de elementos armazenados em um objeto da matriz.|  
|[basic\_istringstream](../standard-library/basic-istringstream-class.md)|Descreve um objeto que extração dos controles dos elementos e de objetos codificados de um buffer de fluxo da classe [basic\_stringbuf](../Topic/basic_stringbuf%20Class.md)\<**Elem**, **Tr**, `Alloc`\>, com elementos de tipo **Elem**, cujos características de caractere são determinados pela classe **Tr**, cujos elementos são atribuídos por um alocador da classe `Alloc`.|  
|[basic\_ostringstream](../standard-library/basic-ostringstream-class.md)|Descreve um objeto que inserção do controla os elementos e objetos codificados em um buffer de fluxo da classe [basic\_stringbuf](../Topic/basic_stringbuf%20Class.md)\<**Elem**, **Tr**, `Alloc`\>, com elementos de tipo **Elem**, cujos características de caractere são determinados pela classe **Tr**, cujos elementos são atribuídos por um alocador da classe `Alloc`.|  
|[basic\_stringstream](../standard-library/basic-stringstream-class.md)|Descreve um objeto que inserção de controles e extração dos elementos e de objetos codificados usando um buffer de fluxo da classe [basic\_stringbuf](../Topic/basic_stringbuf%20Class.md)\<**Elem**, **Tr**, `Alloc`\>, com elementos de tipo **Elem**, cujos características de caractere são determinados pela classe **Tr**, cujos elementos são atribuídos por um alocador da classe `Alloc`.|  
  
## Requisitos  
  
-   sstream \<de**Cabeçalho:** \>  
  
-   **Namespace:** std  
  
## Consulte também  
 [Referência de arquivos de cabeçalho](../standard-library/cpp-standard-library-header-files.md)   
 [Segurança de threads na Biblioteca Padrão C\+\+](../standard-library/thread-safety-in-the-cpp-standard-library.md)   
 [Programação iostream](../Topic/iostream%20Programming.md)   
 [Convenções iostreams](../standard-library/iostreams-conventions.md)