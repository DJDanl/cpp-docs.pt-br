---
title: "Funções globais de manipulação de eventos | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
dev_langs:
- C++
helpviewer_keywords:
- event handling, global functions
- global functions, event handling
ms.assetid: fd674470-3def-47c3-be1c-894fa85f13e8
caps.latest.revision: 20
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
ms.sourcegitcommit: 604a4bf49490ad2599c857eb3afd527d67e1e25b
ms.openlocfilehash: 4bf2a8b0211361f5d5d2bf0f996e978638631116
ms.lasthandoff: 02/25/2017

---
# <a name="event-handling-global-functions"></a>Funções globais de manipulação de eventos
Essa função fornece um manipulador de eventos.  
  
> [!IMPORTANT]
>  A função listada na tabela a seguir não pode ser usada em aplicativos que são executados a [!INCLUDE[wrt](../../atl/reference/includes/wrt_md.md)].  
  
|||  
|-|-|  
|[AtlWaitWithMessageLoop](#atlwaitwithmessageloop)|Espera por um objeto a ser sinalizado, enquanto despacha as mensagens de janela, conforme necessário.|  

## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlbase. h  

##  <a name="a-nameatlwaitwithmessageloopa--atlwaitwithmessageloop"></a><a name="atlwaitwithmessageloop"></a>AtlWaitWithMessageLoop  
 Aguarda o objeto a ser sinalizado, enquanto despacha as mensagens da janela conforme necessário.  
  
> [!IMPORTANT]
>  Essa função não pode ser usada em aplicativos que são executados a [!INCLUDE[wrt](../../atl/reference/includes/wrt_md.md)].  
  
```
BOOL AtlWaitWithMessageLoop(HANDLE hEvent);
```  
  
### <a name="parameters"></a>Parâmetros  
 `hEvent`  
 [in] O identificador do objeto para aguardar.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna **TRUE** se o objeto tiver sido assinalado.  
  
### <a name="remarks"></a>Comentários  
 Isso é útil se você deseja esperar um evento de objeto e ser notificado de que isso aconteça, mas permitir que as mensagens de janela ser expedida enquanto espera.  
  
## <a name="see-also"></a>Consulte também  
 [Funções](../../atl/reference/atl-functions.md)

