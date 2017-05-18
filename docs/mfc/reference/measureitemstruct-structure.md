---
title: Estrutura MEASUREITEMSTRUCT | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- MEASUREITEMSTRUCT
dev_langs:
- C++
helpviewer_keywords:
- MEASUREITEMSTRUCT structure
ms.assetid: d141ace4-47cb-46b5-a81c-ad2c5e5a8501
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
ms.openlocfilehash: 9d32a3ad7c5e420dfa0e7395fd9583654cd174ac
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="measureitemstruct-structure"></a>Estrutura MEASUREITEMSTRUCT
O `MEASUREITEMSTRUCT` estrutura informa ao Windows das dimensões de um item de menu ou controle de desenho proprietário.  
  
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
 `CtlType`  
 Contém o tipo de controle. Os valores para os tipos de controle são da seguinte maneira:  
  
- **ODT_COMBOBOX** caixa de combinação do desenho proprietário  
  
- **ODT_LISTBOX** caixa de listagem de desenho proprietário  
  
- **ODT_MENU** menus de desenho proprietário  
  
 `CtlID`  
 Contém a ID do controle de botão, caixa de listagem ou caixa de combinação. Este membro não é usado em um menu.  
  
 `itemID`  
 Contém a ID do item de menu em um menu ou a ID do item de caixa de listagem para uma caixa de combinação de altura variável ou a caixa de listagem. Este membro não é usado para uma caixa de combinação de altura fixa ou caixa de listagem ou para um botão.  
  
 *itemWidth*  
 Especifica a largura de um item de menu. O proprietário do item de menu desenho proprietário deve preencher esse membro antes de retornar a mensagem.  
  
 *itemHeight*  
 Especifica a altura de um item individual em um menu ou uma caixa de listagem. Antes de retornar a mensagem, o proprietário da caixa de combinação do desenho proprietário, caixa de listagem ou item de menu deve preencher esse membro. A altura máxima de um item de caixa de listagem é 255.  
  
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
  
 Isso permite que o Windows processar a interação do usuário com o controle corretamente. Falha ao preencher os membros adequados a `MEASUREITEMSTRUCT` estrutura fará com que a operação incorreta do controle.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** WinUser. h  
  
## <a name="see-also"></a>Consulte também  
 [Estruturas, estilos, retornos de chamada e mapas de mensagem](../../mfc/reference/structures-styles-callbacks-and-message-maps.md)   
 [CWnd::OnMeasureItem](../../mfc/reference/cwnd-class.md#onmeasureitem)


