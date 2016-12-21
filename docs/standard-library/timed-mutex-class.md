---
title: "Classe timed_mutex | Microsoft Docs"
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
  - "mutex/std::timed_mutex"
dev_langs: 
  - "C++"
ms.assetid: cd198081-6f38-447a-9dba-e06dfbfafe59
caps.latest.revision: 9
caps.handback.revision: 3
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Classe timed_mutex
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Representa *um tipo de instância do programada mutex*.  Os objetos desse tipo são usados para impor a exclusão mútua em bloqueio tempo limitado em um programa.  
  
## Sintaxe  
  
```  
class timed_mutex;  
```  
  
## Membros  
  
### Construtores Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[Construtor timed\_mutex::timed\_mutex](../Topic/timed_mutex::timed_mutex%20Constructor.md)|Cria um objeto de `timed_mutex` que não seja bloqueado.|  
|[Destruidor timed\_mutex::~timed\_mutex](../Topic/timed_mutex::~timed_mutex%20Destructor.md)|Libera todos os recursos que são usados pelo objeto de `timed_mutex` .|  
  
### Métodos Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[Método timed\_mutex::lock](../Topic/timed_mutex::lock%20Method.md)|Bloqueia o thread de chamada até que o thread obtenha a propriedade de `mutex`.|  
|[Método timed\_mutex::try\_lock](../Topic/timed_mutex::try_lock%20Method.md)|Tentativas de obter a propriedade de `mutex` sem bloqueio.|  
|[Método timed\_mutex::try\_lock\_for](../Topic/timed_mutex::try_lock_for%20Method.md)|Tenta obter a propriedade de `mutex` para um intervalo de tempo especificado.|  
|[Método timed\_mutex::try\_lock\_until](../Topic/timed_mutex::try_lock_until%20Method.md)|Tenta obter a propriedade de `mutex` até que o tempo especificado.|  
|[Método timed\_mutex::unlock](../Topic/timed_mutex::unlock%20Method.md)|Libera a propriedade do `mutex`.|  
  
## Requisitos  
 **Cabeçalho:** mutex  
  
 std de **Namespace:**  
  
## Consulte também  
 [Referência de arquivos de cabeçalho](../standard-library/cpp-standard-library-header-files.md)   
 [\<mutex\>](../standard-library/mutex.md)