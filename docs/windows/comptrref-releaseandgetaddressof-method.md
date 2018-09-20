---
title: 'Método comptrref:: Releaseandgetaddressof | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- client/Microsoft::WRL::Details::ComPtrRef::ReleaseAndGetAddressOf
dev_langs:
- C++
helpviewer_keywords:
- ReleaseAndGetAddressOf method
ms.assetid: 004aac42-e135-41ce-8d1d-4c5969d55004
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 48c9c748b80bb7900d57e1e0c0aff68d8e1f4ec1
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46424957"
---
# <a name="comptrrefreleaseandgetaddressof-method"></a>Método ComPtrRef::ReleaseAndGetAddressOf

Oferece suporte a infraestrutura do WRL e não se destina a ser usado diretamente do seu código.

## <a name="syntax"></a>Sintaxe

```cpp
InterfaceType** ReleaseAndGetAddressOf();
```

## <a name="return-value"></a>Valor de retorno

Ponteiro para a interface que fosse representado pelo excluídos **ComPtrRef** objeto.

## <a name="remarks"></a>Comentários

Exclui o atual **ComPtrRef** do objeto e retorna um ponteiro-para-um-ponteiro para a interface que foi representada pela **ComPtrRef** objeto.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** client.h

**Namespace:** Microsoft::WRL::Details

## <a name="see-also"></a>Consulte também

[Classe ComPtrRef](../windows/comptrref-class.md)<br/>
[Namespace Microsoft::WRL::Details](../windows/microsoft-wrl-details-namespace.md)