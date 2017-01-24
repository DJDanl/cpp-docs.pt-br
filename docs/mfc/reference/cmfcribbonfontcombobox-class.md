---
title: "Classe de CMFCRibbonFontComboBox | Microsoft Docs"
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
  - "CMFCRibbonFontComboBox"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CMFCRibbonFontComboBox"
ms.assetid: 33b4db50-df4f-45fa-8f05-2e6e73c31435
caps.latest.revision: 24
caps.handback.revision: 12
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CMFCRibbonFontComboBox
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Implementa uma caixa de combinação que contém uma lista de fontes.  Você pode colocar a caixa de combinação em um painel de faixa de opções.  
  
## Sintaxe  
  
```  
class CMFCRibbonFontComboBox : public CMFCRibbonComboBox  
```  
  
## Membros  
  
### Construtores Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|`CMFCRibbonFontComboBox::~CMFCRibbonFontComboBox`|Destruidor.|  
  
### Construtores Protegidos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CMFCRibbonFontComboBox::CMFCRibbonFontComboBox](../Topic/CMFCRibbonFontComboBox::CMFCRibbonFontComboBox.md)|Constrói e inicializa um objeto `CMFCRibbonFontComboBox`.|  
  
### Métodos Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CMFCRibbonFontComboBox::BuildFonts](../Topic/CMFCRibbonFontComboBox::BuildFonts.md)|Preenche a caixa de combinação da fonte da faixa de opções com as fontes do tipo de fonte especificada, o conjunto de caracteres e densidade e família.|  
|`CMFCRibbonFontComboBox::CreateObject`|Usado pelo framework para criar uma instância desse tipo de classe dinâmica.|  
|[CMFCRibbonFontComboBox::GetCharSet](../Topic/CMFCRibbonFontComboBox::GetCharSet.md)|Retorna o conjunto de caracteres especificado.|  
|[CMFCRibbonFontComboBox::GetFontDesc](../Topic/CMFCRibbonFontComboBox::GetFontDesc.md)||  
|[CMFCRibbonFontComboBox::GetFontType](../Topic/CMFCRibbonFontComboBox::GetFontType.md)|Retorna os tipos de fonte para exibir na caixa de combinação.  As opções válidas são DEVICE\_FONTTYPE, RASTER\_FONTTYPE e TRUETYPE\_FONTTYPE ou qualquer combinação bit a bit dele.|  
|[CMFCRibbonFontComboBox::GetPitchAndFamily](../Topic/CMFCRibbonFontComboBox::GetPitchAndFamily.md)|Retorna a distância e a família de fontes que são exibidos na caixa de combinação.|  
|`CMFCRibbonFontComboBox::GetThisClass`|Usado pelo framework para obter um ponteiro para o [CRuntimeClass](../Topic/CRuntimeClass%20Structure.md) objeto associado esse tipo de classe.|  
|[CMFCRibbonFontComboBox::RebuildFonts](../Topic/CMFCRibbonFontComboBox::RebuildFonts.md)|Preenche a caixa de combinação de fonte de faixa de opções com as fontes do tipo de fonte especificado anteriormente, o conjunto de caracteres e densidade e família.|  
|[CMFCRibbonFontComboBox::SetFont](../Topic/CMFCRibbonFontComboBox::SetFont.md)|Seleciona a fonte especificada na caixa de combinação.|  
  
## Comentários  
 Depois de criar um `CMFCRibbonFontComboBox` de objeto, adicioná\-lo a um painel de faixa de opções chamando [CMFCRibbonPanel::Add](../Topic/CMFCRibbonPanel::Add.md).  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 [CMFCRibbonBaseElement](../../mfc/reference/cmfcribbonbaseelement-class.md)  
  
 [CMFCRibbonButton](../../mfc/reference/cmfcribbonbutton-class.md)  
  
 [CMFCRibbonEdit](../../mfc/reference/cmfcribbonedit-class.md)  
  
 [CMFCRibbonComboBox](../../mfc/reference/cmfcribboncombobox-class.md)  
  
 [CMFCRibbonFontComboBox](../../mfc/reference/cmfcribbonfontcombobox-class.md)  
  
## Requisitos  
 **Cabeçalho:** afxRibbonComboBox.h  
  
## Consulte também  
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes](../Topic/MFC%20Classes.md)   
 [Classe de CMFCRibbonComboBox](../../mfc/reference/cmfcribboncombobox-class.md)