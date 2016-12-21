---
title: "Classe de CMFCAutoHideButton | Microsoft Docs"
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
  - "CMFCAutoHideButton"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CMFCAutoHideButton"
ms.assetid: c80e6b8b-25ca-4d12-9d27-457731028ab0
caps.latest.revision: 33
caps.handback.revision: 21
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CMFCAutoHideButton
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Um botão que exibe ou oculta uma [Classe de CDockablePane](../Topic/CDockablePane%20Class.md) que está configurado para ocultar.  
  
## Sintaxe  
  
```  
class CMFCAutoHideButton : public CObject  
```  
  
## Membros  
  
### Métodos Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CMFCAutoHideButton::BringToTop](../Topic/CMFCAutoHideButton::BringToTop.md)||  
|[CMFCAutoHideButton::Create](../Topic/CMFCAutoHideButton::Create.md)|Cria e inicializa o botão Ocultar automaticamente.|  
|[CMFCAutoHideButton::GetAlignment](../Topic/CMFCAutoHideButton::GetAlignment.md)|Recupera o alinhamento do botão Ocultar automaticamente.|  
|[CMFCAutoHideButton::GetAutoHideWindow](../Topic/CMFCAutoHideButton::GetAutoHideWindow.md)|Retorna o [CDockablePane](../Topic/CDockablePane%20Class.md) objeto associado com o botão Ocultar automaticamente.|  
|[CMFCAutoHideButton::GetParentToolBar](../Topic/CMFCAutoHideButton::GetParentToolBar.md)||  
|[CMFCAutoHideButton::GetRect](../Topic/CMFCAutoHideButton::GetRect.md)||  
|[CMFCAutoHideButton::GetSize](../Topic/CMFCAutoHideButton::GetSize.md)|Determina o tamanho do botão Ocultar automaticamente.|  
|[CMFCAutoHideButton::GetTextSize](../Topic/CMFCAutoHideButton::GetTextSize.md)|Retorna o tamanho do rótulo de texto para o botão Ocultar automaticamente.|  
|[CMFCAutoHideButton::HighlightButton](../Topic/CMFCAutoHideButton::HighlightButton.md)|Destaques automaticamente o botão Ocultar.|  
|[CMFCAutoHideButton::IsActive](../Topic/CMFCAutoHideButton::IsActive.md)|Indica se o botão Ocultar automaticamente está ativo.|  
|[CMFCAutoHideButton::IsHighlighted](../Topic/CMFCAutoHideButton::IsHighlighted.md)|Retorna o estado do botão Ocultar automaticamente de realce.|  
|[CMFCAutoHideButton::IsHorizontal](../Topic/CMFCAutoHideButton::IsHorizontal.md)|Determina se o botão Ocultar automaticamente é horizontal ou vertical.|  
|[CMFCAutoHideButton::IsTop](../Topic/CMFCAutoHideButton::IsTop.md)||  
|[CMFCAutoHideButton::IsVisible](../Topic/CMFCAutoHideButton::IsVisible.md)|Indica se o botão está visível.|  
|[CMFCAutoHideButton::Move](../Topic/CMFCAutoHideButton::Move.md)||  
|[CMFCAutoHideButton::OnDraw](../Topic/CMFCAutoHideButton::OnDraw.md)|O framework chama esse método quando ele se baseia no botão Ocultar automaticamente.|  
|[CMFCAutoHideButton::OnDrawBorder](../Topic/CMFCAutoHideButton::OnDrawBorder.md)|O framework chama esse método quando desenha a borda de um botão de ocultar automaticamente.|  
|[CMFCAutoHideButton::OnFillBackground](../Topic/CMFCAutoHideButton::OnFillBackground.md)|O framework chama esse método quando ele preenche o plano de fundo de um botão de ocultar automaticamente.|  
|[CMFCAutoHideButton::ReplacePane](../Topic/CMFCAutoHideButton::ReplacePane.md)||  
|[CMFCAutoHideButton::ShowAttachedWindow](../Topic/CMFCAutoHideButton::ShowAttachedWindow.md)|Mostra ou oculta associado [Classe de CDockablePane](../Topic/CDockablePane%20Class.md).|  
|[CMFCAutoHideButton::ShowButton](../Topic/CMFCAutoHideButton::ShowButton.md)|Mostra ou oculta o botão Ocultar automaticamente.|  
|[CMFCAutoHideButton::UnSetAutoHideMode](../Topic/CMFCAutoHideButton::UnSetAutoHideMode.md)||  
  
## Comentários  
 Na criação, o `CMFCAutoHideButton` objeto é anexado a um [Classe de CDockablePane](../Topic/CDockablePane%20Class.md).  O `CDockablePane` objeto é ocultado ou exibido conforme o usuário interage com o `CMFCAutoHideButton` objeto.  
  
 Por padrão, o framework cria automaticamente um `CMFCAutoHideButton` quando o usuário ativa de ocultar automaticamente.  A estrutura pode criar um elemento de uma classe de interface do usuário personalizada em vez da `CMFCAutoHideButton` classe.  Para especificar qual classe da interface do usuário personalizada deve usar a estrutura, defina a variável de membro estático `CMFCAutoHideBar::m_pAutoHideButtonRTS` igual a classe de interface do usuário personalizada.  Por padrão, essa variável é definida como `CMFCAutoHideButton`.  
  
## Exemplo  
 O exemplo a seguir demonstra como criar um `CMFCAutoHideButton` e usa vários métodos na `CMFCAutoHideButton` classe.  O exemplo mostra como inicializar uma `CMFCAutoHideButton` objeto usando seu `Create` método, Mostrar associado `CDockablePane` classe e mostrar o botão Ocultar automaticamente.  
  
 [!code-cpp[NVC_MFC_RibbonApp#32](../../mfc/reference/codesnippet/CPP/cmfcautohidebutton-class_1.cpp)]  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 [CMFCAutoHideButton](../../mfc/reference/cmfcautohidebutton-class.md)  
  
## Requisitos  
 **Cabeçalho:** afxautohidebutton.h  
  
## Consulte também  
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes](../Topic/MFC%20Classes.md)   
 [Classe de CMFCAutoHideBar](../Topic/CMFCAutoHideBar%20Class.md)   
 [Classe de CAutoHideDockSite](../../mfc/reference/cautohidedocksite-class.md)