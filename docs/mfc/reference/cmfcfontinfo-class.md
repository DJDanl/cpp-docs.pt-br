---
title: "Classe de CMFCFontInfo | Microsoft Docs"
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
  - "CMFCFontInfo"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CMFCFontInfo"
  - "Construtor de CMFCFontInfo::CMFCFontInfo"
ms.assetid: f88329b2-d74e-4921-9441-a3bb6536a049
caps.latest.revision: 26
caps.handback.revision: 14
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CMFCFontInfo
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

a classe de `CMFCFontInfo` descreve o nome e outros atributos de uma fonte.  
  
## Sintaxe  
  
```  
class CMFCFontInfo : public CObject  
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|`CMFCFontInfo`|Constrói um objeto de `CMFCFontInfo` .|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CMFCFontInfo::GetFullName](../Topic/CMFCFontInfo::GetFullName.md)|Recupera os nomes concatenados de uma fonte e seu conjunto de caracteres \(script\).|  
  
### Membros de dados  
  
|Nome|Descrição|  
|----------|---------------|  
|[CMFCFontInfo::m\_nCharSet](../Topic/CMFCFontInfo::m_nCharSet.md)|Um valor que especifica o conjunto de caracteres \(script\) associado com a fonte.|  
|[CMFCFontInfo::m\_nPitchAndFamily](../Topic/CMFCFontInfo::m_nPitchAndFamily.md)|Um valor que especifica densidade e a família de fontes.|  
|[CMFCFontInfo::m\_nType](../Topic/CMFCFontInfo::m_nType.md)|Um valor que especifica o tipo da fonte.|  
|[CMFCFontInfo::m\_strName](../Topic/CMFCFontInfo::m_strName.md)|O nome da fonte; por exemplo, **Arial**.|  
|[CMFCFontInfo::m\_strScript](../Topic/CMFCFontInfo::m_strScript.md)|o nome de um conjunto de caracteres \(script\) associado com a fonte.|  
  
## Comentários  
 Você pode anexar um objeto de `CMFCFontInfo` a um item da classe de [Classe de CMFCToolBarFontComboBox](../../mfc/reference/cmfctoolbarfontcombobox-class.md) .  Chame o método de [CMFCToolBarFontComboBox::GetFontDesc](../Topic/CMFCToolBarFontComboBox::GetFontDesc.md) para recuperar um ponteiro para um objeto de `CMFCFontInfo` .  
  
## Exemplo  
 O exemplo seguinte demonstra como usar mais membros da classe de `CMFCFontInfo` .  O exemplo a seguir demonstra como obter um objeto de `CMFCFontInfo` de `CMFCRibbonFontComboBox`, e como acessar suas variáveis locais.  Este exemplo é parte de [Exemplo 2007 de demonstração de MSOffice](../../top/visual-cpp-samples.md).  
  
 [!CODE [NVC_MFC_MSOffice2007Demo#6](../CodeSnippet/VS_Snippets_Misc/NVC_MFC_MSOffice2007Demo#6)]  
  
## Requisitos  
 **Cabeçalho:** afxtoolbarfontcombobox.h  
  
## Consulte também  
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes](../Topic/MFC%20Classes.md)   
 [Classe de CMFCToolBarFontComboBox](../../mfc/reference/cmfctoolbarfontcombobox-class.md)   
 [Classe de CMFCToolBarFontSizeComboBox](../../mfc/reference/cmfctoolbarfontsizecombobox-class.md)