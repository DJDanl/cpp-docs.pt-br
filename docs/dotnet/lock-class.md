---
title: "Classe lock | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "reference"
f1_keywords: 
  - "msclr::lock"
  - "msclr.lock"
  - "lock"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "classe lock"
ms.assetid: 5123edd9-6aed-497d-9a0b-f4b6d6c0d666
caps.latest.revision: 10
caps.handback.revision: 10
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe lock
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Essa classe automatiza a realização de um bloqueio para sincronizar o acesso a um objeto de vários threads.  Quando criado ele adquire o bloqueio e quando destruído libera o bloqueio.  
  
## Sintaxe  
  
```  
ref class lock;  
```  
  
## Comentários  
 `lock` estão disponíveis apenas para objetos CLR e pode ser usado somente no código do CLR.  
  
 Internamente, a classe de bloqueio usa <xref:System.Threading.Monitor> para sincronizar o acesso.  Consulte este tópico para obter informações mais detalhadas sobre a sincronização.  
  
## Requisitos  
 msclr \<de**Arquivo de cabeçalho** \\ lock.h\>  
  
 msclr de**Namespace**  
  
## Consulte também  
 [bloqueio](../dotnet/lock.md)   
 [Membros de bloqueio](../dotnet/lock-members.md)