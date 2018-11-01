---
title: Estrutura COMPAREITEMSTRUCT
ms.date: 11/04/2016
f1_keywords:
- COMPAREITEMSTRUCT
helpviewer_keywords:
- COMPAREITEMSTRUCT structure [MFC]
ms.assetid: 4b7131a5-5c7d-4e98-aac7-e85650262b52
ms.openlocfilehash: 78a6e76ee3bbac5b32eb4bccf45578e63f763b75
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50465410"
---
# <a name="compareitemstruct-structure"></a>Estrutura COMPAREITEMSTRUCT

O `COMPAREITEMSTRUCT` estrutura fornece os identificadores e dados fornecidos pelo aplicativo para dois itens em uma caixa de lista classificada, desenhado pelo proprietário ou a caixa de combinação.

## <a name="syntax"></a>Sintaxe

```
typedef struct tagCOMPAREITEMSTRUCT {
    UINT CtlType;
    UINT CtlID;
    HWND hwndItem;
    UINT itemID1;
    DWORD itemData1;
    UINT itemID2;
    DWORD itemData2;
} COMPAREITEMSTRUCT;
```

#### <a name="parameters"></a>Parâmetros

*CtlType*<br/>
ODT_LISTBOX (que especifica uma caixa de listagem do desenho proprietário) ou ODT_COMBOBOX (que especifica uma caixa de combinação do desenho proprietário).

*CtlID*<br/>
A ID de controle de caixa de listagem ou caixa de combinação.

*hwndItem*<br/>
O identificador de janela do controle.

*itemID1*<br/>
O índice do primeiro item na caixa de listagem ou caixa de combinação que estão sendo comparados.

*itemData1*<br/>
Dados fornecidos pelo aplicativo para o primeiro item que estão sendo comparado. Esse valor foi passado na chamada de que adicionou o item à caixa de combinação ou lista.

*itemID2*<br/>
Índice do segundo item na caixa de listagem ou caixa de combinação que estão sendo comparados.

*itemData2*<br/>
Dados fornecidos pelo aplicativo para o segundo item que estão sendo comparado. Esse valor foi passado na chamada de que adicionou o item à caixa de combinação ou lista.

## <a name="remarks"></a>Comentários

Sempre que um aplicativo adiciona um novo item a uma caixa de lista desenhado pelo proprietário ou combinação criado com o estilo CBS_SORT ou LBS_SORT, o Windows envia o proprietário de uma mensagem WM_COMPAREITEM. O *lParam* parâmetro da mensagem contém um ponteiro longo para um `COMPAREITEMSTRUCT` estrutura. Ao receber a mensagem, o proprietário compara os dois itens e retorna um valor que indica qual item classifica antes das outras.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** WinUser. h

## <a name="see-also"></a>Consulte também

[Estruturas, estilos, retornos de chamada e mapas de mensagem](../../mfc/reference/structures-styles-callbacks-and-message-maps.md)<br/>
[CWnd::OnCompareItem](../../mfc/reference/cwnd-class.md#oncompareitem)

