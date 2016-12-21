---
title: "Classe de CMFCRibbonCustomizeDialog | Microsoft Docs"
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
  - "CMFCRibbonCustomizeDialog"
  - "~CMFCRibbonCustomizeDialog"
  - "CMFCRibbonCustomizeDialog::GetThisClass"
  - "CMFCRibbonCustomizeDialog.~CMFCRibbonCustomizeDialog"
  - "CMFCRibbonCustomizeDialog.GetThisClass"
  - "CMFCRibbonCustomizeDialog::~CMFCRibbonCustomizeDialog"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Destruidor de ~CMFCRibbonCustomizeDialog"
  - "Classe de CMFCRibbonCustomizeDialog"
  - "Classe de CMFCRibbonCustomizeDialog, destruidor"
  - "Método de GetThisClass"
ms.assetid: ce67de7f-5eaa-4c75-9b94-f290f36df073
caps.latest.revision: 22
caps.handback.revision: 11
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CMFCRibbonCustomizeDialog
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Exibe a página de **Personalizar** de fita.  
  
## Sintaxe  
  
```  
class CMFCRibbonCustomizeDialog : public CMFCPropertySheet  
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CMFCRibbonCustomizeDialog::CMFCRibbonCustomizeDialog](../Topic/CMFCRibbonCustomizeDialog::CMFCRibbonCustomizeDialog.md)|Constrói um objeto de `CMFCRibbonCustomizeDialog` .|  
|`CMFCRibbonCustomizeDialog::~CMFCRibbonCustomizeDialog`|Destruidor.|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|`CMFCRibbonCustomizeDialog::GetThisClass`|Usado pela estrutura para obter um ponteiro para o objeto de [CRuntimeClass](../Topic/CRuntimeClass%20Structure.md) que está associado com esse tipo da classe.|  
  
## Comentários  
 O MFC cria uma instância de esta classe automaticamente se você não processa a mensagem de AFX\_WM\_ON\_RIBBON\_CUSTOMIZE, ou se você retorna 0 do manipulador de mensagem.  
  
 Se você desejar usar esta classe em seu aplicativo para exibir a caixa de diálogo de **Personalizar** de fita, e assim criar\-la uma instância chama o método de `DoModal` .  
  
 Como essa classe é derivada de [Classe de CMFCPropertySheet](../../mfc/reference/cmfcpropertysheet-class.md), você pode adicionar páginas personalizadas usando `CMFCPropertySheet` API.  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 [CCmdTarget](../Topic/CCmdTarget%20Class.md)  
  
 [CWnd](../Topic/CWnd%20Class.md)  
  
 [CPropertySheet](../../mfc/reference/cpropertysheet-class.md)  
  
 [CMFCPropertySheet](../../mfc/reference/cmfcpropertysheet-class.md)  
  
 [CMFCRibbonCustomizeDialog](../../mfc/reference/cmfcribboncustomizedialog-class.md)  
  
## Requisitos  
 **Cabeçalho:** afxribboncustomizedialog.h  
  
## Consulte também  
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes](../Topic/MFC%20Classes.md)