---
title: Estrutura MSG 1 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- MSG
dev_langs:
- C++
helpviewer_keywords:
- MSG structure [MFC]
ms.assetid: dc166d27-9423-41f1-9599-5ba76d2f0138
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 41dbbcdd3404705a9ac7c6c7969a9ebeeb0238f8
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33372251"
---
# <a name="msg-structure1"></a>Estrutura MSG 1
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
 **Cabeçalho:** WinUser  
  
## <a name="see-also"></a>Consulte também  
 [Estruturas, estilos, retornos de chamada e mapas de mensagem](../../mfc/reference/structures-styles-callbacks-and-message-maps.md)

