---
title: "Classe unique_lock | Microsoft Docs"
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
  - "mutex/std::unique_lock"
dev_langs: 
  - "C++"
ms.assetid: f4ed8ba9-c8af-446f-8ef0-0b356bad14bd
caps.latest.revision: 10
caps.handback.revision: 4
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Classe unique_lock
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Representa um modelo que possa ser criado uma instância do para criar os objetos que gerenciam o bloquear e desbloquear de `mutex`.  
  
## Sintaxe  
  
```  
template<class Mutex>  
class unique_lock;  
```  
  
## Comentários  
 O argumento `Mutex` do modelo deve nomear *um tipo de mutex*.  
  
 Internamente, `unique_lock` armazena um ponteiro para um objeto de `mutex` e associado a um `bool` que indica se o thread atual possuir `mutex`.  
  
## Membros  
  
### Typedefs Públicas  
  
|Nome|Descrição|  
|----------|---------------|  
|`unique_lock::mutex_type`|Sinônimo para o argumento `Mutex`do modelo.|  
  
### Construtores Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[Construtor unique\_lock::unique\_lock](../Topic/unique_lock::unique_lock%20Constructor.md)|Constrói um objeto `unique_lock`.|  
|[Destruidor unique\_lock::~unique\_lock](../Topic/unique_lock::~unique_lock%20Destructor.md)|Libera todos os recursos associados ao objeto de `unique_lock` .|  
  
### Métodos Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[Método unique\_lock::lock](../Topic/unique_lock::lock%20Method.md)|Bloqueia o thread de chamada até que o thread obtenha a propriedade de `mutex`associado.|  
|[Método unique\_lock::mutex](../Topic/unique_lock::mutex%20Method.md)|Recupera o ponteiro armazenado a `mutex`associado.|  
|[Método unique\_lock::owns\_lock](../Topic/unique_lock::owns_lock%20Method.md)|Especifica se o thread de chamada possui `mutex`associado.|  
|[Método unique\_lock::release](../Topic/unique_lock::release%20Method.md)|Desassocia o objeto de `unique_lock` de objeto associado de `mutex` .|  
|[Método unique\_lock::swap](../Topic/unique_lock::swap%20Method.md)|Alterna `mutex` e o status associados da propriedade com a de um objeto especificado.|  
|[Método unique\_lock::try\_lock](../Topic/unique_lock::try_lock%20Method.md)|Tenta obter a propriedade de `mutex` associado sem bloqueio.|  
|[Método unique\_lock::try\_lock\_for](../Topic/unique_lock::try_lock_for%20Method.md)|Tenta obter a propriedade de `mutex` associado sem bloqueio.|  
|[Método unique\_lock::try\_lock\_until](../Topic/unique_lock::try_lock_until%20Method.md)|Tenta obter a propriedade de `mutex` associado sem bloqueio.|  
|[Método unique\_lock::unlock](../Topic/unique_lock::unlock%20Method.md)|Libera a propriedade de `mutex`associado.|  
  
### Operadores Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[Operador booliano unique\_lock::operator](../Topic/unique_lock::operator%20bool%20Operator.md)|Especifica se o thread de chamada tem a propriedade de `mutex`associado.|  
|[Operador unique\_lock::operator\=](../Topic/unique_lock::operator=%20Operator.md)|Copia o ponteiro armazenado de `mutex` e o status associado de propriedade de um objeto especificado.|  
  
## Hierarquia de Herança  
 `unique_lock`  
  
## Requisitos  
 **Cabeçalho:** mutex  
  
 std de **Namespace:**  
  
## Consulte também  
 [Referência de arquivos de cabeçalho](../standard-library/cpp-standard-library-header-files.md)   
 [\<mutex\>](../standard-library/mutex.md)