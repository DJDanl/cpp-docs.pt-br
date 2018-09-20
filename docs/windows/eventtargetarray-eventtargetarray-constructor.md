---
title: 'Construtor eventtargetarray:: Eventtargetarray | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- event/Microsoft::WRL::Details::EventTargetArray::EventTargetArray
dev_langs:
- C++
helpviewer_keywords:
- EventTargetArray, constructor
ms.assetid: 6c6d3737-3cd3-4515-a8f6-d27901bb8ed2
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: dc59b9c93cebb622f40881d961709079abcd9166
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46388622"
---
# <a name="eventtargetarrayeventtargetarray-constructor"></a>Construtor EventTargetArray::EventTargetArray

Oferece suporte a infraestrutura do WRL e não se destina a ser usado diretamente do seu código.

## <a name="syntax"></a>Sintaxe

```cpp
EventTargetArray(
   _Out_ HRESULT* hr,
   size_t items
);
```

### <a name="parameters"></a>Parâmetros

*hr*<br/>
Depois de operações esse construtor, parâmetro *hr* indica se a alocação da matriz foi bem-sucedida ou falhou. A tabela a seguir lista os possíveis valores para *hr*.

S_OK, a operação foi bem-sucedida.

Não foi possível alocar memória E_OUTOFMEMORY para a matriz.

Parâmetro S_FALSE *itens* é menor ou igual a zero.

*Itens*<br/>
O número de elementos da matriz para alocar.

## <a name="remarks"></a>Comentários

Inicializa uma nova instância dos **EventTargetArray** classe.

**EventTargetArray** é usado para manter uma matriz de manipuladores de eventos em um `EventSource` objeto.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** Event. h

**Namespace:** Microsoft::WRL::Details

## <a name="see-also"></a>Consulte também

[Classe EventTargetArray](../windows/eventtargetarray-class.md)<br/>
[Namespace Microsoft::WRL::Details](../windows/microsoft-wrl-details-namespace.md)