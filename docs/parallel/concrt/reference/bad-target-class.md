---
title: "Classe bad_target | Microsoft Docs"
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
  - "concrt/concurrency::bad_target"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe bad_target"
ms.assetid: e6dcddbf-9217-4fac-ac7f-7b8b4781d2f5
caps.latest.revision: 19
caps.handback.revision: 13
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe bad_target
[!INCLUDE[vs2017banner](../../../assembler/inline/includes/vs2017banner.md)]

Essa classe descreve uma exceção lançada quando um bloco de mensagem recebe um ponteiro para um destino que não é válido para a operação que está sendo executada.  
  
## Sintaxe  
  
```  
class bad_target : public std::exception;  
```  
  
## Membros  
  
### Construtores Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[Construtor bad\_target::bad\_target](../Topic/bad_target::bad_target%20Constructor.md)|Sobrecarregado.  Constrói um objeto `bad_target`.|  
  
## Comentários  
 Esta exceção é lançada normalmente por razões como um destino que tenta consumir uma mensagem que foi reservado para um destino diferente ou liberar uma reserva que não sustente.  
  
## Hierarquia de Herança  
 `exception`  
  
 `bad_target`  
  
## Requisitos  
 **Cabeçalho:** concrt.h  
  
 **Namespace:** simultaneidade  
  
## Consulte também  
 [Namespace Concurrency](../../../parallel/concrt/reference/concurrency-namespace.md)   
 [Blocos de mensagens assíncronos](../../../parallel/concrt/asynchronous-message-blocks.md)