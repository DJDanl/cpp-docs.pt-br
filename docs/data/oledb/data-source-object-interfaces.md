---
title: Interfaces de objeto da fonte de dados
ms.date: 10/24/2018
helpviewer_keywords:
- data source objects [C++], interfaces
- data source objects [C++]
- interfaces [C++], OLE DB
- interfaces [C++], list of
- OLE DB provider templates [C++], object interfaces
- OLE DB [C++], interfaces
ms.assetid: 929e100c-c08c-4b64-8437-d8d1357226f6
ms.openlocfilehash: a615694a9db75cdaf3b187cf6d29248bd26ef978
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "70311733"
---
# <a name="data-source-object-interfaces"></a>Interfaces de objeto da fonte de dados

A tabela a seguir mostra as interfaces obrigatórias e opcionais definidas por OLE DB para um objeto de fonte de dados.

|Interface|Necessário?|Implementado por modelos de OLE DB?|
|---------------|---------------|--------------------------------------|
|`IDBCreateSession`|Obrigatório|Sim|
|`IDBInitialize`|Obrigatório|Sim|
|`IDBProperties`|Obrigatório|Sim|
|[IPersist](/windows/win32/api/objidl/nn-objidl-ipersist)|Obrigatório|Sim|
|[IConnectionPointContainer](/windows/win32/api/ocidl/nn-ocidl-iconnectionpointcontainer)|Opcional|Não|
|`IDBDataSourceAdmin`|Opcional|Não|
|`IDBInfo`|Opcional|Não|
|[IPersistFile](/windows/win32/api/objidl/nn-objidl-ipersistfile)|Opcional|Não|
|`ISupportErrorInfo`|Opcional|Não|

O objeto de fonte de dados `IDBProperties`implementa `IDBInitialize`as interfaces `IDBCreateSession` , e por herança. Você pode optar por oferecer suporte à funcionalidade adicional, herdando ou não herdando de uma dessas classes de implementação. Se você quiser dar suporte `IDBDataSourceAdmin` à interface, deverá herdar `IDBDataSourceAdminImpl` da classe.

## <a name="see-also"></a>Consulte também

[Arquitetura de modelo do provedor do OLE DB](../../data/oledb/ole-db-provider-template-architecture.md)<br/>
