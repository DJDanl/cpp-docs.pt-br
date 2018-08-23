---
title: 'Método ftmbase:: Disconnectobject | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- ftm/Microsoft::WRL::FtmBase::DisconnectObject
dev_langs:
- C++
helpviewer_keywords:
- DisconnectObject method
ms.assetid: 33253eec-3a65-4e72-8525-0249245a4790
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: b467162d2f5cc5b04bc43a6d31019eb08e17e750
ms.sourcegitcommit: 6f8dd98de57bb80bf4c9852abafef1c35a7600f1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/22/2018
ms.locfileid: "42595400"
---
# <a name="ftmbasedisconnectobject-method"></a>Método FtmBase::DisconnectObject

Libera forçadamente todas as conexões externas para um objeto. Servidor do objeto chama a implementação do objeto desse método antes de desligar.

## <a name="syntax"></a>Sintaxe

```cpp
STDMETHODIMP DisconnectObject(
   __in DWORD dwReserved
) override;
```

### <a name="parameters"></a>Parâmetros

*dwReserved*  
Reservado para uso futuro; deve ser zero.

## <a name="return-value"></a>Valor de retorno

S_OK se bem-sucedido; Caso contrário, um HRESULT que indica o erro.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** ftm.h

**Namespace:** Microsoft::WRL

## <a name="see-also"></a>Consulte também

[Classe FtmBase](../windows/ftmbase-class.md)