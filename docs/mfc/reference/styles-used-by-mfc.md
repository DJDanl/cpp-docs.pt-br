---
title: "Estilos usados pelo MFC | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "vc.mfc.styles"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "botões, Barras de ferramentas MFC"
  - "caixas de combinação, estilos"
  - "estilos de edição [MFC]"
  - "estilos da janela estendidos"
  - "janelas com moldura, estilos"
  - "caixas de listagem, estilos"
  - "estilos da caixa de mensagem"
  - "estilos de barra de rolagem [MFC]"
  - "estilos estáticos"
  - "estilos"
  - "estilos, MFC"
  - "estilos da janela, em MFC"
ms.assetid: d3b9af37-31b5-4c97-a8ad-189fd724b04c
caps.latest.revision: 10
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Estilos usados pelo MFC
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Use os seguintes estilos quando você cria o objeto correspondente de MFC.  Na maioria dos casos, esses estilos são definidos no parâmetro de `dwStyle` da função de **Criar** da classe.  
  
### Estilos de MFC  
  
|Style|Descrição|  
|-----------|---------------|  
|[Estilo do botão](../../mfc/reference/button-styles.md)|Aplica a [Classe de CButton](../../mfc/reference/cbutton-class.md) objetos, como os botões de opção, as caixas de seleção e as chaves.  Especificar uma combinação de estilos no parâmetro de `dwStyle` de [CButton::Create](../Topic/CButton::Create.md).|  
|[Estilos da caixa de combinação](../../mfc/reference/combo-box-styles.md)|Aplica a [Classe de CComboBox](../../mfc/reference/ccombobox-class.md) objetos.  Especificar uma combinação de estilos no parâmetro de `dwStyle` de [CComboBox::Create](../Topic/CComboBox::Create.md).|  
|[Editar estilos](../../mfc/reference/edit-styles.md)|Aplica a [Classe de CEdit](../Topic/CEdit%20Class.md) objetos.  Especificar uma combinação de estilos no parâmetro de `dwStyle` de [CEdit::Create](../Topic/CEdit::Create.md).|  
|[Estilos de Quadro\- janela](../../mfc/reference/frame-window-styles-mfc.md)|Aplica a [Classe de CFrameWnd](../../mfc/reference/cframewnd-class.md) objetos.  Especificar uma combinação de estilos no parâmetro de `dwStyle` de [CFrameWnd::Create](../Topic/CFrameWnd::Create.md).|  
|[Estilos da caixa de listagem](../../mfc/reference/list-box-styles.md)|Aplica a [Classe de CListBox](../Topic/CListBox%20Class.md) objetos.  Especificar uma combinação de estilos no parâmetro de `dwStyle` de [CListBox::Create](../Topic/CListBox::Create.md).|  
|[Estilos da caixa de mensagem](../../mfc/reference/message-box-styles.md)|Aplica a [AfxMessageBox](../Topic/AfxMessageBox.md) itens.  Especificar uma combinação de estilos no parâmetro de `nType` de `AfxMessageBox`.|  
|[Estilos da barra de rolagem](../../mfc/reference/scroll-bar-styles.md)|Aplica a [Classe de CScrollBar](../../mfc/reference/cscrollbar-class.md) objetos.  Especificar uma combinação de estilos no parâmetro de `dwStyle` de [CScrollBar::Create](../Topic/CScrollBar::Create.md).|  
|[Estilos estáticos](../../mfc/reference/static-styles.md)|Aplica a [Classe de CStatic](../Topic/CStatic%20Class.md) objetos.  Especificar uma combinação de estilos no parâmetro de `dwStyle` de [CStatic::Create](../Topic/CStatic::Create.md).|  
|[Estilos da janela](../Topic/Window%20Styles.md)|Aplica a [Classe de CWnd](../Topic/CWnd%20Class.md) objetos.  Especificar uma combinação de estilos no parâmetro de `dwStyle` de [CWnd::Create](../Topic/CWnd::Create.md) ou de [CWnd::CreateEx](../Topic/CWnd::CreateEx.md).|  
|[Estilos estendidos da janela](../Topic/Extended%20Window%20Styles.md)|Aplica a [Classe de CWnd](../Topic/CWnd%20Class.md) objetos.  Especificar uma combinação de estilos no parâmetro de `dwExStyle` de [CWnd::CreateEx](../Topic/CWnd::CreateEx.md).|  
  
## Consulte também  
 [Visão geral da classe](../../mfc/class-library-overview.md)