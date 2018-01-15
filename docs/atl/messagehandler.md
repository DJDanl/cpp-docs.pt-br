---
title: MessageHandler | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: MessageHandler
dev_langs: C++
helpviewer_keywords: MessageHandler function
ms.assetid: 8a0acf97-1b0d-4226-91b9-75446634a03c
caps.latest.revision: "11"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: f5a09439cf47c695af0d3b7d6c7724cffcb9ccb4
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="messagehandler"></a>MessageHandler
**MessageHandler** é o nome da função identificada pelo parâmetro do segundo o `MESSAGE_HANDLER` macro em seu mapa de mensagem.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
 
    LRESULT 
    MessageHandler 
 (
    UINT uMsg,  
    WPARAM wParam,  
    LPARAM lParam,  
    BOOL& bHandled);
```  
  
#### <a name="parameters"></a>Parâmetros  
 `uMsg`  
 Especifica a mensagem.  
  
 `wParam`  
 Informações adicionais de mensagem específica.  
  
 `lParam`  
 Informações adicionais de mensagem específica.  
  
 `bHandled`  
 Os conjuntos de mapa de mensagem `bHandled` para **TRUE** antes de `MessageHandler` é chamado. Se `MessageHandler` não totalmente processa a mensagem, ele deve ser definido `bHandled` para **FALSE** para indicar que a mensagem precisa de processamento adicional.  
  
## <a name="return-value"></a>Valor de retorno  
 O resultado do processamento de mensagens. 0 se for bem-sucedido.  
  
## <a name="remarks"></a>Comentários  
 Para obter um exemplo de como usar este manipulador de mensagens em um mapa de mensagem, consulte [MESSAGE_HANDLER](reference/message-map-macros-atl.md#message_handler).  
  
## <a name="see-also"></a>Consulte também  
 [Implementando uma janela](../atl/implementing-a-window.md)   
 [Mapas de mensagem](../atl/message-maps-atl.md)   
 [WM_NOTIFY](http://msdn.microsoft.com/library/windows/desktop/bb775583)

