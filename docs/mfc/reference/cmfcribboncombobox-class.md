---
title: "Classe de CMFCRibbonComboBox | Microsoft Docs"
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
  - "CMFCRibbonComboBox"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CMFCRibbonComboBox"
ms.assetid: 9b29a6a4-cf17-4152-9b13-0bf90784b30d
caps.latest.revision: 35
caps.handback.revision: 23
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CMFCRibbonComboBox
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

A classe de `CMFCRibbonComboBox` implementa um controle caixa de combinação que você pode adicionar a barra de fita, um painel de fita, ou a um menu pop\-up de fita.  
  
## Sintaxe  
  
```  
class CMFCRibbonComboBox : public CMFCRibbonEdit  
```  
  
## Membros  
  
### Construtores  
  
|Nome|Descrição|  
|----------|---------------|  
|[CMFCRibbonComboBox::CMFCRibbonComboBox](../Topic/CMFCRibbonComboBox::CMFCRibbonComboBox.md)|Constrói um objeto de CMFCRibbonComboBox.|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CMFCRibbonComboBox::AddItem](../Topic/CMFCRibbonComboBox::AddItem.md)|Adiciona um item exclusivo a caixa de listagem.|  
|[CMFCRibbonComboBox::DeleteItem](../Topic/CMFCRibbonComboBox::DeleteItem.md)|Exclui um item específico da caixa de listagem.|  
|[CMFCRibbonComboBox::EnableDropDownListResize](../Topic/CMFCRibbonComboBox::EnableDropDownListResize.md)|Especifica se a caixa de listagem pode alterar o tamanho quando se soltar para baixo.|  
|[CMFCRibbonComboBox::FindItem](../Topic/CMFCRibbonComboBox::FindItem.md)|Retorna o índice do primeiro item na caixa de seleção que corresponde uma cadeia de caracteres especificada.|  
|[CMFCRibbonComboBox::GetCount](../Topic/CMFCRibbonComboBox::GetCount.md)|Retorna o número de itens na caixa de listagem.|  
|[CMFCRibbonComboBox::GetCurSel](../Topic/CMFCRibbonComboBox::GetCurSel.md)|Obtém o índice do item atualmente selecionado na caixa de listagem.|  
|[CMFCRibbonComboBox::GetDropDownHeight](../Topic/CMFCRibbonComboBox::GetDropDownHeight.md)|Obtém a altura da caixa de listagem quando a caixa de listagem é descartada para baixo.|  
|[CMFCRibbonComboBox::GetIntermediateSize](../Topic/CMFCRibbonComboBox::GetIntermediateSize.md)|Retorna o tamanho da caixa de combinação como mostrado no modo intermediária.|  
|[CMFCRibbonComboBox::GetItem](../Topic/CMFCRibbonComboBox::GetItem.md)|Retorna a cadeia de caracteres associada a um item em um índice especificado na caixa de listagem.|  
|[CMFCRibbonComboBox::GetItemData](../Topic/CMFCRibbonComboBox::GetItemData.md)|Retorna os dados associados com um item em um índice especificado na caixa de listagem.|  
|[CMFCRibbonComboBox::HasEditBox](../Topic/CMFCRibbonComboBox::HasEditBox.md)|Indica se o controle contém uma caixa de edição.|  
|[CMFCRibbonComboBox::IsResizeDropDownList](../Topic/CMFCRibbonComboBox::IsResizeDropDownList.md)|Indica se a caixa de listagem pode ser redimensionada.|  
|[CMFCRibbonComboBox::OnSelectItem](../Topic/CMFCRibbonComboBox::OnSelectItem.md)|Chamado pela estrutura quando o usuário seleciona um item na caixa de listagem.|  
|[CMFCRibbonComboBox::RemoveAllItems](../Topic/CMFCRibbonComboBox::RemoveAllItems.md)|Exclui todos os itens da caixa de listagem e desmarque a caixa de edição.|  
|[CMFCRibbonComboBox::SelectItem](../Topic/CMFCRibbonComboBox::SelectItem.md)|Seleciona um item na caixa de listagem.|  
|[CMFCRibbonComboBox::SetDropDownHeight](../Topic/CMFCRibbonComboBox::SetDropDownHeight.md)|Defina a altura da caixa de listagem quando é descartada para baixo.|  
  
## Comentários  
 A caixa de combinação de fita consiste em uma caixa de lista combinada com um rótulo estático ou o rótulo que podem ser editadas pelo usuário.  Você deve especificar o tipo que desejam quando você cria sua caixa de combinação de fita.  
  
## Exemplo  
 O exemplo a seguir demonstra como criar um objeto da classe de `CMFCRibbonComboBox` , adicionar um item à caixa de combinação, selecione um item na caixa de combinação, e adicionar uma caixa de combinação a um painel.  
  
 [!code-cpp[NVC_MFC_RibbonApp#11](../../mfc/reference/codesnippet/CPP/cmfcribboncombobox-class_1.cpp)]  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 [CMFCRibbonBaseElement](../../mfc/reference/cmfcribbonbaseelement-class.md)  
  
 [CMFCRibbonButton](../../mfc/reference/cmfcribbonbutton-class.md)  
  
 [CMFCRibbonEdit](../../mfc/reference/cmfcribbonedit-class.md)  
  
 [CMFCRibbonComboBox](../../mfc/reference/cmfcribboncombobox-class.md)  
  
## Requisitos  
 **Cabeçalho:** afxribboncombobox.h  
  
## Consulte também  
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes](../Topic/MFC%20Classes.md)   
 [Classe de CMFCRibbonEdit](../../mfc/reference/cmfcribbonedit-class.md)