---
title: "Classe cancellation_token_registration | Microsoft Docs"
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
  - "pplcancellation_token/concurrency::cancellation_token_registration"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe cancellation_token_registration"
ms.assetid: 823d63f4-7233-4d65-8976-6152ccf12d0e
caps.latest.revision: 9
caps.handback.revision: 3
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe cancellation_token_registration
[!INCLUDE[vs2017banner](../../../assembler/inline/includes/vs2017banner.md)]

A classe de `cancellation_token_registration` representa uma notificação de retorno de chamada de `cancellation_token`.  Quando o método de `register` em um `cancellation_token` é usado para receber a notificação quando o cancelamento ocorre, um objeto de `cancellation_token_registration` é retornado como um manipulador ao retorno de chamada para que o chamador possa solicitar que um retorno de chamada específica não seja mais feito usando o método de `deregister`.  
  
## Sintaxe  
  
```  
class cancellation_token_registration;  
```  
  
## Membros  
  
### Construtores Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[Construtor cancellation\_token\_registration::cancellation\_token\_registration](../Topic/cancellation_token_registration::cancellation_token_registration%20Constructor.md)||  
|[Destruidor cancellation\_token\_registration::~cancellation\_token\_registration](../Topic/cancellation_token_registration::~cancellation_token_registration%20Destructor.md)||  
  
### Operadores Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[Operador cancellation\_token\_registration::operator\!\=](../Topic/cancellation_token_registration::operator!=%20Operator.md)||  
|[Operador cancellation\_token\_registration::operator\=](../Topic/cancellation_token_registration::operator=%20Operator.md)||  
|[Operador cancellation\_token\_registration::operator\=\=](../Topic/cancellation_token_registration::operator==%20Operator.md)||  
  
## Hierarquia de Herança  
 `cancellation_token_registration`  
  
## Requisitos  
 **Cabeçalho:** pplcancellation\_token.h  
  
 **Namespace:** simultaneidade  
  
## Consulte também  
 [Namespace Concurrency](../../../parallel/concrt/reference/concurrency-namespace.md)