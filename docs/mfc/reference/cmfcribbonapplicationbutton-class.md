---
title: "Classe de CMFCRibbonApplicationButton | Microsoft Docs"
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
  - "CMFCRibbonApplicationButton"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CMFCRibbonApplicationButton"
ms.assetid: beb81757-fabd-4641-9130-876ba8505b78
caps.latest.revision: 25
caps.handback.revision: 13
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CMFCRibbonApplicationButton
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Implementa um botão especial localizado no canto superior esquerdo da janela do aplicativo.  Quando clicado, o botão abrir um menu que contém geralmente comandos comuns de **Arquivo** como **Abrir**, **Salvar**, e **Sair**.  
  
## Sintaxe  
  
```  
class CMFCRibbonApplicationButton : public CMFCRibbonButton  
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CMFCRibbonApplicationButton::CMFCRibbonApplicationButton](../Topic/CMFCRibbonApplicationButton::CMFCRibbonApplicationButton.md)|As compilações e inicializam um objeto de `CMFCRibbonApplicationButton` .|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|`CMFCRibbonApplicationButton::CreateObject`|Usado pela estrutura dinâmica para criar uma instância de esse tipo da classe.|  
|`CMFCRibbonApplicationButton::GetThisClass`|Usado pela estrutura para obter um ponteiro para o objeto de [CRuntimeClass](../Topic/CRuntimeClass%20Structure.md) que está associado com esse tipo da classe.|  
|[CMFCRibbonApplicationButton::SetImage](../Topic/CMFCRibbonApplicationButton::SetImage.md)|Define uma imagem para o botão do aplicativo de fita.|  
  
## Exemplo  
 O exemplo a seguir demonstra como usar vários métodos na classe de `CMFCRibbonApplicationButton` .  O exemplo a seguir mostra como atribuir uma imagem para o botão do aplicativo, e como definir sua dica de ferramenta.  Este trecho de código é parte de [Exemplo do cliente de desenho](../../top/visual-cpp-samples.md).  
  
 [!code-cpp[NVC_MFC_DrawClient#4](../../mfc/reference/codesnippet/CPP/cmfcribbonapplicationbutton-class_1.h)]  
[!code-cpp[NVC_MFC_DrawClient#5](../../mfc/reference/codesnippet/CPP/cmfcribbonapplicationbutton-class_2.cpp)]  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 [CMFCRibbonBaseElement](../../mfc/reference/cmfcribbonbaseelement-class.md)  
  
 [CMFCRibbonButton](../../mfc/reference/cmfcribbonbutton-class.md)  
  
 [CMFCRibbonApplicationButton](../../mfc/reference/cmfcribbonapplicationbutton-class.md)  
  
## Requisitos  
 **Cabeçalho:** afxRibbonBar.h  
  
## Consulte também  
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes](../Topic/MFC%20Classes.md)   
 [Classe de CMFCRibbonButton](../../mfc/reference/cmfcribbonbutton-class.md)