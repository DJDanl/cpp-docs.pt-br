---
title: "Classe de CMFCPropertyPage | Microsoft Docs"
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
  - "CMFCPropertyPage"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CMFCPropertyPage"
  - "Método de CMFCPropertyPage::CreateObject"
  - "Método de CMFCPropertyPage::OnSetActive"
  - "Método de CMFCPropertyPage::PreTranslateMessage"
ms.assetid: d279d7f2-2d81-418d-9f23-6147d6e8df09
caps.latest.revision: 30
caps.handback.revision: 18
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CMFCPropertyPage
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

A classe de `CMFCPropertyPage` oferece suporte a exibição do menu pop\-up em uma página de propriedades.  
  
## Sintaxe  
  
```  
class CMFCPropertyPage : public CPropertyPage  
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CMFCPropertyPage::CMFCPropertyPage](../Topic/CMFCPropertyPage::CMFCPropertyPage.md)|Constrói um objeto de `CMFCPropertyPage` .|  
|`CMFCPropertyPage::~CMFCPropertyPage`|Destruidor.|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|`CMFCPropertyPage::CreateObject`|Usado pela estrutura dinâmica para criar uma instância de esse tipo da classe.|  
|`CMFCPropertyPage::GetThisClass`|Usado pela estrutura para obter um ponteiro para o objeto de [CRuntimeClass](../Topic/CRuntimeClass%20Structure.md) que está associado com esse tipo da classe.|  
|`CMFCPropertyPage::OnSetActive`|Essa função de membro é chamada pela estrutura quando a página é escolhida pelo usuário e as transformações a página.  Overrides \( [CPropertyPage::OnSetActive](../Topic/CPropertyPage::OnSetActive.md).\)|  
|`CMFCPropertyPage::PreTranslateMessage`|Converte mensagens de janela antes que são distribuídos funções do windows de [TranslateMessage](http://msdn.microsoft.com/library/windows/desktop/ms644955) e de [DispatchMessage](http://msdn.microsoft.com/library/windows/desktop/ms644934) .  Para mais informações e sintaxe do método, consulte [CWnd::PreTranslateMessage](../Topic/CWnd::PreTranslateMessage.md).  Overrides \( `CPropertyPage::PreTranslateMessage`.\)|  
  
## Comentários  
 A classe de `CMFCPropertyPage` representa as páginas individuais de uma folha de propriedades, se não conhecido como uma caixa de diálogo de tabulação.  
  
 Use a classe de `CMFCPropertyPage` juntamente com a classe de [CMFCPropertySheet](../../mfc/reference/cmfcpropertysheet-class.md) .  Para usar menus em uma página de propriedades, substitua todas as ocorrências da classe de `CPropertyPage` com a classe de `CMFCPropertyPage` .  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 [CCmdTarget](../Topic/CCmdTarget%20Class.md)  
  
 [CWnd](../Topic/CWnd%20Class.md)  
  
 [CDialog](../../mfc/reference/cdialog-class.md)  
  
 [CPropertyPage](../../mfc/reference/cpropertypage-class.md)  
  
 [CMFCPropertyPage](../../mfc/reference/cmfcpropertypage-class.md)  
  
## Requisitos  
 **Cabeçalho:** afxpropertypage.h  
  
## Consulte também  
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes](../Topic/MFC%20Classes.md)   
 [Classe de CMFCPropertySheet](../../mfc/reference/cmfcpropertysheet-class.md)