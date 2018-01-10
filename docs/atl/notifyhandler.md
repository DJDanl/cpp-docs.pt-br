---
title: NotifyHandler | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: NotifyHandler
dev_langs: C++
helpviewer_keywords: NotifyHandler function
ms.assetid: 5ff953ec-de35-42bc-8b3c-d384d636c139
caps.latest.revision: "11"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 11f078e6e47aa6c392de79d9811df8738ce09ed9
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="notifyhandler"></a>NotifyHandler
O nome da função identificada pelo parâmetro do terceiro o `NOTIFY_HANDLER` macro em seu mapa de mensagem.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
 
    LRESULT 
    NotifyHandler 
 (
    int idCtrl,  
    LPNMHDR pnmh,  
    BOOL& bHandled);
```  
  
#### <a name="parameters"></a>Parâmetros  
 `idCtrl`  
 O identificador do controle enviar a mensagem.  
  
 *pnmh*  
 Endereço de um [NMHDR](http://msdn.microsoft.com/library/windows/desktop/bb775514) estrutura que contém o código de notificação e informações adicionais. Para algumas mensagens de notificação, esse parâmetro aponta para uma estrutura maior que tem o **NMHDR** estrutura como seu primeiro membro.  
  
 `bHandled`  
 Os conjuntos de mapa de mensagem `bHandled` para **TRUE** antes de *NotifyHandler* é chamado. Se *NotifyHandler* não totalmente processa a mensagem, ele deve ser definido `bHandled` para **FALSE** para indicar que a mensagem precisa de processamento adicional.  
  
## <a name="return-value"></a>Valor de retorno  
 O resultado do processamento de mensagens. 0 se for bem-sucedido.  
  
## <a name="remarks"></a>Comentários  
 Para obter um exemplo de como usar este manipulador de mensagens em um mapa de mensagem, consulte [NOTIFY_HANDLER](reference/message-map-macros-atl.md#notify_handler)).  
  
## <a name="see-also"></a>Consulte também  
 [Implementando uma janela](../atl/implementing-a-window.md)   
 [Mapas de mensagem](../atl/message-maps-atl.md)   
 [WM_NOTIFY](http://msdn.microsoft.com/library/windows/desktop/bb775583)

