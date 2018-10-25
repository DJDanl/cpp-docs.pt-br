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
ms.openlocfilehash: 9061205bdf3697e492b846d160a5b4dd2d154bb9
ms.sourcegitcommit: a9dcbcc85b4c28eed280d8e451c494a00d8c4c25
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/25/2018
ms.locfileid: "50065012"
---
# <a name="deleteitemstruct-structure"></a>Estrutura DELETEITEMSTRUCT

O `DELETEITEMSTRUCT` estrutura descreve um item excluído de caixa de listagem ou caixa de combinação desenhado pelo proprietário.

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

*CtlType*<br/>
Especifica ODT_LISTBOX (uma caixa de lista desenhado pelo proprietário) ou ODT_COMBOBOX (uma caixa de combinação do desenho proprietário).

*CtlID*<br/>
Especifica o identificador da caixa de listagem ou caixa de combinação.

*itemID*<br/>
Especifica o índice do item na caixa de listagem ou caixa de combinação que está sendo removido.

*hwndItem*<br/>
Identifica o controle.

*itemData*<br/>
Especifica os dados definidos pelo aplicativo para o item. Esse valor é passado para o controle na *lParam* parâmetro da mensagem, que adiciona o item à caixa de listagem ou caixa de combinação.

## <a name="remarks"></a>Comentários

Quando um item é removido da caixa de listagem ou caixa de combinação ou caixa de listagem ou caixa de combinação é destruída, o Windows envia a mensagem WM_DELETEITEM até o proprietário de cada item excluído. O *lParam* parâmetro da mensagem contém um ponteiro para essa estrutura.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atldbcli.h

## <a name="see-also"></a>Consulte também

[Estruturas, estilos, retornos de chamada e mapas de mensagem](../../mfc/reference/structures-styles-callbacks-and-message-maps.md)<br/>
[CWnd::OnDeleteItem](../../mfc/reference/cwnd-class.md#ondeleteitem)

