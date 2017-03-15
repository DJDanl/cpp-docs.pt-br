---
title: Estrutura MINMAXINFO | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- MINMAXINFO
dev_langs:
- C++
helpviewer_keywords:
- MINMAXINFO structure
ms.assetid: be6fb578-f98a-4581-9ada-be9df308ed2f
caps.latest.revision: 10
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
ms.openlocfilehash: 772416bdac3c72f55644fa31aef23ba76a14e606
ms.lasthandoff: 02/25/2017

---
# <a name="minmaxinfo-structure"></a>Estrutura MINMAXINFO
O `MINMAXINFO` estrutura contém informações sobre o tamanho de uma janela maximizada e posição e tamanho mínimo e máximo de rastreamento.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
typedef struct tagMINMAXINFO {  
    POINT ptReserved;  
    POINT ptMaxSize;  
    POINT ptMaxPosition;  
    POINT ptMinTrackSize;  
    POINT ptMaxTrackSize;  
} MINMAXINFO;  
```  
  
#### <a name="parameters"></a>Parâmetros  
 *ptReserved*  
 Reservado para uso interno.  
  
 *ptMaxSize*  
 Especifica a largura maximizada (point.x) e a altura maximizada (point.y) da janela.  
  
 `ptMaxPosition`  
 Especifica a posição do lado esquerdo da janela maximizada (point.x) e a posição da parte superior da janela maximizada (point.y).  
  
 *ptMinTrackSize*  
 Especifica o mínimo de largura (point.x) de rastreamento e o mínimo de altura (point.y) da janela de rastreamento.  
  
 *ptMaxTrackSize*  
 Especifica o máximo controle largura (point.x) e o máximo de altura (point.y) da janela de rastreamento.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** WinUser. h  
  
## <a name="see-also"></a>Consulte também  
 [Estruturas, estilos, retornos de chamada e mapas de mensagem](../../mfc/reference/structures-styles-callbacks-and-message-maps.md)   
 [CWnd::OnGetMinMaxInfo](../../mfc/reference/cwnd-class.md#ongetminmaxinfo)


