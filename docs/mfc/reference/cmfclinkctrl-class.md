---
title: "Classe de CMFCLinkCtrl | Microsoft Docs"
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
  - "CMFCLinkCtrl"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CMFCLinkCtrl"
ms.assetid: 80f3874d-7cc8-410e-9ff1-62a225f5034b
caps.latest.revision: 27
caps.handback.revision: 15
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CMFCLinkCtrl
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Exibe de classe de `CMFCLinkCtrl` um botão como um hiperlink e invocam o destino do link quando o botão é clicado.  
  
## Sintaxe  
  
```  
class CMFCLinkCtrl : public CMFCButton  
```  
  
## Membros  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CMFCLinkCtrl::SetURL](../Topic/CMFCLinkCtrl::SetURL.md)|Exibe um URL especificado como o texto do botão.|  
|[CMFCLinkCtrl::SetURLPrefix](../Topic/CMFCLinkCtrl::SetURLPrefix.md)|Define o protocolo implícito \(por exemplo, “http: "\) da URL.|  
|[CMFCLinkCtrl::SizeToContent](../Topic/CMFCLinkCtrl::SizeToContent.md)|Redimensionar o botão para conter texto ou bitmap do botão.|  
  
### Métodos protegidos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CMFCLinkCtrl::OnDrawFocusRect](../Topic/CMFCLinkCtrl::OnDrawFocusRect.md)|Chamado pela estrutura antes do retângulo de foco do botão é desenhado.|  
  
## Comentários  
 Quando você clica em um botão que é derivado da classe de `CMFCLinkCtrl` , a estrutura passa a URL do botão como um parâmetro para o método de `ShellExecute` .  O método de `ShellExecute` abre o destino URL.  
  
## Exemplo  
 O exemplo a seguir demonstra como definir o tamanho de um objeto de `CMFCLinkCtrl` , e como definir um URL e um tooltip em um objeto de `CMFCLinkCtrl` .  Este exemplo é parte de [novo exemplo de controles](../../top/visual-cpp-samples.md).  
  
 [!CODE [NVC_MFC_NewControls#9](../CodeSnippet/VS_Snippets_Misc/NVC_MFC_NewControls#9)]  
[!CODE [NVC_MFC_NewControls#10](../CodeSnippet/VS_Snippets_Misc/NVC_MFC_NewControls#10)]  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 [CCmdTarget](../Topic/CCmdTarget%20Class.md)  
  
 [CWnd](../Topic/CWnd%20Class.md)  
  
 [CButton](../../mfc/reference/cbutton-class.md)  
  
 [CMFCButton](../../mfc/reference/cmfcbutton-class.md)  
  
 [CMFCLinkCtrl](../../mfc/reference/cmfclinkctrl-class.md)  
  
## Requisitos  
 **Cabeçalho:** afxlinkctrl.h  
  
## Consulte também  
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes](../Topic/MFC%20Classes.md)   
 [Classe de CLinkCtrl](../../mfc/reference/clinkctrl-class.md)   
 [Classe de CMFCButton](../../mfc/reference/cmfcbutton-class.md)