---
title: "Classe regex_error | Microsoft Docs"
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
  - "std::tr1::regex_error"
  - "regex_error"
  - "std.tr1.regex_error"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe regex_error [TR1]"
ms.assetid: 3333a1a3-ca6f-4612-84b2-1b4c7e3db5a4
caps.latest.revision: 19
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Classe regex_error
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Relatórios de um objeto de basic\_regex incorreta.  
  
## Sintaxe  
  
```  
class regex_error  
    : public std::runtime_error {  
public:  
    explicit regex_error(regex_constants::error_code error);  
    regex_constants::error_code code() const;  
    };  
```  
  
## Comentários  
 A classe descreve um objeto de exceção gerado para relatar um erro na construção ou uso de um `basic_regex` objeto.  
  
## Requisitos  
 **Cabeçalho:** \< regex \>  
  
 **Namespace:** std  
  
## Consulte também  
 [\<regex\>](../standard-library/regex.md)   
 [regex\_error](../standard-library/regex-error-class.md)