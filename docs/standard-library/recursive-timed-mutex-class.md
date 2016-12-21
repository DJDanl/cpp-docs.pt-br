---
title: "Classe recursive_timed_mutex | Microsoft Docs"
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
  - "mutex/std::recursive_timed_mutex"
dev_langs: 
  - "C++"
ms.assetid: 59cc2d5c-ed80-45f3-a0a8-05652a8ead7e
caps.latest.revision: 9
caps.handback.revision: 3
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Classe recursive_timed_mutex
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Representa *um tipo de instância do programada mutex*.  Os objetos desse tipo são usados para impor a exclusão mútua usando bloqueio tempo limitado em um programa.  Diferentemente dos objetos de tipo [timed\_mutex](../standard-library/timed-mutex-class.md), o efeito dos métodos de bloqueio de chamada para objetos de `recursive_timed_mutex` é bem definido.  
  
## Sintaxe  
  
```  
class recursive_timed_mutex;  
```  
  
## Membros  
  
### Construtores Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[Construtor recursive\_timed\_mutex::recursive\_timed\_mutex](../Topic/recursive_timed_mutex::recursive_timed_mutex%20Constructor.md)|Cria um objeto de `recursive_timed_mutex` que não seja bloqueado.|  
|[Destruidor recursive\_timed\_mutex::~recursive\_timed\_mutex](../Topic/recursive_timed_mutex::~recursive_timed_mutex%20Destructor.md)|Libera todos os recursos que são usados pelo objeto de `recursive_timed_mutex` .|  
  
### Métodos Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[Método recursive\_timed\_mutex::lock](../Topic/recursive_timed_mutex::lock%20Method.md)|Bloqueia o thread de chamada até que o thread obtenha a propriedade de `mutex`.|  
|[Método recursive\_timed\_mutex::try\_lock](../Topic/recursive_timed_mutex::try_lock%20Method.md)|Tentativas de obter a propriedade de `mutex` sem bloqueio.|  
|[Método recursive\_timed\_mutex::try\_lock\_for](../Topic/recursive_timed_mutex::try_lock_for%20Method.md)|Tenta obter a propriedade de `mutex` para um intervalo de tempo especificado.|  
|[Método recursive\_timed\_mutex::try\_lock\_until](../Topic/recursive_timed_mutex::try_lock_until%20Method.md)|Tenta obter a propriedade de `mutex` até que o tempo especificado.|  
|[Método recursive\_timed\_mutex::unlock](../Topic/recursive_timed_mutex::unlock%20Method.md)|Libera a propriedade do `mutex`.|  
  
## Requisitos  
 **Cabeçalho:** mutex  
  
 std de **Namespace:**  
  
## Consulte também  
 [Referência de arquivos de cabeçalho](../standard-library/cpp-standard-library-header-files.md)   
 [\<mutex\>](../standard-library/mutex.md)