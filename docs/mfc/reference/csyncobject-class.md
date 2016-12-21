---
title: "Classe de CSyncObject | Microsoft Docs"
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
  - "CSyncObject"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CSyncObject"
  - "classes de sincronização, CSyncObject"
ms.assetid: c62ea6eb-a17b-4e01-aed4-321fc435a5f4
caps.latest.revision: 21
caps.handback.revision: 9
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CSyncObject
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Uma classe virtual pura que fornece a funcionalidade comum de sincronização a objetos no Win32.  
  
## Sintaxe  
  
```  
class CSyncObject : public CObject  
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CSyncObject::CSyncObject](../Topic/CSyncObject::CSyncObject.md)|Constrói um objeto de `CSyncObject` .|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CSyncObject::Lock](../Topic/CSyncObject::Lock.md)|Obtiver acesso ao objeto de sincronização.|  
|[CSyncObject::Unlock](../Topic/CSyncObject::Unlock.md)|Obtiver acesso ao objeto de sincronização.|  
  
### Operadores públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[ALÇA de CSyncObject::operator](../Topic/CSyncObject::operator%20HANDLE.md)|Fornece acesso ao objeto de sincronização.|  
  
### Membros públicos de dados  
  
|Nome|Descrição|  
|----------|---------------|  
|[CSyncObject::m\_hObject](../Topic/CSyncObject::m_hObject.md)|O identificador para o objeto subjacente de sincronização.|  
  
## Comentários  
 A biblioteca de classe de base do Microsoft fornece várias classes derivadas de `CSyncObject`.  Esses são [CEvent](../../mfc/reference/cevent-class.md), [CMutex](../../mfc/reference/cmutex-class.md), [CCriticalSection](../Topic/CCriticalSection%20Class.md), e [CSemaphore](../../mfc/reference/csemaphore-class.md).  
  
 Para obter informações sobre como usar objetos de sincronização, consulte o artigo [multithreading: Como usar as classes de sincronização](../../parallel/multithreading-how-to-use-the-synchronization-classes.md).  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 `CSyncObject`  
  
## Requisitos  
 **Cabeçalho:** afxmt.h  
  
## Consulte também  
 [Classe de CObject](../Topic/CObject%20Class.md)   
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)