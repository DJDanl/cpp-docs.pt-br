---
title: Funções globais de manipulação de eventos | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-atl
ms.topic: reference
f1_keywords:
- atlbase/ATL::AtlWaitWithMessageLoop
dev_langs:
- C++
helpviewer_keywords:
- event handling, global functions
- global functions, event handling
ms.assetid: fd674470-3def-47c3-be1c-894fa85f13e8
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: cb2c7834e7d5475810973a42ef179ea4f5f0079f
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
---
# <a name="event-handling-global-functions"></a>Funções globais de tratamento de evento
Essa função fornece um manipulador de eventos.  
  
> [!IMPORTANT]
>  A função listada na tabela a seguir não pode ser usada em aplicativos que são executados o tempo de execução do Windows.  
  
|||  
|-|-|  
|[AtlWaitWithMessageLoop](#atlwaitwithmessageloop)|Espera um objeto a ser sinalizada, enquanto isso ao distribuir as mensagens de janela, conforme necessário.|  

## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlbase  

##  <a name="atlwaitwithmessageloop"></a>  AtlWaitWithMessageLoop  
 Aguarda o objeto a ser sinalizado, enquanto despacha as mensagens da janela conforme necessário.  
  
> [!IMPORTANT]
>  Essa função não pode ser usada em aplicativos que são executados o tempo de execução do Windows.  
  
```
BOOL AtlWaitWithMessageLoop(HANDLE hEvent);
```  
  
### <a name="parameters"></a>Parâmetros  
 `hEvent`  
 [in] O identificador do objeto de espera para.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna **TRUE** se o objeto foi sinalizado.  
  
### <a name="remarks"></a>Comentários  
 Isso é útil se você quiser aguardar um evento de objeto acontecer e ser notificado de que ele está ocorrendo, mas permitir que as mensagens de janela deve ser distribuída ao aguardar.  
  
## <a name="see-also"></a>Consulte também  
 [Funções](../../atl/reference/atl-functions.md)
