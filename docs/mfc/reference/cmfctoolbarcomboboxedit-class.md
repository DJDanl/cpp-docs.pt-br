---
title: "Classe de CMFCToolBarComboBoxEdit | Microsoft Docs"
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
  - "CMFCComboEdit"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CMFCToolBarComboBoxEdit"
  - "Método de CMFCToolBarComboBoxEdit::PreTranslateMessage"
ms.assetid: 4789c34a-ce58-48ba-a26f-38748b601352
caps.latest.revision: 25
caps.handback.revision: 12
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CMFCToolBarComboBoxEdit
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

A estrutura de `CMFCToolBarComboBoxEdit` usa a classe para criar um botão da barra de ferramentas que se comporta como um controle editável da caixa combo.  
  
## Sintaxe  
  
```  
class CMFCToolBarComboBoxEdit : public CEdit  
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CMFCToolBarComboBoxEdit::CMFCToolBarComboBoxEdit](../Topic/CMFCToolBarComboBoxEdit::CMFCToolBarComboBoxEdit.md)|Constrói um objeto de `CMFCToolBarComboBoxEdit` .|  
|`CMFCToolBarComboBoxEdit::~CMFCToolBarComboBoxEdit`|Destruidor.|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|`CMFCToolBarComboBoxEdit::PreTranslateMessage`|Converte mensagens de janela antes que são distribuídos funções do windows de [TranslateMessage](http://msdn.microsoft.com/library/windows/desktop/ms644955) e de [DispatchMessage](http://msdn.microsoft.com/library/windows/desktop/ms644934) .  Overrides \( [CWnd::PreTranslateMessage](../Topic/CWnd::PreTranslateMessage.md).\)|  
  
### Comentários  
 Uma classe derivada da classe de `CMFCToolBarComboBoxEdit` para personalizar as operações de edição.  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 [CCmdTarget](../Topic/CCmdTarget%20Class.md)  
  
 [CWnd](../Topic/CWnd%20Class.md)  
  
 [CEdit](../Topic/CEdit%20Class.md)  
  
 [CMFCToolBarComboBoxEdit](../../mfc/reference/cmfctoolbarcomboboxedit-class.md)  
  
## Requisitos  
 **Cabeçalho:** afxtoolbarcomboboxbutton.h  
  
## Consulte também  
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes](../Topic/MFC%20Classes.md)   
 [Classe de CMFCToolBarComboBoxButton](../Topic/CMFCToolBarComboBoxButton%20Class.md)   
 [CMFCToolBarComboBoxButton::CreateEdit](../Topic/CMFCToolBarComboBoxButton::CreateEdit.md)