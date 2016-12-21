---
title: "Classe de CMFCCustomColorsPropertyPage | Microsoft Docs"
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
  - "CMFCCustomColorsPropertyPage"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CMFCCustomColorsPropertyPage"
ms.assetid: 46a45ba2-1fda-440d-8018-d4dcd44f5816
caps.latest.revision: 23
caps.handback.revision: 11
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CMFCCustomColorsPropertyPage
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Representa uma página de propriedades que pode selecionar cores personalizadas em uma caixa de diálogo de cor.  
  
## Sintaxe  
  
```  
class CMFCCustomColorsPropertyPage : public CPropertyPage  
```  
  
## Membros  
  
### Construtores public  
  
|||  
|-|-|  
|Nome|Descrição|  
|`CMFCCustomColorsPropertyPage::CMFCCustomColorsPropertyPage`|Construtor padrão.|  
  
### Métodos públicos  
  
|||  
|-|-|  
|Nome|Descrição|  
|`CMFCCustomColorsPropertyPage::CreateObject`|Usado pela estrutura dinâmica para criar uma instância de esse tipo da classe.|  
|`CMFCCustomColorsPropertyPage::GetThisClass`|Usado pela estrutura para obter um ponteiro para o objeto de [CRuntimeClass](../Topic/CRuntimeClass%20Structure.md) que está associado com esse tipo da classe.|  
|[CMFCCustomColorsPropertyPage::Setup](../Topic/CMFCCustomColorsPropertyPage::Setup.md)|Defina os componentes a cor da página de propriedades.|  
  
### Comentários  
 A classe de `CMFCColorDialog` usar esta classe para exibir a página de propriedades de cores personalizado.  Para obter mais informações sobre o `CMFCColorDialog`, consulte [Classe de CMFCColorDialog](../../mfc/reference/cmfccolordialog-class.md).  
  
## Exemplo  
 O exemplo a seguir demonstra como criar um objeto de `CMFCCustomColorsPropertyPage` e definir os componentes a cor da página de propriedades.  
  
 [!code-cpp[NVC_MFC_RibbonApp#35](../../mfc/reference/codesnippet/CPP/cmfccustomcolorspropertypage-class_1.cpp)]  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 [CCmdTarget](../Topic/CCmdTarget%20Class.md)  
  
 [CWnd](../Topic/CWnd%20Class.md)  
  
 [CDialog](../../mfc/reference/cdialog-class.md)  
  
 [CPropertyPage](../../mfc/reference/cpropertypage-class.md)  
  
 [CMFCCustomColorsPropertyPage](../../mfc/reference/cmfccustomcolorspropertypage-class.md)  
  
## Requisitos  
 **Cabeçalho:** afxcustomcolorspropertypage.h  
  
## Consulte também  
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes](../Topic/MFC%20Classes.md)   
 [Classe de CMFCColorDialog](../../mfc/reference/cmfccolordialog-class.md)   
 [Classe de CMFCStandardColorsPropertyPage](../../mfc/reference/cmfcstandardcolorspropertypage-class.md)