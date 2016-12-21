---
title: "Classe de CMFCRibbonCustomizePropertyPage | Microsoft Docs"
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
  - "GetThisClass"
  - "CMFCRibbonCustomizePropertyPage::CreateObject"
  - "CMFCRibbonCustomizePropertyPage"
  - "CMFCRibbonCustomizePropertyPage::~CMFCRibbonCustomizePropertyPage"
  - "CMFCRibbonCustomizePropertyPage.GetThisClass"
  - "CMFCRibbonCustomizePropertyPage.CreateObject"
  - "~CMFCRibbonCustomizePropertyPage"
  - "CreateObject"
  - "CMFCRibbonCustomizePropertyPage.~CMFCRibbonCustomizePropertyPage"
  - "CMFCRibbonCustomizePropertyPage::GetThisClass"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Destruidor de ~CMFCRibbonCustomizePropertyPage"
  - "Classe de CMFCRibbonCustomizePropertyPage"
  - "Classe de CMFCRibbonCustomizePropertyPage, destruidor"
  - "Método de CreateObject"
  - "Método de GetThisClass"
ms.assetid: ea32a99a-dfbe-401e-8975-aa191552532f
caps.latest.revision: 26
caps.handback.revision: 14
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CMFCRibbonCustomizePropertyPage
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Implementa uma página personalizado para a caixa de diálogo de **Personalizar** em aplicativos baseados Fita\-.  
  
## Sintaxe  
  
```  
class CMFCRibbonCustomizePropertyPage: public CMFCPropertyPage  
```  
  
## Membros  
  
### Construtores public  
  
|||  
|-|-|  
|Nome|Descrição|  
|[CMFCRibbonCustomizePropertyPage::CMFCRibbonCustomizePropertyPage](../Topic/CMFCRibbonCustomizePropertyPage::CMFCRibbonCustomizePropertyPage.md)|Constrói um objeto de `CMFCRibbonCustomizePropertyPage` .|  
|`CMFCRibbonCustomizePropertyPage::~CMFCRibbonCustomizePropertyPage`|Destruidor.|  
  
### Métodos públicos  
  
|||  
|-|-|  
|Nome|Descrição|  
|[CMFCRibbonCustomizePropertyPage::AddCustomCategory](../Topic/CMFCRibbonCustomizePropertyPage::AddCustomCategory.md)|Adiciona uma categoria personalizado à caixa de combinação de **Comandos** .|  
|`CMFCRibbonCustomizePropertyPage::CreateObject`|Usado pela estrutura dinâmica para criar uma instância de esse tipo da classe.|  
|`CMFCRibbonCustomizePropertyPage::GetThisClass`|Usado pela estrutura para obter um ponteiro para o objeto de [CRuntimeClass](../Topic/CRuntimeClass%20Structure.md) que está associado com esse tipo da classe.|  
|[CMFCRibbonCustomizePropertyPage::OnOK](../Topic/CMFCRibbonCustomizePropertyPage::OnOK.md)|Chamado pelo sistema quando um usuário clica **OK** na caixa de diálogo de **Personalizar** .|  
  
## Comentários  
 Se você deseja adicionar comandos personalizados a caixa de diálogo de **Personalizar** , você deve manipular a mensagem de AFX\_WM\_ON\_RIBBON\_CUSTOMIZE.  Em o manipulador de mensagem, criar uma instância de um objeto de `CMFCRibbonCustomizePropertyPage` na pilha.  Crie uma lista de comandos personalizados, e então chame `AddCustomCategory` para adicionar a nova página a caixa de diálogo de **Personalizar** .  
  
## Exemplo  
 O exemplo a seguir demonstra como criar um objeto de `CMFCRibbonCustomizePropertyPage` e adicionar uma categoria personalizada.  
  
 [!code-cpp[NVC_MFC_RibbonApp#22](../../mfc/reference/codesnippet/CPP/cmfcribboncustomizepropertypage-class_1.cpp)]  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 [CCmdTarget](../Topic/CCmdTarget%20Class.md)  
  
 [CWnd](../Topic/CWnd%20Class.md)  
  
 [CDialog](../../mfc/reference/cdialog-class.md)  
  
 [CPropertyPage](../../mfc/reference/cpropertypage-class.md)  
  
 [CMFCPropertyPage](../../mfc/reference/cmfcpropertypage-class.md)  
  
 [CMFCRibbonCustomizePropertyPage](../../mfc/reference/cmfcribboncustomizepropertypage-class.md)  
  
## Requisitos  
 **Cabeçalho:** afxribboncustomizedialog.h  
  
## Consulte também  
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes](../Topic/MFC%20Classes.md)