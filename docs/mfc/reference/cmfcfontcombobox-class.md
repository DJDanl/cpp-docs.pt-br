---
title: "Classe de CMFCFontComboBox | Microsoft Docs"
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
  - "CMFCFontComboBox"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CMFCFontComboBox"
  - "Método de CMFCFontComboBox::CompareItem"
  - "Método de CMFCFontComboBox::DrawItem"
  - "Método de CMFCFontComboBox::MeasureItem"
  - "Método de CMFCFontComboBox::PreTranslateMessage"
ms.assetid: 9a53fb0c-7b45-486d-8187-2a4c723d9fbb
caps.latest.revision: 29
caps.handback.revision: 18
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CMFCFontComboBox
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

A classe de `CMFCFontComboBox` cria um controle caixa de combinação que contém uma lista de fontes.  
  
## Sintaxe  
  
```  
class CMFCFontComboBox : public CComboBox  
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CMFCFontComboBox::CMFCFontComboBox](../Topic/CMFCFontComboBox::CMFCFontComboBox.md)|Constrói um objeto de `CMFCFontComboBox` .|  
|`CMFCFontComboBox::~CMFCFontComboBox`|Destruidor.|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|`CMFCFontComboBox::CompareItem`|Chamado pela estrutura para determinar a posição relativa de um novo item na caixa de listagem classificado do controle atual da caixa combo da fonte.  Overrides \( [CComboBox::CompareItem](../Topic/CComboBox::CompareItem.md).\)|  
|`CMFCFontComboBox::DrawItem`|Chamado pela estrutura para desenhar um item específico no controle atual da caixa combo da fonte.  Overrides \( [CComboBox::DrawItem](../Topic/CComboBox::DrawItem.md).\)|  
|[CMFCFontComboBox::GetSelFont](../Topic/CMFCFontComboBox::GetSelFont.md)|Recupera informações sobre a fonte selecionada.|  
|`CMFCFontComboBox::MeasureItem`|Chamado pela estrutura para informar o windows das dimensões da caixa de listagem no controle atual da caixa combo da fonte.  Overrides \( [CComboBox::MeasureItem](../Topic/CComboBox::MeasureItem.md).\)|  
|`CMFCFontComboBox::PreTranslateMessage`|Converte mensagens de janela antes que são distribuídos funções do windows de [TranslateMessage](http://msdn.microsoft.com/library/windows/desktop/ms644955) e de [DispatchMessage](http://msdn.microsoft.com/library/windows/desktop/ms644934) .  Overrides \( [CWnd::PreTranslateMessage](../Topic/CWnd::PreTranslateMessage.md).\)|  
|[CMFCFontComboBox::SelectFont](../Topic/CMFCFontComboBox::SelectFont.md)|Seleciona a fonte que corresponde aos critérios específicos de caixa combo da fonte.|  
|[CMFCFontComboBox::Setup](../Topic/CMFCFontComboBox::Setup.md)|Inicializa a lista de itens da caixa combo da fonte.|  
  
### Membros de dados  
  
|Nome|Descrição|  
|----------|---------------|  
|[CMFCFontComboBox::m\_bDrawUsingFont](../Topic/CMFCFontComboBox::m_bDrawUsingFont.md)|Indica a estrutura que a fonte para usar para desenhar o item rotula na caixa de combinação atual da fonte.|  
  
## Comentários  
 Para usar um objeto de `CMFCFontComboBox` em uma caixa de diálogo, adicione uma variável de `CMFCFontComboBox` a classe da caixa de diálogo.  Em o método de `OnInitDialog` da classe da caixa de diálogo, chame o método de [CMFCFontComboBox::Setup](../Topic/CMFCFontComboBox::Setup.md) para inicializar a lista de itens no controle de caixa combo.  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 [CCmdTarget](../Topic/CCmdTarget%20Class.md)  
  
 [CWnd](../Topic/CWnd%20Class.md)  
  
 [CComboBox](../../mfc/reference/ccombobox-class.md)  
  
 [CMFCFontComboBox](../../mfc/reference/cmfcfontcombobox-class.md)  
  
## Requisitos  
 **Cabeçalho:** afxfontcombobox.h  
  
## Consulte também  
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes](../Topic/MFC%20Classes.md)   
 [Classe de CMFCToolBarFontComboBox](../../mfc/reference/cmfctoolbarfontcombobox-class.md)   
 [Classe de CMFCFontInfo](../../mfc/reference/cmfcfontinfo-class.md)