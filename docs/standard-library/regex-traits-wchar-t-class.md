---
title: "&lt; wchar_t &gt; classe regex_traits | Microsoft Docs"
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
  - "std::tr1::regex_traits<wchar_t>"
  - "regex_traits<wchar_t>"
  - "std.tr1.regex_traits<wchar_t>"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "classe regex_traits < wchar_t > [TR1]"
ms.assetid: 288d6fdb-fb8e-4a4d-904a-53916be7f95b
caps.latest.revision: 17
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# &lt; wchar_t &gt; classe regex_traits
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Especialização de regex\_traits para wchar\_t.  
  
## Sintaxe  
  
```  
template <>  
    class regex_traits<wchar_t>  
```  
  
## Comentários  
 A classe é uma especialização explícita da classe de modelo [Classe regex\_traits](../standard-library/regex-traits-class.md) para elementos do tipo `wchar_t` \(de forma que ele pode tirar proveito das funções de biblioteca que manipulam objetos desse tipo\).  
  
## Requisitos  
 **Cabeçalho:** \< regex \>  
  
 **Namespace:** std  
  
## Consulte também  
 [\<regex\>](../standard-library/regex.md)   
 [Classe regex\_traits](../standard-library/regex-traits-class.md)