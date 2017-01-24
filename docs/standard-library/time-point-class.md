---
title: "Classe time_point | Microsoft Docs"
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
  - "chrono/std::chrono::time_point"
dev_langs: 
  - "C++"
ms.assetid: 18be1e52-57b9-489a-8a9b-f58894f0aaad
caps.latest.revision: 10
caps.handback.revision: 4
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Classe time_point
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Uma `time_point` descreve um tipo que representa um ponto no tempo.  Contém um objeto do tipo [duração](../standard-library/duration-class.md) que armazena o tempo decorrido desde a época que é representada pelo argumento `Clock` do modelo.  
  
## Sintaxe  
  
```  
template<  
   class Clock,  
   class Duration = typename Clock::duration  
>  
class time_point;  
```  
  
## Membros  
  
### Typedefs Públicas  
  
|Nome|Descrição|  
|----------|---------------|  
|`time_point::clock`|Sinônimo para o parâmetro de modelo `Clock`.|  
|`time_point::duration`|Sinônimo para o parâmetro de modelo `Duration`.|  
|`time_point::period`|Sinônimo para o nome do tipo aninhado `duration::period`.|  
|`time_point::rep`|Sinônimo para o nome do tipo aninhado `duration::rep`.|  
  
### Construtores Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[Construtor time\_point::time\_point](../Topic/time_point::time_point%20Constructor.md)|Constrói um objeto `time_point`.|  
  
### Métodos Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[Método time\_point::max](../Topic/time_point::max%20Method.md)|Especifica o limite superior para `time_point::ref`.|  
|[Método time\_point::min](../Topic/time_point::min%20Method.md)|Especificar o limite inferior para `time_point::ref`.|  
|[Método time\_point::time\_since\_epoch](../Topic/time_point::time_since_epoch%20Method.md)|Retorna o valor armazenado `duration`.|  
  
### Operadores Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[Operador time\_point::operator\+\=](../Topic/time_point::operator+=%20Operator.md)|Adiciona um valor especificado à duração armazenada.|  
|[Operador time\_point::operator\-\=](../Topic/time_point::operator-=%20Operator.md)|Subtrai um valor especificado da duração armazenada.|  
  
## Requisitos  
 **Cabeçalho:** crono  
  
 **Namespace:** std::chrono  
  
## Consulte também  
 [Referência de arquivos de cabeçalho](../standard-library/cpp-standard-library-header-files.md)   
 [\<chrono\>](../standard-library/chrono.md)