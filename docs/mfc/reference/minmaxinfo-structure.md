---
title: Estrutura MINMAXINFO | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.reviewer: ''
ms.suite: ''
ms.technology:
- cpp-windows
ms.tgt_pltfrm: ''
ms.topic: article
f1_keywords:
- MINMAXINFO
dev_langs:
- C++
helpviewer_keywords:
- MINMAXINFO structure [MFC]
ms.assetid: be6fb578-f98a-4581-9ada-be9df308ed2f
caps.latest.revision: 10
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: c2c799299ef9058648d6b056dcd02fe580f06148
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="minmaxinfo-structure"></a>Estrutura MINMAXINFO
O `MINMAXINFO` estrutura contém informações sobre tamanho maximizada da janela e posição e tamanho mínimo e máximo controle.  
  
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
 Especifica o mínimo de largura (point.x) de rastreamento e o mínimo (point.y) da altura da janela de rastreamento.  
  
 *ptMaxTrackSize*  
 Especifica o máximo controle largura (point.x) e o máximo de altura (point.y) da janela de rastreamento.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** WinUser  
  
## <a name="see-also"></a>Consulte também  
 [Estruturas, estilos, retornos de chamada e mapas de mensagem](../../mfc/reference/structures-styles-callbacks-and-message-maps.md)   
 [CWnd::OnGetMinMaxInfo](../../mfc/reference/cwnd-class.md#ongetminmaxinfo)

