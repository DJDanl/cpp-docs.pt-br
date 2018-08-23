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
ms.openlocfilehash: 00f3275095648a41eb25d10bac1f34637b2ac242
ms.sourcegitcommit: 6f8dd98de57bb80bf4c9852abafef1c35a7600f1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/22/2018
ms.locfileid: "42604566"
---
# <a name="eventsourceremove-method"></a>Método EventSource::Remove

Exclui o manipulador de eventos, representado pelo token de registro de evento especificado do conjunto de manipuladores de eventos associados ao atual **EventSource** objeto.

## <a name="syntax"></a>Sintaxe

```cpp
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

Para obter mais informações sobre o `EventRegistrationToken` estrutura, consulte a **Windows::Foundation::EventRegistrationToken estrutura** tópico no **tempo de execução do Windows** documentação de referência.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** Event. h

**Namespace:** Microsoft::WRL

## <a name="see-also"></a>Consulte também
[Classe EventSource](../windows/eventsource-class.md)