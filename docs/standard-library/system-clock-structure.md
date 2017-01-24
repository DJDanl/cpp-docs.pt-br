---
title: "Estrutura system_clock | Microsoft Docs"
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
  - "chrono/std::chrono::system_clock"
dev_langs: 
  - "C++"
ms.assetid: a97bd46e-267a-4836-9f7d-af1f664e99ae
caps.latest.revision: 14
caps.handback.revision: 5
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Estrutura system_clock
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Representa uma *tipo de relógio* que se baseia no relógio do sistema em tempo real.  
  
## Sintaxe  
  
```  
struct system_clock;  
```  
  
## Comentários  
 Um *tipo de relógio* é usada para obter a hora atual como UTC.  O tipo incorpora uma instanciação de [duração](../standard-library/duration-class.md) e o modelo de classe [time\_point](../standard-library/time-point-class.md), e define uma função de membro estático `now()` que retorna a hora.  
  
 É um relógio *monotônico* se o valor retornado por uma chamada primeira para `now()` é sempre menor ou igual ao valor retornado por uma chamada subsequente para `now()`.  
  
 É um relógio *estável* se for *monotônico* e se o tempo entre tiques do relógio é constante.  
  
 Nessa implementação, um `system_clock` é sinônimo de um `high_resolution_clock`.  
  
## Membros  
  
### Typedefs públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|`system_clock::duration`|Um sinônimo para `duration<rep, period>`.|  
|`system_clock::period`|Um sinônimo para o tipo que é usado para representar o período de escala a instanciação independente de `duration`.|  
|`system_clock::rep`|Um sinônimo para o tipo que é usado para representar o número de tiques do relógio na instanciação independente de `duration`.|  
|`system_clock::time_point`|Um sinônimo para `time_point<Clock, duration>`, onde `Clock` é um sinônimo para o próprio tipo de relógio ou outro tipo de relógio que se baseia a mesma época e o mesmo aninhadas `duration` tipo.|  
  
### Métodos Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[Método system\_clock::from\_time\_t](../Topic/system_clock::from_time_t%20Method.md)|Estático.  Retorna um `time_point` que mais se aproxima de um tempo especificado.|  
|[Método system\_clock::now](../Topic/system_clock::now%20Method.md)|Estático.  Retorna a hora atual.|  
|[Método system\_clock::to\_time\_t](../Topic/system_clock::to_time_t%20Method.md)|Estático.  Retorna um `time_t` que mais se aproxima de um objeto `time_point`.|  
  
### Constantes públicas  
  
|Nome|Descrição|  
|----------|---------------|  
|[Constante system\_clock::is\_monotonic](../Topic/system_clock::is_monotonic%20Constant.md)|Especifica se o tipo de relógio monotônico.|  
|[Constante system\_clock::is\_steady](../Topic/system_clock::is_steady%20Constant.md)|Especifica se o tipo de relógio é constante.|  
  
## Requisitos  
 **Cabeçalho:** chrono  
  
 **Namespace:** std::chrono  
  
## Consulte também  
 [Referência de arquivos de cabeçalho](../standard-library/cpp-standard-library-header-files.md)   
 [\<chrono\>](../standard-library/chrono.md)   
 [Struct steady\_clock](../Topic/steady_clock%20struct.md)