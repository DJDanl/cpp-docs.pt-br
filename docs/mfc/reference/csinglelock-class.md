---
title: "Classe de CSingleLock | Microsoft Docs"
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
  - "CSingleLock"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CSingleLock"
  - "objetos de sincronização, controle de acesso"
  - "threading [MFC], controle de acesso"
  - "threading [MFC], sincronização"
ms.assetid: 7dae7288-8066-4a3e-85e0-78d28bfc6bc8
caps.latest.revision: 20
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CSingleLock
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Representa o mecanismo de controle de acesso usado no controle de acesso a um recurso em um programa com vários segmentos.  
  
## Sintaxe  
  
```  
  
class CSingleLock  
  
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CSingleLock::CSingleLock](../Topic/CSingleLock::CSingleLock.md)|Constrói um objeto de `CSingleLock` .|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CSingleLock::IsLocked](../Topic/CSingleLock::IsLocked.md)|Determina se o objeto é bloqueado.|  
|[CSingleLock::Lock](../Topic/CSingleLock::Lock.md)|Pára em um objeto de sincronização.|  
|[CSingleLock::Unlock](../Topic/CSingleLock::Unlock.md)|Libera um objeto de sincronização.|  
  
## Comentários  
 `CSingleLock` não tem uma classe base.  
  
 Para usar as classes [CSemaphore](../../mfc/reference/csemaphore-class.md)de sincronização, [CMutex](../../mfc/reference/cmutex-class.md), [CCriticalSection](../Topic/CCriticalSection%20Class.md), e [CEvent](../../mfc/reference/cevent-class.md), você deve criar `CSingleLock` ou objeto de [CMultiLock](../../mfc/reference/cmultilock-class.md) para esperar sobre e liberar o objeto de sincronização.  Use `CSingleLock` quando você só precisará esperar em um objeto de cada vez.  Use **CMultiLock** quando há vários objetos que você pode usar em um horário específico.  
  
 Para usar um objeto de `CSingleLock` , chamar o construtor em uma função de membro na classe do recurso controlado.  Chame a função de membro de [IsLocked](../Topic/CSingleLock::IsLocked.md) para determinar se o recurso está disponível.  Se estiver, vá com o restante da função de membro.  Se o recurso não estiver disponível, espere um período de tempo especificado para que o recurso seja solto, ou retornar a falha.  Após o uso de recursos é concluída, ou chame a função de [desbloquear](../Topic/CSingleLock::Unlock.md) se o objeto de `CSingleLock` deve ser usado novamente, ou permite que o objeto de `CSingleLock` é destruído.  
  
 Os objetos de`CSingleLock` requerem a presença de um objeto derivado de [CSyncObject](../../mfc/reference/csyncobject-class.md).  Isso é geralmente um membro de dados de classe do recurso controlado.  Para obter mais informações sobre como usar objetos de `CSingleLock` , consulte o artigo [multithreading: Como usar as classes de sincronização](../../parallel/multithreading-how-to-use-the-synchronization-classes.md).  
  
## Hierarquia de herança  
 `CSingleLock`  
  
## Requisitos  
 **Cabeçalho:** afxmt.h  
  
## Consulte também  
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe de CMultiLock](../../mfc/reference/cmultilock-class.md)