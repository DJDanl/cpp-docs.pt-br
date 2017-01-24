---
title: "Classe de CMFCPropertyGridToolTipCtrl | Microsoft Docs"
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
  - "CMFCPropertyGridToolTipCtrl::PreTranslateMessage"
  - "~CMFCPropertyGridToolTipCtrl"
  - "PreTranslateMessage"
  - "CMFCPropertyGridToolTipCtrl.~CMFCPropertyGridToolTipCtrl"
  - "CMFCPropertyGridToolTipCtrl"
  - "CMFCPropertyGridToolTipCtrl.PreTranslateMessage"
  - "CMFCPropertyGridToolTipCtrl::~CMFCPropertyGridToolTipCtrl"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Destruidor de ~CMFCPropertyGridToolTipCtrl"
  - "Classe de CMFCPropertyGridToolTipCtrl"
  - "Classe de CMFCPropertyGridToolTipCtrl, destruidor"
  - "Método de PreTranslateMessage"
ms.assetid: 84b436e5-6695-4da0-9569-1a875e087711
caps.latest.revision: 24
caps.handback.revision: 12
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CMFCPropertyGridToolTipCtrl
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Implementa um controle de dica de ferramenta que [Classe de CMFCPropertyGridCtrl](../../mfc/reference/cmfcpropertygridctrl-class.md) usa para exibir as dicas de ferramentas.  
  
## Sintaxe  
  
```  
class CMFCPropertyGridToolTipCtrl : public CWnd  
```  
  
## Membros  
  
### Construtores public  
  
|||  
|-|-|  
|Nome|Descrição|  
|[CMFCPropertyGridToolTipCtrl::CMFCPropertyGridToolTipCtrl](../Topic/CMFCPropertyGridToolTipCtrl::CMFCPropertyGridToolTipCtrl.md)|Constrói um objeto de `CMFCPropertyGridToolTipCtrl` .|  
|`CMFCPropertyGridToolTipCtrl::~CMFCPropertyGridToolTipCtrl`|Destruidor.|  
  
### Métodos públicos  
  
|||  
|-|-|  
|Nome|Descrição|  
|[CMFCPropertyGridToolTipCtrl::Create](../Topic/CMFCPropertyGridToolTipCtrl::Create.md)|Cria uma janela para o tipo de controle tooltip.|  
|[CMFCPropertyGridToolTipCtrl::Deactivate](../Topic/CMFCPropertyGridToolTipCtrl::Deactivate.md)|Desativa e ocultará o controle de tooltip.|  
|[CMFCPropertyGridToolTipCtrl::GetLastRect](../Topic/CMFCPropertyGridToolTipCtrl::GetLastRect.md)|Retorna as coordenadas da posição mais recente do controle de tooltip.|  
|[CMFCPropertyGridToolTipCtrl::Hide](../Topic/CMFCPropertyGridToolTipCtrl::Hide.md)|Ocultará o controle de tooltip.|  
|`CMFCPropertyGridToolTipCtrl::PreTranslateMessage`|Usado pela classe [CWinApp](../../mfc/reference/cwinapp-class.md) transladar mensagens de janela antes que são distribuídos funções do windows de [TranslateMessage](http://msdn.microsoft.com/library/windows/desktop/ms644955) e de [DispatchMessage](http://msdn.microsoft.com/library/windows/desktop/ms644934) .  Overrides \( [CWnd::PreTranslateMessage](../Topic/CWnd::PreTranslateMessage.md).\)|  
|[CMFCPropertyGridToolTipCtrl::SetTextMargin](../Topic/CMFCPropertyGridToolTipCtrl::SetTextMargin.md)|Define o espacejamento entre texto de tooltip e a borda da janela de tooltip.|  
|[CMFCPropertyGridToolTipCtrl::Track](../Topic/CMFCPropertyGridToolTipCtrl::Track.md)|Exibe o tipo de controle tooltip.|  
  
## Comentários  
 Dicas de ferramentas é exibido quando o ponteiro permanece em um nome de propriedade.  Exibe de classe de [CMFCPropertyGridToolTipCtrl](../../mfc/reference/cmfcpropertygridtooltipctrl-class.md) uma dica de ferramenta para que ele seja facilmente legíveis pelo usuário.  Em geral, a posição de um tooltip é determinada pela posição do ponteiro.  Usando essa classe, a ferramenta de dica aparece no nome de propriedade e se assemelha a extensão natural da propriedade, para que o nome da propriedade é totalmente visível.  
  
 O MFC automaticamente cria esse controle e usa\-o em [Classe de CMFCPropertyGridCtrl](../../mfc/reference/cmfcpropertygridctrl-class.md).  
  
## Exemplo  
 O exemplo a seguir demonstra como criar um objeto da classe de `CMFCPropertyGridToolTipCtrl` , e como exibir o controle de tooltip.  
  
 [!code-cpp[NVC_MFC_RibbonApp#23](../../mfc/reference/codesnippet/CPP/cmfcpropertygridtooltipctrl-class_1.cpp)]  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 [CCmdTarget](../Topic/CCmdTarget%20Class.md)  
  
 [CWnd](../Topic/CWnd%20Class.md)  
  
 [CMFCPropertyGridToolTipCtrl](../../mfc/reference/cmfcpropertygridtooltipctrl-class.md)  
  
## Requisitos  
 **Cabeçalho:** afxpropertygridtooltipctrl.h  
  
## Consulte também  
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes](../Topic/MFC%20Classes.md)