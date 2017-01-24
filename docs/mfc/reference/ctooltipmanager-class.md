---
title: "Classe de CTooltipManager | Microsoft Docs"
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
  - "CTooltipManager"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CTooltipManager"
ms.assetid: c71779d7-8b6e-47ef-8500-d4552731fe86
caps.latest.revision: 22
caps.handback.revision: 11
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CTooltipManager
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Mantém informações de tempo de execução sobre dicas de ferramenta.  O `CTooltipManager` classe é instanciada uma vez por aplicativo.  
  
## Sintaxe  
  
```  
class CTooltipManager : public CObject  
```  
  
## Membros  
  
### Métodos Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CTooltipManager::CreateToolTip](../Topic/CTooltipManager::CreateToolTip.md)|Cria um controle de dica de ferramenta para os tipos especificados de controle do Windows.|  
|[CTooltipManager::DeleteToolTip](../Topic/CTooltipManager::DeleteToolTip.md)|Exclui um controle de dica de ferramenta.|  
|[CTooltipManager::SetTooltipParams](../Topic/CTooltipManager::SetTooltipParams.md)|Personaliza a aparência visual do controle dica de ferramenta para os tipos especificados de controle do Windows.|  
|[CTooltipManager::SetTooltipText](../Topic/CTooltipManager::SetTooltipText.md)|Define o texto e a descrição de um controle de dica de ferramenta.|  
|[CTooltipManager::UpdateTooltips](../Topic/CTooltipManager::UpdateTooltips.md)||  
  
## Comentários  
 Use [Classe de CMFCToolTipCtrl](../../mfc/reference/cmfctooltipctrl-class.md), `CMFCToolTipInfo`, e `CTooltipManager` juntos para implementar as dicas de ferramenta personalizadas em seu aplicativo.  Para obter um exemplo de como usar essas classes de dica de ferramenta, consulte o [Classe de CMFCToolTipCtrl](../../mfc/reference/cmfctooltipctrl-class.md) tópico.  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 [CTooltipManager](../../mfc/reference/ctooltipmanager-class.md)  
  
## Requisitos  
 **Cabeçalho:** afxtooltipmanager.h  
  
## Consulte também  
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes](../Topic/MFC%20Classes.md)   
 [Classe de CMFCToolTipCtrl](../../mfc/reference/cmfctooltipctrl-class.md)   
 [Classe de CMFCToolTipInfo](../../mfc/reference/cmfctooltipinfo-class.md)