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
ms.openlocfilehash: 632f1b8b975c73c4f8a708ddb9efd64ce0cae015
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46427245"
---
# <a name="drawitemstruct-structure"></a>Estrutura DRAWITEMSTRUCT

O `DRAWITEMSTRUCT` estrutura fornece informações sobre a janela do proprietário deve ter para determinar como pintar um item de menu ou controle desenhado pelo proprietário.

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

*CtlType*<br/>
O tipo de controle. Os valores para tipos de controle são da seguinte maneira:

- Botão de desenho proprietário ODT_BUTTON

- Caixa de combinação do desenho proprietário ODT_COMBOBOX

- Caixa de lista desenhado pelo proprietário ODT_LISTBOX

- Menu desenhados pelo proprietário do ODT_MENU

- Controle de exibição de lista de ODT_LISTVIEW

- ODT_STATIC controle estático desenhado pelo proprietário

- Controle de guia ODT_TAB

*CtlID*<br/>
A ID de controle para uma caixa de combinação, caixa de listagem ou botão. Esse membro não é usado para um menu.

*itemID*<br/>
A ID de item de menu para um menu ou o índice do item em uma caixa de listagem ou caixa de combinação. Para uma caixa de listagem vazios ou caixa de combinação, esse membro é um valor negativo, o que permite que o aplicativo desenhar o retângulo de foco somente nas coordenadas especificadas pelo `rcItem` membro mesmo se não houver nenhum item no controle. O usuário pode ser mostrado, portanto, se a caixa de listagem ou caixa de combinação tem o foco de entrada. A configuração de bits no `itemAction` membro determina se o retângulo deve ser desenhado como se a caixa de combinação ou caixa de listagem tem foco de entrada.

*itemAction*<br/>
Define a ação de desenho necessária. Isso será um ou mais dos seguintes bits:

- ODA_DRAWENTIRE esse bit é definido quando o controle inteiro precisa ser desenhado.

- ODA_FOCUS esse bit é definido quando o controle ganha ou perde o foco de entrada. O `itemState` membro deve ser verificado para determinar se o controle tem foco.

- ODA_SELECT esse bit é definido quando apenas o status de seleção foi alterado. O `itemState` membro deve ser verificado para determinar o novo estado de seleção.

*itemState*<br/>
Especifica o estado visual do item depois que a ação atual de desenho ocorre. Ou seja, se um item de menu é esmaecido, o sinalizador de estado ODS_GRAYED será ser definido. Os sinalizadores de estado são da seguinte maneira:

- ODS_CHECKED esse bit é definido se o item de menu deve ser verificada. Esse bit é usado somente em um menu.

- ODS_DISABLED esse bit é definido se o item a ser desenhado como desabilitado.

- ODS_FOCUS esse bit é definido se o item tem o foco de entrada.

- ODS_GRAYED esse bit é definido se o item a ser desativadas. Esse bit é usado somente em um menu.

- ODS_SELECTED esse bit é definido se o status do item é selecionado.

- ODS_COMBOBOXEDIT o desenho ocorre no campo de seleção (controle de edição) de uma caixa de combinação ownerdrawn.

- ODS_DEFAULT o item é o item padrão.

*hwndItem*<br/>
Especifica o identificador de janela do controle para botões, caixas de listagem e caixas de combinação. Especifica o identificador do menu (HMENU) que contém o item para menus.

*hDC*<br/>
Identifica um contexto de dispositivo. Esse contexto de dispositivo deve ser usado ao executar operações de desenho no controle.

*rcItem*<br/>
Um retângulo no contexto de dispositivo especificado pelo *hDC* membro que define os limites do controle a ser desenhado. Windows recorta automaticamente qualquer coisa que o proprietário desenha no contexto de dispositivo para botões, caixas de listagem e caixas de combinação, mas ele não clip-itens de menu. Ao desenhar itens de menu, o proprietário não deve ser desenhados fora dos limites do retângulo definido pelo `rcItem` membro.

*itemData*<br/>
Para uma caixa de combinação ou caixa de listagem, esse membro contém o valor que foi passado para a caixa de listagem por um dos seguintes:

- [CComboBox:: AddString](../../mfc/reference/ccombobox-class.md#addstring)

- [CComboBox::InsertString](../../mfc/reference/ccombobox-class.md#insertstring)

- [CListBox::AddString](../../mfc/reference/clistbox-class.md#addstring)

- [CListBox::InsertString](../../mfc/reference/clistbox-class.md#insertstring)

Para um menu, esse membro contém o valor que foi passado para o menu por um dos seguintes:

- [CMenu::AppendMenu](../../mfc/reference/cmenu-class.md#appendmenu)

- [CMenu::InsertMenu](../../mfc/reference/cmenu-class.md#insertmenu)

- [CMenu::ModifyMenu](../../mfc/reference/cmenu-class.md#modifymenu)

## <a name="remarks"></a>Comentários

A janela do proprietário do item menu ou controle desenhado pelo proprietário recebe um ponteiro para essa estrutura como o *lParam* parâmetro da mensagem WM_DRAWITEM.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** WinUser. h

## <a name="see-also"></a>Consulte também

[Estruturas, estilos, retornos de chamada e mapas de mensagem](../../mfc/reference/structures-styles-callbacks-and-message-maps.md)<br/>
[CWnd::OnDrawItem](../../mfc/reference/cwnd-class.md#ondrawitem)

