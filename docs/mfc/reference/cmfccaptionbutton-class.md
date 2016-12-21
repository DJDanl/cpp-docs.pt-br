---
title: "Classe de CMFCCaptionButton | Microsoft Docs"
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
  - "CMFCCaptionButton"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CMFCCaptionButton"
ms.assetid: c5774b38-c0dd-414a-9ede-3b2f78f233ec
caps.latest.revision: 28
caps.handback.revision: 16
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CMFCCaptionButton
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

A classe de `CMFCCaptionButton` implementa um botão que é exibido na barra de título para um painel de encaixe ou uma janela de mini\-linguagem quadro.  Normalmente, a estrutura cria os botões da barra de título automaticamente.  
  
## Sintaxe  
  
```  
class CMFCCaptionButton : public CObject  
```  
  
## Membros  
  
### Construtores  
  
|Nome|Descrição|  
|----------|---------------|  
|[CMFCCaptionButton::CMFCCaptionButton](../Topic/CMFCCaptionButton::CMFCCaptionButton.md)|Constrói um objeto de CMFCCaptionButton.|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CMFCCaptionButton::GetHit](../Topic/CMFCCaptionButton::GetHit.md)|Retorna o comando representado pelo botão.|  
|[CMFCCaptionButton::GetIconID](../Topic/CMFCCaptionButton::GetIconID.md)|Retorna a identificação de imagem associado com o botão.|  
|[CMFCCaptionButton::GetRect](../Topic/CMFCCaptionButton::GetRect.md)|Retorna o retângulo ocupado pelo botão.|  
|[CMFCCaptionButton::GetSize](../Topic/CMFCCaptionButton::GetSize.md)|Retorna a largura e a altura do botão.|  
|[CMFCCaptionButton::IsMiniFrameButton](../Topic/CMFCCaptionButton::IsMiniFrameButton.md)|Indica se a altura da barra de título é definida como o mini tamanho.|  
|[CMFCCaptionButton::Move](../Topic/CMFCCaptionButton::Move.md)|Define o estado do local de desenho do botão e de apresentação da janela.|  
|[CMFCCaptionButton::OnDraw](../Topic/CMFCCaptionButton::OnDraw.md)|Desenha o botão da barra de título.|  
|[CMFCCaptionButton::SetMiniFrameButton](../Topic/CMFCCaptionButton::SetMiniFrameButton.md)|Defina o tamanho mini da barra de título.|  
  
## Comentários  
 Você pode derivar uma classe de [Classe CPaneFrameWnd](../../mfc/reference/cpaneframewnd-class.md) e usar o método protegido, `AddButton`, para adicionar botões de legenda para uma janela mini do quadro.  
  
 CPaneFrameWnd.h define IDs de comando para dois tipos de botões da barra de título:  
  
-   `AFX_CAPTION_BTN_PIN`, que exibe um botão de pino quando o painel de encaixe oferece suporte ao modo automático ocultar de.  
  
-   `AFX_CAPTION_BTN_CLOSE`, que exibe um botão de **Fechar** quando o painel pode ser fechado ou oculto.  
  
## Exemplo  
 O exemplo a seguir demonstra como criar um objeto de `CMFCCaptionButton` e mini definir o tamanho da barra de título.  
  
 [!code-cpp[NVC_MFC_RibbonApp#43](../../mfc/reference/codesnippet/CPP/cmfccaptionbutton-class_1.cpp)]  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 [CMFCCaptionButton](../../mfc/reference/cmfccaptionbutton-class.md)  
  
## Requisitos  
 **Cabeçalho:** afxcaptionbutton.h  
  
## Consulte também  
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes](../Topic/MFC%20Classes.md)   
 [Classe CPaneFrameWnd](../../mfc/reference/cpaneframewnd-class.md)   
 [Classe de CDockablePane](../Topic/CDockablePane%20Class.md)