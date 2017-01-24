---
title: "Estrutura duration_values | Microsoft Docs"
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
  - "chrono/std::chrono::duration_values"
dev_langs: 
  - "C++"
ms.assetid: 7f66d2e3-1faf-47c3-b47e-08f2a87f20e8
caps.latest.revision: 13
caps.handback.revision: 4
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Estrutura duration_values
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Fornece valores específicos para o parâmetro `Rep`do modelo de [duração](../standard-library/duration-class.md).  
  
## Sintaxe  
  
```  
template<class Rep>  
   struct duration_values;  
```  
  
## Membros  
  
### Métodos Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[Método duration\_values::max](../Topic/duration_values::max%20Method.md)|Estático.  Especifica o limite superior para um valor de tipo `Rep`.|  
|[Método duration\_values::min](../Topic/duration_values::min%20Method.md)|Estático.  Especifica o limite inferior para um valor de tipo `Rep`.|  
|[Método duration\_values::zero](../Topic/duration_values::zero%20Method.md)|Estático.  Retorna `Rep(0)`.|  
  
## Requisitos  
 **Cabeçalho:** crono  
  
 **Namespace:** std::chrono  
  
## Consulte também  
 [Referência de arquivos de cabeçalho](../standard-library/cpp-standard-library-header-files.md)   
 [\<chrono\>](../standard-library/chrono.md)