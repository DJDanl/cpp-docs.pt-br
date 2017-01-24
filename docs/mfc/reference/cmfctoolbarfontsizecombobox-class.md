---
title: "Classe de CMFCToolBarFontSizeComboBox | Microsoft Docs"
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
  - "CMFCToolBarFontSizeComboBox"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CMFCToolBarFontSizeComboBox"
ms.assetid: 72e0c44c-6a0e-4194-a71f-ab64e3afb9b5
caps.latest.revision: 26
caps.handback.revision: 14
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CMFCToolBarFontSizeComboBox
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Um botão na barra de ferramentas que contém um controle caixa de combinação que permite que o usuário selecione um tamanho da fonte.  
  
## Sintaxe  
  
```  
class CMFCToolBarFontSizeComboBox : public CMFCToolBarComboBoxButton  
```  
  
## Membros  
  
### Construtores protegidos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CMFCToolBarFontSizeComboBox::CMFCToolBarFontSizeComboBox](../Topic/CMFCToolBarFontSizeComboBox::CMFCToolBarFontSizeComboBox.md)|Constrói um objeto de `CMFCToolBarFontSizeComboBox` .|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CMFCToolBarFontSizeComboBox::GetTwipSize](../Topic/CMFCToolBarFontSizeComboBox::GetTwipSize.md)|Retorna o tamanho da fonte selecionado em twips.|  
|[CMFCToolBarFontSizeComboBox::RebuildFontSizes](../Topic/CMFCToolBarFontSizeComboBox::RebuildFontSizes.md)|Preenche a lista da caixa de combinação com todos os tamanhos de fonte suportados para uma fonte especificada.|  
|[CMFCToolBarFontSizeComboBox::SetTwipSize](../Topic/CMFCToolBarFontSizeComboBox::SetTwipSize.md)|Defina o tamanho da fonte em twips.|  
  
## Comentários  
 Você pode usar um objeto de `CMFCToolBarFontSizeComboBox` juntamente com um objeto de [Classe de CMFCToolBarFontComboBox](../../mfc/reference/cmfctoolbarfontcombobox-class.md) para permitir que um usuário selecione uma fonte e um tamanho da fonte.  
  
 Você pode adicionar um botão da caixa combo de tamanho da fonte para uma barra de ferramentas assim como você adiciona um botão da caixa combo da fonte.  Para mais informações, consulte [Classe de CMFCToolBarFontComboBox](../../mfc/reference/cmfctoolbarfontcombobox-class.md).  
  
 Quando o usuário seleciona uma nova fonte em um objeto de `CMFCToolBarFontComboBox` , você pode preencher a caixa de combinação de tamanho da fonte com tamanhos suporte para a fonte usando o método de [CMFCToolBarFontSizeComboBox::RebuildFontSizes](../Topic/CMFCToolBarFontSizeComboBox::RebuildFontSizes.md) .  
  
## Exemplo  
 O exemplo a seguir demonstra como usar vários métodos na classe de `CMFCToolBarFontSizeComboBox` para configurar um objeto de `CMFCToolBarFontSizeComboBox` .  O exemplo ilustra como recuperar o tamanho da fonte, em twips, da caixa de texto, preenchimento a caixa de combinação de tamanho da fonte com todos os tamanhos de fonte determinada válidos, e especifica o tamanho da fonte em twips.  Este trecho de código é parte de [Exemplo de preenchimento da palavra](../../top/visual-cpp-samples.md).  
  
 [!code-cpp[NVC_MFC_WordPad#8](../../mfc/reference/codesnippet/CPP/cmfctoolbarfontsizecombobox-class_1.cpp)]  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 [CMFCToolBarButton](../../mfc/reference/cmfctoolbarbutton-class.md)  
  
 [CMFCToolBarComboBoxButton](../Topic/CMFCToolBarComboBoxButton%20Class.md)  
  
 [CMFCToolBarFontSizeComboBox](../../mfc/reference/cmfctoolbarfontsizecombobox-class.md)  
  
## Requisitos  
 **Cabeçalho:** afxtoolbarfontcombobox.h  
  
## Consulte também  
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes](../Topic/MFC%20Classes.md)   
 [Classe de CMFCToolBar](../../mfc/reference/cmfctoolbar-class.md)   
 [Classe de CMFCToolBarButton](../../mfc/reference/cmfctoolbarbutton-class.md)   
 [Classe de CMFCToolBarComboBoxButton](../Topic/CMFCToolBarComboBoxButton%20Class.md)   
 [Classe de CMFCFontInfo](../../mfc/reference/cmfcfontinfo-class.md)   
 [CMFCToolBar::ReplaceButton](../Topic/CMFCToolBar::ReplaceButton.md)   
 [Instruções passo a passo: colocando controles em barras de ferramentas](../../mfc/walkthrough-putting-controls-on-toolbars.md)