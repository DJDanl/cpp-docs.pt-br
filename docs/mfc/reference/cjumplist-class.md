---
title: "Classe de CJumpList | Microsoft Docs"
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
  - "afxadv/CJumpList"
  - "CJumpList"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CJumpList"
ms.assetid: d364d27e-f512-4b12-9872-c2a17c78ab1f
caps.latest.revision: 15
caps.handback.revision: 3
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CJumpList
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

`CJumpList` é a lista de atalhos revelada quando você clica com o botão direito do mouse em um ícone na barra de tarefas.  
  
## Sintaxe  
  
```  
class CJumpList;  
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CJumpList::CJumpList](../Topic/CJumpList::CJumpList.md)|Constrói um objeto de `CJumpList` .|  
|[CJumpList::~CJumpList](../Topic/CJumpList::~CJumpList.md)|For um objeto de `CJumpList` .|  
  
|Nome|Descrição|  
|----------|---------------|  
|[CJumpList::AbortList](../Topic/CJumpList::AbortList.md)|Nulos uma transação de compilação lista\- sem confirmar.|  
|[CJumpList::AddDestination](../Topic/CJumpList::AddDestination.md)|Sobrecarregado.  Adiciona o destino à lista.|  
|[CJumpList::AddKnownCategory](../Topic/CJumpList::AddKnownCategory.md)|Acrescenta uma categoria conhecida à lista.|  
|[CJumpList::AddTask](../Topic/CJumpList::AddTask.md)|Sobrecarregado.  Adiciona itens à categoria canônica de tarefas.|  
|[CJumpList::AddTasks](../Topic/CJumpList::AddTasks.md)|Adiciona itens à categoria canônica de tarefas.|  
|[CJumpList::AddTaskSeparator](../Topic/CJumpList::AddTaskSeparator.md)|Adiciona um separador entre tarefas.|  
|[CJumpList::ClearAll](../Topic/CJumpList::ClearAll.md)|Remove todas as tarefas e destinos que tenham sido adicionados à instância atual de `CJumpList` até o momento.|  
|[CJumpList::ClearAllDestinations](../Topic/CJumpList::ClearAllDestinations.md)|Remove todos os destinos que tenham sido adicionados à instância atual de `CJumpList` até o momento.|  
|[CJumpList::CommitList](../Topic/CJumpList::CommitList.md)|Termina uma transação de lista\- compilação e confirma a lista relatada no armazenamento o Registro associado \(em este caso\).|  
|[CJumpList::GetDestinationList](../Topic/CJumpList::GetDestinationList.md)|Recupera um ponteiro de interface à lista de destino.|  
|[CJumpList::GetMaxSlots](../Topic/CJumpList::GetMaxSlots.md)|Retorna o número máximo de itens, incluindo os cabeçalhos de categoria que podem exibir o menu de destino do aplicativo de chamada.|  
|[CJumpList::GetRemovedItems](../Topic/CJumpList::GetRemovedItems.md)|Matriz de retornos de itens que representam destinos removidos.|  
|[CJumpList::InitializeList](../Topic/CJumpList::InitializeList.md)|Inicia uma transação de lista\- compilação.|  
|[CJumpList::SetAppID](../Topic/CJumpList::SetAppID.md)|Define a identificação do modelo de usuário do aplicativo para a lista que será criada.|  
  
## Hierarquia de herança  
 [CJumpList](../../mfc/reference/cjumplist-class.md)  
  
## Requisitos  
 **Cabeçalho:** afxadv.h  
  
## Consulte também  
 [Classes](../Topic/MFC%20Classes.md)