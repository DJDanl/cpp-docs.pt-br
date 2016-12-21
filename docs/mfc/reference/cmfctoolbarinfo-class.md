---
title: "Classe de CMFCToolBarInfo | Microsoft Docs"
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
  - "CMFCToolBarInfo"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CMFCToolBarInfo"
ms.assetid: 6dc84482-eaaa-491f-aa5d-dd7a57886b46
caps.latest.revision: 22
caps.handback.revision: 10
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CMFCToolBarInfo
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Contém os IDs de recursos de imagens da barra de ferramentas em vários estados.  `CMFCToolBarInfo` é uma classe auxiliar que é usada como um parâmetro do método de [CMFCToolBar::LoadToolBarEx](../Topic/CMFCToolBar::LoadToolBarEx.md) .  
  
## Sintaxe  
  
```  
class CMFCToolBarInfo  
```  
  
## Membros  
  
### Membros de dados  
  
|Nome|Descrição|  
|----------|---------------|  
|[CMFCToolBarInfo::m\_uiColdResID](../Topic/CMFCToolBarInfo::m_uiColdResID.md)|A identificação de recurso de bitmap da barra de ferramentas que contém a barra de ferramentas \(fria\) normal imagens.|  
|[CMFCToolBarInfo::m\_uiDisabledResID](../Topic/CMFCToolBarInfo::m_uiDisabledResID.md)|A identificação de recurso de bitmap da barra de ferramentas que contém a barra de ferramentas desativado imagens.|  
|[CMFCToolBarInfo::m\_uiHotResID](../Topic/CMFCToolBarInfo::m_uiHotResID.md)|A identificação de recurso de bitmap da barra de ferramentas que contém a barra de ferramentas \(quente\) selecionada imagens.|  
|[CMFCToolBarInfo::m\_uiLargeColdResID](../Topic/CMFCToolBarInfo::m_uiLargeColdResID.md)|A identificação de recurso de bitmap da barra de ferramentas que contém a grande, barra de ferramentas normal imagens.|  
|[CMFCToolBarInfo::m\_uiLargeDisabledResID](../Topic/CMFCToolBarInfo::m_uiLargeDisabledResID.md)|A identificação de recurso de bitmap da barra de ferramentas que contém a grande, barra de ferramentas desativado imagens.|  
|[CMFCToolBarInfo::m\_uiLargeHotResID](../Topic/CMFCToolBarInfo::m_uiLargeHotResID.md)|A identificação de recurso de bitmap da barra de ferramentas que contém a grande, barra de ferramentas selecionada imagens.|  
|[CMFCToolBarInfo::m\_uiMenuDisabledResID](../Topic/CMFCToolBarInfo::m_uiMenuDisabledResID.md)|A identificação de recurso de bitmap da barra de ferramentas que contém o menu desativado imagens.|  
|[CMFCToolBarInfo::m\_uiMenuResID](../Topic/CMFCToolBarInfo::m_uiMenuResID.md)|Identificação do recurso de bitmap da barra de ferramentas contendo imagens do menu.|  
  
## Comentários  
 Um bitmap completo da barra de ferramentas consiste de imagens pequenas da barra de ferramentas \(botões\) de um tamanho fixo.  Identificação de cada recurso que é armazenado em um objeto de `CMFCToolBarInfo` é um bitmap que contém um conjunto completo de imagens da barra de ferramentas em um único estado \(por exemplo, imagens selecionado, desativado, grandes, ou de menu\).  
  
## Hierarquia de herança  
 [CMFCToolBarInfo](../../mfc/reference/cmfctoolbarinfo-class.md)  
  
## Requisitos  
 **Cabeçalho:** afxtoolbar.h  
  
## Consulte também  
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes](../Topic/MFC%20Classes.md)   
 [Classe de CMFCToolBar](../../mfc/reference/cmfctoolbar-class.md)   
 [CMFCToolBar::LoadToolBarEx](../Topic/CMFCToolBar::LoadToolBarEx.md)