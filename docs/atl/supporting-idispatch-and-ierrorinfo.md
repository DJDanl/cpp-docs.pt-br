---
title: Suporte a IDispatch e IErrorInfo | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-atl
ms.topic: conceptual
f1_keywords:
- IErrorInfo
- IDispatch
dev_langs:
- C++
helpviewer_keywords:
- ISupportErrorInfoImpl method
- IErrorInfo class suppor in ATL
- IDispatchImpl class
- IDispatch class support in ATL
ms.assetid: 7db2220f-319d-4ce9-9382-d340019f14f7
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 0d9c27dfe81c3bbd2978f418c8e942ac20190b30
ms.sourcegitcommit: 92dbc4b9bf82fda96da80846c9cfcdba524035af
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/05/2018
ms.locfileid: "43753602"
---
# <a name="supporting-idispatch-and-ierrorinfo"></a>Suporte a IDispatch e IErrorInfo

Você pode usar a classe de modelo [IDispatchImpl](../atl/reference/idispatchimpl-class.md) para fornecer uma implementação padrão da `IDispatch Interface` parte de qualquer interface dupla em seu objeto.

Se o objeto usa o `IErrorInfo` interface para relatar erros de volta para o cliente e, em seguida, seu objeto deve dar suporte a `ISupportErrorInfo Interface` interface. A classe de modelo [ISupportErrorInfoImpl](../atl/reference/isupporterrorinfoimpl-class.md) fornece uma maneira fácil de implementar isso, se você tiver apenas uma única interface que gera erros em seu objeto.

## <a name="see-also"></a>Consulte também

[Princípios básicos de objetos COM da ATL](../atl/fundamentals-of-atl-com-objects.md)

