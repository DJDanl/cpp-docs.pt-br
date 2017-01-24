---
title: "Classe de CMFCToolBarFontComboBox | Microsoft Docs"
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
  - "CMFCToolBarFontComboBox"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CMFCToolBarFontComboBox"
ms.assetid: 25f8e08c-aadd-4cb5-9581-a99d49d444b1
caps.latest.revision: 29
caps.handback.revision: 18
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CMFCToolBarFontComboBox
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Um botão na barra de ferramentas que contém um controle caixa de combinação que permite que o usuário selecione uma fonte de uma lista de fontes de sistema.  
  
## Sintaxe  
  
```  
class CMFCToolBarFontComboBox : public CMFCToolBarComboBoxButton  
```  
  
## Membros  
  
### Construtores protegidos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CMFCToolBarFontComboBox::CMFCToolBarFontComboBox](../Topic/CMFCToolBarFontComboBox::CMFCToolBarFontComboBox.md)|Constrói um objeto de `CMFCToolBarFontComboBox` .|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CMFCToolBarFontComboBox::GetFontDesc](../Topic/CMFCToolBarFontComboBox::GetFontDesc.md)|Retorna um ponteiro para o objeto de `CMFCFontInfo` para um índice especificado na caixa de combinação.|  
|[CMFCToolBarFontComboBox::SetFont](../Topic/CMFCToolBarFontComboBox::SetFont.md)|Selecione uma fonte na caixa de combinação de fonte de acordo com o nome da fonte, ou o prefixo e o conjunto de caracteres da fonte.|  
  
### Membros de dados  
 [CMFCToolBarFontComboBox::m\_nFontHeight](../Topic/CMFCToolBarFontComboBox::m_nFontHeight.md)  
 A altura de caracteres na caixa de combinação de fonte.  
  
## Comentários  
 Para adicionar um botão da caixa combo de fonte para uma barra de ferramentas, siga estas etapas:  
  
1.  Reservar uma identificação de recurso fictício no botão no recurso pai da barra de ferramentas.  
  
2.  Construir um objeto de `CMFCToolBarFontComboBox` .  
  
3.  Em o manipulador de mensagem que processa a mensagem de `AFX_WM_RESETTOOLBAR` , substitua o botão original com o novo botão da caixa de combinação usando [CMFCToolBar::ReplaceButton](../Topic/CMFCToolBar::ReplaceButton.md).  
  
4.  Sincronizar a fonte que está selecionada na caixa de combinação com a fonte no documento usando o método de [CMFCToolBarFontComboBox::SetFont](../Topic/CMFCToolBarFontComboBox::SetFont.md) .  
  
 Para sincronizar a fonte do documento com a fonte selecionada na caixa de combinação, use o método de [CMFCToolBarFontComboBox::GetFontDesc](../Topic/CMFCToolBarFontComboBox::GetFontDesc.md) para recuperar os atributos de fonte selecionada, e use esses atributos para criar um objeto de [Classe de CFont](../../mfc/reference/cfont-class.md) .  
  
 O botão da caixa combo de fonte chama a função [EnumFontFamiliesEx](http://msdn.microsoft.com/library/windows/desktop/dd162620) Win32 para determinar as fontes de tela e de impressora disponíveis para o sistema.  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 [CMFCToolBarButton](../../mfc/reference/cmfctoolbarbutton-class.md)  
  
 [CMFCToolBarComboBoxButton](../Topic/CMFCToolBarComboBoxButton%20Class.md)  
  
 [CMFCToolBarFontComboBox](../../mfc/reference/cmfctoolbarfontcombobox-class.md)  
  
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