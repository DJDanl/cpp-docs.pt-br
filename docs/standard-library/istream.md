---
title: "&lt; istream &gt; | Microsoft Docs"
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
  - "istream/std::<istream>"
  - "std.<istream>"
  - "<istream>"
  - "std::<istream>"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Cabeçalho istream"
ms.assetid: efcf24e4-05d1-4719-ab0b-9e7ebe845d89
caps.latest.revision: 20
caps.handback.revision: 9
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# &lt; istream &gt;
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Define o modelo classe basic\_istream, que atua como mediador extrações para o iostreams, e o modelo classe basic\_iostream, que atua como mediador extrações e inserções. O cabeçalho também define um manipulador relacionado. Esse arquivo de cabeçalho é normalmente incluído para você por outro cabeçalho iostreams; Você raramente precisará incluí\-lo diretamente.  
  
## Sintaxe  
  
```  
  
#include <istream>  
  
```  
  
### Typedefs  
  
|||  
|-|-|  
|[iostream](../Topic/iostream.md)|Um tipo `basic_iostream` especializadas em `char`.|  
|[istream](../Topic/istream.md)|Um tipo `basic_istream` especializadas em `char`.|  
|[wiostream](../Topic/wiostream.md)|Um tipo `basic_iostream` especializadas em **wchar**.|  
|[wistream](../Topic/wistream.md)|Um tipo `basic_istream` especializadas em **wchar**.|  
  
### Manipuladores  
  
|||  
|-|-|  
|[ws](../Topic/ws.md)|Ignora o espaço em branco no fluxo.|  
|[swap](../Topic/%3Cistream%3E%20swap.md)|Troca dois objetos de fluxo.|  
  
### Operadores  
  
|||  
|-|-|  
|[Operador \>\>](../Topic/operator%3E%3E%20\(%3Cistream%3E\).md)|Extrai cadeias de caracteres e caracteres do fluxo.|  
  
### Classes  
  
|||  
|-|-|  
|[basic\_iostream](../standard-library/basic-iostream-class.md)|Uma classe de fluxo que pode fazer ambos de entrada e saída.|  
|[basic\_istream](../Topic/basic_istream%20Class.md)|A classe de modelo descreve um objeto que controla a extração de elementos e objetos codificados de um buffer de fluxo com elementos do tipo **Elem**, também conhecido como [char\_type](../Topic/basic_ios::char_type.md), cujas características de caractere são determinadas pela classe **Tr**, também conhecido como [traits\_type](../Topic/basic_ios::traits_type.md).|  
  
## Consulte também  
 [Segurança de threads na Biblioteca Padrão C\+\+](../standard-library/thread-safety-in-the-cpp-standard-library.md)   
 [Programação iostream](../Topic/iostream%20Programming.md)   
 [Convenções iostreams](../standard-library/iostreams-conventions.md)