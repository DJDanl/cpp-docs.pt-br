---
title: "Classe de CMultiLock | Microsoft Docs"
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
  - "CMultiLock"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CMultiLock"
  - "objetos de sincronização, controle de acesso"
ms.assetid: c5b7c78b-1f81-4387-b7dd-2c813c5b6b61
caps.latest.revision: 20
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CMultiLock
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Representa o mecanismo de controle de acesso usado no acesso aos recursos de controle em um programa com vários segmentos.  
  
## Sintaxe  
  
```  
class CMultiLock  
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CMultiLock::CMultiLock](../Topic/CMultiLock::CMultiLock.md)|Constrói um objeto de `CMultiLock` .|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CMultiLock::IsLocked](../Topic/CMultiLock::IsLocked.md)|Determina se um determinado objeto de sincronização na matriz é bloqueado.|  
|[CMultiLock::Lock](../Topic/CMultiLock::Lock.md)|Pára na matriz de objetos de sincronização.|  
|[CMultiLock::Unlock](../Topic/CMultiLock::Unlock.md)|Libera quaisquer objetos pertencentes a sincronização.|  
  
## Comentários  
 `CMultiLock` não tem uma classe base.  
  
 Para usar as classes [CSemaphore](../../mfc/reference/csemaphore-class.md)de sincronização, [CMutex](../../mfc/reference/cmutex-class.md), e [CEvent](../../mfc/reference/cevent-class.md), você pode criar **CMultiLock** ou objeto de [CSingleLock](../../mfc/reference/csinglelock-class.md) para esperar sobre e liberar o objeto de sincronização.  Use **CMultiLock** quando há vários objetos que você pode usar em um horário específico.  Use `CSingleLock` quando você só precisará esperar em um objeto de cada vez.  
  
 Para usar um objeto de **CMultiLock** , primeiro crie uma matriz de objetos de sincronização que você deseja aguardar em.  Em seguida, chama o construtor do objeto de **CMultiLock** dentro de uma função de membro na classe do recurso controlado.  Chame a função de membro de [Bloquear](../Topic/CMultiLock::Lock.md) para determinar se um recurso está disponível \(signaled.\)  Se um for, continue com o restante da função de membro.  Se nenhum recurso está disponível, espere um período de tempo especificado para um recurso será liberado, ou retornar a falha.  Após o uso de um recurso está completo, ou chame a função de [desbloquear](../Topic/CMultiLock::Unlock.md) se o objeto de **CMultiLock** deve ser usado novamente, ou permite que o objeto de **CMultiLock** é destruído.  
  
 Os objetos de**CMultiLock** são mais úteis quando um segmento possui um grande número de objetos que `CEvent` possa responder.  Criar uma matriz que contém todos os ponteiros de `CEvent` , e a chamada `Lock`.  Isso fará com que o segmento aguarde até que um de eventos é sinalizado.  
  
 Para obter mais informações sobre como usar objetos de **CMultiLock** , consulte o artigo [multithreading: Como usar as classes de sincronização](../../parallel/multithreading-how-to-use-the-synchronization-classes.md).  
  
## Hierarquia de herança  
 `CMultiLock`  
  
## Requisitos  
 **Cabeçalho:** afxmt.h  
  
## Consulte também  
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)