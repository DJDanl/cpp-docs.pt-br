---
title: "Classe de CMFCTasksPaneTaskGroup | Microsoft Docs"
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
  - "CMFCTasksPaneTaskGroup"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CMFCTasksPaneTaskGroup"
ms.assetid: 2111640b-a46e-4b27-b033-29e88632b86a
caps.latest.revision: 33
caps.handback.revision: 21
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CMFCTasksPaneTaskGroup
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

A classe de `CMFCTasksPaneTaskGroup` é uma classe auxiliar usada pelo controle de [CMFCTasksPane](../Topic/CMFCTasksPane%20Class.md) .  Os objetos do tipo `CMFCTasksPaneTaskGroup` representam *um grupo de trabalho*.  O grupo de trabalho é uma lista de itens que exibe em uma caixa de estrutura separada que tenha um botão recolher.  A caixa pode ter uma legenda opcional \(nome de grupo.\)  Se um grupo é recolhido, a lista de tarefas não estiver visível.  
  
## Sintaxe  
  
```  
class CMFCTasksPaneTaskGroup : public CObject  
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CMFCTasksPaneTaskGroup::CMFCTasksPaneTaskGroup](../Topic/CMFCTasksPaneTaskGroup::CMFCTasksPaneTaskGroup.md)|Constrói um objeto de `CMFCTasksPaneTaskGroup` .|  
|`CMFCTasksPaneTaskGroup::~CMFCTasksPaneTaskGroup`|Destruidor.|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CMFCTasksPaneTaskGroup::SetACCData](../Topic/CMFCTasksPaneTaskGroup::SetACCData.md)|Determina os dados de acessibilidade para o grupo de trabalho atual.|  
  
### Membros de dados  
  
|Nome|Descrição|  
|----------|---------------|  
|[CMFCTasksPaneTaskGroup::m\_bIsBottom](../Topic/CMFCTasksPaneTaskGroup::m_bIsBottom.md)|Determina se o grupo de trabalho é alinhado à parte inferior do controle do painel de tarefas.|  
|[CMFCTasksPaneTaskGroup::m\_bIsCollapsed](../Topic/CMFCTasksPaneTaskGroup::m_bIsCollapsed.md)|Determina se o grupo de trabalho é recolhido.|  
|[CMFCTasksPaneTaskGroup::m\_bIsSpecial](../Topic/CMFCTasksPaneTaskGroup::m_bIsSpecial.md)|Determina se o grupo de trabalho é *especial.* a estrutura exibe legendas especiais em uma cor diferente.|  
|[CMFCTasksPaneTaskGroup::m\_lstTasks](../Topic/CMFCTasksPaneTaskGroup::m_lstTasks.md)|Contém a lista interna de tarefas.|  
|[CMFCTasksPaneTaskGroup::m\_rect](../Topic/CMFCTasksPaneTaskGroup::m_rect.md)|Especifica o retângulo delimitador de legenda de grupo.|  
|[CMFCTasksPaneTaskGroup::m\_rectGroup](../Topic/CMFCTasksPaneTaskGroup::m_rectGroup.md)|Especifica o retângulo delimitador do grupo.|  
|[CMFCTasksPaneTaskGroup::m\_strName](../Topic/CMFCTasksPaneTaskGroup::m_strName.md)|Especifica o nome de grupo.|  
  
## Comentários  
 A ilustração a seguir mostra um grupo de trabalho expandido:  
  
 ![Grupo de tarefas expandido](../../mfc/reference/media/nexttaskgrpexpand.png "NextTaskGrpExpand")  
  
 A ilustração a seguir mostra um grupo de trabalho recolhido:  
  
 ![Grupo de tarefas recolhido](../Image/NextTaskGrpCollapse.png "NextTaskGrpCollapse")  
  
 A ilustração a seguir mostra um grupo de trabalho sem uma legenda:  
  
 ![Grupo de tarefas sem legenda](../../mfc/reference/media/nexttaskgrpnocapt.png "NextTaskGrpNoCapt")  
  
 A ilustração a seguir mostra dois grupos de trabalho.  O primeiro grupo de trabalho está marcado como especiais definindo o parâmetro de `m_bIsSpecial` a `TRUE`, enquanto o segundo grupo de trabalho não é especial.  Observe como a legenda para o primeiro grupo de trabalho é mais escura do segundo grupo de trabalho:  
  
 ![Grupo de tarefas especiais](../../mfc/reference/media/nexttaskgrpspecial.png "NextTaskGrpSpecial")  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 [CMFCTasksPaneTaskGroup](../../mfc/reference/cmfctaskspanetaskgroup-class.md)  
  
## Requisitos  
 **Cabeçalho:** afxTasksPane.h  
  
## Consulte também  
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes](../Topic/MFC%20Classes.md)   
 [Classe de CMFCTasksPane](../Topic/CMFCTasksPane%20Class.md)   
 [Classe de CMFCTasksPaneTask](../../mfc/reference/cmfctaskspanetask-class.md)   
 [Classe CMFCOutlookBar](../../mfc/reference/cmfcoutlookbar-class.md)   
 [Classe de CObject](../Topic/CObject%20Class.md)