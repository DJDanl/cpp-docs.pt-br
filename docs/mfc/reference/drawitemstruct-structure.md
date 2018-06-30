---
title: Estrutura DRAWITEMSTRUCT | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- DRAWITEMSTRUCT
dev_langs:
- C++
helpviewer_keywords:
- DRAWITEMSTRUCT structure [MFC]
ms.assetid: ba9ef1d4-aebb-45e9-b956-4b81a02e50f7
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: ff4596a52170d0c6d197a0bda431963b5f0e9344
ms.sourcegitcommit: 208d445fd7ea202de1d372d3f468e784e77bd666
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/29/2018
ms.locfileid: "37120926"
---
# <a name="drawitemstruct-structure"></a>Estrutura DRAWITEMSTRUCT
O `DRAWITEMSTRUCT` estrutura fornece informações sobre a janela do proprietário deve ter para determinar como um item de menu ou controle de desenho proprietário de pintura.  
  
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
 *CtlType*  
 O tipo de controle. Os valores para os tipos de controle são da seguinte maneira:  
  
- Botão de desenho proprietário ODT_BUTTON  
  
- Caixa de combinação do desenho proprietário ODT_COMBOBOX  
  
- Caixa de listagem de desenho proprietário ODT_LISTBOX  
  
- Menu de desenho proprietário ODT_MENU  
  
- Controle de exibição de lista de ODT_LISTVIEW  
  
- ODT_STATIC desenhados pelo proprietário do controle estático  
  
- Controle de guia ODT_TAB  
  
 *CtlID*  
 A ID de controle de botão, caixa de listagem ou caixa de combinação. Esse membro não é usado para um menu.  
  
 *itemID*  
 A ID de item de menu de um menu ou o índice do item em uma caixa de listagem ou caixa de combinação. Para uma caixa de listagem vazia ou caixa de combinação, esse membro é um valor negativo, o que permite que o aplicativo desenhar o retângulo de foco em coordenadas especificadas pelo `rcItem` membro mesmo quando não há nenhum item no controle. O usuário pode ser mostrado, portanto, se a caixa de listagem ou caixa de combinação tem o foco de entrada. A configuração de bits no `itemAction` membro determina se o retângulo deve ser desenhado como se a caixa de listagem ou caixa de combinação tem entrada foco.  
  
 *ItemAction*  
 Define a ação de desenho necessária. Isso será um ou mais destes bits:  
  
- ODA_DRAWENTIRE esse bit é definido quando todo o controle deve ser desenhado.  
  
- ODA_FOCUS esse bit é definido quando o controle recebe ou perde o foco de entrada. O `itemState` membro deve ser verificado para determinar se o controle tem foco.  
  
- ODA_SELECT esse bit é definido quando o status de seleção é alterada. O `itemState` membro deve ser verificado para determinar o novo estado de seleção.  
  
 *itemState*  
 Especifica o estado visual do item após a ação de desenho atual. Ou seja, se um item de menu é esmaecido, o sinalizador de estado ODS_GRAYED será ser definida. Os sinalizadores de estado são os seguintes:  
  
- ODS_CHECKED esse bit é definido se o item de menu a ser verificada. Esse bit é usado somente em um menu.  
  
- ODS_DISABLED esse bit é definido se o item a ser desenhado como desabilitado.  
  
- ODS_FOCUS esse bit é definido se o item tem foco de entrada.  
  
- ODS_GRAYED esse bit é definido se o item é esmaecida. Esse bit é usado somente em um menu.  
  
- ODS_SELECTED esse bit é definido se o status do item é selecionado.  
  
- O desenho de ODS_COMBOBOXEDIT ocorre no campo de seleção (controle de edição) de uma caixa de combinação ownerdrawn.  
  
- ODS_DEFAULT o item é o item padrão.  
  
 *hwndItem*  
 Especifica o identificador de janela do controle para caixas de combinação, caixas de listagem e botões. Especifica o identificador do menu (HMENU) que contém o item de menus.  
  
 *hDC*  
 Identifica um contexto de dispositivo. Deve ser usado neste contexto de dispositivo ao executar operações de desenho no controle.  
  
 *rcItem*  
 Um retângulo no contexto de dispositivo especificado pelo *hDC* membro que define os limites do controle a ser desenhada. Windows recorta automaticamente qualquer coisa que o proprietário desenha no contexto do dispositivo para caixas de combinação, caixas de listagem e botões, mas ele não corta os itens de menu. Ao desenhar itens de menu, o proprietário não deve desenhar fora dos limites do retângulo definido pelo `rcItem` membro.  
  
 *itemData*  
 Para uma caixa de combinação ou caixa de listagem, esse membro contém o valor passado para a caixa de lista por um dos seguintes:  
  
- [CComboBox::AddString](../../mfc/reference/ccombobox-class.md#addstring)  
  
- [CComboBox::InsertString](../../mfc/reference/ccombobox-class.md#insertstring)  
  
- [CListBox::AddString](../../mfc/reference/clistbox-class.md#addstring)  
  
- [CListBox::InsertString](../../mfc/reference/clistbox-class.md#insertstring)  
  
 Para um menu, esse membro contém o valor que foi passado para o menu por um dos seguintes:  
  
- [CMenu::AppendMenu](../../mfc/reference/cmenu-class.md#appendmenu)  
  
- [CMenu::InsertMenu](../../mfc/reference/cmenu-class.md#insertmenu)  
  
- [CMenu::ModifyMenu](../../mfc/reference/cmenu-class.md#modifymenu)  
  
## <a name="remarks"></a>Comentários  
 A janela do proprietário do item menu ou controle de desenho proprietário recebe um ponteiro para essa estrutura como o *lParam* parâmetro da mensagem WM_DRAWITEM.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** WinUser  
  
## <a name="see-also"></a>Consulte também  
 [Estruturas, estilos, retornos de chamada e mapas de mensagem](../../mfc/reference/structures-styles-callbacks-and-message-maps.md)   
 [CWnd::OnDrawItem](../../mfc/reference/cwnd-class.md#ondrawitem)

