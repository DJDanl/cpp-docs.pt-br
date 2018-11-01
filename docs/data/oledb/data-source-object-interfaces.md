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
ms.openlocfilehash: aaa9e90996750b0518999803487fcb39729c76f9
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50519633"
---
# <a name="data-source-object-interfaces"></a>Interfaces de objeto da fonte de dados

A tabela a seguir mostra as interfaces obrigatórias e opcionais definidas por OLE DB para um objeto de fonte de dados.

|Interface|Necessário?|Implementado por modelos OLE DB?|
|---------------|---------------|--------------------------------------|
|`IDBCreateSession`|Obrigatório|Sim|
|`IDBInitialize`|Obrigatório|Sim|
|`IDBProperties`|Obrigatório|Sim|
|[IPersist](/windows/desktop/api/objidl/nn-objidl-ipersist)|Obrigatório|Sim|
|[IConnectionPointContainer](/windows/desktop/api/ocidl/nn-ocidl-iconnectionpointcontainer)|Opcional|Não|
|`IDBDataSourceAdmin`|Opcional|Não|
|`IDBInfo`|Opcional|Não|
|[IPersistFile](/windows/desktop/api/objidl/nn-objidl-ipersistfile)|Opcional|Não|
|`ISupportErrorInfo`|Opcional|Não|

A fonte de dados objeto implementa a `IDBProperties`, `IDBInitialize`, e `IDBCreateSession` interfaces por meio da herança. Você pode escolher dar suporte à funcionalidade adicional por herdar ou não herdar de uma dessas classes de implementação. Se você quiser dar suporte a `IDBDataSourceAdmin` interface, você deve herdar o `IDBDataSourceAdminImpl` classe.

## <a name="see-also"></a>Consulte também

[Arquitetura de modelo do provedor do OLE DB](../../data/oledb/ole-db-provider-template-architecture.md)<br/>
