---
title: Suporte a IDispatch e IErrorInfo | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
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
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: f39db3e844df884e8e95352bed2a078b01beede8
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="supporting-idispatch-and-ierrorinfo"></a>Suporte a IDispatch e IErrorInfo
Você pode usar a classe de modelo [IDispatchImpl](../atl/reference/idispatchimpl-class.md) para fornecer uma implementação padrão da `IDispatch Interface` parte de qualquer interface dupla em seu objeto.  
  
 Se o objeto usa o `IErrorInfo` interface para relatar erros de volta ao cliente, em seguida, o objeto deve dar suporte a `ISupportErrorInfo Interface` interface. A classe de modelo [ISupportErrorInfoImpl](../atl/reference/isupporterrorinfoimpl-class.md) fornece uma maneira fácil de implementar isso, se você tiver apenas uma única interface que gera erros em seu objeto.  
  
## <a name="see-also"></a>Consulte também  
 [Princípios básicos de objetos COM da ATL](../atl/fundamentals-of-atl-com-objects.md)

