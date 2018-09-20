---
title: Estrutura MEASUREITEMSTRUCT | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- MEASUREITEMSTRUCT
dev_langs:
- C++
helpviewer_keywords:
- MEASUREITEMSTRUCT structure [MFC]
ms.assetid: d141ace4-47cb-46b5-a81c-ad2c5e5a8501
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: db24d772e2f007b3350443ae6bc84f97cac34e76
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46397761"
---
# <a name="measureitemstruct-structure"></a>Estrutura MEASUREITEMSTRUCT

O `MEASUREITEMSTRUCT` estrutura informa ao Windows das dimensões de um item de menu ou controle desenhado pelo proprietário.

## <a name="syntax"></a>Sintaxe

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

#### <a name="parameters"></a>Parâmetros

*CtlType*<br/>
Contém o tipo de controle. Os valores para tipos de controle são da seguinte maneira:

- Caixa de combinação do desenho proprietário ODT_COMBOBOX

- Caixa de listagem do desenho proprietário ODT_LISTBOX

- Menus de desenho proprietário ODT_MENU

*CtlID*<br/>
Contém a ID de controle para uma caixa de combinação, caixa de listagem ou botão. Esse membro não é usado para um menu.

*itemID*<br/>
Contém a ID de item de menu para um menu ou a ID de item de caixa de listagem para uma caixa de combinação de altura variável ou a caixa de listagem. Esse membro não é usado para uma caixa de combinação de altura fixa ou uma caixa de listagem ou para um botão.

*itemWidth*<br/>
Especifica a largura de um item de menu. O proprietário do item de menu de desenho do proprietário deve preencher esse membro antes de retornar a mensagem.

*itemHeight*<br/>
Especifica a altura de um item individual em uma caixa de listagem ou um menu. Antes de retornar a mensagem, o proprietário da caixa de combinação do desenho proprietário, caixa de listagem ou item de menu deve preencher esse membro. A altura máxima de um item de caixa de listagem é 255.

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

Isso permite que o Windows processar a interação do usuário com o controle corretamente. Falha ao preencher os membros adequados no `MEASUREITEMSTRUCT` estrutura fará com que uma operação inadequada do controle.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** WinUser. h

## <a name="see-also"></a>Consulte também

[Estruturas, estilos, retornos de chamada e mapas de mensagem](../../mfc/reference/structures-styles-callbacks-and-message-maps.md)<br/>
[CWnd::OnMeasureItem](../../mfc/reference/cwnd-class.md#onmeasureitem)

