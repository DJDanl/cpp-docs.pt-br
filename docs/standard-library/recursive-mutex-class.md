---
title: "Classe recursive_mutex | Microsoft Docs"
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
  - "mutex/std::recursive_mutex"
dev_langs: 
  - "C++"
ms.assetid: eb5ffd1b-7e78-4559-8391-bb220ead42fc
caps.latest.revision: 9
caps.handback.revision: 3
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Classe recursive_mutex
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Representa um *tipo mutex*.  Em contraste com [mutex](../standard-library/mutex-class-stl.md), o comportamento das chamadas para bloquear métodos para os objetos que estão bloqueados já é bem definido.  
  
## Sintaxe  
  
```  
class recursive_mutex;  
```  
  
## Membros  
  
### Construtores Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[Construtor recursive\_mutex::recursive\_mutex](../Topic/recursive_mutex::recursive_mutex%20Constructor.md)|Constrói um objeto `recursive_mutex`.|  
|[Destruidor recursive\_mutex::~recursive\_mutex](../Topic/recursive_mutex::~recursive_mutex%20Destructor.md)|Libera todos os recursos que são usados pelo objeto de `recursive_mutex` .|  
  
### Métodos Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[Método recursive\_mutex::lock](../Topic/recursive_mutex::lock%20Method.md)|Bloqueia o thread de chamada até que o thread obtenha a propriedade do mutex.|  
|[Método recursive\_mutex::try\_lock](../Topic/recursive_mutex::try_lock%20Method.md)|Tenta obter a propriedade do mutex sem bloqueio.|  
|[Método recursive\_mutex::unlock](../Topic/recursive_mutex::unlock%20Method.md)|Libera a propriedade do mutex.|  
  
## Requisitos  
 **Cabeçalho:** mutex  
  
 std de **Namespace:**  
  
## Consulte também  
 [Referência de arquivos de cabeçalho](../standard-library/cpp-standard-library-header-files.md)   
 [\<mutex\>](../standard-library/mutex.md)