---
title: Estrutura DELETEITEMSTRUCT | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- DELETEITEMSTRUCT
dev_langs:
- C++
helpviewer_keywords:
- DELETEITEMSTRUCT structure [MFC]
ms.assetid: 48d3998c-f4a8-402a-bf90-df3770a78685
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 5c844ad428143c82e8214eab74262b326bf2c9a4
ms.sourcegitcommit: 208d445fd7ea202de1d372d3f468e784e77bd666
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/29/2018
ms.locfileid: "37123234"
---
# <a name="deleteitemstruct-structure"></a>Estrutura DELETEITEMSTRUCT
O `DELETEITEMSTRUCT` estrutura descreve um item excluído de caixa de listagem ou caixa de combinação desenhados pelo proprietário.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
typedef struct tagDELETEITEMSTRUCT { /* ditms */  
    UINT CtlType;  
    UINT CtlID;  
    UINT itemID;  
    HWND hwndItem;  
    UINT itemData;  
} DELETEITEMSTRUCT;  
```  
  
#### <a name="parameters"></a>Parâmetros  
 *CtlType*  
 Especifica o ODT_LISTBOX (uma caixa de listagem de desenho proprietário) ou ODT_COMBOBOX (uma caixa de combinação do desenho proprietário).  
  
 *CtlID*  
 Especifica o identificador da caixa de listagem ou caixa de combinação.  
  
 *itemID*  
 Especifica o índice do item na caixa de listagem ou caixa de combinação que está sendo removido.  
  
 *hwndItem*  
 Identifica o controle.  
  
 *itemData*  
 Especifica os dados definidos pelo aplicativo para o item. Esse valor é passado para o controle no *lParam* parâmetro da mensagem que adiciona o item à caixa de listagem ou caixa de combinação.  
  
## <a name="remarks"></a>Comentários  
 Quando um item é removido da caixa de listagem ou caixa de combinação ou caixa de listagem ou caixa de combinação é destruída, o Windows envia a mensagem WM_DELETEITEM para o proprietário de cada item excluído. O *lParam* parâmetro da mensagem contém um ponteiro para essa estrutura.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atldbcli.h  
  
## <a name="see-also"></a>Consulte também  
 [Estruturas, estilos, retornos de chamada e mapas de mensagem](../../mfc/reference/structures-styles-callbacks-and-message-maps.md)   
 [CWnd::OnDeleteItem](../../mfc/reference/cwnd-class.md#ondeleteitem)


