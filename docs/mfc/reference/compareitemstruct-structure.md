---
title: Estrutura COMPAREITEMSTRUCT | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- COMPAREITEMSTRUCT
dev_langs:
- C++
helpviewer_keywords:
- COMPAREITEMSTRUCT structure
ms.assetid: 4b7131a5-5c7d-4e98-aac7-e85650262b52
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
translationtype: Machine Translation
ms.sourcegitcommit: 040985df34f2613b4e4fae29498721aef15d50cb
ms.openlocfilehash: 6c38c3e362f2e97cb51f5474aaa0bc05098b1ec2
ms.lasthandoff: 02/25/2017

---
# <a name="compareitemstruct-structure"></a>Estrutura COMPAREITEMSTRUCT
O `COMPAREITEMSTRUCT` estrutura fornece os identificadores e dados fornecidos pelo aplicativo para dois itens em uma caixa de combinação ou caixa de lista classificada, desenhados pelo proprietário.  
  
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
 `CtlType`  
 **ODT_LISTBOX** (que especifica uma caixa de listagem de desenho proprietário) ou **ODT_COMBOBOX** (que especifica uma caixa de combinação do desenho proprietário).  
  
 `CtlID`  
 A identificação do controle de caixa de listagem ou caixa de combinação.  
  
 `hwndItem`  
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
 Sempre que um aplicativo adiciona um novo item a uma caixa de lista desenhado pelo proprietário ou caixa de combinação é criado com o **CBS_SORT** ou **LBS_SORT** estilo, o Windows envia o proprietário um `WM_COMPAREITEM` mensagem. O `lParam` parâmetro da mensagem contém um ponteiro longo para um `COMPAREITEMSTRUCT` estrutura. Ao receber a mensagem, o proprietário compara os dois itens e retorna um valor que indica qual item classifica antes da outra.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** WinUser. h  
  
## <a name="see-also"></a>Consulte também  
 [Estruturas, estilos, retornos de chamada e mapas de mensagem](../../mfc/reference/structures-styles-callbacks-and-message-maps.md)   
 [CWnd::OnCompareItem](../../mfc/reference/cwnd-class.md#oncompareitem)


