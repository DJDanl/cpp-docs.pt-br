---
title: 'Método EventSource:: remove | Microsoft Docs'
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
ms.openlocfilehash: 9dd026158a2bbc76e7a3e195bc5346f65821f2b7
ms.sourcegitcommit: d5d6bb9945c3550b8e8864b22b3a565de3691fde
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/06/2018
ms.locfileid: "39569489"
---
# <a name="eventsourceremove-method"></a>Método EventSource::Remove
Exclui o manipulador de eventos, representado pelo token de registro de evento especificado do conjunto de manipuladores de eventos associados ao atual **EventSource** objeto.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
HRESULT Remove(  
   EventRegistrationToken token  
);  
```  
  
### <a name="parameters"></a>Parâmetros  
 *token*  
 Um identificador que representa um manipulador de eventos. Esse token foi retornado quando o manipulador de eventos foi registrado pela [Add ()](../windows/eventsource-add-method.md) método.  
  
## <a name="return-value"></a>Valor de retorno  
 S_OK se bem-sucedido; Caso contrário, um HRESULT que indica o erro.  
  
## <a name="remarks"></a>Comentários  
 Para obter mais informações sobre a estrutura EventRegistrationToken, consulte o `Windows::Foundation::EventRegistrationToken` tópico de estrutura na documentação de referência do tempo de execução do Windows.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** Event. h  
  
 **Namespace:** Microsoft::WRL
 
 ## <a name="see-also"></a>Consulte também
 [Classe EventSource](../windows/eventsource-class.md)