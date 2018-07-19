---
title: CommandHandler | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-atl
ms.topic: reference
f1_keywords:
- CommandHandler
dev_langs:
- C++
helpviewer_keywords:
- CommandHandler function
ms.assetid: 662bc7bf-4a10-42b3-986d-d8bae4f63551
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 784551b090f7c0c73b96b846fcc8d74017cc1e30
ms.sourcegitcommit: 26fff80635bd1d51bc51899203fddfea8b29b530
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/05/2018
ms.locfileid: "37850635"
---
# <a name="commandhandler"></a>CommandHandler
`CommandHandler` a função é identificada pelo terceiro parâmetro da macro COMMAND_HANDLER no seu mapa de mensagem.  
  
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
 *wNotifyCode*  
 O código de notificação.  
  
 *wID*  
 O identificador do controle, item de menu ou acelerador.  
  
 *hWndCtl*  
 Um identificador para um controle de janela.  
  
 *bHandled*  
 Os conjuntos de mapa de mensagem *bHandled* como TRUE antes `CommandHandler` é chamado. Se `CommandHandler` não consegue tratar por completo a mensagem, ela deverá definir *bHandled* como FALSE para indicar que a mensagem precisa de processamento adicional.  
  
## <a name="return-value"></a>Valor de retorno  
 O resultado do processamento de mensagens. 0 se for bem-sucedido.  
  
## <a name="remarks"></a>Comentários  
 Para obter um exemplo de como usar este manipulador de mensagens em um mapa de mensagem, consulte [COMMAND_HANDLER](reference/message-map-macros-atl.md#command_handler).  
  
## <a name="see-also"></a>Consulte também  
 [Implementando uma janela](../atl/implementing-a-window.md)   
 [Mapas de Mensagens](../atl/message-maps-atl.md)   
 [WM_NOTIFY](http://msdn.microsoft.com/library/windows/desktop/bb775583)

