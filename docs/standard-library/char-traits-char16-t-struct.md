---
title: "Struct char_traits&lt;char16_t&gt; | Microsoft Docs"
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
  - "std::char_traits<char16_t>"
  - "std.char_traits<char16_t>"
  - "char_traits<char16_t>"
  - "string/std::char_traits<char16_t>"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe char_traits<char16_t>"
ms.assetid: 5daf3b62-dd6e-451f-b189-0350a04ff966
caps.latest.revision: 15
caps.handback.revision: 5
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Struct char_traits&lt;char16_t&gt;
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Uma estrutura que é uma especialização da estrutura **char\_traits\<CharType\>** do modelo a um elemento do tipo `char16_t`.  
  
## Sintaxe  
  
```  
template<> struct char_traits<char16_t>;  
```  
  
## Comentários  
 A especialização permite que o struct aproveitamento das funções da biblioteca que manipulam objetos do tipo `char16_t`.  
  
## Requisitos  
 **Cabeçalho:** \<cadeia de caracteres\>  
  
 **Namespace:** std  
  
## Consulte também  
 [\<string\>](../standard-library/string.md)   
 [Struct char\_traits](../standard-library/char-traits-struct.md)   
 [Segurança de threads na Biblioteca Padrão C\+\+](../standard-library/thread-safety-in-the-cpp-standard-library.md)