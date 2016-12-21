---
title: "Classe de CMFCToolTipCtrl | Microsoft Docs"
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
  - "CMFCToolTipCtrl"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CMFCToolTipCtrl"
ms.assetid: 9fbfcfb1-a8ab-417f-ae29-9a9ca85ee58f
caps.latest.revision: 33
caps.handback.revision: 21
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CMFCToolTipCtrl
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Uma implementação de dica de ferramenta estendida se baseia o [Classe de CToolTipCtrl](../Topic/CToolTipCtrl%20Class.md).  Uma dica de ferramenta com base no `CMFCToolTipCtrl` classe pode exibir um ícone, um rótulo e uma descrição.  Você pode personalizar sua aparência visual usando um preenchimento de gradiente, texto personalizado e cores de borda, negrito, cantos arredondados ou um estilo de balão.  
  
## Sintaxe  
  
```  
class CMFCToolTipCtrl : public CToolTipCtrl  
```  
  
## Membros  
  
### Construtores Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|`CMFCToolTipCtrl::CMFCToolTipCtrl`|Construtor padrão.|  
  
### Métodos Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CMFCToolTipCtrl::GetIconSize](../Topic/CMFCToolTipCtrl::GetIconSize.md)|Retorna o tamanho de um ícone em uma dica de ferramenta.|  
|[CMFCToolTipCtrl::GetParams](../Topic/CMFCToolTipCtrl::GetParams.md)|Retorna as configurações de exibição de uma dica de ferramenta.|  
|[CMFCToolTipCtrl::OnDrawBorder](../Topic/CMFCToolTipCtrl::OnDrawBorder.md)|Desenhe a borda de uma dica de ferramenta.|  
|[CMFCToolTipCtrl::OnDrawDescription](../Topic/CMFCToolTipCtrl::OnDrawDescription.md)||  
|[CMFCToolTipCtrl::OnDrawIcon](../Topic/CMFCToolTipCtrl::OnDrawIcon.md)|Exibe um ícone em uma dica de ferramenta.|  
|[CMFCToolTipCtrl::OnDrawLabel](../Topic/CMFCToolTipCtrl::OnDrawLabel.md)|Desenha o rótulo de uma dica de ferramenta ou calcula o tamanho do rótulo.|  
|[CMFCToolTipCtrl::OnDrawSeparator](../Topic/CMFCToolTipCtrl::OnDrawSeparator.md)|Desenha o separador entre o rótulo e a descrição em uma dica de ferramenta.|  
|[CMFCToolTipCtrl::OnFillBackground](../Topic/CMFCToolTipCtrl::OnFillBackground.md)|Preenche o plano de fundo da dica de ferramenta.|  
|[CMFCToolTipCtrl::SetDescription](../Topic/CMFCToolTipCtrl::SetDescription.md)|Define a descrição a ser exibido, a dica de ferramenta.|  
|[CMFCToolTipCtrl::SetFixedWidth](../Topic/CMFCToolTipCtrl::SetFixedWidth.md)||  
|[CMFCToolTipCtrl::SetHotRibbonButton](../Topic/CMFCToolTipCtrl::SetHotRibbonButton.md)||  
|[CMFCToolTipCtrl::SetLocation](../Topic/CMFCToolTipCtrl::SetLocation.md)||  
|[CMFCToolTipCtrl::SetParams](../Topic/CMFCToolTipCtrl::SetParams.md)|Especifica a aparência visual de uma dica de ferramenta usando um `CMFCToolTipInfo` objeto.|  
  
## Comentários  
 Use `CMFCToolTipCtrl`, `CMFCToolTipInfo`, e [Classe de CTooltipManager](../../mfc/reference/ctooltipmanager-class.md) objetos para implementar dicas de ferramenta personalizadas em seu aplicativo.  
  
 Por exemplo, para usar dicas de ferramenta em estilo de balão, siga estas etapas:  
  
 1.  Use o [Classe de CWinAppEx](../../mfc/reference/cwinappex-class.md) método para inicializar o Gerenciador de dica de ferramenta em seu aplicativo.  
  
 2.  Criar um `CMFCToolTipInfo` para especificar o estilo visual desejado:  
  
```  
CMFCToolTipInfo params;  
 params.m_bBoldLabel = FALSE;  
 params.m_bDrawDescription = FALSE;  
 params.m_bDrawIcon = FALSE;  
 params.m_bRoundedCorners = TRUE;  
 params.m_bDrawSeparator = FALSE;  
 if (m_bCustomColors)  
 {  
  params.m_clrFill = RGB (255, 255, 255);  
  params.m_clrFillGradient = RGB (228, 228, 240);  
  params.m_clrText = RGB (61, 83, 80);  
  params.m_clrBorder = RGB (144, 149, 168);  
 }  
```  
  
 3.  Use o [CTooltipManager::SetTooltipParams](../Topic/CTooltipManager::SetTooltipParams.md) método para definir o estilo visual para todas as dicas de ferramentas do aplicativo usando os estilos definidos na `CMFCToolTipInfo` objeto:  
  
```  
theApp.GetTooltipManager ()->SetTooltipParams (AFX_TOOLTIP_TYPE_ALL,  
    RUNTIME_CLASS (CMFCToolTipCtrl), &params);  
```  
  
 Você também pode derivar uma nova classe de `CMFCToolTipCtrl` para controlar o comportamento de dica de ferramenta e renderização.  Para especificar uma nova classe de controle de dica de ferramenta, use o `CTooltipManager::SetTooltipParams` método:  
  
```  
myApp.GetTooltipManager ()->SetTooltipParams (AFX_TOOLTIP_TYPE_ALL,  
    RUNTIME_CLASS (CMyToolTipCtrl))  
```  
  
 Para restaurar o padrão a dica de ferramenta classe de controle e redefinir a aparência de dica de ferramenta para seu estado padrão, especifique NULL nos runtime classe e dica de ferramenta informações sobre parâmetros de `SetTooltipParams`:  
  
```  
theApp.GetTooltipManager ()->SetTooltipParams (AFX_TOOLTIP_TYPE_ALL,  
    NULL, NULL);  
```  
  
## Exemplo  
 O exemplo a seguir demonstra como criar um `CMFCToolTipCtrl` do objeto, defina a descrição do que a dica de ferramenta exibe e definir a largura do controle dica de ferramenta.  
  
 [!code-cpp[NVC_MFC_RibbonApp#41](../../mfc/reference/codesnippet/CPP/cmfctooltipctrl-class_1.cpp)]  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 [CCmdTarget](../Topic/CCmdTarget%20Class.md)  
  
 [CWnd](../Topic/CWnd%20Class.md)  
  
 [CToolTipCtrl](../Topic/CToolTipCtrl%20Class.md)  
  
 [CMFCToolTipCtrl](../../mfc/reference/cmfctooltipctrl-class.md)  
  
## Requisitos  
 **Cabeçalho:** afxtooltipctrl.h  
  
## Consulte também  
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes](../Topic/MFC%20Classes.md)   
 [Classe de CToolTipCtrl](../Topic/CToolTipCtrl%20Class.md)   
 [Classe de CTooltipManager](../../mfc/reference/ctooltipmanager-class.md)   
 [Classe de CMFCToolTipInfo](../../mfc/reference/cmfctooltipinfo-class.md)   
 [Classe de CWinAppEx](../../mfc/reference/cwinappex-class.md)