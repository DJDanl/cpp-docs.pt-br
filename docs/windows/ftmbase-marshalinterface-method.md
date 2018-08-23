---
title: 'Método ftmbase:: Marshalinterface | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- ftm/Microsoft::WRL::FtmBase::MarshalInterface
dev_langs:
- C++
helpviewer_keywords:
- MarshalInterface method
ms.assetid: fc8421b4-06e4-4925-b908-c285fe4790d2
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: a95521123a87a6ae68ce9f923779c1a6ceda4ccf
ms.sourcegitcommit: 6f8dd98de57bb80bf4c9852abafef1c35a7600f1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/22/2018
ms.locfileid: "42599705"
---
# <a name="ftmbasemarshalinterface-method"></a>Método FtmBase::MarshalInterface

Grava os dados necessários para inicializar um objeto de proxy em algum processo do cliente em um fluxo.

## <a name="syntax"></a>Sintaxe

```cpp
STDMETHODIMP MarshalInterface(
   __in IStream *pStm,
   __in REFIID riid,
   __in_opt void *pv,
   __in DWORD dwDestContext,
   __reserved void *pvDestContext,
   __in DWORD mshlflags
) override;
```

### <a name="parameters"></a>Parâmetros

*pStm*  
Ponteiro para o fluxo a ser usado durante o marshaling.

*riid*  
Referência ao identificador da interface a ser empacotado. Essa interface deve ser derivada de `IUnknown` interface.

*VP*  
Ponteiro para o ponteiro de interface para ser empacotado; pode ser NULL se o chamador não tem um ponteiro para a interface desejada.

*dwDestContext*  
Contexto de destino onde a interface especificada deve ser desempacotada.

Especifique um ou mais valores de enumeração MSHCTX.

Unmarshaling pode ocorrer em outra apartment do processo atual (MSHCTX_INPROC) ou em outro processo no mesmo computador que o processo atual (MSHCTX_LOCAL).

*pvDestContext*  
Reservado para uso futuro; deve ser zero.

*mshlflags*  
Especifica se os dados a ser empacotado deve ser transmitido de volta para o processo do cliente — o caso comum — ou gravados em uma tabela global, onde ela pode ser recuperada por vários clientes.

## <a name="return-value"></a>Valor de retorno

S_OK o ponteiro de interface foi empacotado com êxito.

Não há suporte para a interface especificada de E_NOINTERFACE.

STG_E_MEDIUMFULL o fluxo está cheio.

E_FAIL a operação falha.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** ftm.h

**Namespace:** Microsoft::WRL

## <a name="see-also"></a>Consulte também

[Classe FtmBase](../windows/ftmbase-class.md)