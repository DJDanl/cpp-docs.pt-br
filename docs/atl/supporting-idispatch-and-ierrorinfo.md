---
title: Suporte a IDispatch e IErrorInfo
ms.date: 11/04/2016
helpviewer_keywords:
- ISupportErrorInfoImpl method
- IErrorInfo class suppor in ATL
- IDispatchImpl class
- IDispatch class support in ATL
ms.assetid: 7db2220f-319d-4ce9-9382-d340019f14f7
ms.openlocfilehash: 2dcebd215ff5e1bdf72323323dfbaebd16fa3403
ms.sourcegitcommit: c6f8e6c2daec40ff4effd8ca99a7014a3b41ef33
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/24/2019
ms.locfileid: "64342031"
---
# <a name="supporting-idispatch-and-ierrorinfo"></a>Suporte a IDispatch e IErrorInfo

Você pode usar a classe de modelo [IDispatchImpl](../atl/reference/idispatchimpl-class.md) para fornecer uma implementação padrão da `IDispatch Interface` parte de qualquer interface dupla em seu objeto.

Se o objeto usa o `IErrorInfo` interface para relatar erros de volta para o cliente e, em seguida, seu objeto deve dar suporte a `ISupportErrorInfo Interface` interface. A classe de modelo [ISupportErrorInfoImpl](../atl/reference/isupporterrorinfoimpl-class.md) fornece uma maneira fácil de implementar isso, se você tiver apenas uma única interface que gera erros em seu objeto.

## <a name="see-also"></a>Consulte também

[Princípios básicos de objetos COM da ATL](../atl/fundamentals-of-atl-com-objects.md)
