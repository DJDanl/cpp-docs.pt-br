---
title: "Classe critical_section | Microsoft Docs"
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
  - "concrt/concurrency::critical_section"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe critical_section"
ms.assetid: fa3c89d6-be5d-4d1b-bddb-8232814e6cf6
caps.latest.revision: 23
caps.handback.revision: 15
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe critical_section
[!INCLUDE[vs2017banner](../../../assembler/inline/includes/vs2017banner.md)]

Um mutex não reentrante que seja explicitamente ciente de tempo de execução de simultaneidade.  
  
## Sintaxe  
  
```  
class critical_section;  
```  
  
## Membros  
  
### Typedefs Públicas  
  
|Nome|Descrição|  
|----------|---------------|  
|`native_handle_type`|Uma referência a um objeto de `critical_section` .|  
  
### Classe Públicas  
  
|Nome|Descrição|  
|----------|---------------|  
|[Classe critical\_section::scoped\_lock](../Topic/critical_section::scoped_lock%20Class.md)|Um wrapper seguro de exceção RAII para um objeto de `critical_section` .|  
  
### Construtores Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[Construtor critical\_section::critical\_section](../Topic/critical_section::critical_section%20Constructor.md)|Constrói uma nova seção crítica.|  
|[Destruidor critical\_section::~critical\_section](../Topic/critical_section::~critical_section%20Destructor.md)|Destrói uma seção crítica.|  
  
### Métodos Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[Método critical\_section::lock](../Topic/critical_section::lock%20Method.md)|Adquire esta seção crítica.|  
|[Método critical\_section::native\_handle](../Topic/critical_section::native_handle%20Method.md)|Retorna um identificador nativo específica de plataforma, se houver.|  
|[Método critical\_section::try\_lock](../Topic/critical_section::try_lock%20Method.md)|Tenta adquirir o bloqueio sem bloqueio.|  
|[Método critical\_section::try\_lock\_for](../Topic/critical_section::try_lock_for%20Method.md)|Tenta adquirir o bloqueio sem bloqueio para um número específico de milissegundos.|  
|[Método critical\_section::unlock](../Topic/critical_section::unlock%20Method.md)|Desbloqueia a seção crítica.|  
  
## Comentários  
 Para obter mais informações, consulte [Estruturas de dados de sincronização](../Topic/Synchronization%20Data%20Structures.md).  
  
## Hierarquia de Herança  
 `critical_section`  
  
## Requisitos  
 **Cabeçalho:** concrt.h  
  
 **Namespace:** simultaneidade  
  
## Consulte também  
 [Namespace Concurrency](../../../parallel/concrt/reference/concurrency-namespace.md)   
 [Classe reader\_writer\_lock](../Topic/reader_writer_lock%20Class.md)