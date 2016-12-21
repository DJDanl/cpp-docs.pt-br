---
title: "Classe de CMFCTasksPaneTask | Microsoft Docs"
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
  - "CMFCTasksPaneTask"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CMFCTasksPaneTask"
ms.assetid: c5a7513b-cd8f-4e2e-b16f-650e1fe30954
caps.latest.revision: 27
caps.handback.revision: 15
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CMFCTasksPaneTask
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

A classe de `CMFCTasksPaneTask` é uma classe auxiliar que representa tarefas para o controle do painel de tarefas \([CMFCTasksPane](../Topic/CMFCTasksPane%20Class.md)\).  O objeto de tarefa representa um item no grupo de trabalho \([CMFCTasksPaneTaskGroup](../../mfc/reference/cmfctaskspanetaskgroup-class.md)\).  Cada tarefa pode ter um comando que a estrutura é executado quando um usuário clica na tarefa e um ícone que aparece à esquerda do nome da tarefa.  
  
## Sintaxe  
  
```  
class CMFCTasksPaneTask : public CObject  
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CMFCTasksPaneTask::CMFCTasksPaneTask](../Topic/CMFCTasksPaneTask::CMFCTasksPaneTask.md)|Cria e inicializa um objeto de `CMFCTasksPaneTask` .|  
|`CMFCTasksPaneTask::~CMFCTasksPaneTask`|Destruidor.|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CMFCTasksPaneTask::SetACCData](../Topic/CMFCTasksPaneTask::SetACCData.md)|Determina os dados de acessibilidade para a tarefa atual.|  
  
### Membros de dados  
  
|Nome|Descrição|  
|----------|---------------|  
|[CMFCTasksPaneTask::m\_bAutoDestroyWindow](../Topic/CMFCTasksPaneTask::m_bAutoDestroyWindow.md)|Determina se a janela de tarefa é automaticamente destruída.|  
|[CMFCTasksPaneTask::m\_bIsBold](../Topic/CMFCTasksPaneTask::m_bIsBold.md)|Determina se a estrutura desenha um rótulo de tarefa em negrito.|  
|[CMFCTasksPaneTask::m\_dwUserData](../Topic/CMFCTasksPaneTask::m_dwUserData.md)|Contém os dados definidos pelo usuário que a estrutura associa com a tarefa.  Defina a zero se a tarefa não tem nenhum dado associado.|  
|[CMFCTasksPaneTask::m\_hwndTask](../Topic/CMFCTasksPaneTask::m_hwndTask.md)|Um identificador para a janela de tarefas.|  
|[CMFCTasksPaneTask::m\_nIcon](../Topic/CMFCTasksPaneTask::m_nIcon.md)|O índice na lista de imagem a estrutura da imagem que aparece ao lado de tarefas.|  
|[CMFCTasksPaneTask::m\_nWindowHeight](../Topic/CMFCTasksPaneTask::m_nWindowHeight.md)|A altura da janela de tarefas.  Se a tarefa não tem nenhuma janela de tarefas, esse valor é zero.|  
|[CMFCTasksPaneTask::m\_pGroup](../Topic/CMFCTasksPaneTask::m_pGroup.md)|Um ponteiro para `CMFCTasksPaneTaskGroup` que esta tarefa pertence.|  
|[CMFCTasksPaneTask::m\_rect](../Topic/CMFCTasksPaneTask::m_rect.md)|Especifica o retângulo delimitador de tarefas.|  
|[CMFCTasksPaneTask::m\_strName](../Topic/CMFCTasksPaneTask::m_strName.md)|O nome da tarefa.|  
|[CMFCTasksPaneTask::m\_uiCommandID](../Topic/CMFCTasksPaneTask::m_uiCommandID.md)|Especifica a identificação do comando de linha de comando que a estrutura é executado quando o usuário clica a tarefa.  Se esse valor é não um identificador válido de comando, a tarefa é tratado como um rótulo simples.|  
  
## Comentários  
 A ilustração a seguir mostra um grupo de trabalho que contém três tarefas:  
  
 ![Grupo de tarefas expandido](../../mfc/reference/media/nexttaskgrpexpand.png "NextTaskGrpExpand")  
  
> [!NOTE]
>  Se uma tarefa não tem um identificador válido de comando, é tratado como um rótulo simples.  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 [CMFCTasksPaneTask](../../mfc/reference/cmfctaskspanetask-class.md)  
  
## Requisitos  
 **Cabeçalho:** afxTasksPane.h  
  
## Consulte também  
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes](../Topic/MFC%20Classes.md)   
 [Classe de CObject](../Topic/CObject%20Class.md)