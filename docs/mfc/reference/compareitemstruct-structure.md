---
title: Estrutura COMPAREITEMSTRUCT | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- COMPAREITEMSTRUCT
dev_langs:
- C++
helpviewer_keywords:
- COMPAREITEMSTRUCT structure [MFC]
ms.assetid: 4b7131a5-5c7d-4e98-aac7-e85650262b52
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 5a54b4f4749e7865d793559a9cb5f475c1d57898
ms.sourcegitcommit: be0e3457f2884551f18e183ef0ea65c3ded7f689
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/28/2018
ms.locfileid: "37078252"
---
# <a name="compareitemstruct-structure"></a>Estrutura COMPAREITEMSTRUCT
O `COMPAREITEMSTRUCT` estrutura fornece os identificadores e os dados fornecidos pelo aplicativo para dois itens em uma caixa de lista classificada, desenhados pelo proprietário ou caixa de combinação.  
  
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
 *CtlType*  
 **ODT_LISTBOX** (que especifica uma caixa de listagem do desenho proprietário) ou **ODT_COMBOBOX** (que especifica uma caixa de combinação do desenho proprietário).  
  
 *CtlID*  
 A identificação do controle de caixa de listagem ou caixa de combinação.  
  
 *hwndItem*  
 O identificador de janela do controle.  
  
 *itemID1*  
 O índice do primeiro item na caixa de listagem ou caixa de combinação que estão sendo comparados.  
  
 *itemData1*  
 Dados fornecidos pelo aplicativo para o primeiro item que estão sendo comparado. Esse valor foi passado na chamada que adicionou o item à caixa de combinação ou lista.  
  
 *itemID2*  
 Índice do segundo item na caixa de listagem ou caixa de combinação que estão sendo comparados.  
  
 *itemData2*  
 Dados fornecidos pelo aplicativo para o segundo item que estão sendo comparado. Esse valor foi passado na chamada que adicionou o item à caixa de combinação ou lista.  
  
## <a name="remarks"></a>Comentários  
 Sempre que um aplicativo adiciona um novo item a uma caixa de listagem de desenho proprietário ou caixa de combinação criada com o **CBS_SORT** ou **LBS_SORT** estilo, o Windows envia o proprietário uma mensagem WM_COMPAREITEM. O *lParam* parâmetro da mensagem contém um ponteiro de tempo para um `COMPAREITEMSTRUCT` estrutura. Ao receber a mensagem, o proprietário compara os dois itens e retorna um valor que indica qual item classifica antes da outra.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** WinUser  
  
## <a name="see-also"></a>Consulte também  
 [Estruturas, estilos, retornos de chamada e mapas de mensagem](../../mfc/reference/structures-styles-callbacks-and-message-maps.md)   
 [CWnd::OnCompareItem](../../mfc/reference/cwnd-class.md#oncompareitem)

