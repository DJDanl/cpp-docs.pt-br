---
title: "Classe de CMFCRibbonUndoButton | Microsoft Docs"
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
  - "CMFCRibbonUndoButton"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CMFCRibbonUndoButton"
ms.assetid: 5c42adf7-871d-4239-901e-47ae7fb816fc
caps.latest.revision: 35
caps.handback.revision: 23
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CMFCRibbonUndoButton
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

A classe de `CMFCRibbonUndoButton` implementa um botão da lista suspensa que contém os comandos os mais recentes do usuário.  Os usuários podem selecionar um ou mais dos comandos os mais recentes da lista suspensa refazer\-los ou desfazer\-l.  
  
## Sintaxe  
  
```  
class CMFCRibbonUndoButton : public CMFCRibbonGallery  
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CMFCRibbonUndoButton::CMFCRibbonUndoButton](../Topic/CMFCRibbonUndoButton::CMFCRibbonUndoButton.md)|Constrói um novo objeto de `CMFCRibbonUndoButton` usando a ID de comando que você especifica o rótulo, texto e imagens da lista de imagem do objeto pai.|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CMFCRibbonUndoButton::AddUndoAction](../Topic/CMFCRibbonUndoButton::AddUndoAction.md)|Adiciona um novo à lista de ação ações.|  
|[CMFCRibbonUndoButton::CleanUpUndoList](../Topic/CMFCRibbonUndoButton::CleanUpUndoList.md)|Limpa a lista de ação, que é a lista suspensa.|  
|[CMFCRibbonUndoButton::GetActionNumber](../Topic/CMFCRibbonUndoButton::GetActionNumber.md)|Determina o número de itens que um usuário tiver selecionado na lista suspensa.|  
|[CMFCRibbonUndoButton::HasMenu](../Topic/CMFCRibbonUndoButton::HasMenu.md)|Indica se o objeto contém um menu.|  
  
## Comentários  
 a classe de `CMFCRibbonUndoButton` usa uma pilha para representar a lista suspensa.  
  
## Exemplo  
 O exemplo a seguir demonstra como criar um objeto da classe de `CMFCRibbonUndoButton` , e adicione uma nova ação à lista de ações.  Este trecho de código é parte de [Exemplo de gadget de fita](../../top/visual-cpp-samples.md).  
  
 [!code-cpp[NVC_MFC_RibbonGadgets#2](../../mfc/reference/codesnippet/CPP/cmfcribbonundobutton-class_1.cpp)]  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 [CMFCRibbonBaseElement](../../mfc/reference/cmfcribbonbaseelement-class.md)  
  
 [CMFCRibbonButton](../../mfc/reference/cmfcribbonbutton-class.md)  
  
 [CMFCRibbonGallery](../../mfc/reference/cmfcribbongallery-class.md)  
  
 [CMFCRibbonUndoButton](../../mfc/reference/cmfcribbonundobutton-class.md)  
  
## Requisitos  
 **Cabeçalho:** afxribbonundobutton.h  
  
## Consulte também  
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes](../Topic/MFC%20Classes.md)   
 [Classe de CMFCRibbonGallery](../../mfc/reference/cmfcribbongallery-class.md)   
 [Classe de CMFCRibbonButton](../../mfc/reference/cmfcribbonbutton-class.md)