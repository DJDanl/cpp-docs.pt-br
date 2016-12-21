---
title: "Struct char_traits&lt;wchar_t&gt; | Microsoft Docs"
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
  - "std.char_traits<wchar_t>"
  - "char_traits<wchar_t>"
  - "string/std::char_traits<wchar_t>"
  - "std::char_traits<wchar_t>"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe char_traits<wchar_t>"
ms.assetid: 31f34072-04d6-4871-88fe-48e17d473484
caps.latest.revision: 21
caps.handback.revision: 11
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Struct char_traits&lt;wchar_t&gt;
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Uma classe que é uma especialização da estrutura **char\_traits\<CharType\>** do modelo a um elemento do tipo `wchar_t`.  
  
## Sintaxe  
  
```  
template<> struct char_traits<wchar_t>;  
```  
  
## Comentários  
 A especialização permite que o struct aproveitamento das funções da biblioteca que manipulam objetos desse tipo `wchar_t`.  
  
## Requisitos  
 **Cabeçalho:** \<cadeia de caracteres\>  
  
 **Namespace:** std  
  
## Consulte também  
 [Struct char\_traits](../standard-library/char-traits-struct.md)   
 [Segurança de threads na Biblioteca Padrão C\+\+](../standard-library/thread-safety-in-the-cpp-standard-library.md)