---
title: Estrutura DRAWITEMSTRUCT | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- DRAWITEMSTRUCT
dev_langs:
- C++
helpviewer_keywords:
- DRAWITEMSTRUCT structure
ms.assetid: ba9ef1d4-aebb-45e9-b956-4b81a02e50f7
caps.latest.revision: 11
author: mikeblome
ms.author: mblome
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
ms.translationtype: Machine Translation
ms.sourcegitcommit: 040985df34f2613b4e4fae29498721aef15d50cb
ms.openlocfilehash: bd47b12f6401cb6603855fa153fe268bfe68914c
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="drawitemstruct-structure"></a>Estrutura DRAWITEMSTRUCT
O `DRAWITEMSTRUCT` estrutura fornece informações sobre a janela do proprietário deve ter para determinar como pintar um item de menu ou controle de desenho proprietário.  
  
## <a name="syntax"></a>Sintaxe  
  
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
  
#### <a name="parameters"></a>Parâmetros  
 `CtlType`  
 O tipo de controle. Os valores para os tipos de controle são da seguinte maneira:  
  
- **ODT_BUTTON** botão de desenho proprietário  
  
- **ODT_COMBOBOX** caixa de combinação do desenho proprietário  
  
- **ODT_LISTBOX** caixa de listagem de desenho proprietário  
  
- **ODT_MENU** menus de desenho proprietário  
  
- **ODT_LISTVIEW** controle de exibição de lista  
  
- **ODT_STATIC** controle estático desenhados pelo proprietário  
  
- **ODT_TAB** controle guia  
  
 `CtlID`  
 A ID do controle de botão, caixa de listagem ou caixa de combinação. Este membro não é usado em um menu.  
  
 `itemID`  
 A ID do item de menu para um menu ou o índice do item em uma caixa de listagem ou caixa de combinação. Para uma caixa de listagem vazios ou caixa de combinação, esse membro é um valor negativo, o que permite que o aplicativo desenhar o retângulo de foco em coordenadas especificadas pelo **rcItem** membro mesmo se não houver nenhum item no controle. O usuário pode ser mostrado, portanto, se a caixa de listagem ou caixa de combinação tem o foco de entrada. A configuração dos bits no **itemAction** membro determina se o retângulo será desenhado como se a caixa de listagem ou caixa de combinação tem o foco de entrada.  
  
 `itemAction`  
 Define a ação de desenho necessária. Isso será um ou mais destes bits:  
  
- **ODA_DRAWENTIRE** esse bit é definido quando o controle inteiro precisa ser desenhado.  
  
- **ODA_FOCUS** esse bit é definido quando o controle obtém ou perde o foco de entrada. O **itemState** membro deve ser verificado para determinar se o controle tem o foco.  
  
- **ODA_SELECT** esse bit é definido quando o status de seleção é alterada. O **itemState** membro deve ser verificado para determinar o novo estado de seleção.  
  
 *itemState*  
 Especifica o estado visual do item após ocorre a ação de desenho atual. Ou seja, se um item de menu é ser esmaecido, o sinalizador de estado **ODS_GRAYED** será definido. Os sinalizadores de estado são os seguintes:  
  
- **ODS_CHECKED** esse bit é definido se o item de menu a ser verificada. Esse bit é usado somente em um menu.  
  
- **ODS_DISABLED** esse bit é definido se o item a ser desenhado como desabilitado.  
  
- **ODS_FOCUS** esse bit é definido se o item tem o foco de entrada.  
  
- **ODS_GRAYED** esse bit é definido se o item deve ser esmaecido. Esse bit é usado somente em um menu.  
  
- **ODS_SELECTED** esse bit é definido se o status do item é selecionado.  
  
- **ODS_COMBOBOXEDIT** o desenho ocorre no campo de seleção (controle de edição) de uma caixa de combinação ownerdrawn.  
  
- **ODS_DEFAULT** o item é o padrão.  
  
 `hwndItem`  
 Especifica o identificador de janela do controle de botões, caixas de listagem e caixas de combinação. Especifica o identificador do menu (`HMENU`) que contém o item de menus.  
  
 `hDC`  
 Identifica um contexto de dispositivo. Esse contexto de dispositivo deve ser usado ao executar operações de desenho no controle.  
  
 *rcItem*  
 Um retângulo no contexto de dispositivo especificado pelo `hDC` membro que define os limites do controle a ser desenhada. Windows recorta automaticamente qualquer coisa que o proprietário desenha no contexto de dispositivo para botões, caixas de listagem e caixas de combinação, mas ele não recortar itens de menu. Ao desenhar itens de menu, o proprietário não deve desenhar fora dos limites do retângulo definido pelo **rcItem** membro.  
  
 `itemData`  
 Para uma caixa de combinação ou caixa de listagem, este membro contém o valor que foi passado para a caixa de listagem por um dos seguintes:  
  
- [CComboBox:: AddString](../../mfc/reference/ccombobox-class.md#addstring)  
  
- [CComboBox::InsertString](../../mfc/reference/ccombobox-class.md#insertstring)  
  
- [CListBox::AddString](../../mfc/reference/clistbox-class.md#addstring)  
  
- [CListBox::InsertString](../../mfc/reference/clistbox-class.md#insertstring)  
  
 Para um menu, esse membro contém o valor que foi passado para o menu por um dos seguintes:  
  
- [CMenu::AppendMenu](../../mfc/reference/cmenu-class.md#appendmenu)  
  
- [CMenu::InsertMenu](../../mfc/reference/cmenu-class.md#insertmenu)  
  
- [CMenu::ModifyMenu](../../mfc/reference/cmenu-class.md#modifymenu)  
  
## <a name="remarks"></a>Comentários  
 A janela do proprietário do item menu ou controle de desenho proprietário recebe um ponteiro para essa estrutura como o `lParam` parâmetro o `WM_DRAWITEM` mensagem.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** WinUser. h  
  
## <a name="see-also"></a>Consulte também  
 [Estruturas, estilos, retornos de chamada e mapas de mensagem](../../mfc/reference/structures-styles-callbacks-and-message-maps.md)   
 [CWnd::OnDrawItem](../../mfc/reference/cwnd-class.md#ondrawitem)


