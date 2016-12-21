---
title: "Struct char_traits&lt;char32_t&gt; | Microsoft Docs"
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
  - "string/std::char_traits<char_32t>"
  - "char_traits<char32_t>"
  - "std.char_traits<char_32t>"
  - "std::char_traits<char_32t>"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe char_traits<char32_t>"
ms.assetid: c0315466-45d0-4a99-b83e-3b1dbfbfbbc3
caps.latest.revision: 14
caps.handback.revision: 4
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Struct char_traits&lt;char32_t&gt;
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Uma estrutura que é uma especialização da estrutura **char\_traits\<CharType\>** do modelo a um elemento do tipo `char32_t`.  
  
## Sintaxe  
  
```  
template<> struct char_traits<char32_t>;  
```  
  
## Comentários  
 A especialização permite que o struct aproveitamento das funções da biblioteca que manipulam objetos desse tipo `char32_t`.  
  
## Requisitos  
 **Cabeçalho:** \<cadeia de caracteres\>  
  
 **Namespace:** std  
  
## Consulte também  
 [\<string\>](../standard-library/string.md)   
 [Struct char\_traits](../standard-library/char-traits-struct.md)