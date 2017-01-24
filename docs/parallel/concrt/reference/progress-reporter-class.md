---
title: "Classe progress_reporter | Microsoft Docs"
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
  - "ppltasks/concurrency::progress_reporter"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe progress_reporter"
ms.assetid: b836efab-2d05-4649-b6fa-d15236f1f813
caps.latest.revision: 11
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe progress_reporter
[!INCLUDE[vs2017banner](../../../assembler/inline/includes/vs2017banner.md)]

A classe de repórter de progresso permite relatar notificações de progresso de um tipo específico.  Cada objeto progress\_reporter é associado a uma ação ou a uma operação assíncrona específica.  
  
## Sintaxe  
  
```  
template<  
   typename _ProgressType  
>  
class progress_reporter;  
```  
  
#### Parâmetros  
 `_ProgressType`  
 O tipo de carga útil de cada notificação de progresso relatada pelo repórter de progresso.  
  
## Membros  
  
### Construtores Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[Construtor progress\_reporter::progress\_reporter](../Topic/progress_reporter::progress_reporter%20Constructor.md)||  
  
### Métodos Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[Método progress\_reporter::report](../Topic/progress_reporter::report%20Method.md)|Envia um relatório de andamento para a ação ou a operação assíncrona para que este repórter de progresso seja associado.|  
  
## Comentários  
 Essa tipo está disponível somente para aplicativos do Windows Store.  
  
## Hierarquia de Herança  
 `progress_reporter`  
  
## Requisitos  
 **Cabeçalho:** ppltasks.h  
  
 **Namespace:** simultaneidade  
  
## Consulte também  
 [Namespace Concurrency](../../../parallel/concrt/reference/concurrency-namespace.md)   
 [Função create\_async](../Topic/create_async%20Function.md)