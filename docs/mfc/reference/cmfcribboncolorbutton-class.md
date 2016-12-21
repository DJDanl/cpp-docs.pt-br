---
title: "Classe de CMFCRibbonColorButton | Microsoft Docs"
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
  - "CMFCRibbonColorButton"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CMFCRibbonColorButton"
ms.assetid: 6b4b4ee3-8cc0-41b4-a4eb-93e8847008e1
caps.latest.revision: 36
caps.handback.revision: 24
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CMFCRibbonColorButton
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

A classe de `CMFCRibbonColorButton` implementa um botão de cor que você pode adicionar a barra de fita.  O botão de cor de fita exibe um menu drop\-down que contém uma ou mais paletas de cores.  
  
## Sintaxe  
  
```  
class CMFCRibbonColorButton : public CMFCRibbonGallery  
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CMFCRibbonColorButton::CMFCRibbonColorButton](../Topic/CMFCRibbonColorButton::CMFCRibbonColorButton.md)||  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CMFCRibbonColorButton::AddColorsGroup](../Topic/CMFCRibbonColorButton::AddColorsGroup.md)|Adiciona um grupo de cores para a área de cor normal.|  
|[CMFCRibbonColorButton::EnableAutomaticButton](../Topic/CMFCRibbonColorButton::EnableAutomaticButton.md)|Especifica se o botão de **Automático** está habilitado.|  
|[CMFCRibbonColorButton::EnableOtherButton](../Topic/CMFCRibbonColorButton::EnableOtherButton.md)|Habilita o botão de **Outro** .|  
|[CMFCRibbonColorButton::GetAutomaticColor](../Topic/CMFCRibbonColorButton::GetAutomaticColor.md)||  
|[CMFCRibbonColorButton::GetColor](../Topic/CMFCRibbonColorButton::GetColor.md)|Retorna a cor selecionada.|  
|[CMFCRibbonColorButton::GetColorBoxSize](../Topic/CMFCRibbonColorButton::GetColorBoxSize.md)|Retorna o tamanho dos elementos de cor que aparecem na barra de cor.|  
|[CMFCRibbonColorButton::GetColumns](../Topic/CMFCRibbonColorButton::GetColumns.md)||  
|[CMFCRibbonColorButton::GetHighlightedColor](../Topic/CMFCRibbonColorButton::GetHighlightedColor.md)|Retorna a cor do elemento selecionado em paleta de cores pop\-up.|  
|[CMFCRibbonColorButton::RemoveAllColorGroups](../Topic/CMFCRibbonColorButton::RemoveAllColorGroups.md)|Remove todos os grupos de cor da área normal de cor.|  
|[CMFCRibbonColorButton::SetColor](../Topic/CMFCRibbonColorButton::SetColor.md)|Selecione uma cor da área normal de cor.|  
|[CMFCRibbonColorButton::SetColorBoxSize](../Topic/CMFCRibbonColorButton::SetColorBoxSize.md)|Defina o tamanho de todos os elementos de cor que aparecem na barra de cor.|  
|[CMFCRibbonColorButton::SetColorName](../Topic/CMFCRibbonColorButton::SetColorName.md)||  
|[CMFCRibbonColorButton::SetColumns](../Topic/CMFCRibbonColorButton::SetColumns.md)||  
|[CMFCRibbonColorButton::SetDocumentColors](../Topic/CMFCRibbonColorButton::SetDocumentColors.md)|Especifica uma lista de valores RGB para exibir na área de cor do documento.|  
|[CMFCRibbonColorButton::SetPalette](../Topic/CMFCRibbonColorButton::SetPalette.md)||  
|[CMFCRibbonColorButton::UpdateColor](../Topic/CMFCRibbonColorButton::UpdateColor.md)||  
  
## Comentários  
 O botão de cor de fita exibe uma barra de cor quando um usuário pressiona o.  Por padrão, essa barra de cor contém uma paleta de seleção de cores chamada a área normal de cor.  Opcionalmente, a barra de cor pode exibir um botão de **Automático** , que permite que o usuário selecione uma cor padrão, e um botão de **Outro** , que exibe uma paleta de cores pop\-up que contém cores adicionais.  
  
## Exemplo  
 O exemplo a seguir demonstra como usar vários métodos na classe de `CMFCRibbonColorButton` .  O exemplo a seguir mostra como criar um objeto de `CMFCRibbonColorButton` , defina a grande imagem, habilita o botão de **Automático** , habilita o botão de **Outro** , define o número de colunas, defina o tamanho de todos os elementos de cor que aparecem na barra de cor, adicione um grupo de cores para a área de cor normal, e especificam uma lista de valores RGB para exibir na área de cor do documento.  Este trecho de código é parte de [Exemplo do cliente de desenho](../../top/visual-cpp-samples.md).  
  
 [!code-cpp[NVC_MFC_DrawClient#3](../../mfc/reference/codesnippet/CPP/cmfcribboncolorbutton-class_1.cpp)]  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 [CMFCRibbonBaseElement](../../mfc/reference/cmfcribbonbaseelement-class.md)  
  
 [CMFCRibbonButton](../../mfc/reference/cmfcribbonbutton-class.md)  
  
 [CMFCRibbonGallery](../../mfc/reference/cmfcribbongallery-class.md)  
  
 [CMFCRibbonColorButton](../../mfc/reference/cmfcribboncolorbutton-class.md)  
  
## Requisitos  
 **Cabeçalho:** afxribboncolorbutton.h  
  
## Consulte também  
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes](../Topic/MFC%20Classes.md)   
 [Classe de CMFCRibbonGallery](../../mfc/reference/cmfcribbongallery-class.md)