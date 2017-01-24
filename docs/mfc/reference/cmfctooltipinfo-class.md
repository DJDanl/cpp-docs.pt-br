---
title: "Classe de CMFCToolTipInfo | Microsoft Docs"
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
  - "CMFCToolTipInfo"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CMFCToolTipInfo"
ms.assetid: f9d3d7f8-1f08-4342-a7b2-683860e5d2a5
caps.latest.revision: 27
caps.handback.revision: 15
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CMFCToolTipInfo
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Armazena informações sobre a aparência visual de dicas de ferramentas.  
  
## Sintaxe  
  
```  
class CMFCToolTipInfo  
```  
  
## Membros  
  
### Métodos Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CMFCToolTipInfo::operator\=](../Topic/CMFCToolTipInfo::operator=.md)||  
  
### Membros de Dados  
  
|Nome|Descrição|  
|----------|---------------|  
|[CMFCToolTipInfo::m\_bBalloonTooltip](../Topic/CMFCToolTipInfo::m_bBalloonTooltip.md)|Uma variável Boolean que indica se a dica de ferramenta tem uma aparência de balão.|  
|[CMFCToolTipInfo::m\_bBoldLabel](../Topic/CMFCToolTipInfo::m_bBoldLabel.md)|Uma variável Boolean que indica se a dica de ferramenta rótulos são exibidos em uma fonte em negrito.|  
|[CMFCToolTipInfo::m\_bDrawDescription](../Topic/CMFCToolTipInfo::m_bDrawDescription.md)|Uma variável Boolean que indica se a dica de ferramenta contém uma descrição.|  
|[CMFCToolTipInfo::m\_bDrawIcon](../Topic/CMFCToolTipInfo::m_bDrawIcon.md)|Uma variável Boolean que indica se a dica de ferramenta contém um ícone.|  
|[CMFCToolTipInfo::m\_bDrawSeparator](../Topic/CMFCToolTipInfo::m_bDrawSeparator.md)|Uma variável Boolean que indica se um separador é exibido entre o rótulo de dica de ferramenta e a descrição da dica de ferramenta.|  
|[CMFCToolTipInfo::m\_bRoundedCorners](../Topic/CMFCToolTipInfo::m_bRoundedCorners.md)|Uma variável Boolean que indica se a dica de ferramenta tem cantos arredondados.|  
|[CMFCToolTipInfo::m\_bVislManagerTheme](../Topic/CMFCToolTipInfo::m_bVislManagerTheme.md)|Uma variável Boolean que indica se a aparência da dica de ferramenta deve ser controlada por um Gerenciador visual \(consulte [Classe de CMFCVisualManager](../../mfc/reference/cmfcvisualmanager-class.md)\).|  
|[CMFCToolTipInfo::m\_clrBorder](../Topic/CMFCToolTipInfo::m_clrBorder.md)|A cor da borda da dica de ferramenta.|  
|[CMFCToolTipInfo::m\_clrFill](../Topic/CMFCToolTipInfo::m_clrFill.md)|A cor do plano de fundo dica de ferramenta.|  
|[CMFCToolTipInfo::m\_clrFillGradient](../Topic/CMFCToolTipInfo::m_clrFillGradient.md)|A cor de preenchimento de gradiente na dica de ferramenta.|  
|[CMFCToolTipInfo::m\_clrText](../Topic/CMFCToolTipInfo::m_clrText.md)|A cor do texto na dica de ferramenta.|  
|[CMFCToolTipInfo::m\_nGradientAngle](../Topic/CMFCToolTipInfo::m_nGradientAngle.md)|O ângulo do preenchimento com gradiente na dica de ferramenta.|  
|[CMFCToolTipInfo::m\_nMaxDescrWidth](../Topic/CMFCToolTipInfo::m_nMaxDescrWidth.md)|A máxima possível largura, em pixels, da descrição na dica de ferramenta.|  
  
## Comentários  
 Use [Classe de CMFCToolTipCtrl](../../mfc/reference/cmfctooltipctrl-class.md), `CMFCToolTipInfo`, e [Classe de CTooltipManager](../../mfc/reference/ctooltipmanager-class.md) juntos para implementar as dicas de ferramenta personalizadas em seu aplicativo.  Para obter um exemplo de como usar essas classes de dica de ferramenta, consulte o [Classe de CMFCToolTipCtrl](../../mfc/reference/cmfctooltipctrl-class.md) tópico.  
  
## Exemplo  
 O exemplo a seguir demonstra como definir os valores das diversas variáveis de membro na `CMFCToolTipInfo` classe.  
  
 [!code-cpp[NVC_MFC_RibbonApp#42](../../mfc/reference/codesnippet/CPP/cmfctooltipinfo-class_1.cpp)]  
  
## Hierarquia de herança  
 [CMFCToolTipInfo](../../mfc/reference/cmfctooltipinfo-class.md)  
  
## Requisitos  
 **Cabeçalho:** afxtooltipctrl.h  
  
## Consulte também  
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes](../Topic/MFC%20Classes.md)   
 [Classe de CTooltipManager](../../mfc/reference/ctooltipmanager-class.md)   
 [Classe de CMFCToolTipCtrl](../../mfc/reference/cmfctooltipctrl-class.md)