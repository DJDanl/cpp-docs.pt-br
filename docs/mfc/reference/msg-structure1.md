---
title: Estrutura MSG&1; | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- MSG
dev_langs:
- C++
helpviewer_keywords:
- MSG structure
ms.assetid: dc166d27-9423-41f1-9599-5ba76d2f0138
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
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: f26a97a4285db71f1c1f82cd199456bc528aff0c
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="msg-structure1"></a>Estrutura MSG&1;
O `MSG` estrutura contém informações sobre a mensagem da fila de mensagens do thread.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
typedef struct tagMSG {     // msg    
    HWND hwnd;  
    UINT message;  
    WPARAM wParam;  
    LPARAM lParam;  
    DWORD time;  
    POINT pt;  
} MSG;  
```  
  
#### <a name="parameters"></a>Parâmetros  
 *HWND*  
 Identifica a janela cujo procedimento de janela recebe a mensagem.  
  
 `message`  
 Especifica o número da mensagem.  
  
 `wParam`  
 Especifica informações adicionais sobre a mensagem. O significado exato depende do valor da **mensagem** membro.  
  
 `lParam`  
 Especifica informações adicionais sobre a mensagem. O significado exato depende do valor da **mensagem** membro.  
  
 `time`  
 Especifica a hora em que a mensagem foi postada.  
  
 `pt`  
 Especifica a posição do cursor, em coordenadas da tela, quando a mensagem foi postada.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** WinUser. h  
  
## <a name="see-also"></a>Consulte também  
 [Estruturas, estilos, retornos de chamada e mapas de mensagem](../../mfc/reference/structures-styles-callbacks-and-message-maps.md)


