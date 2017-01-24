---
title: "Estrutura is_error_code_enum | Microsoft Docs"
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
  - "future/std::is_error_code_enum"
dev_langs: 
  - "C++"
ms.assetid: 84ae4b99-66d2-41ba-9b50-645fcbe14630
caps.latest.revision: 13
caps.handback.revision: 3
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Estrutura is_error_code_enum
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Especialização que indica que [future\_errc](../Topic/future_errc%20Enumeration.md) é apropriado para armazenar [error\_code](../standard-library/error-code-class.md).  
  
## Sintaxe  
  
```  
template<>  
struct is_error_code_enum<Future_errc> : public true_type;  
```  
  
## Requisitos  
 **Cabeçalho:** futuro  
  
 std de **Namespace:**  
  
## Consulte também  
 [Referência de arquivos de cabeçalho](../standard-library/cpp-standard-library-header-files.md)   
 [\< futuro \>](../standard-library/future.md)