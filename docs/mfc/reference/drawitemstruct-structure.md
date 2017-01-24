---
title: "Estrutura DRAWITEMSTRUCT | Microsoft Docs"
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
  - "DRAWITEMSTRUCT"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Estrutura DRAWITEMSTRUCT"
ms.assetid: ba9ef1d4-aebb-45e9-b956-4b81a02e50f7
caps.latest.revision: 11
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Estrutura DRAWITEMSTRUCT
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

A estrutura de `DRAWITEMSTRUCT` fornece informações que a janela do proprietário deve ter para determinar como pintar um controle ou item de menu proprietário\- desenhado.  
  
## Sintaxe  
  
```  
  
      typedef struct tagDRAWITEMSTRUCT {  
   UINT CtlType;  
   UINT CtlID;  
   UINT itemID;  
   UINT itemAction;  
   UINT itemState;  
   HWND hwndItem;  
   HDC hDC;  
   RECT rcItem;  
   DWORD itemData;  
} DRAWITEMSTRUCT;  
```  
  
#### Parâmetros  
 `CtlType`  
 O tipo do controle.  Os valores para tipos de controle são os seguintes:  
  
-   Botão Proprietário\-desenhado**ODT\_BUTTON**  
  
-   A caixa de combinação Proprietário\- desenhada**ODT\_COMBOBOX**  
  
-   Caixa de listagem Proprietário\-desenhada**ODT\_LISTBOX**  
  
-   Menu Proprietário\-desenhado**ODT\_MENU**  
  
-   Controle de exibição de lista de**ODT\_LISTVIEW**  
  
-   Controle estático Proprietário\-desenhado**ODT\_STATIC**  
  
-   Controle de guia de**ODT\_TAB**  
  
 `CtlID`  
 A ID de O controle para uma caixa de combinação, uma caixa de listagem, ou um botão.  Esse membro não é usado para um menu.  
  
 `itemID`  
 A ID de O item de menu para um menu ou o índice do item em uma caixa de listagem ou em uma caixa de combinação.  Para uma caixa de listagem ou uma caixa de combinação vazia, esse membro é um valor negativo, que permita o aplicativo desenhar apenas o retângulo de foco em coordenadas especificadas pelo membro de **rcItem** mesmo que não haja nenhum item no controle.  O usuário pode então ser mostrado se a caixa de listagem ou a caixa de combinação tiver o foco de entrada.  A configuração de bit no membro de **itemAction** determina se o retângulo deve ser desenhado como se a caixa de listagem ou a caixa de combinação registrados no foco.  
  
 `itemAction`  
 Define a ação de desenho necessária.  Esse será um ou mais dos seguintes: bit  
  
-   **ODA\_DRAWENTIRE** este bit é definido quando as necessidades de controle inteiras de ser desenhado.  
  
-   **ODA\_FOCUS** este bit é definido quando o controle vence ou perder o foco de entrada.  O membro de **itemState** deve ser verificada para determinar se o controle que tem o foco.  
  
-   **ODA\_SELECT** este bit é definido quando apenas o status de seleção for alterada.  O membro de **itemState** deve ser verificado para determinar o novo estado de seleção.  
  
 *itemState*  
 Especifica o estado visual do item depois que a ação atual de desenho ocorre.  Ou seja, se um item de menu deverá ser esmaecido, o sinalizador **ODS\_GRAYED** de estado será definido.  Os sinalizadores de estado são os seguintes:  
  
-   **ODS\_CHECKED** este bit é definido como se o item de menu deverá ser verificado.  Esse bit é usado somente em um menu.  
  
-   **ODS\_DISABLED** este bit é definido como se o item deve ser desenhado como desabilitado.  
  
-   **ODS\_FOCUS** este bit é definido como se o item está conectado o foco.  
  
-   **ODS\_GRAYED** este bit é definido como se o item deve ser esmaecido.  Esse bit é usado somente em um menu.  
  
-   **ODS\_SELECTED** este bit é definido como se o status do item selecionado.  
  
-   **ODS\_COMBOBOXEDIT** o desenho ocorre no campo de seleção \(controle de edição\) de uma caixa de combinação de ownerdrawn.  
  
-   **ODS\_DEFAULT** o item é o item padrão.  
  
 `hwndItem`  
 Especifica o identificador de janela de controle para caixas de combinação, caixas de listagem, os botões e.  Especifica o identificador do menu \(`HMENU`\) que contém o item de menu.  
  
 `hDC`  
 Identifica um contexto do dispositivo.  Esse contexto de dispositivo deve ser usado ao executar operações de desenho no controle.  
  
 *rcItem*  
 Um retângulo no contexto do dispositivo especificado pelo membro de `hDC` que define os limites do controle a ser desenhado.  As janelas recortam automaticamente qualquer coisa que o proprietário desenha no contexto de dispositivo para caixas de combinação, caixas de listagem, e botões, mas não diminuísse itens de menu.  Ao chamar itens de menu, o proprietário não deve chamar fora do retângulo definido pelo membro de **rcItem** .  
  
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
  
## Comentários  
 A janela do proprietário do controle ou do item de menu proprietário\- desenhado recebe um ponteiro a essa estrutura como o parâmetro de `lParam` da mensagem de `WM_DRAWITEM` .  
  
## Requisitos  
 **Header:** winuser.h  
  
## Consulte também  
 [Estruturas, estilos, retornos de chamada e mapas de mensagem](../../mfc/reference/structures-styles-callbacks-and-message-maps.md)   
 [CWnd::OnDrawItem](../Topic/CWnd::OnDrawItem.md)