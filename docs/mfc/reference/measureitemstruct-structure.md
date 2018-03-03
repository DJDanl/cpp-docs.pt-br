---
title: Estrutura MEASUREITEMSTRUCT | Microsoft Docs
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
- MEASUREITEMSTRUCT structure [MFC]
ms.assetid: d141ace4-47cb-46b5-a81c-ad2c5e5a8501
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: ce5221943ba1591a01ddebe2c261e4197fa18501
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="measureitemstruct-structure"></a>Estrutura MEASUREITEMSTRUCT
O `MEASUREITEMSTRUCT` estrutura informa as janelas de dimensões de um item de menu ou controle de desenho proprietário.  
  
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
  
- **ODT_LISTBOX** caixa de listagem do desenho proprietário  
  
- **ODT_MENU** menu de desenho proprietário  
  
 `CtlID`  
 Contém a ID de controle de botão, caixa de listagem ou caixa de combinação. Esse membro não é usado para um menu.  
  
 `itemID`  
 Contém a ID do item de menu para um menu ou a ID de item de caixa de listagem para uma caixa de combinação de altura variável ou a caixa de listagem. Esse membro não é usado para uma caixa de combinação de altura fixa ou uma caixa de listagem ou para um botão.  
  
 *itemWidth*  
 Especifica a largura de um item de menu. O proprietário do item de menu de desenho proprietário deve preencher este membro antes de retornar a mensagem.  
  
 *itemHeight*  
 Especifica a altura de um item individual em um menu ou uma caixa de listagem. Antes de retornar a mensagem, o proprietário da caixa de combinação do desenho proprietário, caixa de listagem ou item de menu deve preencher este membro. A altura máxima de um item de caixa de listagem é 255.  
  
 `itemData`  
 Para uma caixa de combinação ou caixa de listagem, esse membro contém o valor passado para a caixa de lista por um dos seguintes:  
  
- [CComboBox::AddString](../../mfc/reference/ccombobox-class.md#addstring)  
  
- [CComboBox::InsertString](../../mfc/reference/ccombobox-class.md#insertstring)  
  
- [CListBox::AddString](../../mfc/reference/clistbox-class.md#addstring)  
  
- [CListBox::InsertString](../../mfc/reference/clistbox-class.md#insertstring)  
  
 Para um menu, esse membro contém o valor que foi passado para o menu por um dos seguintes:  
  
- [CMenu::AppendMenu](../../mfc/reference/cmenu-class.md#appendmenu)  
  
- [CMenu::InsertMenu](../../mfc/reference/cmenu-class.md#insertmenu)  
  
- [CMenu::ModifyMenu](../../mfc/reference/cmenu-class.md#modifymenu)  
  
 Isso permite que o Windows processar a interação do usuário com o controle corretamente. Falha ao preencher os membros adequados a `MEASUREITEMSTRUCT` estrutura fará com que uma operação inadequada do controle.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** WinUser  
  
## <a name="see-also"></a>Consulte também  
 [Estruturas, estilos, retornos de chamada e mapas de mensagem](../../mfc/reference/structures-styles-callbacks-and-message-maps.md)   
 [CWnd::OnMeasureItem](../../mfc/reference/cwnd-class.md#onmeasureitem)

