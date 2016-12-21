---
title: "Classe mutex (STL) | Microsoft Docs"
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
  - "mutex/std::mutex"
dev_langs: 
  - "C++"
ms.assetid: 7999d055-f74f-4303-810f-8d3c9cde2f69
caps.latest.revision: 11
caps.handback.revision: 5
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Classe mutex (STL)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Representa um *tipo mutex*.  Os objetos desse tipo podem ser usados para aplicar a exclusão mútua em um programa.  
  
## Sintaxe  
  
```  
class mutex;  
```  
  
## Membros  
  
### Construtores Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[Construtor mutex::mutex \(STL\)](../Topic/mutex::mutex%20Constructor%20\(STL\).md)|Constrói um objeto `mutex`.|  
|[Destruidor mutex::~mutex \(STL\)](../Topic/mutex::~mutex%20Destructor%20\(STL\).md)|Libera todos os recursos que foram usados pelo objeto `mutex`.|  
  
### Métodos Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[Método mutex::lock \(STL\)](../Topic/mutex::lock%20Method%20\(STL\).md)|Bloqueia o thread de chamada até que o thread obtenha a propriedade de `mutex`.|  
|[mutex::native\_handle \- método \(STL\)](../Topic/mutex::native_handle%20Method%20\(STL\).md)|Retorna o tipo específico da implementação que representa o identificador mutex.|  
|[Método mutex::try\_lock \(STL\)](../Topic/mutex::try_lock%20Method%20\(STL\).md)|Tentativas de obter a propriedade de `mutex` sem bloqueio.|  
|[Método mutex::unlock \(STL\)](../Topic/mutex::unlock%20Method%20\(STL\).md)|Libera a propriedade do `mutex`.|  
  
## Requisitos  
 **Cabeçalho:** mutex  
  
 std de **Namespace:**  
  
## Consulte também  
 [Referência de arquivos de cabeçalho](../standard-library/cpp-standard-library-header-files.md)   
 [\<mutex\>](../standard-library/mutex.md)