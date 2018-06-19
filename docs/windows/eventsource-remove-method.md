---
title: 'Método EventSource: | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- event/Microsoft::WRL::EventSource::Remove
dev_langs:
- C++
helpviewer_keywords:
- Remove method
ms.assetid: afafedf5-3665-4408-a639-fb6884f7c5f9
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: bbf0480252fca342b8a690e93f92ae14ca5e84c0
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2018
ms.locfileid: "33874376"
---
# <a name="eventsourceremove-method"></a>Método EventSource::Remove
Exclui o manipulador de eventos representado pelo token de registro de evento especificado da coleção de manipuladores de eventos associados ao objeto de EventSource atual.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
HRESULT Remove(  
   EventRegistrationToken token  
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `token`  
 Um identificador que representa um manipulador de eventos. Esse token foi retornado quando o manipulador de eventos foi registrado pelo [Add](../windows/eventsource-add-method.md) método.  
  
## <a name="return-value"></a>Valor de retorno  
 S_OK se bem-sucedido; Caso contrário, o HRESULT que indica o erro.  
  
## <a name="remarks"></a>Comentários  
 Para obter mais informações sobre a estrutura EventRegistrationToken, consulte o tópico de estrutura Windows::Foundation::EventRegistrationToken na documentação de referência do tempo de execução do Windows.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** event.h  
  
 **Namespace:** Microsoft::WRL
 
 ## <a name="see-also"></a>Consulte também
 [Classe EventSource](../windows/eventsource-class.md)