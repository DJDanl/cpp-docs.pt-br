---
title: "Estrutura DELETEITEMSTRUCT | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "DELETEITEMSTRUCT"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Estrutura DELETEITEMSTRUCT"
ms.assetid: 48d3998c-f4a8-402a-bf90-df3770a78685
caps.latest.revision: 13
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Estrutura DELETEITEMSTRUCT
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

A estrutura de `DELETEITEMSTRUCT` descreve um item excluído proprietário\- desenhado na caixa de listagem ou na caixa de combinação.  
  
## Sintaxe  
  
```  
  
      typedef struct tagDELETEITEMSTRUCT { /* ditms */  
    UINT CtlType;  
    UINT CtlID;  
    UINT itemID;  
    HWND hwndItem;  
    UINT itemData;  
} DELETEITEMSTRUCT;  
```  
  
#### Parâmetros  
 `CtlType`  
 Especifica **ODT\_LISTBOX** \(uma caixa de listagem proprietário\- desenhada\) ou \( **ODT\_COMBOBOX** uma caixa de combinação proprietário\- desenhada\).  
  
 `CtlID`  
 Especifica o identificador da caixa de listagem ou na caixa de combinação.  
  
 `itemID`  
 Especifica o índice do item na caixa de listagem ou na caixa de combinação que estão sendo descartadas.  
  
 `hwndItem`  
 Identifica o controle.  
  
 `itemData`  
 Especifica definidas por dados para o item.  Esse valor é passado ao controle do parâmetro de **lParam** de mensagem que adiciona o item à caixa de listagem ou à caixa de combinação.  
  
## Comentários  
 Quando um item é removido da caixa de listagem ou na caixa de combinação ou quando a caixa de listagem ou a caixa de combinação são destruídas, o envia a mensagem de `WM_DELETEITEM` o proprietário de cada item excluído.  O parâmetro de **lParam** da mensagem contém um ponteiro a essa estrutura.  
  
## Requisitos  
 **Header:** atldbcli.h  
  
## Consulte também  
 [Estruturas, estilos, retornos de chamada e mapas de mensagem](../../mfc/reference/structures-styles-callbacks-and-message-maps.md)   
 [CWnd::OnDeleteItem](../Topic/CWnd::OnDeleteItem.md)