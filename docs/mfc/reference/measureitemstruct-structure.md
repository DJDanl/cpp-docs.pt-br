---
title: "Estrutura MEASUREITEMSTRUCT | Microsoft Docs"
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
  - "MEASUREITEMSTRUCT"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Estrutura MEASUREITEMSTRUCT"
ms.assetid: d141ace4-47cb-46b5-a81c-ad2c5e5a8501
caps.latest.revision: 11
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Estrutura MEASUREITEMSTRUCT
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

A estrutura de `MEASUREITEMSTRUCT` informa o windows de dimensões de um controle ou de um item de menu proprietário\- desenhado.  
  
## Sintaxe  
  
```  
  
      typedef struct tagMEASUREITEMSTRUCT {  
   UINT CtlType;  
   UINT CtlID;  
   UINT itemID;  
   UINT itemWidth;  
   UINT itemHeight;  
   DWORD itemData  
} MEASUREITEMSTRUCT;  
```  
  
#### Parâmetros  
 `CtlType`  
 Contém o tipo do controle.  Os valores para tipos de controle são os seguintes:  
  
-   A caixa de combinação de Proprietário\- descompasso de**ODT\_COMBOBOX**  
  
-   Caixa de listagem da Proprietário\- descompasso de**ODT\_LISTBOX**  
  
-   O menu de Proprietário\- descompasso de**ODT\_MENU**  
  
 `CtlID`  
 Contém a ID do controle para uma caixa de combinação, uma caixa de listagem, ou um botão.  Esse membro não é usado para um menu.  
  
 `itemID`  
 Contém a ID do item de menu para um menu ou a ID do item lista\-caixa\- para uma caixa de combinação ou caixa de listagem de variáveis altura.  Esse membro não é usado para uma caixa de combinação ou caixa de listagem a altitude fixa, ou para um botão.  
  
 *itemWidth*  
 Especifica a largura de um item de menu.  O proprietário do item de menu de proprietário\- desenhe o deve preencher esse membro antes de retornar da mensagem.  
  
 *itemHeight*  
 Especifica a altitude de um item individual em uma caixa de listagem ou em um menu.  Antes de retornar da mensagem, o proprietário da caixa de combinação, na caixa de listagem, ou do item de menu de proprietário\- descompasso deve completar este membro.  A altura máxima de um item de caixa de listagem é 255.  
  
 `itemData`  
 Para uma caixa de combinação ou caixa de listagem, esse membro contém o valor passado para a caixa de listagem por um dos seguintes:  
  
-   [CComboBox::AddString](../Topic/CComboBox::AddString.md)  
  
-   [CComboBox::InsertString](../Topic/CComboBox::InsertString.md)  
  
-   [CListBox::AddString](../Topic/CListBox::AddString.md)  
  
-   [CListBox::InsertString](../Topic/CListBox::InsertString.md)  
  
 Para um menu, esse membro contém o valor passado ao menu por um dos seguintes:  
  
-   [CMenu::AppendMenu](../Topic/CMenu::AppendMenu.md)  
  
-   [CMenu::InsertMenu](../Topic/CMenu::InsertMenu.md)  
  
-   [CMenu::ModifyMenu](../Topic/CMenu::ModifyMenu.md)  
  
 Isso permite que o processe a interação do usuário com o controle corretamente.  A falha completar os membros apropriados na estrutura de `MEASUREITEMSTRUCT` fará com que o funcionamento inadequado do controle.  
  
## Requisitos  
 **Header:** winuser.h  
  
## Consulte também  
 [Estruturas, estilos, retornos de chamada e mapas de mensagem](../../mfc/reference/structures-styles-callbacks-and-message-maps.md)   
 [CWnd::OnMeasureItem](../Topic/CWnd::OnMeasureItem.md)