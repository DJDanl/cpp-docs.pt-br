---
title: CommandHandler | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: CommandHandler
dev_langs: C++
helpviewer_keywords: CommandHandler function
ms.assetid: 662bc7bf-4a10-42b3-986d-d8bae4f63551
caps.latest.revision: "13"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: c17d9e731eaee9c6e1a1c584e61db6c9826cf8d3
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="commandhandler"></a>CommandHandler
`CommandHandler`é a função identificada pelo parâmetro do terceiro o `COMMAND_HANDLER` macro em seu mapa de mensagem.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
 
    LRESULT 
    CommandHandler 
 (
    WORD wNotifyCode,  
    WORD wID,  
    HWND hWndCtl,  
    BOOL& bHandled);
```  
  
#### <a name="parameters"></a>Parâmetros  
 `wNotifyCode`  
 O código de notificação.  
  
 *wID*  
 O identificador do item de menu, o controle ou o acelerador.  
  
 *hWndCtl*  
 Um identificador para um controle de janela.  
  
 `bHandled`  
 Os conjuntos de mapa de mensagem `bHandled` para **TRUE** antes de `CommandHandler` é chamado. Se `CommandHandler` não totalmente processa a mensagem, ele deve ser definido `bHandled` para **FALSE** para indicar que a mensagem precisa de processamento adicional.  
  
## <a name="return-value"></a>Valor de retorno  
 O resultado do processamento de mensagens. 0 se for bem-sucedido.  
  
## <a name="remarks"></a>Comentários  
 Para obter um exemplo de como usar este manipulador de mensagens em um mapa de mensagem, consulte [COMMAND_HANDLER](reference/message-map-macros-atl.md#command_handler).  
  
## <a name="see-also"></a>Consulte também  
 [Implementando uma janela](../atl/implementing-a-window.md)   
 [Mapas de mensagem](../atl/message-maps-atl.md)   
 [WM_NOTIFY](http://msdn.microsoft.com/library/windows/desktop/bb775583)

